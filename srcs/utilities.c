/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utilities.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: realves <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/03/24 20:31:43 by realves           #+#    #+#             */
/*   Updated: 2014/03/24 20:37:16 by realves          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/game.h"

void		gm_putallarrow(t_env *e, int nb)
{
	e->up_arrow = nb;
	e->down_arrow = nb;
	e->left_arrow = nb;
	e->right_arrow = nb;
}
