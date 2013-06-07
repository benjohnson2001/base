#ifndef __DIALOG_EVENTS_H__
#define __DIALOG_EVENTS_H__

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

// event callback can only accept one argument, but we need two,
// hence this struct.
// each dialog has a local static copy:
//   win is the dialog window 
//   stop is the transientize semaphore: when 0, retransientizing this dialog is allowed

typedef struct { 
  GtkWidget *win;
  guint stop;
} win_data;

gboolean sp_dialog_event_handler (GtkWindow *win, GdkEvent *event, gpointer data);
void sp_dialog_defocus (GtkWindow *win);
void sp_dialog_defocus_callback (GtkWindow *win, gpointer data);
void sp_dialog_defocus_on_enter (GtkWidget *w);
void sp_transientize (GtkWidget *win);
void sp_transientize_callback (Inkscape *inkscape, SPDesktop *desktop, win_data *wd);

#endif
