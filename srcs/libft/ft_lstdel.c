/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstdel.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: realves <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/01/08 00:09:45 by realves           #+#    #+#             */
/*   Updated: 2014/04/04 22:35:44 by realves          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/game.h"

static void	del(t_anim *elem)
{
	if (elem->next != NULL)
		del(elem->next);
}

void		ft_lstdel(t_anim **fanim)
{
	del(*fanim);
	*fanim = NULL;
}
