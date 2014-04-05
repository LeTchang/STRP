/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   timer.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: realves <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/04/05 18:39:44 by realves           #+#    #+#             */
/*   Updated: 2014/04/05 19:46:53 by realves          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/game.h"

static void	sub_timer(t_env *e, t_anim *tmp)
{
	if (get_time_ms() - e->time.time_frame >= tmp->tick && 
			tmp->check != e->time.check)
	{
		if (e->img_tab[tmp->nb_img].ptr != NULL)
			mlx_destroy_image(e->mlx_ptr, e->img_tab[tmp->nb_img].ptr);
		gm_init_screen(e->mlx_ptr, 16, 16, &(e->img_tab[tmp->nb_img]));
		gm_draw_texture(e, &(e->tileset[tmp->nb_tileset]),
				&(e->img_tab[tmp->nb_img]), tmp->x, tmp->y);
		tmp->check = e->time.check;
	}
}

void		gm_anim_timer(t_env *e)
{
	t_anim	*tmp;

	tmp = e->map.fanim;
	if (tmp != NULL)
	{
		while (tmp->next != NULL)
		{
			sub_timer(e, tmp);
			tmp = tmp->next;
		}
		sub_timer(e, tmp);
	}
	if (get_time_ms() - e->time.time_frame >= 4000)
	{
		if (e->time.check == 0)
			e->time.check = 1;
		else
			e->time.check = 0;
		e->time.time_frame = get_time_ms();
	}
}
