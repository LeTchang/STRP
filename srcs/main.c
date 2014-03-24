/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: realves <realves@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/02/26 16:32:17 by realves           #+#    #+#             */
/*   Updated: 2014/03/24 20:35:06 by realves          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/game.h"

static int	key_press_event(int keycode, t_env *e)
{
	if (keycode == UP)
	{
		gm_putallarrow(e, 0);
		e->up_arrow = 1;
	}
	if (keycode == DOWN)
	{
		gm_putallarrow(e, 0);
		e->down_arrow = 1;
	}
	if (keycode == LEFT)
	{
		gm_putallarrow(e, 0);
		e->left_arrow = 1;
	}
	if (keycode == RIGHT)
	{
		gm_putallarrow(e, 0);
		e->right_arrow = 1;
	}
	if (keycode == ESCAPE)
		exit(0);
	if (keycode == SPACE)
		e->speed = 5000;
	return (0);
}

static int	key_release_event(int keycode, t_env *e)
{
	if (keycode == UP)
		e->up_arrow = 0;
	if (keycode == DOWN)
		e->down_arrow = 0;
	if (keycode == LEFT)
		e->left_arrow = 0;
	if (keycode == RIGHT)
		e->right_arrow = 0;
	if (keycode == SPACE)
		e->speed = 100000;
	return (0);
}

static int		loop_hook(t_env *e)
{
	int			nb;

	nb = e->map.map[e->y * e->map.w + e->x];
	if (e->img_tab[nb].teleport != NULL)
		gm_trans(e, nb);
	if (e->up_arrow == 1)
		gm_up(e);
	if (e->down_arrow == 1)
		gm_down(e);
	if (e->left_arrow == 1)
		gm_left(e);
	if (e->right_arrow == 1)
		gm_right(e);
	gm_gene_map(e, 0, 0);
	gm_draw_img(&(e->screen), &(e->red), e->red_posx, e->red_posy);
	mlx_put_image_to_window(e->mlx_ptr, e->win_ptr, e->screen.ptr, 0, 0);
	usleep(e->speed);
	return (0);
}

int		main()
{
	t_env	e;

	e.red_posx = (WIDTH / RATIO) / 2 + 1;
	e.red_posy = (HEIGHT / RATIO) / 2 - 8;
	e.x = 10;
	e.y = 10;
	e.sens = 0;
	e.speed = 5000;
	gm_init_mlx(&e);
	e.red = gm_init_img(&e, "./img/red/red_up_1.xpm", 16, 32);
	gm_init_map(&e, "./map/map_1.map");
	mlx_hook(e.win_ptr, 2, 1, &key_press_event, &e);
	mlx_hook(e.win_ptr, 3, 2, &key_release_event, &e);
	mlx_loop_hook(e.mlx_ptr, loop_hook, &e);
	mlx_loop(e.mlx_ptr);
	return (0);
}
