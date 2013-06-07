#define __SP_PATH_C__

/*
 * SVG <path> implementation
 *
 * Authors:
 *   Lauris Kaplinski <lauris@kaplinski.com>
 *
 * Copyright (C) 1999-2002 Lauris Kaplinski
 * Copyright (C) 2000-2001 Ximian, Inc.
 *
 * Released under GNU GPL, read the file 'COPYING' for more information
 */

#include <string.h>

#include <libnr/nr-path.h>
#include <libnr/nr-values.h>
#include <libnr/nr-macros.h>
#include <libnr/nr-matrix.h>

#include "svg/svg.h"
#include "attributes.h"
#include "style.h"
#include "version.h"

#include "sp-path.h"

#define noPATH_VERBOSE

static void sp_path_class_init (SPPathClass *klass);
static void sp_path_init (SPPath *path);

static void sp_path_build (SPObject * object, SPDocument * document, SPRepr * repr);
static void sp_path_set (SPObject *object, unsigned int key, const gchar *value);

static SPRepr *sp_path_write (SPObject *object, SPRepr *repr, guint flags);
static void sp_path_write_transform (SPItem *item, SPRepr *repr, NRMatrixF *transform);

static SPShapeClass *parent_class;

/**
 * Gets the GType object for SPPathClass
 */
GType
sp_path_get_type (void)
{
	static GType type = 0;

	if (!type) {
		GTypeInfo info = {
			sizeof (SPPathClass),
			NULL, NULL,
			(GClassInitFunc) sp_path_class_init,
			NULL, NULL,
			sizeof (SPPath),
			16,
			(GInstanceInitFunc) sp_path_init,
		};
		type = g_type_register_static (SP_TYPE_SHAPE, "SPPath", &info, (GTypeFlags)0);
	}
	return type;
}

/** 
 *  Does the object-oriented work of initializing the class structure
 *  including parent class, and registers function pointers for
 *  the functions build, set, write, and write_transform.
 */
static void
sp_path_class_init (SPPathClass * klass)
{
	SPObjectClass *sp_object_class;
	SPItemClass *item_class;

	sp_object_class = (SPObjectClass *) klass;
	item_class = (SPItemClass *) klass;

	parent_class = (SPShapeClass *)g_type_class_peek_parent (klass);

	sp_object_class->build = sp_path_build;
	sp_object_class->set = sp_path_set;
	sp_object_class->write = sp_path_write;

	item_class->write_transform = sp_path_write_transform;
}

/**
 * Initializes an SPPath.  Currently does nothing.
 */
static void
sp_path_init (SPPath *path)
{
	/* Nothing here */
}

/**
 *  Given a repr, this sets the data items in the path object such as
 *  fill & style attributes, markers, and CSS properties.
 */
static void
sp_path_build (SPObject *object, SPDocument *document, SPRepr *repr)
{
	SPPath *path;
	SPVersion version;
	const gchar* marker_value;

	path = SP_PATH (object);

	version = sp_object_get_sodipodi_version (object);

	/* Fixes old Sodipodi nodetype to namespaced parameter */
	if (sp_version_inside_range (version, 0, 0, 0, 25)) {
		const gchar *str;
		str = sp_repr_attr (repr, "INKSCAPE-PATH-NODE-TYPES");
		sp_repr_set_attr (repr, "sodipodi:nodetypes", str);
		sp_repr_set_attr (repr, "INKSCAPE-PATH-NODE-TYPES", NULL);
	}

	sp_object_read_attr (object, "d");

	/* Are these calls actually necessary? */
	sp_object_read_attr (object, "marker");
	sp_object_read_attr (object, "marker-start");
	sp_object_read_attr (object, "marker-mid");
	sp_object_read_attr (object, "marker-end");

	if (sp_version_inside_range (version, 0, 0, 0, 25)) {
		SPShape *shape;
		SPCSSAttr *css;
		const gchar *val;
		gboolean changed;
		gboolean open;
		shape = (SPShape *) path;
		/* Remove fill from open paths for compatibility with inkscape < 0.25 */
		/* And set fill-rule of closed paths to evenodd */
		/* We force style rewrite at moment (Lauris) */
		changed = TRUE;
		open = FALSE;
		if (shape->curve && shape->curve->bpath) {
			ArtBpath *bp;
			for (bp = shape->curve->bpath; bp->code != ART_END; bp++) {
				if (bp->code == ART_MOVETO_OPEN) {
					open = TRUE;
					break;
				}
			}
		}
		css = sp_repr_css_attr (repr, "style");
		if (open) {
			val = sp_repr_css_property (css, "fill", NULL);
			if (val && strcmp (val, "none")) {
				sp_repr_css_set_property (css, "fill", "none");
				changed = TRUE;
			}
		} else {
			val = sp_repr_css_property (css, "fill-rule", NULL);
			if (!val) {
				sp_repr_css_set_property (css, "fill-rule", "evenodd");
				changed = TRUE;
			}
		}
		if (changed) {
			sp_repr_css_set (repr, css, "style");
		}
		sp_repr_css_attr_unref (css);
	}

	if (((SPObjectClass *) parent_class)->build) {
		((SPObjectClass *) parent_class)->build (object, document, repr);
	}
}

/**
 *  Sets a value in the path object given by 'key', to 'value'.  This is used
 *  for setting attributes and markers on a path object.
 */
static void
sp_path_set (SPObject *object, unsigned int key, const gchar *value)
{
	SPPath *path;
	int marker_type;

	path = (SPPath *) object;

	switch (key) {
	case SP_ATTR_D:
		if (value) {
			ArtBpath *bpath;
			SPCurve *curve;
			bpath = sp_svg_read_path (value);
			curve = sp_curve_new_from_bpath (bpath);
			sp_shape_set_curve ((SPShape *) path, curve, TRUE);
			sp_curve_unref (curve);
		} else {
			sp_shape_set_curve ((SPShape *) path, NULL, TRUE);
		}
		break;
	case SP_PROP_MARKER:
	case SP_PROP_MARKER_START:
	case SP_PROP_MARKER_MID:
	case SP_PROP_MARKER_END:
	      sp_shape_set_marker (object, key,  value);
	    break;
 	default:
		if (((SPObjectClass *) parent_class)->set) {
			((SPObjectClass *) parent_class)->set (object, key, value);
		}
		break;
	}
}

/**
 *
 * Writes the path object into a SPRepr
 */
static SPRepr *
sp_path_write (SPObject *object, SPRepr *repr, guint flags)
{
	SPShape *shape;
	ArtBpath *abp;
	gchar *str;

	shape = (SPShape *) object;

	if ((flags & SP_OBJECT_WRITE_BUILD) && !repr) {
		repr = sp_repr_new ("path");
	}

	abp = sp_curve_first_bpath (shape->curve);
	str = sp_svg_write_path (abp);
	sp_repr_set_attr (repr, "d", str);
	g_free (str);

	if (((SPObjectClass *) (parent_class))->write) {
		((SPObjectClass *) (parent_class))->write (object, repr, flags);
	}

	return repr;
}

/**
 * Writes the given transform into the repr for the given item.
 */
static void
sp_path_write_transform (SPItem *item, SPRepr *repr, NRMatrixF *transform)
{
	SPPath *path;
	SPShape *shape;
	NRBPath dpath, spath;
	double ex;
	gchar *svgpath;
	SPStyle *style;

	path = (SPPath *) item;
	shape = (SPShape *) item;

	/* Calculate the DF */
	ex = NR_MATRIX_DF_EXPANSION (transform);

	/* Take the path for the shape, write it as an svgpath, and add it to the repr */
	spath.path = shape->curve->bpath;
	nr_path_duplicate_transform (&dpath, &spath, transform);
	svgpath = sp_svg_write_path (dpath.path);
	sp_repr_set_attr (repr, "d", svgpath);
	g_free (svgpath);
	nr_free (dpath.path);

	/* Wrte the style info into the repr */
	style = SP_OBJECT_STYLE (item);
	if (style->stroke.type != SP_PAINT_TYPE_NONE) {
		if (!NR_DF_TEST_CLOSE (ex, 1.0, NR_EPSILON_D)) {
			gchar *str;
			/* Scale changed, so we have to adjust stroke width */
			style->stroke_width.computed *= ex;
			if (style->stroke_dash.n_dash != 0) {
				int i;
				for (i = 0; i < style->stroke_dash.n_dash; i++) style->stroke_dash.dash[i] *= ex;
				style->stroke_dash.offset *= ex;
			}
			str = sp_style_write_difference (style, SP_OBJECT_STYLE (SP_OBJECT_PARENT (item)));
			sp_repr_set_attr (repr, "style", str);
			g_free (str);
		}
	}
	sp_repr_set_attr (repr, "transform", NULL);
}

