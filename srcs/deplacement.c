/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   deplacement.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: realves <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/03/22 21:16:58 by realves           #+#    #+#             */
/*   Updated: 2014/03/23 19:45:34 by realves          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/game.h"

void	gm_up(t_env *e)
{
	int	nb;

	nb = e->map.map[(e->y - 1) * e->map.w + e->x];
	if (e->img_tab[nb].solid == 0)
	{
		gm_gene_map(e, 0, 4);
		gm_draw_halfline(e, 1, 4);
		e->red = gm_init_img(e, "./img/red/red_down_2.xpm", 16, 32);
		gm_draw_img(&(e->screen), &(e->red), e->red_posx, e->red_posy);
		mlx_put_image_to_window(e->mlx_ptr, e->win_ptr, e->screen.ptr, 0, 0);
		usleep(e->speed);
		gm_gene_map(e, 0, 8);
		gm_draw_halfline(e, 1, 8);
		e->red = gm_init_img(e, "./img/red/red_down_1.xpm", 16, 32);
		gm_draw_img(&(e->screen), &(e->red), e->red_posx, e->red_posy);
		mlx_put_image_to_window(e->mlx_ptr, e->win_ptr, e->screen.ptr, 0, 0);
		usleep(e->speed);
		gm_gene_map(e, 0, 12);
		gm_draw_halfline(e, 1, 12);
		e->red = gm_init_img(e, "./img/red/red_down_3.xpm", 16, 32);
		gm_draw_img(&(e->screen), &(e->red), e->red_posx, e->red_posy);
		mlx_put_image_to_window(e->mlx_ptr, e->win_ptr, e->screen.ptr, 0, 0);
		e->red = gm_init_img(e, "./img/red/red_down_1.xpm", 16, 32);
		usleep(e->speed);
		e->y -= 1;
	}
}

void	gm_down(t_env *e)
{
	int	nb;

	nb = e->map.map[(e->y + 1) * e->map.w + e->x];
	if (e->img_tab[nb].solid == 0)
	{
		gm_gene_map(e, 0, -4);
		gm_draw_halfline(e, 3, 4);
		e->red = gm_init_img(e, "./img/red/red_up_2.xpm", 16, 32);
		gm_draw_img(&(e->screen), &(e->red), e->red_posx, e->red_posy);
		mlx_put_image_to_window(e->mlx_ptr, e->win_ptr, e->screen.ptr, 0, 0);
		usleep(e->speed);
		gm_gene_map(e, 0, -8);
		gm_draw_halfline(e, 3, 8);
		e->red = gm_init_img(e, "./img/red/red_up_1.xpm", 16, 32);
		gm_draw_img(&(e->screen), &(e->red), e->red_posx, e->red_posy);
		mlx_put_image_to_window(e->mlx_ptr, e->win_ptr, e->screen.ptr, 0, 0);
		usleep(e->speed);
		gm_gene_map(e, 0, -12);
		gm_draw_halfline(e, 3, 12);
		e->red = gm_init_img(e, "./img/red/red_up_3.xpm", 16, 32);
		gm_draw_img(&(e->screen), &(e->red), e->red_posx, e->red_posy);
		mlx_put_image_to_window(e->mlx_ptr, e->win_ptr, e->screen.ptr, 0, 0);
		e->red = gm_init_img(e, "./img/red/red_up_1.xpm", 16, 32);
		usleep(e->speed);
		e->y += 1;
	}
}

void	gm_left(t_env *e)
{
	int	nb;

	nb = e->map.map[e->y * e->map.w + (e->x - 1)];
	if (e->img_tab[nb].solid == 0)
	{
		gm_gene_map(e, 4, 0);
		gm_draw_halfline(e, 2, 4);
		e->red = gm_init_img(e, "./img/red/red_left_2.xpm", 16, 32);
		gm_draw_img(&(e->screen), &(e->red), e->red_posx, e->red_posy);
		mlx_put_image_to_window(e->mlx_ptr, e->win_ptr, e->screen.ptr, 0, 0);
		usleep(e->speed);
		gm_gene_map(e, 8, 0);
		gm_draw_halfline(e, 2, 8);
		e->red = gm_init_img(e, "./img/red/red_left_1.xpm", 16, 32);
		gm_draw_img(&(e->screen), &(e->red), e->red_posx, e->red_posy);
		mlx_put_image_to_window(e->mlx_ptr, e->win_ptr, e->screen.ptr, 0, 0);
		usleep(e->speed);
		gm_gene_map(e, 12, 0);
		gm_draw_halfline(e, 2, 12);
		e->red = gm_init_img(e, "./img/red/red_left_3.xpm", 16, 32);
		gm_draw_img(&(e->screen), &(e->red), e->red_posx, e->red_posy);
		mlx_put_image_to_window(e->mlx_ptr, e->win_ptr, e->screen.ptr, 0, 0);
		e->red = gm_init_img(e, "./img/red/red_left_1.xpm", 16, 32);
		usleep(e->speed);
		e->x -= 1;
	}
}

void	gm_right(t_env *e)
{
	int	nb;

	nb = e->map.map[e->y * e->map.w + (e->x + 1)];
	if (e->img_tab[nb].solid == 0)
	{
		gm_gene_map(e, -4, 0);
		gm_draw_halfline(e, 4, 4);
		e->red = gm_init_img(e, "./img/red/red_right_2.xpm", 16, 32);
		gm_draw_img(&(e->screen), &(e->red), e->red_posx, e->red_posy);
		mlx_put_image_to_window(e->mlx_ptr, e->win_ptr, e->screen.ptr, 0, 0);
		usleep(e->speed);
		gm_gene_map(e, -8, 0);
		gm_draw_halfline(e, 4, 8);
		e->red = gm_init_img(e, "./img/red/red_right_1.xpm", 16, 32);
		gm_draw_img(&(e->screen), &(e->red), e->red_posx, e->red_posy);
		mlx_put_image_to_window(e->mlx_ptr, e->win_ptr, e->screen.ptr, 0, 0);
		usleep(e->speed);
		gm_gene_map(e, -12, 0);
		gm_draw_halfline(e, 4, 12);
		e->red = gm_init_img(e, "./img/red/red_right_3.xpm", 16, 32);
		gm_draw_img(&(e->screen), &(e->red), e->red_posx, e->red_posy);
		mlx_put_image_to_window(e->mlx_ptr, e->win_ptr, e->screen.ptr, 0, 0);
		e->red = gm_init_img(e, "./img/red/red_right_1.xpm", 16, 32);
		usleep(e->speed);
		e->x += 1;
	}
}
