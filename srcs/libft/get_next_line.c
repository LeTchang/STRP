/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmancero <jmancero@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/12/03 22:08:24 by jmancero          #+#    #+#             */
/*   Updated: 2014/03/22 15:48:37 by realves          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/game.h"

static char	*ft_my_realloc(char *s, unsigned int start, size_t len)
{
	char			*substr;
	size_t			j;

	substr = (char *)malloc(sizeof(char) * (len + 1));
	substr[len] = '\0';
	if (substr == NULL || !s)
		return (NULL);
	j = 0;
	while (j < len)
	{
		substr[j] = s[start];
		j++;
		start++;
	}
	free(s);
	return (substr);
}

static int	if_mini(char **mini, char **line, int *i)
{
	char			*j;
	unsigned int	k;

	if (!(j = ft_strchr(*mini, '\n')))
	{
		*line = ft_my_realloc(*line, 0, (*i = *i + ft_strlen(*mini)));
		ft_strncat(*line, *mini, ft_strlen(*mini));
		*mini = ft_strnew(0);
	}
	else
	{
		*line = ft_my_realloc(*line, 0, (*i = *i + (k = j - *mini)));
		ft_strncat(*line, *mini, k);
		*mini = *mini + k + 1;
		return (1);
	}
	return (0);
}

static int	if_no_mini(char **buff, char **line, int *i, char **mini)
{
	char			*j;
	unsigned int	k;

	if (!(j = ft_strchr(*buff, '\n')))
	{
		*line = ft_my_realloc(*line, 0, (*i = *i + BUFF_SIZE));
		ft_strncat(*line, *buff, BUFF_SIZE);
	}
	else
	{
		*line = ft_my_realloc(*line, 0, (*i = *i + (k = j - *buff)));
		ft_strncat(*line, *buff, k);
		*mini = ft_strsub(*buff, k + 1, BUFF_SIZE - k - 1);
		return (1);
	}
	return (0);
}

int			get_next_line(int const fd, char **line)
{
	char			*buff;
	int				i;
	int				m;
	static char		*mini = "\0";

	i = 0;
	m = 1;
	*line = (char *)malloc(sizeof(char) * 1);
	buff = (char *)malloc(sizeof(char) * (BUFF_SIZE + 1));
	if (line == NULL || fd < 0 || *line == NULL || buff == NULL)
		return (-1);
	**line = '\0';
	while (m != 0)
	{
		if (*mini && if_mini(&mini, line, &i) == 1)
			return (1);
		if (!(*mini) && (m = read(fd, buff, BUFF_SIZE)) && (buff[m] = 0) == 0)
		{
			if (if_no_mini(&buff, line, &i, &mini) == 1)
				return (1);
		}
	}
	if (**line)
		return (1);
	return (0);
}
