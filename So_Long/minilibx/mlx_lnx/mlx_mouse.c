#include "mlx_int.h"

int		mlx_mouse_move(t_xvar *xvar, t_win_list *win, int x, int y)
{
	XWarpPointer(xvar->render, None, win->window, 0, 0, 0, 0, x, y);
	return (0);
}

int		mlx_mouse_hide(t_xvar *xvar, t_win_list *win)
{
	static char data[1] = {0};
	Cursor cursor;
	Pixmap blank;
	XColor dummy;

	blank = XCreateBitmapFromData(xvar->render, win->window, data, 1, 1);
	cursor = XCreatePixmapCursor(xvar->render, blank, blank, &dummy, &dummy, 0, 0);
	XDefineCursor(xvar->render, win->window, cursor);
	XFreePixmap(xvar->render, blank);
	XFreeCursor(xvar->render, cursor);
}

int		mlx_mouse_show(t_xvar *xvar, t_win_list *win)
{
	XUndefineCursor(xvar->render, win->window);
}
