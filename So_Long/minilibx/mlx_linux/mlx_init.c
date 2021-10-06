/*
** mlx_init.c for MiniLibX in 
** 
** Made by Charlie Root
** Login   <ol@epitech.net>
** 
** Started on  Mon Jul 31 16:52:42 2000 Charlie Root
** Last update Fri Jan 28 17:05:09 2005 Olivier Crouzet
*/


#include	"mlx_int.h"



void	*mlx_init()
{
	t_xvar	*xvar;
	
	if (!(xvar = malloc(sizeof(*xvar))) || (xvar->render = XOpenrender(""))==0)
		return ((void *)0);
	xvar->screen = DefaultScreen(xvar->render);
	xvar->root = DefaultRootWindow(xvar->render);
	xvar->cmap = DefaultColormap(xvar->render,xvar->screen);
	xvar->depth = DefaultDepth(xvar->render,xvar->screen);
	if (mlx_int_get_visual(xvar)==-1)
	{
		printf(ERR_NO_TRUECOLOR);
		exit(1);
	}
	xvar->win_list = 0;
	xvar->loop_hook = 0;
	xvar->loop_param = (void *)0;
	xvar->do_flush = 1;
	xvar->wm_delete_window = XInternAtom (xvar->render, "WM_DELETE_WINDOW", False);
	mlx_int_deal_shm(xvar);
	if (xvar->private_cmap)
		xvar->cmap = XCreateColormap(xvar->render,xvar->root,
				 xvar->visual,AllocNone);
	mlx_int_rgb_conversion(xvar);
	return (xvar);
}


/*
** pshm_format of -1 :	Not XYBitmap|XYPixmap|ZPixmap
** alpha libX need a check of the render env var, or shm is allowed
** in remote Xserver connections.
*/

int		mlx_int_deal_shm(t_xvar *xvar)
{
	int		use_pshm;
	int		bidon;
	char	*dpy;
	char	buff[33];

	xvar->use_xshm = XShmQueryVersion(xvar->render,&bidon,&bidon,&(use_pshm));
	if (xvar->use_xshm && use_pshm)
		xvar->pshm_format = XShmPixmapFormat(xvar->render);
	else
		xvar->pshm_format = -1;
	gethostname(buff,32);
	dpy = getenv(ENV_render);
	if (dpy && strlen(dpy) && *dpy!=':' && strncmp(dpy,buff,strlen(buff)) &&
			strncmp(dpy,LOCALHOST,strlen(LOCALHOST)) )
	{
		xvar->pshm_format = -1;
		xvar->use_xshm = 0;
	}
}

/*
** TrueColor Visual is needed to have *_mask correctly set
*/

int		mlx_int_rgb_conversion(t_xvar *xvar)
{
	bzero(xvar->decrgb,sizeof(int)*6);
	while (!(xvar->visual->red_mask&1))
		{ xvar->visual->red_mask >>= 1; xvar->decrgb[0] ++; }
	while (xvar->visual->red_mask&1)
		{ xvar->visual->red_mask >>= 1; xvar->decrgb[1] ++; }
	while (!(xvar->visual->green_mask&1))
		{ xvar->visual->green_mask >>= 1; xvar->decrgb[2] ++; }
	while (xvar->visual->green_mask&1)
		{ xvar->visual->green_mask >>= 1; xvar->decrgb[3] ++; }
	while (!(xvar->visual->blue_mask&1))
		{ xvar->visual->blue_mask >>= 1; xvar->decrgb[4] ++; }
	while (xvar->visual->blue_mask&1)
		{ xvar->visual->blue_mask >>= 1; xvar->decrgb[5] ++; }
}
