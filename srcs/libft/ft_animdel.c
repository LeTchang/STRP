/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstdel.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: realves <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/01/08 00:09:45 by realves           #+#    #+#             */
/*   Updated: 2014/04/05 19:22:49 by realves          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/game.h"

static void	del(t_anim *elem)
{
	if (elem->next != NULL)
		del(elem->next);
	free(elem);
}

void		ft_animdel(t_anim **fanim)
{
	del(*fanim);
	*fanim = NULL;
}
