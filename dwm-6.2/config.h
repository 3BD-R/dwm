/* See LICENSE file for copyright and license details. */

/* appearance */
static const unsigned int borderpx  = 1;        /* border pixel of windows */
static const unsigned int gappx     = 2;        /* gaps between windows */
static const unsigned int snap      = 32;       /* snap pixel */
static const int showbar            = 0;        /* 0 means no bar */
static const int topbar             = 0;        /* 0 means bottom bar */
static const char *fonts[]          = { "Terminus :style=Bold:size=10", };
static const char dmenufont[]       = "DejaVu Sans:size=10";
static const char col_gray1[]       = "#222222";
static const char col_gray2[]       = "#444444";
static const char col_gray3[]       = "#bbbbbb";
static const char col_gray4[]       = "#eeeeee";
static const char col_cyan[]        = "#559aff";
static const char col_black[]       = "#0f0f0f";
static const char col_black1[]      = "#100a09";
static const char *colors[][3]      = {
     /*               fg         bg         border   */
       [SchemeNorm] = { col_gray3, col_gray1, col_gray2 },
       [SchemeSel]  = { "#cccccc", col_black/*"#830400"*/, "#003ad9" },

};

/* tagging */
static const char *tags[] = { "I", "II", "III"};

static const Rule rules[] = {
	/* xprop(1):
	 *	WM_CLASS(STRING) = instance, class
	 *	WM_NAME(STRING) = title
	 */
	/* class      instance    title       tags mask     isfloating   monitor */
	{ "Gimp",     NULL,       NULL,       0,            1,           -1 },
	{ "Firefox",  NULL,       NULL,       1 << 8,       0,           -1 },
};

/* layout(s) */
static const float mfact     = 0.55; /* factor of master area size [0.05..0.95] */
static const int nmaster     = 1;    /* number of clients in master area */
static const int resizehints = 1;    /* 1 means respect size hints in tiled resizals */
static const int lockfullscreen = 0; /* 1 will force focus on the fullscreen window */

static const Layout layouts[] = {
	/* symbol     arrange function */
	{ "[]=",      tile },    /* first entry is default */
	{ "><>",      NULL },    /* no layout function means floating behavior */
	{ "[M]",      monocle },
};

/* key definitions */
#define MODKEY Mod4Mask
#define TAGKEYS(KEY,TAG) /* \
	{ MODKEY,                       KEY,      view,           {.ui = 1 << TAG} }, \
	{ MODKEY|ControlMask,           KEY,      toggleview,     {.ui = 1 << TAG} }, \
	{ MODKEY|ShiftMask,             KEY,      tag,            {.ui = 1 << TAG} }, \
	{ MODKEY|ControlMask|ShiftMask, KEY,      toggletag,      {.ui = 1 << TAG} },  */

/* helper for spawning shell commands in the pre dwm-5.0 fashion */
#define SHCMD(cmd) { .v = (const char*[]){ "/bin/sh", "-c", cmd, NULL } }

/* commands */
static char dmenumon[2] = "0"; /* component of dmenucmd, manipulated in spawn() */
static const char *dmenucmd[] = { "dmenu_run", "-b", "-i", "-m", dmenumon, "-fn", dmenufont, "-nb", col_gray1, "-nf", col_gray3, "-sb", col_black, "-sf", col_gray4, NULL };
static const char *termcmd[]  = { "kitty", NULL };
/* static const char *termcmd2[] = {"st", NULL}; */

/* enable function keys */
#include <X11/XF86keysym.h>

/* shif-tools patch */
#include "shift-tools.c"

static Key keys[] = {
	/* modifier                         key               function             argument */
	{ Mod1Mask,                         XK_space,         spawn,               {.v = dmenucmd } },
	{ Mod1Mask|ControlMask,             XK_z,             spawn,               {.v = termcmd } },
/*	{ Mod1Mask|ControlMask,             XK_x,             spawn,               {.v = termcmd2 } }, */
	{ MODKEY,                           XK_F1,            togglebar,           {0} },
	{ Mod1Mask,                         XK_Tab,           focusstack,          {.i = +1 } },
 /* { MODKEY,                           XK_k,             focusstack,          {.i = -1 } }, */
 	{ MODKEY|ShiftMask,                 XK_h,             incnmaster,          {.i = +1 } },
	{ MODKEY|ShiftMask,                 XK_l,             incnmaster,          {.i = -1 } }, 
    { MODKEY,                           XK_h,             setmfact,            {.f = -0.05} },
	{ MODKEY,                           XK_l,             setmfact,            {.f = +0.05} },
	{ MODKEY,                           XK_Return,        zoom,                {0} },
 /* { MODKEY,                           XK_Tab,           view,                {0} }, */
	{ Mod1Mask,                         XK_F4,            killclient,          {0} },
	{ MODKEY,                           XK_n,             setlayout,           {.v = &layouts[0]} },
	{ MODKEY,                           XK_f,             setlayout,           {.v = &layouts[1]} },
	{ MODKEY,                           XK_p,             setlayout,           {.v = &layouts[2]} },
    { MODKEY,                           XK_v,             setlayout,           {0} }, 
/*	{ MODKEY|Mod1Mask,                  XK_Up,            togglefloating,      {0} }, */
 /* { MODKEY,                           XK_0,             view,                {.ui = ~0 } },
	{ MODKEY|ShiftMask,                 XK_0,             tag,                 {.ui = ~0 } },
	{ MODKEY,                           XK_comma,         focusmon,            {.i = -1 } },
	{ MODKEY,                           XK_period,        focusmon,            {.i = +1 } },
	{ MODKEY|ShiftMask,                 XK_comma,         tagmon,              {.i = -1 } },
	{ MODKEY|ShiftMask,                 XK_period,        tagmon,              {.i = +1 } }, */
	{ MODKEY,                           XK_minus,         setgaps,             {.i = -1 } },
	{ MODKEY,                           XK_equal,         setgaps,             {.i = +1 } },
	{ MODKEY|Mod1Mask,                  XK_equal,         setgaps,             {.i = 0  } },
 /*	TAGKEYS(                            XK_1,                                  0)
	TAGKEYS(                            XK_2,                                  1)
	TAGKEYS(                            XK_3,                                  2)
    TAGKEYS(                            XK_4,                                  3)
	TAGKEYS(                            XK_5,                                  4)
	TAGKEYS(                            XK_6,                                  5)
	TAGKEYS(                            XK_7,                                  6)
	TAGKEYS(                            XK_8,                                  7)
	TAGKEYS(                            XK_9,                                  8)  */
	{ ControlMask|ShiftMask,            XK_Delete,        spawn,               SHCMD("loginctl terminate-session $(loginctl session-status | awk '{print $1}' | head -n 1)") },
/*  { ControlMask|ShiftMask|Mod1Mask,   XK_Delete,        quit,                {0} }, */
    { MODKEY,                           XK_r,             quit,                {0} },
    { 0, XF86XK_MonBrightnessUp,        spawn,                                 SHCMD("brightness up") },
    { 0, XF86XK_MonBrightnessDown,      spawn,                                 SHCMD("brightness down") },
    { 0, XF86XK_AudioMute,              spawn,                                 SHCMD("amixer set Master toggle") },
    { 0, XF86XK_AudioLowerVolume,       spawn,                                 SHCMD("pactl -- set-sink-volume 0 -2%") },
    { 0, XF86XK_AudioRaiseVolume,       spawn,                                 SHCMD("pactl -- set-sink-volume 0 +2%") },
 /* { MODKEY,                           XK_p,             spawn,               SHCMD("albert toggle") },*/
    { MODKEY,                           XK_Tab,           shiftviewclients,    { .i = +1 } },
    { ControlMask|Mod1Mask,             XK_l,             shiftview,           { .i = +1 } },
    { ControlMask|Mod1Mask,             XK_h,             shiftview,           { .i = -1 } },
 /* { MODKEY,                           XK_i,             shiftviewclients,    { .i = -1 } }, */
    { ControlMask|Mod1Mask|ShiftMask,   XK_l,             shiftboth,           { .i = +1 } },
    { ControlMask|Mod1Mask|ShiftMask,   XK_h,             shiftboth,           { .i = -1 } },
 /* { MODKEY|ControlMask,               XK_h,             shiftswaptags,       { .i = -1 } },
    { MODKEY|ControlMask,               XK_l,             shiftswaptags,       { .i = +1 } }, */
 /* { MODKEY,                           XK_l,             spawn,               SHCMD(".sh/i3lkscreen") } */
};

/* button definitions */
/* click can be ClkTagBar, ClkLtSymbol, ClkStatusText, ClkWinTitle, ClkClientWin, or ClkRootWin */
static Button buttons[] = {
	/* click                event mask      button          function        argument */
	{ ClkLtSymbol,          0,              Button1,        setlayout,      {0} },
	{ ClkLtSymbol,          0,              Button3,        setlayout,      {.v = &layouts[2]} },
/*	{ ClkWinTitle,          0,              Button2,        zoom,           {0} }, */
	{ ClkStatusText,        0,              Button2,        spawn,          {.v = termcmd } },
	{ ClkClientWin,         MODKEY,         Button1,        movemouse,      {0} },
    { ClkClientWin,         MODKEY,         Button2,        togglefloating, {0} },
	{ ClkClientWin,         MODKEY,         Button3,        resizemouse,    {0} },
	{ ClkTagBar,            0,              Button1,        view,           {0} },
	{ ClkTagBar,            0,              Button3,        toggleview,     {0} },
	{ ClkTagBar,            MODKEY,         Button1,        tag,            {0} },
	{ ClkTagBar,            MODKEY,         Button3,        toggletag,      {0} },
};

