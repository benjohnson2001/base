#ifndef __SP_COLOR_PREVIEW_H__
#define __SP_COLOR_PREVIEW_H__

/*
 * A simple color preview widget
 *
 * Author:
 *   Lauris Kaplinski <lauris@kaplinski.com>
 *
 * Copyright (C) 2001-2002 Lauris Kaplinski
 * Copyright (C) 2001 Ximian, Inc.
 *
 * Released under GNU GPL, read the file 'COPYING' for more information
 */

#include <gtk/gtkwidget.h>

#include <glib.h>

G_BEGIN_DECLS

typedef struct _SPColorPreview SPColorPreview;
typedef struct _SPColorPreviewClass SPColorPreviewClass;

#define SP_TYPE_COLOR_PREVIEW (sp_color_preview_get_type ())
#define SP_COLOR_PREVIEW(o) (GTK_CHECK_CAST ((o), SP_TYPE_COLOR_PREVIEW, SPColorPreview))
#define SP_COLOR_PREVIEW_CLASS(k) (GTK_CHECK_CLASS_CAST ((k), SP_TYPE_COLOR_PREVIEW, SPColorPreviewClass))
#define SP_IS_COLOR_PREVIEW(o) (GTK_CHECK_TYPE ((o), SP_TYPE_COLOR_PREVIEW))
#define SP_IS_COLOR_PREVIEW_CLASS(k) (GTK_CHECK_CLASS_TYPE ((k), SP_TYPE_COLOR_PREVIEW))

struct _SPColorPreview {
	GtkWidget widget;

	guint32 rgba;
};

struct _SPColorPreviewClass {
	GtkWidgetClass parent_class;
};

GtkType sp_color_preview_get_type (void);

GtkWidget *sp_color_preview_new (guint32 rgba);

void sp_color_preview_set_rgba32 (SPColorPreview *cp, guint32 color);


G_END_DECLS

#endif
