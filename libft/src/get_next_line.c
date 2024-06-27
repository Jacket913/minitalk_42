/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: andymalgonne <andymalgonne@student.42.f    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/11 16:18:09 by gmoulin           #+#    #+#             */
/*   Updated: 2024/04/26 10:19:44 by andymalgonn      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*clean_buffer(char *sbuffer, char *buffer)
{
	char	*tmp;

	tmp = ft_strjoin(sbuffer, buffer);
	free(sbuffer);
	return (tmp);
}

char	*get_line(char *sbuffer)
{
	char	*line;
	int		i;

	i = 0;
	if (!sbuffer[i])
		return (NULL);
	while (sbuffer[i] && sbuffer[i] != '\n')
		i++;
	if (sbuffer[i] == '\n')
		line = ft_calloc((i + 2), sizeof(char));
	else
		line = ft_calloc((i + 1), sizeof(char));
	i = 0;
	while (sbuffer[i] && sbuffer[i] != '\n')
	{
		line[i] = sbuffer[i];
		i++;
	}
	if (sbuffer[i] == '\n')
		line[i] = '\n';
	return (line);
}

char	*get_next(char *sbuffer)
{
	char	*line;
	int		i;
	int		j;

	i = 0;
	while (sbuffer[i] && sbuffer[i] != '\n')
		i++;
	if (!sbuffer[i])
		return (free(sbuffer), NULL);
	line = ft_calloc((ft_strlen(sbuffer) - i + 1), sizeof(char));
	i++;
	j = 0;
	while (sbuffer[i])
		line[j++] = sbuffer[i++];
	free(sbuffer);
	return (line);
}

char	*read_file(char *sbuffer, int fd)
{
	char	*buffer;
	int		b_read;

	if (!sbuffer)
		sbuffer = ft_calloc(1, 1);
	buffer = ft_calloc(BUFFER_SIZE + 1, sizeof(char));
	b_read = 1;
	while (b_read > 0)
	{
		b_read = read(fd, buffer, BUFFER_SIZE);
		if (b_read == -1)
			return (free(buffer), NULL);
		buffer[b_read] = '\0';
		sbuffer = clean_buffer(sbuffer, buffer);
		if (ft_strchr(buffer, '\n'))
			break ;
	}
	free(buffer);
	return (sbuffer);
}

char	*get_next_line(int fd)
{
	static char	*sbuffer[MAX_FD];
	char		*line;

	if (fd < 0 || fd >= MAX_FD || read(fd, 0, 0) < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	if (!sbuffer[fd])
		sbuffer[fd] = ft_calloc(1, sizeof(char));
	sbuffer[fd] = read_file(sbuffer[fd], fd);
	if (!(sbuffer[fd]))
		return (free(sbuffer[fd]), NULL);
	line = get_line(sbuffer[fd]);
	sbuffer[fd] = get_next(sbuffer[fd]);
	return (line);
}
