/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   struct_anim.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: realves <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/04/04 22:14:22 by realves           #+#    #+#             */
/*   Updated: 2014/04/05 19:01:06 by realves          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef STRUCT_ANIM_H
# define STRUCT_ANIM_H

typedef struct			s_anim
{
	int					tick;
	int					check;
	int					nb_tileset;
	int					nb_img;
	int					x;
	int					y;
	struct s_anim		*next;
}						t_anim;

#endif /* !STRUCT_ANIM_H */
