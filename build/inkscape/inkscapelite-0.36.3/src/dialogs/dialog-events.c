#define __DIALOG_EVENTS_C__

/*
 * Event handler for dialog windows
 *
 * Authors:
 *   bulia byak <bulia@dr.com>
 *
 * Copyright (C) 2003 authors
 *
 * Released under GNU GPL, read the file 'COPYING' for more information
 */

#include <config.h>

#include <glib.h>
#include <gdk/gdkkeysyms.h>
#include <gtk/gtksignal.h>
#include <time.h>
#include "helper/window.h"
#include "widgets/sp-widget.h"
#include "macros.h"
#include "inkscape.h"
#include <gtk/gtk.h>
#include "desktop-events.h"
#include "desktop.h"
#include "inkscape-private.h"

#include "dialog-events.h"

// this function is called to zero the transientize semaphore by a timeout
gboolean 
sp_allow_again (gpointer *wd) 
{
	((win_data *) wd)->stop = 0;
	return FALSE; // so that it is only called once
}

/**
\brief remove focus from window to whoever it is transient for
*/
void
sp_dialog_defocus (GtkWindow *win)
{
	GtkWindow *w;
	//find out the document window we're transient for
	w = gtk_window_get_transient_for ((GtkWindow *) win);
	//switch to it
	if (w) {
		gtk_window_present (w);
	}
}

/**
\brief callback to defocus a widget's parent dialog
*/
void
sp_dialog_defocus_callback (GtkWindow *win, gpointer data)
{
	sp_dialog_defocus ((GtkWindow *) gtk_widget_get_toplevel ((GtkWidget *) data));
}

void
sp_dialog_defocus_on_enter (GtkWidget *w)
{
	g_signal_connect (G_OBJECT (w), "activate", G_CALLBACK (sp_dialog_defocus_callback), w);
}

gboolean
sp_dialog_event_handler (GtkWindow *win, GdkEvent *event, gpointer data)
{
	gboolean ret = FALSE; 

	switch (event->type) {
	case GDK_KEY_PRESS:
		switch (event->key.keyval) {
		case GDK_Escape: 
			sp_dialog_defocus (win);
			ret = TRUE; 
			break;
		case GDK_F4:
		case GDK_w:
		case GDK_W:
			// close dialog
			if (MOD__CTRL_ONLY) {
				// this code sends a delete_event to the dialog, instead of just destroying it,
				// so that the dialog can do some housekeeping, such as remember its position
				GdkEventAny event;
				GtkWidget *widget = (GtkWidget *) win;
				event.type = GDK_DELETE;
				event.window = widget->window;
				event.send_event = TRUE;
				g_object_ref (G_OBJECT (event.window));
				gtk_main_do_event ((GdkEvent*)&event);
				g_object_unref (G_OBJECT (event.window));

				ret = TRUE; 
			}
			break;
		default: // pass keypress to the canvas
			break;
		}
	default:
		;
	}
	return ret; 
}

void
sp_transientize (GtkWidget *dialog)
{
	// transientzing does not work on windows; when you minimize a document and then open it back, 
	// only its transient emerges and you cannot access the document window 
#ifndef WIN32
	// if there's an active document window, attach dialog to it as a transient:
	if (SP_ACTIVE_DESKTOP && g_object_get_data (G_OBJECT (SP_ACTIVE_DESKTOP), "window")) 
		gtk_window_set_transient_for ((GtkWindow *) dialog, (GtkWindow *) g_object_get_data (G_OBJECT (SP_ACTIVE_DESKTOP), "window"));
#endif
}

void
sp_transientize_callback (Inkscape *inkscape, SPDesktop *desktop, win_data *wd)
{
#ifndef WIN32
	if (wd->stop) { // if retransientizing of this dialog is still forbidden after previous call
		// warning turned off because it was confusingly fired when loading many files from command line
		//		g_warning("Retranzientize aborted! You're switching windows too fast!"); 
		return;
	}
	GtkWindow *w;

	w = (GtkWindow *) g_object_get_data (G_OBJECT (desktop), "window"); 
	if (w && wd->win) {
		wd->stop = 1; // disallow other attempts to retranzientize this dialog
		gtk_window_set_transient_for ((GtkWindow *) wd->win, w);

		/* Uncomment the following line if you want "aggressive" transientization,
		i.e. dialogs always emerging on top when you switch documents. Note however
		that this breaks "click to raise" policy of a window manager because the switched-to
		document will be raised at once (so that its transients also could raise) */
		//gtk_window_present (w); // without this, a transient window not always emerges on top
	}
	// we're done, allow next retransientizing not sooner than after 6 msec
	gtk_timeout_add (6, (GtkFunction) sp_allow_again, (gpointer) wd);  
#endif
}

