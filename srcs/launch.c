
#include "rtv1.h"

void	ft_usage(void)
{
	ft_putstr("Usage: binary file [a valid map].\n");
	exit(0);
}

void	ft_destroy(t_mx *v)
{
	mlx_destroy_image(v->mptr, v->iptr);
	mlx_clear_window(v->mptr, v->wptr);
	mlx_destroy_window(v->mptr, v->wptr);
}

int		key_press(int keycode, void *p)
{
	t_mx	*v;

	v = (t_mx *)p;
	if (keycode == 53)
	{
		ft_destroy(v);
		exit(0);
	}
	return(0);
}

int		red_button(void *p)
{
	t_mx	*v;

	v = (t_mx *)p;
	ft_destroy(v);
	exit(0);
}

void setup(t_mx *v){
	v->mptr = mlx_init();
	v->wptr = mlx_new_window(v->mptr, WIN_W, WIN_H, "RTv1");
	v->iptr = mlx_new_image(v->mptr, WIN_W, WIN_H);
	v->rt = (int *)mlx_get_data_addr(v->iptr, &v->bpp, &v->size, &v->end);
	mlx_hook(v->wptr, 2, 0, key_press, v);
	mlx_hook(v->wptr, 17, 0, red_button, v);
}

void  display(t_mx *mx){
	//mlx_pixel_put(mx->mptr, mx->wptr, 100, 100, 0xFF00FF);
	mlx_put_image_to_window(mx->mptr, mx->wptr, mx->iptr, 0, 0);
	mlx_loop(mx->mptr);
}

void run(t_mx *mx){
	setup(mx);
	update(mx);
	display(mx);
}