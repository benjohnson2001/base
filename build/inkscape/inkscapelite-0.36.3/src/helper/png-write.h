#ifndef __SP_PNG_WRITE_H__
#define __SP_PNG_WRITE_H__

/*
 * PNG file format utilities
 *
 * Authors:
 *   Lauris Kaplinski <lauris@kaplinski.com>
 *
 * Copyright (C) 1999-2002 Lauris Kaplinski
 *
 * Released under GNU GPL, read the file 'COPYING' for more information
 */

int sp_png_write_rgba (const gchar *filename, const guchar *px, int width, int height, int rowstride);

int sp_png_write_rgba_striped (const gchar *filename, int width, int height,
			       int (* get_rows) (const guchar **rows, int row, int num_rows, void *data),
			       void *data);

#endif
