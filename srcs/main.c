/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: realves <realves@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/02/26 16:32:17 by realves           #+#    #+#             */
/*   Updated: 2014/03/01 18:51:56 by realves          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/game.h"

static int	key_press_event(int keycode, t_env *e)
{
	if (keycode == UP)
	{
		e->up_arrow = 1;
		e->down_arrow = 0;
		e->left_arrow = 0;
		e->right_arrow = 0;
	}
	if (keycode == DOWN)
	{
		e->down_arrow = 1;
		e->up_arrow = 0;
		e->left_arrow = 0;
		e->right_arrow = 0;
	}
	if (keycode == LEFT)
	{
		e->left_arrow = 1;
		e->right_arrow = 0;
		e->up_arrow = 0;
		e->down_arrow = 0;
	}
	if (keycode == RIGHT)
	{
		e->right_arrow = 1;
		e->left_arrow = 0;
		e->up_arrow = 0;
		e->down_arrow = 0;
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

	if (e->up_arrow == 1)
	{
		nb = e->map.map[(e->y - 1) * e->map.w + e->x];
		if (e->img_tab[nb].solid == 0)
			e->y -= 1;
		if (e->sens != 2)
		{
			e->sens = 2;
			e->frame = 0;
		}
		if (e->frame == 0 || e->frame == 2)
			e->red = gm_init_img(e, "./img/red/red_down_1.xpm", 16, 32);
		else if (e->frame == 1)
			e->red = gm_init_img(e, "./img/red/red_down_2.xpm", 16, 32);
		else if (e->frame == 3)
			e->red = gm_init_img(e, "./img/red/red_down_3.xpm", 16, 32);
		if (e->frame >= 4)
			e->frame = 0;
		else
			e->frame = e->frame + 1;

	}
	if (e->down_arrow == 1)
	{
		nb = e->map.map[(e->y + 1) * e->map.w + e->x];
		if (e->img_tab[nb].solid == 0)
			e->y += 1;
		if (e->sens != 4)
		{
			e->sens = 4;
			e->frame = 0;
		}
		if (e->frame == 0 || e->frame == 2)
			e->red = gm_init_img(e, "./img/red/red_up_1.xpm", 16, 32);
		else if (e->frame == 1)
			e->red = gm_init_img(e, "./img/red/red_up_2.xpm", 16, 32);
		else if (e->frame == 3)
			e->red = gm_init_img(e, "./img/red/red_up_3.xpm", 16, 32);
		if (e->frame >= 4)
			e->frame = 0;
		else
			e->frame = e->frame + 1;
	}
	if (e->left_arrow == 1)
	{
		nb = e->map.map[e->y * e->map.w + (e->x - 1)];
		if (e->img_tab[nb].solid == 0)
			e->x -= 1;
		if (e->sens != 3)
		{
			e->sens = 3;
			e->frame = 0;
		}
		if (e->frame == 0)
			e->red = gm_init_img(e, "./img/red/red_left_1.xpm", 16, 32);
		else if (e->frame == 1)
			e->red = gm_init_img(e, "./img/red/red_left_2.xpm", 16, 32);
		else if (e->frame == 3)
			e->red = gm_init_img(e, "./img/red/red_left_3.xpm", 16, 32);
		if (e->frame >= 4)
			e->frame = 0;
		else
			e->frame = e->frame + 1;
	}
	if (e->right_arrow == 1)
	{
		nb = e->map.map[e->y * e->map.w + (e->x + 1)];
		if (e->img_tab[nb].solid == 0)
			e->x += 1;
		if (e->sens != 1)
		{
			e->sens = 1;
			e->frame = 0;
		}
		if (e->frame == 0 || e->frame == 2)
			e->red = gm_init_img(e, "./img/red/red_right_1.xpm", 16, 32);
		else if (e->frame == 1)
			e->red = gm_init_img(e, "./img/red/red_right_2.xpm", 16, 32);
		else if (e->frame == 3)
			e->red = gm_init_img(e, "./img/red/red_right_3.xpm", 16, 32);
		if (e->frame >= 4)
			e->frame = 0;
		else
			e->frame = e->frame + 1;
	}
	gm_gene_map(e);
	gm_draw_img(&(e->screen), &(e->red), 161, 119);
	mlx_put_image_to_window(e->mlx_ptr, e->win_ptr, e->screen.ptr, 0, 0);
	usleep(e->speed);
	return (0);
}

int		main()
{
	t_env	e;

	e.x = 10;
	e.y = 10;
	e.frame = 0;
	e.sens = 0;
	e.speed = 5000;
	gm_init_mlx(&e);
	e.red = gm_init_img(&e, "./img/red/red_up_1.xpm", 16, 32);
	e.img_tab[0] = gm_init_img(&e, "./img/black.xpm", 16, 16);
	gm_init_map(&e, "./map/map_1.map");
	mlx_hook(e.win_ptr, 2, 1, &key_press_event, &e);
	mlx_hook(e.win_ptr, 3, 2, &key_release_event, &e);
	mlx_loop_hook(e.mlx_ptr, loop_hook, &e);
	mlx_loop(e.mlx_ptr);
	return (0);
}
