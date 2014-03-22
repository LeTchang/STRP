/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_2.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: realves <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/03/22 20:30:04 by realves           #+#    #+#             */
/*   Updated: 2014/03/22 23:32:26 by realves          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/game.h"

void		gm_draw_halfline(t_env *e, int sens, int nb_px)
{
	int		tab[4];
	int		x;
	int		n;
	int		i;

	i = 0;
	tab[3] = nb_px;
	if (sens == 1)
	{
		x = e->x - 10;
		tab[2] = 3;
		while (x < e->x + 10)
		{
			tab[0] = i * 16 + 1;
			tab[1] = 1 - (16 - nb_px);
			if (x >= 0 && e->y - 9 >= 0 && x < e->map.w && e->y - 9 < e->map.h)
			{
				n = e->map.back[(e->y - 9) * e->map.w + x];
				gm_draw_half(&(e->screen), &(e->img_tab[n]), tab);
				n = e->map.map[(e->y - 9) * e->map.w + x];
				gm_draw_half(&(e->screen), &(e->img_tab[n]), tab);
			}
			else
				gm_draw_half(&(e->screen), &(e->img_tab[0]), tab);
			x++;
			i++;
		}
	}
	else if (sens == 2)
	{
		x = e->y - 8;
		tab[2] = 4;
		while (x < e->x + 8)
		{
			tab[0] = 1 - (16 - nb_px);
			tab[1] = i * 16 + 1;
			if (e->x - 11 >= 0 && x >= 0 && e->x - 11 < e->map.w && x < e->map.h)
			{
				n = e->map.back[x * e->map.w + (e->x - 11)];
				gm_draw_half(&(e->screen), &(e->img_tab[n]), tab);
				n = e->map.map[x * e->map.w + (e->x - 11)];
				gm_draw_half(&(e->screen), &(e->img_tab[n]), tab);
			}
			else
				gm_draw_half(&(e->screen), &(e->img_tab[0]), tab);
			x++;
			i++;
		}
	}
	else if (sens == 3)
	{
/*		x = e->x - 10;
		tab[2] = 1;
		while (x < e->x + 10)
		{
			tab[0] = i * 16 + 1;
			tab[1] = 1 - (16 - nb_px);
			if (x >= 0 && e->y + 9 >= 0 && x < e->map.w && e->y + 9 < e->map.h)
			{
				n = e->map.back[(e->y + 9) * e->map.w + x];
				gm_draw_half(&(e->screen), &(e->img_tab[n]), tab);
				n = e->map.map[(e->y + 9) * e->map.w + x];
				gm_draw_half(&(e->screen), &(e->img_tab[n]), tab);
			}
			else
				gm_draw_half(&(e->screen), &(e->img_tab[0]), tab);
			x++;
			i++;
		}
*/	}
	else
	{
		x = e->y - 8;
		tab[2] = 2;
		while (x < e->x + 8)
		{
			tab[0] = WIDTH - 16 - (16 - nb_px);
			tab[1] = i * 16 + 1;
			if (e->x + 11 >= 0 && x >= 0 && e->x + 11 < e->map.w && x < e->map.h)
			{
				n = e->map.back[x * e->map.w + (e->x + 11)];
				gm_draw_half(&(e->screen), &(e->img_tab[n]), tab);
				n = e->map.map[x * e->map.w + (e->x + 11)];
				gm_draw_half(&(e->screen), &(e->img_tab[n]), tab);
			}
			else
				gm_draw_half(&(e->screen), &(e->img_tab[0]), tab);
			x++;
			i++;
		}
	}
}
