/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ealves <ealves@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/02 11:04:53 by ealves            #+#    #+#             */
/*   Updated: 2023/04/12 15:34:29 by ealves           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

// '\n' trouve dans la ligne : je coupe la ligne
char	*cutline(char **line)
{
	char	*new_line;
	char	*rline;
	int		endl;

	rline = NULL;
	endl = ft_strlen_gnl(*line, '\n');
	if (endl != -1)
	{
		rline = ft_strdup_gnl(*line, endl + 1);
		new_line = ft_strdup_gnl(*line + (endl + 1),
				ft_strlen_gnl(*line, '\0'));
		free(*line);
		*line = new_line;
	}
	else
	{
		if (*line && *line[0])
			rline = ft_strdup_gnl(*line, ft_strlen_gnl(*line, '\0'));
		if (*line)
		{
			free(*line);
			*line = NULL;
		}
	}
	return (rline);
}

char	*get_next_line(int fd)
{
	char			*buff;
	static char		*line;
	ssize_t			count;

	count = 0;
	if (fd < 0 || BUFFER_SIZE < 1)
		return (NULL);
	buff = malloc(sizeof(char) * BUFFER_SIZE + 1);
	if (!buff)
		return (NULL);
	while (ft_strlen_gnl(line, '\n') == -1)
	{
		count = read(fd, buff, BUFFER_SIZE);
		if (count <= 0)
			break ;
		buff[count] = '\0';
		if (!line)
			line = ft_strdup_gnl(buff, count);
		else
			line = ft_strjoin_gnl(line, buff);
	}
	free(buff);
	if (count == -1)
		return (NULL);
	return (cutline(&line));
}
