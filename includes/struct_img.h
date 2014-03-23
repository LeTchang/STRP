/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   struct_img.h                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: realves <realves@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/02/26 13:47:25 by realves           #+#    #+#             */
/*   Updated: 2014/03/23 20:27:19 by realves          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef STRUCT_IMG_H
# define STRUCT_IMG_H

# include "game.h"

typedef struct		s_img
{
	void			*ptr;
	char			*img;
	char			*teleport;
	int				bpp;
	int				size_line;
	int				endian;
	int				width;
	int				height;
	int				max_size;
	int				solid;
	int				sens;
	int				teleport_x;
	int				teleport_y;
	int				teleport_sens;
}					t_img;

#endif /* !STRUCT_IMG_H */
