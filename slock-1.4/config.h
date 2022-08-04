/* user and group to drop privileges to */
static const char *user  = "mega";
static const char *group = "mega";

static const char *colorname[NUMCOLS] = {
	[INIT] =   "#111111",     /* after initialization */
	[INPUT] =  "#006699",   /* during input */
	[FAILED] = "#EE4444",   /* wrong password */
};

/* treat a cleared input like a wrong password (color) */
static const int failonclear = 1;

/* default message */
static const char * message = "LOCKED";

/* text color */
static const char * text_color = "#ffffff";

/* text size (must be a valid size) */
static const char * font_name = "lucidasans-bolditalic-24";
