
extensiondir = $(libdir)/inkscape/extensions

otherstuffdir = $(datadir)/inkscape/extensions

moduledir = $(datadir)/inkscape/modules

extensions = \
	roundhole \
	ill2svg.pl \
	dia2svg.sh

otherstuff = \
	roundhole.xpm

modules = \
	svgz_input.inkmod \
	svgz_output.inkmod \
	ai_input.inkmod \
	roundhole.inkmod \
	dia.inkmod

extension_SCRIPTS = \
	$(extensions)

otherstuff_DATA = \
	$(otherstuff)

module_DATA = \
	$(modules)

EXTRA_DIST = $(extension_SCRIPTS) $(otherstuff_DATA) $(module_DATA)

