/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   deplacement.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: realves <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/03/22 21:16:58 by realves           #+#    #+#             */
/*   Updated: 2014/03/22 23:28:30 by realves          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/game.h"

void	gm_up(t_env *e)
{
	gm_gene_map(e, 0, 4);
	gm_draw_halfline(e, 1, 4);
	mlx_put_image_to_window(e->mlx_ptr, e->win_ptr, e->screen.ptr, 0, 0);
	usleep(e->speed);
	gm_gene_map(e, 0, 8);
	gm_draw_halfline(e, 1, 8);
	mlx_put_image_to_window(e->mlx_ptr, e->win_ptr, e->screen.ptr, 0, 0);
	usleep(e->speed);
	gm_gene_map(e, 0, 12);
	gm_draw_halfline(e, 1, 12);
	mlx_put_image_to_window(e->mlx_ptr, e->win_ptr, e->screen.ptr, 0, 0);
	usleep(e->speed);
	e->y -= 1;
}

void	gm_down(t_env *e)
{
	gm_gene_map(e, 0, -4);
	gm_draw_halfline(e, 3, 4);
	mlx_put_image_to_window(e->mlx_ptr, e->win_ptr, e->screen.ptr, 0, 0);
	usleep(e->speed);
	gm_gene_map(e, 0, -8);
	gm_draw_halfline(e, 3, 8);
	mlx_put_image_to_window(e->mlx_ptr, e->win_ptr, e->screen.ptr, 0, 0);
	usleep(e->speed);
	gm_gene_map(e, 0, -12);
	gm_draw_halfline(e, 3, 12);
	mlx_put_image_to_window(e->mlx_ptr, e->win_ptr, e->screen.ptr, 0, 0);
	usleep(e->speed);
	e->y += 1;
}

void	gm_left(t_env *e)
{
	gm_gene_map(e, 4, 0);
	gm_draw_halfline(e, 2, 4);
	mlx_put_image_to_window(e->mlx_ptr, e->win_ptr, e->screen.ptr, 0, 0);
	usleep(e->speed);
	gm_gene_map(e, 8, 0);
	gm_draw_halfline(e, 2, 8);
	mlx_put_image_to_window(e->mlx_ptr, e->win_ptr, e->screen.ptr, 0, 0);
	usleep(e->speed);
	gm_gene_map(e, 12, 0);
	gm_draw_halfline(e, 2, 12);
	mlx_put_image_to_window(e->mlx_ptr, e->win_ptr, e->screen.ptr, 0, 0);
	usleep(e->speed);
	e->x -= 1;
}

void	gm_right(t_env *e)
{
	gm_gene_map(e, -4, 0);
	gm_draw_halfline(e, 4, 4);
	mlx_put_image_to_window(e->mlx_ptr, e->win_ptr, e->screen.ptr, 0, 0);
	usleep(e->speed);
	gm_gene_map(e, -8, 0);
	gm_draw_halfline(e, 4, 8);
	mlx_put_image_to_window(e->mlx_ptr, e->win_ptr, e->screen.ptr, 0, 0);
	usleep(e->speed);
	gm_gene_map(e, -12, 0);
	gm_draw_halfline(e, 4, 12);
	mlx_put_image_to_window(e->mlx_ptr, e->win_ptr, e->screen.ptr, 0, 0);
	usleep(e->speed);
	e->x += 1;
}
