/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iballest <iballest@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/11 17:06:28 by iballest          #+#    #+#             */
/*   Updated: 2023/10/11 17:06:31 by iballest         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*reader(int fd, char *data)
{
	char	*buffer;
	int		bytes_read;

	bytes_read = 1;
	buffer = (char *)malloc(sizeof(char) * (BUFFER_SIZE + 1));
	if (!buffer)
		return (NULL);
	while (!ft_contains(data, '\n') && bytes_read > 0)
	{
		bytes_read = read(fd, buffer, BUFFER_SIZE);
		if (bytes_read < 0)
		{
			free(buffer);
			free(data);
			return (NULL);
		}
		buffer[bytes_read] = '\0';
		if (bytes_read > 0)
			data = ft_strjoin(data, buffer);
	}
	free(buffer);
	return (data);
}

char	*ft_extract_line(char *data)
{
	int		i;
	char	*line;

	if (data == NULL)
		return (NULL);
	i = 0;
	while (data[i] != '\n' && data[i] != '\0')
		i++;
	line = (char *)malloc(sizeof(char) * (i + 2));
	if (!line)
		return (NULL);
	i = 0;
	while (data[i] != '\n' && data[i] != '\0')
	{
		line[i] = data[i];
		i++;
	}
	if (data[i] == '\n')
		line[i++] = '\n';
	line[i] = '\0';
	return (line);
}

char	*ft_update_data(char *old_data)
{
	int		i;
	int		j;
	char	*new_data;

	i = 0;
	j = 0;
	while (old_data[i] != '\n' && old_data[i] != '\0')
		i++;
	if (old_data[i] == '\0')
	{
		free(old_data);
		return (NULL);
	}
	new_data = (char *)malloc(sizeof(char) * (ft_strlen(old_data) - i + 1));
	if (old_data[++i] == '\0')
	{
		free(old_data);
		free(new_data);
		return (NULL);
	}
	while (old_data[i] != '\0')
		new_data[j++] = old_data[i++];
	new_data[j] = '\0';
	free(old_data);
	return (new_data);
}

char	*get_next_line(int fd)
{
	char		*line;
	static char	*data[1024];

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	data[fd] = reader(fd, data[fd]);
	if (data[fd] == NULL)
	{
		free(data[fd]);
		return (NULL);
	}
	line = ft_extract_line(data[fd]);
	data[fd] = ft_update_data(data[fd]);
	return (line);
}
