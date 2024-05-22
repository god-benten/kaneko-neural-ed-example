#include <unistd.h>
#include "graphic.h"
  
Display *d;
Window w;
GC gc, gc2;
XEvent e;
unsigned long black, white;

void init()
{
  d = XOpenDisplay ("");
  black = BlackPixel(d, DefaultScreen(d));
  white = WhitePixel(d, DefaultScreen(d));
  w = XCreateSimpleWindow (d, RootWindow (d,0), 500, 500, 768, 300, 2, black, white);
  XSelectInput (d, w, KeyPressMask | KeyReleaseMask);
  XMapWindow (d,w);
  gc = XCreateGC (d,w,0,0);
  XSetForeground(d, gc, black);
  XSetBackground(d, gc, white);
  XSetLineAttributes(d,gc,1,LineSolid,CapRound,JoinRound);
  gc2 = XCreateGC (d,w,0,0);
  XSetForeground(d, gc2, white);
  XSetBackground(d, gc2, white);
  XSetLineAttributes(d,gc2,1,LineSolid,CapRound,JoinRound);
  XFlush(d);
  sleep(1);
}

void box(int x0, int y0, int x1, int y1)
{
  XDrawRectangle(d, w, gc, x0, y0, x1 - x0, y1 - y0);
}

void line(int x0, int y0, int x1, int y1)
{
  XDrawLine(d, w, gc, x0,y0,x1,y1);
}

void line2(int x0, int y0, int x1, int y1)
{
  XDrawLine(d, w, gc2, x0,y0,x1,y1);
}

void pointset(int x, int y)
{
  XDrawPoint(d,w,gc,x,y);
}

void pointreset(int x, int y)
{
  XDrawPoint(d,w,gc2,x,y);
}

void xpause()
{
  XNextEvent(d,&e);
}

void flush()
{
  XFlush(d);
}






