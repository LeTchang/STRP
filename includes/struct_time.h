/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   struct_time.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: realves <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/04/04 22:11:57 by realves           #+#    #+#             */
/*   Updated: 2014/04/04 22:14:16 by realves          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef STRUCT_TIME_H
# define STRUCT_TIME_H

typedef struct		s_time
{
	double			time;
	double			time_frame;
	int				check;
	int				tick;
}					t_time;

#endif /* !STRUCT_TIME_H */
