/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   deplacement.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: realves <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/03/22 21:16:58 by realves           #+#    #+#             */
/*   Updated: 2014/04/05 19:18:12 by realves          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/game.h"

static void	walk(t_env *e, char *text, int x, int y, int sens, int px)
{
	gm_gene_map(e, x, y, 0);
	gm_draw_halfline(e, sens, px);
	if (e->red.ptr != NULL)
		mlx_destroy_image(e->mlx_ptr, e->red.ptr);
	e->red = gm_init_img(e, text, 16, 32);
	gm_draw_img(e, &(e->screen), &(e->red), e->red_posx, e->red_posy);
	gm_gene_map(e, x, y, 1);
	mlx_put_image_to_window(e->mlx_ptr, e->win_ptr, e->screen.ptr, 0, 0);
}

static void	run(t_env *e, char *text, int x, int y, int sens, int px, int redx, int redy)
{
	gm_gene_map(e, x, y, 0);
	gm_draw_halfline(e, sens, px);
	if (e->red.ptr != NULL)
		mlx_destroy_image(e->mlx_ptr, e->red.ptr);
	e->red = gm_init_img(e, text, 16, 32);
	gm_draw_img(e, &(e->screen), &(e->red), redx, redy);
	gm_gene_map(e, x, y, 1);
	mlx_put_image_to_window(e->mlx_ptr, e->win_ptr, e->screen.ptr, 0, 0);
	usleep(10000);
}

void		gm_up(t_env *e)
{
	int	nb;
	int	nb2;

	if (e->x >= 0 && e->y - 1 >= 0 && e->x < e->map.w && e->y - 1 < e->map.h
			&& (e->direction == 1 || e->sprint == 1 || e->sprint == 2))
	{
		nb = e->map.map[(e->y - 1) * e->map.w + e->x];
		nb2 = e->map.back[(e->y - 1) * e->map.w + e->x];
		if (e->img_tab[nb].solid == 0 && e->img_tab[nb2].solid == 0 &&
				(e->img_tab[nb].sens == 0 || e->img_tab[nb].sens == 1 ||
				 e->img_tab[nb].sens == 5 || e->img_tab[nb].sens == 6 ||
				 e->img_tab[nb].sens == 7 || e->img_tab[nb].sens == 12 ||
				 e->img_tab[nb].sens == 13 || e->img_tab[nb].sens == 14))
		{
			if (e->sprint == 1)
			{
				run(e, "./img/red/red_up_run_2.xpm", 0, 4, 1, 4, e->red_posx, e->red_posy + 1);
				gm_anim_timer(e);
				run(e, "./img/red/red_up_run_2.xpm", 0, 8, 1, 8, e->red_posx, e->red_posy + 1);
				gm_anim_timer(e);
				run(e, "./img/red/red_up_run_1.xpm", 0, 12, 1, 12, e->red_posx, e->red_posy + 1);
				e->sprint = 2;
			}
			else if (e->sprint == 2)
			{
				run(e, "./img/red/red_up_run_3.xpm", 0, 4, 1, 4, e->red_posx, e->red_posy + 1);
				gm_anim_timer(e);
				run(e, "./img/red/red_up_run_3.xpm", 0, 8, 1, 8, e->red_posx, e->red_posy + 1);
				gm_anim_timer(e);
				run(e, "./img/red/red_up_run_1.xpm", 0, 12, 1, 12, e->red_posx, e->red_posy + 1);
				e->sprint = 1;
			}
			else
			{
				walk(e, "./img/red/red_up_2.xpm", 0, 1, 1, 1);
				walk(e, "./img/red/red_up_2.xpm", 0, 2, 1, 2);
				gm_anim_timer(e);
				walk(e, "./img/red/red_up_2.xpm", 0, 3, 1, 3);
				walk(e, "./img/red/red_up_2.xpm", 0, 4, 1, 4);
				gm_anim_timer(e);
				walk(e, "./img/red/red_up_1.xpm", 0, 5, 1, 5);
				walk(e, "./img/red/red_up_1.xpm", 0, 6, 1, 6);
				gm_anim_timer(e);
				walk(e, "./img/red/red_up_1.xpm", 0, 7, 1, 7);
				walk(e, "./img/red/red_up_1.xpm", 0, 8, 1, 8);
				gm_anim_timer(e);
				walk(e, "./img/red/red_up_3.xpm", 0, 9, 1, 9);
				walk(e, "./img/red/red_up_3.xpm", 0, 10, 1, 10);
				gm_anim_timer(e);
				walk(e, "./img/red/red_up_3.xpm", 0, 11, 1, 11);
				walk(e, "./img/red/red_up_3.xpm", 0, 12, 1, 12);
				gm_anim_timer(e);
				walk(e, "./img/red/red_up_3.xpm", 0, 13, 1, 13);
				walk(e, "./img/red/red_up_1.xpm", 0, 14, 1, 14);
				gm_anim_timer(e);
				walk(e, "./img/red/red_up_1.xpm", 0, 15, 1, 15);
			}
			e->y -= 1;
		}
	}
	if (e->direction != 1 && e->sprint != 1 && e->sprint != 2)
		usleep(25000);
	e->direction = 1;
	if (e->red.ptr != NULL)
		mlx_destroy_image(e->mlx_ptr, e->red.ptr);
	e->red = gm_init_img(e, "./img/red/red_up_1.xpm", 16, 32);
}

void	gm_down(t_env *e)
{
	int	nb;
	int	nb2;

	if (e->x >= 0 && e->y + 1 >= 0 && e->x < e->map.w && e->y + 1 < e->map.h
			&& (e->direction == 3 || e->sprint == 1 || e->sprint == 2))
	{
		nb = e->map.map[(e->y + 1) * e->map.w + e->x];
		nb2 = e->map.back[(e->y + 1) * e->map.w + e->x];
		if (e->img_tab[nb].solid == 0 && e->img_tab[nb2].solid == 0 &&
				(e->img_tab[nb].sens == 0 || e->img_tab[nb].sens == 3 ||
				 e->img_tab[nb].sens == 6 || e->img_tab[nb].sens == 8 ||
				 e->img_tab[nb].sens == 10 || e->img_tab[nb].sens == 11 ||
				 e->img_tab[nb].sens == 12 || e->img_tab[nb].sens == 14))
		{
			if (e->sprint == 1)
			{
				run(e, "./img/red/red_down_run_2.xpm", 0, -4, 3, 4, e->red_posx, e->red_posy);
				gm_anim_timer(e);
				run(e, "./img/red/red_down_run_2.xpm", 0, -8, 3, 8, e->red_posx, e->red_posy);
				gm_anim_timer(e);
				run(e, "./img/red/red_down_run_1.xpm", 0, -12, 3, 12, e->red_posx, e->red_posy + 1);
				e->sprint = 2;
			}
			else if (e->sprint == 2)
			{
				run(e, "./img/red/red_down_run_3.xpm", 0, -4, 3, 4, e->red_posx, e->red_posy);
				gm_anim_timer(e);
				run(e, "./img/red/red_down_run_3.xpm", 0, -8, 3, 8, e->red_posx, e->red_posy);
				gm_anim_timer(e);
				run(e, "./img/red/red_down_run_1.xpm", 0, -12, 3, 12, e->red_posx, e->red_posy + 1);
				e->sprint = 1;
			}
			else
			{
				walk(e, "./img/red/red_down_2.xpm", 0, -1, 3, 1);
				walk(e, "./img/red/red_down_2.xpm", 0, -2, 3, 2);
				gm_anim_timer(e);
				walk(e, "./img/red/red_down_2.xpm", 0, -3, 3, 3);
				walk(e, "./img/red/red_down_2.xpm", 0, -4, 3, 4);
				gm_anim_timer(e);
				walk(e, "./img/red/red_down_1.xpm", 0, -5, 3, 5);
				walk(e, "./img/red/red_down_1.xpm", 0, -6, 3, 6);
				gm_anim_timer(e);
				walk(e, "./img/red/red_down_1.xpm", 0, -7, 3, 7);
				walk(e, "./img/red/red_down_1.xpm", 0, -8, 3, 8);
				gm_anim_timer(e);
				walk(e, "./img/red/red_down_3.xpm", 0, -9, 3, 9);
				walk(e, "./img/red/red_down_3.xpm", 0, -10, 3, 10);
				gm_anim_timer(e);
				walk(e, "./img/red/red_down_3.xpm", 0, -11, 3, 11);
				walk(e, "./img/red/red_down_3.xpm", 0, -12, 3, 12);
				gm_anim_timer(e);
				walk(e, "./img/red/red_down_3.xpm", 0, -13, 3, 13);
				walk(e, "./img/red/red_down_1.xpm", 0, -14, 3, 14);
				gm_anim_timer(e);
				walk(e, "./img/red/red_down_1.xpm", 0, -15, 3, 15);
			}
			e->y += 1;
		}
	}
	if (e->direction != 3 && e->sprint != 1 && e->sprint != 2)
		usleep(25000);
	e->direction = 3;
	if (e->red.ptr != NULL)
		mlx_destroy_image(e->mlx_ptr, e->red.ptr);
	e->red = gm_init_img(e, "./img/red/red_down_1.xpm", 16, 32);
}

void	gm_left(t_env *e)
{
	int	nb;
	int	nb2;

	if (e->x - 1 >= 0 && e->y >= 0 && e->x - 1 < e->map.w && e->y < e->map.h
			&& (e->direction == 2 || e->sprint == 1 || e->sprint == 2))
	{
		nb = e->map.map[e->y * e->map.w + (e->x - 1)];
		nb2 = e->map.back[e->y * e->map.w + (e->x - 1)];
		if (e->img_tab[nb].solid == 0 && e->img_tab[nb2].solid == 0 &&
				(e->img_tab[nb].sens == 0 || e->img_tab[nb].sens == 2 ||
				 e->img_tab[nb].sens == 5 || e->img_tab[nb].sens == 8 ||
				 e->img_tab[nb].sens == 9 || e->img_tab[nb].sens == 11 ||
				 e->img_tab[nb].sens == 13 || e->img_tab[nb].sens == 14))
		{
			if (e->sprint == 1)
			{
				run(e, "./img/red/red_left_run_2.xpm", 4, 0, 2, 4, e->red_posx, e->red_posy);
				gm_anim_timer(e);
				run(e, "./img/red/red_left_run_2.xpm", 8, 0, 2, 8, e->red_posx, e->red_posy);
				gm_anim_timer(e);
				run(e, "./img/red/red_left_run_2.xpm", 12, 0, 2, 12, e->red_posx, e->red_posy);
				e->sprint = 2;
			}
			else if (e->sprint == 2)
			{
				run(e, "./img/red/red_left_run_3.xpm", 4, 0, 2, 4, e->red_posx, e->red_posy);
				gm_anim_timer(e);
				run(e, "./img/red/red_left_run_3.xpm", 8, 0, 2, 8, e->red_posx, e->red_posy);
				gm_anim_timer(e);
				run(e, "./img/red/red_left_run_3.xpm", 12, 0, 2, 12, e->red_posx, e->red_posy);
				e->sprint = 1;
			}
			else
			{
				walk(e, "./img/red/red_left_2.xpm", 1, 0, 2, 1);
				walk(e, "./img/red/red_left_2.xpm", 2, 0, 2, 2);
				gm_anim_timer(e);
				walk(e, "./img/red/red_left_2.xpm", 3, 0, 2, 3);
				walk(e, "./img/red/red_left_2.xpm", 4, 0, 2, 4);
				gm_anim_timer(e);
				walk(e, "./img/red/red_left_1.xpm", 5, 0, 2, 5);
				walk(e, "./img/red/red_left_1.xpm", 6, 0, 2, 6);
				gm_anim_timer(e);
				walk(e, "./img/red/red_left_1.xpm", 7, 0, 2, 7);
				walk(e, "./img/red/red_left_1.xpm", 8, 0, 2, 8);
				gm_anim_timer(e);
				walk(e, "./img/red/red_left_3.xpm", 9, 0, 2, 9);
				walk(e, "./img/red/red_left_3.xpm", 10, 0, 2, 10);
				gm_anim_timer(e);
				walk(e, "./img/red/red_left_3.xpm", 11, 0, 2, 11);
				walk(e, "./img/red/red_left_3.xpm", 12, 0, 2, 12);
				gm_anim_timer(e);
				walk(e, "./img/red/red_left_3.xpm", 13, 0, 2, 13);
				walk(e, "./img/red/red_left_1.xpm", 14, 0, 2, 14);
				gm_anim_timer(e);
				walk(e, "./img/red/red_left_1.xpm", 15, 0, 2, 15);
			}
			e->x -= 1;
		}
	}
	if (e->direction != 2 && e->sprint != 1 && e->sprint != 2)
		usleep(25000);
	e->direction = 2;
	if (e->red.ptr != NULL)
		mlx_destroy_image(e->mlx_ptr, e->red.ptr);
	e->red = gm_init_img(e, "./img/red/red_left_1.xpm", 16, 32);
}

void	gm_right(t_env *e)
{
	int	nb;
	int	nb2;

	if (e->x + 1 >= 0 && e->y >= 0 && e->x + 1 < e->map.w && e->y < e->map.h
			&& (e->direction == 4 || e->sprint == 1 || e->sprint == 2))
	{
		nb = e->map.map[e->y * e->map.w + (e->x + 1)];
		nb2 = e->map.back[e->y * e->map.w + (e->x + 1)];
		if (e->img_tab[nb].solid == 0 && e->img_tab[nb2].solid == 0 &&
				(e->img_tab[nb].sens == 0 || e->img_tab[nb].sens == 4 ||
				 e->img_tab[nb].sens == 7 || e->img_tab[nb].sens == 9 ||
				 e->img_tab[nb].sens == 10 || e->img_tab[nb].sens == 11 ||
				 e->img_tab[nb].sens == 12 || e->img_tab[nb].sens == 13))
		{
			if (e->sprint == 1)
			{
				run(e, "./img/red/red_right_run_2.xpm", -4, 0, 4, 4, e->red_posx, e->red_posy);
				gm_anim_timer(e);
				run(e, "./img/red/red_right_run_2.xpm", -8, 0, 4, 8, e->red_posx, e->red_posy);
				gm_anim_timer(e);
				run(e, "./img/red/red_right_run_2.xpm", -12, 0, 4, 12, e->red_posx, e->red_posy);
				e->sprint = 2;
			}
			else if (e->sprint == 2)
			{
				run(e, "./img/red/red_right_run_3.xpm", -4, 0, 4, 4, e->red_posx, e->red_posy);
				gm_anim_timer(e);
				run(e, "./img/red/red_right_run_3.xpm", -8, 0, 4, 8, e->red_posx, e->red_posy);
				gm_anim_timer(e);
				run(e, "./img/red/red_right_run_3.xpm", -12, 0, 4, 12, e->red_posx, e->red_posy);
				e->sprint = 1;
			}
			else
			{
				walk(e, "./img/red/red_right_2.xpm", -1, 0, 4, 1);
				walk(e, "./img/red/red_right_2.xpm", -2, 0, 4, 2);
				gm_anim_timer(e);
				walk(e, "./img/red/red_right_2.xpm", -3, 0, 4, 3);
				walk(e, "./img/red/red_right_2.xpm", -4, 0, 4, 4);
				gm_anim_timer(e);
				walk(e, "./img/red/red_right_1.xpm", -5, 0, 4, 5);
				walk(e, "./img/red/red_right_1.xpm", -6, 0, 4, 6);
				gm_anim_timer(e);
				walk(e, "./img/red/red_right_1.xpm", -7, 0, 4, 7);
				walk(e, "./img/red/red_right_1.xpm", -8, 0, 4, 8);
				gm_anim_timer(e);
				walk(e, "./img/red/red_right_3.xpm", -9, 0, 4, 9);
				walk(e, "./img/red/red_right_3.xpm", -10, 0, 4, 10);
				gm_anim_timer(e);
				walk(e, "./img/red/red_right_3.xpm", -11, 0, 4, 11);
				walk(e, "./img/red/red_right_3.xpm", -12, 0, 4, 12);
				gm_anim_timer(e);
				walk(e, "./img/red/red_right_3.xpm", -13, 0, 4, 13);
				walk(e, "./img/red/red_right_1.xpm", -14, 0, 4, 14);
				gm_anim_timer(e);
				walk(e, "./img/red/red_right_1.xpm", -15, 0, 4, 15);
			}
			e->x += 1;
		}
	}
	if (e->direction != 4 && e->sprint != 1 && e->sprint != 2)
		usleep(25000);
	e->direction = 4;
	if (e->red.ptr != NULL)
		mlx_destroy_image(e->mlx_ptr, e->red.ptr);
	e->red = gm_init_img(e, "./img/red/red_right_1.xpm", 16, 32);
}
