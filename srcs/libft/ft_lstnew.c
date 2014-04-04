/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstnew.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: realves <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/12/05 00:23:27 by realves           #+#    #+#             */
/*   Updated: 2014/04/04 22:28:59 by realves          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/game.h"

t_anim		*ft_lstnew(int tick, int nb_tileset, int nb_img, int x, int y)
{
	t_anim	*tmp;

	tmp = malloc(sizeof(t_anim));
	tmp->tick = tick;
	tmp->check = 0;
	tmp->nb_tileset = nb_tileset;
	tmp->nb_img = nb_img;
	tmp->x = x;
	tmp->y = y;
	return (tmp);
}
