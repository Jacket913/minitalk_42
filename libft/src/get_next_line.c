/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gmoulin <gmoulin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/18 15:44:28 by gmoulin           #+#    #+#             */
/*   Updated: 2024/09/18 15:44:38 by gmoulin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*get_next_line(int fd)
{
	static char	buffer[BUFFER_SIZE];
	char		*process;
	char		*line;

	line = NULL;
	process = NULL;
	while (!is_valid(line) && read_file(fd, (char **) &buffer))
	{
		process = process_buffer(buffer);
		if (!process)
			return (free(line), NULL);
		if (line)
		{
			line = ft_strcat(line, process);
			if (!line)
				return (NULL);
		}
		else
			line = process;
	}
	return (line);
}

int	is_valid(char *line)
{
	if (!line)
		return (FALSE);
	return (line[ft_strlen(line) - 1] == '\n');
}

int	read_file(int fd, char **buffer)
{
	ssize_t	readed;

	if (!buffer[0])
	{
		readed = read(fd, buffer, BUFFER_SIZE);
		if (readed <= 0)
			return (FALSE);
	}
	return (TRUE);
}

char	*process_buffer(char *buffer)
{
	char	*line;
	size_t	len;
	size_t	i;

	len = find_end_line(buffer);
	line = ft_calloc(len + 1, sizeof(char));
	if (!line)
		return (NULL);
	i = -1;
	while (++i < len)
		line[i] = buffer[i];
	line[i] = '\0';
	ft_shift_str(buffer, len, BUFFER_SIZE);
	return (line);
}
