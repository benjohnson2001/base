/*
 * @file inkscape-stock.h GTK+ Stock resources
 *
 * Authors:
 *   Robert Crosbie
 *
 * Copyright (C) 1999-2002 Authors
 *
 * This program is free software; you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation; either version 2 of the License, or
 * (at your option) any later version.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this program; if not, write to the Free Software
 * Foundation, Inc., 59 Temple Place, Suite 330, Boston, MA  02111-1307  USA
 */

#ifndef _INKSCAPE_STOCK_H_
#define _INKSCAPE_STOCK_H_

/**************************************************************************/
/** @name Inkscape Stock images                                           */
/**************************************************************************/
/*@{*/

/*stroke style*/
#define INKSCAPE_STOCK_ABOUT                 "inkscape-about"
#define INKSCAPE_STOCK_JOIN_MITER            "join_miter"
#define INKSCAPE_STOCK_JOIN_ROUND            "join_round"
#define INKSCAPE_STOCK_JOIN_BEVEL            "join_bevel"
#define INKSCAPE_STOCK_CAP_BUTT              "cap_butt"
#define INKSCAPE_STOCK_CAP_ROUND             "cap_round"
#define INKSCAPE_STOCK_CAP_SQUARE            "cap_square"
#define INKSCAPE_STOCK_START_NONE            "start_marker-none"
#define INKSCAPE_STOCK_START_FILLED_ARROW    "start_marker-filled_arrow"
#define INKSCAPE_STOCK_START_HOLLOW_ARROW    "start_marker-hollow_arrow"
#define INKSCAPE_STOCK_MID_NONE              "start_marker-none"
#define INKSCAPE_STOCK_MID_FILLED_ARROW      "mid_marker-filled_arrow"
#define INKSCAPE_STOCK_MID_HOLLOW_ARROW      "mid_marker-hollow_arrow"
#define INKSCAPE_STOCK_END_NONE              "end_marker-none"
#define INKSCAPE_STOCK_END_FILLED_ARROW      "end_marker-filled_arrow"
#define INKSCAPE_STOCK_END_HOLLOW_ARROW      "end_marker-hollow_arrow"
/*object properties*/
#define INKSCAPE_STOCK_ROTATE_LEFT           "rotate_left"
#define INKSCAPE_STOCK_SCALE_HOR             "scale_hor"
#define INKSCAPE_STOCK_SCALE_VER             "scale_ver"
#define INKSCAPE_STOCK_ARROWS_HOR            "arrows_hor"
#define INKSCAPE_STOCK_ARROWS_VER            "arrows_ver"
#define INKSCAPE_STOCK_DIMENSION_HOR         "dimension_hor"
#define INKSCAPE_STOCK_DIMENSION_VER         "dimension_hor"

#define INKSCAPE_STOCK_WRITING_MODE_LR       "writing_mode_lr"
#define INKSCAPE_STOCK_WRITING_MODE_TB       "writing_mode_tb"
/*xml-tree*/
#define INKSCAPE_STOCK_ADD_XML_ELEMENT_NODE  "add_xml_element_node"
#define INKSCAPE_STOCK_ADD_XML_TEXT_NODE     "add_xml_text_node"
#define INKSCAPE_STOCK_DUPLICATE_XML_NODE    "duplicate_xml_node"
#define INKSCAPE_STOCK_DELETE_XML_NODE       "delete_xml_node"
#define INKSCAPE_STOCK_DELETE_XML_ATTRIBUTE  "delete_xml_attribute"
#define INKSCAPE_STOCK_SET                   "set"
/*paint-selector*/
#define INKSCAPE_STOCK_FILL_NONE             "fill_none"
#define INKSCAPE_STOCK_FILL_SOLID            "fill_solid"
#define INKSCAPE_STOCK_FILL_GRADIENT         "fill_gradient"
#define INKSCAPE_STOCK_FILL_RADIAL           "fill_radial"
#define INKSCAPE_STOCK_FILL_PATTERN          "fill_pattern"
#define INKSCAPE_STOCK_FILL_FRACTAL          "fill_fractal"

#define INKSCAPE_STOCK_GUIDE_DIALOG          "guide_dialog"

#define INKSCAPE_STOCK_TOOLBOX_FILE          "toolbox_file"
#define INKSCAPE_STOCK_TOOLBOX_EDIT          "toolbox_edit"
#define INKSCAPE_STOCK_TOOLBOX_OBJECT        "toolbox_object"
#define INKSCAPE_STOCK_TOOLBOX_SELECT        "toolbox_select"
#define INKSCAPE_STOCK_TOOLBOX_DRAW          "toolbox_draw"
#define INKSCAPE_STOCK_TOOLBOX_ZOOM          "toolbox_zoom"
#define INKSCAPE_STOCK_TOOLBOX_NODE          "toolbox_node"
#define INKSCAPE_STOCK_SEPARATE_TOOL         "separate_tool"

#define INKSCAPE_STOCK_EDIT_DUPLICATE        "edit_duplicate"

#define INKSCAPE_STOCK_SELECTION_TOP         "selection_top"
#define INKSCAPE_STOCK_SELECTION_BOT         "selection_bot"
#define INKSCAPE_STOCK_SELECTION_UP          "selection_up"
#define INKSCAPE_STOCK_SELECTION_DOWN        "selection_down"
#define INKSCAPE_STOCK_SELECTION_GROUP       "selection_group"
#define INKSCAPE_STOCK_SELECTION_UNGROUP     "selection_ungroup"
#define INKSCAPE_STOCK_SELECTION_COMBINE     "selection_combine"
#define INKSCAPE_STOCK_SELECTION_BREAK       "selection_break"

#define INKSCAPE_STOCK_OBJECT_ROTATE         "object_rotate"
#define INKSCAPE_STOCK_OBJECT_RESET          "object_reset"
#define INKSCAPE_STOCK_OBJECT_TOCURVE        "object_tocurve"

#define INKSCAPE_STOCK_DRAW_SELECT           "draw_select"
#define INKSCAPE_STOCK_DRAW_NODE             "draw_node"
#define INKSCAPE_STOCK_DRAW_RECT             "draw_rect"
#define INKSCAPE_STOCK_DRAW_ARC              "draw_arc"
#define INKSCAPE_STOCK_DRAW_STAR             "draw_star"
#define INKSCAPE_STOCK_DRAW_SPIRAL           "draw_spiral"
#define INKSCAPE_STOCK_DRAW_FREEHAND         "draw_freehand"
#define INKSCAPE_STOCK_DRAW_PEN              "draw_pen"
#define INKSCAPE_STOCK_DRAW_DYNAHAND         "draw_dynahand"
#define INKSCAPE_STOCK_DRAW_TEXT             "draw_text"
#define INKSCAPE_STOCK_DRAW_ZOOM             "draw_zoom"
#define INKSCAPE_STOCK_DRAW_DROPPER          "draw_dropper"

#define INKSCAPE_STOCK_ZOOM_IN               "zoom_in"
#define INKSCAPE_STOCK_ZOOM_OUT              "zoom_out"
#define INKSCAPE_STOCK_TOGGLE_GRID           "toggle_grid"
#define INKSCAPE_STOCK_TOGGLE_GUIDES         "toggle_guides"
#define INKSCAPE_STOCK_ZOOM_PAGE             "zoom_page"
#define INKSCAPE_STOCK_ZOOM_DRAW             "zoom_draw"
#define INKSCAPE_STOCK_ZOOM_SELECT           "zoom_select"

#define INKSCAPE_STOCK_OBJECT_LAYOUT         "object_layout"
#define INKSCAPE_STOCK_OBJECT_TRANS          "object_trans"
#define INKSCAPE_STOCK_OBJECT_ALIGN          "object_align"
#define INKSCAPE_STOCK_OBJECT_FONT           "object_font"


/**
 * Sets up the inkscape stock repository.
 */
#ifdef __cplusplus
extern "C" {
#endif /* __cplusplus */

void inkscape_gtk_stock_init(void);

#ifdef __cplusplus
}
#endif /* __cplusplus */

#endif /* _INKSCAPE_STOCK_H_ */
