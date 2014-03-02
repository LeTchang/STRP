/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   gene_map.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: realves <realves@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/02/28 14:41:26 by realves           #+#    #+#             */
/*   Updated: 2014/03/02 18:59:31 by realves          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/game.h"

static void gene_back(t_env *e)
{
	int		x;
	int		y;
	int		i;
	int		j;
	int		n;

	i = 0;
	x = e->x - 10;
	while (x < e->x + 10)
	{
		y = e->y - 8;
		j = 0;
		while (y < e->y + 8)
		{
			if (x >= 0 && y >= 0 && x < e->map.w && y < e->map.h)
			{
				n = e->map.back[y * e->map.w + x];
				gm_draw_img(&(e->screen), &(e->img_tab[n]), i * 16 + 1, j * 16 + 1);
			}
			else
				gm_draw_img(&(e->screen), &(e->img_tab[0]), i * 16 + 1, j * 16 + 1);
			y++;
			j++;
		}
		x++;
		i++;
	}
}

void		gm_gene_map(t_env *e)
{
	int		x;
	int		y;
	int		i;
	int		j;
	int		n;

	gene_back(e);
	i = 0;
	x = e->x - 10;
	while (x < e->x + 10)
	{
		y = e->y - 8;
		j = 0;
		while (y < e->y + 8)
		{
			if (x >= 0 && y >= 0 && x < e->map.w && y < e->map.h)
			{
				n = e->map.map[y * e->map.w + x];
				gm_draw_img(&(e->screen), &(e->img_tab[n]), i * 16 + 1, j * 16 + 1);
			}
			else
				gm_draw_img(&(e->screen), &(e->img_tab[0]), i * 16 + 1, j * 16 + 1);
			y++;
			j++;
		}
		x++;
		i++;
	}
}
