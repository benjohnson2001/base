static const Bool wmborder = False;
static const char *font = "-misc-cloaked humanity bold-medium-r-normal--0-0-0-0-p-0-adobe-fontspecific";
static const char *normbgcolor = "#222222";
static const char *normfgcolor = "#7D7D7D";
static const char *pressbgcolor = "#ffffff";
static const char *pressfgcolor = "#000000";
static const char *highlightbgcolor = "#222222";
static const char *highlightfgcolor = "#CCCCCC";

static float widthscaling = 1.0;
static float heightscaling = 1.0;

#define MODKEY Mod1Mask

static Key keys[] = {
	/* modifier                     key           function        argument */
	{ MODKEY,                       XK_n,         togglebar,      {0} }                // toggle bar visibility          Alt+b
};

