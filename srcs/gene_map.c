/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   gene_map.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: realves <realves@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/02/28 14:41:26 by realves           #+#    #+#             */
/*   Updated: 2014/03/22 21:25:36 by realves          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/game.h"

void		gm_gene_map(t_env *e, int pos_x, int pos_y)
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
				gm_draw_img(&(e->screen), &(e->img_tab[n]), i * 16 + 1 + pos_x, j * 16 + 1 + pos_y);
				n = e->map.map[y * e->map.w + x];
				gm_draw_img(&(e->screen), &(e->img_tab[n]), i * 16 + 1 + pos_x, j * 16 + 1 + pos_y);
			}
			else
				gm_draw_img(&(e->screen), &(e->img_tab[0]), i * 16 + 1 + pos_x, j * 16 + 1 + pos_y);
			y++;
			j++;
		}
		x++;
		i++;
	}
}
