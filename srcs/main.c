/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: realves <realves@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/02/26 16:32:17 by realves           #+#    #+#             */
/*   Updated: 2014/04/17 21:03:45 by realves          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/game.h"

static int	key_release_event(int keycode, t_env *e);
static int	key_press_event(int keycode, t_env *e);

static int	mouse_event(int button, int x, int y, t_env *e)
{
	if (e->menu.current_menu == 1)
	{
		printf("Button : %d\n%d , %d\n\n", button, x, y);
	}
	return (0);
}

static int	key_press_event(int keycode, t_env *e)
{
	if (e->menu.current_menu == 1)
	{
		if (keycode == UP)
		{
			if (e->menu.current_cat > 1)
				e->menu.current_cat -= 1;
			else
				e->menu.current_cat = 4;
		}
		if (keycode == DOWN)
		{
			if (e->menu.current_cat < 4)
				e->menu.current_cat += 1;
			else
				e->menu.current_cat = 1;
		}
		if (keycode == ENTER)
		{
			e->menu.current_menu = 0;
			if (e->menu.current_cat == 1)
			{
				e->win_width = 320;
				e->win_height = 256;
				e->win_ratio = 1;
			}
			else if (e->menu.current_cat == 2)
			{
				e->win_width = 640;
				e->win_height = 512;
				e->win_ratio = 2;
			}
			else if (e->menu.current_cat == 3)
			{
				e->win_width = 960;
				e->win_height = 768;
				e->win_ratio = 3;
			}
			else
			{
				e->win_width = 1280;
				e->win_height = 1024;
				e->win_ratio = 4;
			}
			e->red_posx = (e->win_width / e->win_ratio) / 2 + 1;
			e->red_posy = (e->win_height / e->win_ratio) / 2 - 14;
			mlx_destroy_window(e->mlx_ptr, e->win_ptr);
			e->win_ptr = mlx_new_window(e->mlx_ptr, e->win_width, e->win_height, FEN_NAME);
			gm_init_screen(e->mlx_ptr, e->win_width, e->win_height, &(e->screen));
			mlx_hook(e->win_ptr, 2, 1, key_press_event, e);
			mlx_hook(e->win_ptr, 3, 2, key_release_event, e);
			e->menu.current_menu = 0;
		}
	}
	else
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
		if (keycode == SPACE)
			e->sprint = 1;
	}
	if (keycode == ESCAPE)
		gm_exit(e, 0);
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
		e->sprint = 0;
	return (0);
}

static int		loop_hook(t_env *e)
{
	int			nb;


	if (e->menu.current_menu == 1)
	{
		gm_draw_img(e, &(e->screen), &(e->tmp), 0, 0);
		if (e->menu.current_cat == 1)
			gm_draw_img(e, &(e->screen), &(e->tmp2), 135, 127);
		else if (e->menu.current_cat == 2)
			gm_draw_img(e, &(e->screen), &(e->tmp2), 135, 182);
		else if (e->menu.current_cat == 3)
			gm_draw_img(e, &(e->screen), &(e->tmp2), 135, 240);
		else
			gm_draw_img(e, &(e->screen), &(e->tmp2), 135, 295);
		mlx_put_image_to_window(e->mlx_ptr, e->win_ptr, e->screen.ptr, 0, 0);
		usleep(50000);
	}
	else
	{
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
		gm_gene_map(e, 0, 0, 0);
		gm_draw_img(e, &(e->screen), &(e->red), e->red_posx, e->red_posy);
		gm_gene_map(e, 0, 0, 1);
		mlx_put_image_to_window(e->mlx_ptr, e->win_ptr, e->screen.ptr, 0, 0);
		gm_anim_timer(e);
		if (e->time.time + 33.3 > get_time_ms())
			usleep(e->time.time + 33.3 - get_time_ms());
		e->time.time = get_time_ms();
	}
	return (0);
}

int		main()
{
	t_env	e;

	e.menu.current_menu = 1;
	e.menu.current_cat = 4;
	e.win_width = 798;
	e.win_height = 798;
	e.win_ratio = 2;
	e.red_posx = (e.win_width / e.win_ratio) / 2 + 1;
	e.red_posy = (e.win_height / e.win_ratio) / 2 - 14;
	gm_init_mlx(&e);
	e.tmp = gm_init_img(&e, "./img/title.xpm", 400, 400);
	e.tmp2 = gm_init_img(&e, "./img/title_select.xpm", 130, 35);
	e.red = gm_init_img(&e, "./img/red/red_down_1.xpm", 16, 32);
	gm_init_map(&e, "./map/first.map");
	mlx_hook(e.win_ptr, 2, 1, &key_press_event, &e);
	mlx_hook(e.win_ptr, 3, 2, &key_release_event, &e);
	mlx_mouse_hook(e.win_ptr, &mouse_event, &e);
	mlx_loop_hook(e.mlx_ptr, loop_hook, &e);
	mlx_loop(e.mlx_ptr);
	return (0);
}
