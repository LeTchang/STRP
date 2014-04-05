/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstadd.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: realves <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/12/05 04:59:38 by realves           #+#    #+#             */
/*   Updated: 2014/04/05 18:06:14 by realves          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/game.h"

void		ft_animadd(t_anim **fanim, t_anim *new)
{
	if (*fanim == NULL)
		*fanim = new;
	else
	{
		new->next = *fanim;
		*fanim = new;
	}
}
