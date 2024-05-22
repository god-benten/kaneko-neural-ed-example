#include <X11/Xlib.h>
#include <X11/Xutil.h>
#include <X11/cursorfont.h>

extern Display *d;
extern Window w;
extern GC gc, gc2;
extern XEvent e;
extern unsigned long black, white;

extern void init();
extern void line(int x0, int y0, int x1, int y1);
extern void line2(int x0, int y0, int x1, int y1);
extern void pointset(int x, int y);
extern void pointreset(int x, int y);
extern void xpause();
extern void flush();
extern void box(int, int, int, int);

