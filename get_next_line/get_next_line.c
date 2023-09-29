/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iballest <iballest@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/26 10:29:57 by iballest          #+#    #+#             */
/*   Updated: 2023/09/26 10:29:57 by iballest         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

size_t ft_strlen(char *str)
{
    size_t i;

    i = 0;
    if(str == NULL)
        return (0);
    while(str[i] != '\0')
        i++;
    return i;
}

int ft_contains(char *str, char c)
{
    int i;

    i = 0;
    if(str == NULL)
        return 0;
    if(c == '\0')
        return 1;
    while(str[i] != '\0')
    {
        if(str[i] == c)
            return 1;
        i++;
    }
    return 0;
}

char	*ft_strjoin(char *s1, char *s2)
{
	char	*join;
	size_t	len;
	int		i;
	int		j;

	len = ft_strlen(s1) + ft_strlen(s2);
	join = malloc(sizeof(char) * (len + 1));
	i = 0;
	while (s1 != NULL && s1[i] != '\0')
	{
		join[i] = s1[i];
		++i;
	}
	free(s1);
	j = 0;
	while (s2 != NULL && s2[j] != '\0')
		join[i++] = s2[j++];
	join[len] = '\0';
	return (join);
}

char *reader(int fd, char *data)
{
    char *buffer;
    int bytes_read;
    bytes_read = 1;
    buffer = (char *)malloc(sizeof(char) * (BUFFER_SIZE + 1));
    if (!buffer)
        return NULL;
    while(!ft_contains(data, '\n') && bytes_read > 0)
    {
        bytes_read = read(fd, buffer, BUFFER_SIZE);
        if(bytes_read < 0)
        {
            free(buffer);
            free(data);
            return NULL;
        }
        buffer[bytes_read] = '\0';
        data = ft_strjoin(data, buffer);
    }
    free(buffer);
    if(bytes_read == 0 && ft_strlen(data) == 0)
        return NULL;
    return (data);
}

char *ft_extract_line(char *data)
{
    int i;
    char *line;
    if(data == NULL)
        return NULL;
    
    i = 0;
    while(data[i] != '\n' && data[i] != '\0')
        i++;
    line = (char *)malloc(sizeof(char) * (i + 1));
    if (!line)
        return NULL;
    i = 0;
    while(data[i] != '\n' && data[i] != '\0')
    {
        line[i] = data[i];
        i++;
    }
    line[i] = '\0';
    return (line);
}

char *ft_update_data(char *old_data)
{
    int i;
    int j;
    char *new_data;

    i = 0;
    j = 0;
    while(old_data[i] != '\n' && old_data[i] != '\0')
        i++;
    if(old_data[i] == '\0')
    {
        free(old_data);
        return NULL;
    }
    new_data = (char *)malloc(sizeof(char) * (ft_strlen(old_data) - i + 1));
    if (!new_data)
        return NULL;
    i++;
    while(old_data[i] != '\0')
    {
        new_data[j] = old_data[i];
        i++;
        j++;
    }
    new_data[j] = '\0';
    free(old_data);
    return (new_data);
}

char	*get_next_line(int fd)
{
	char		*line;
	static char	*data;

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	data = reader(fd, data);
	if (data == NULL)
		return (NULL);
	line = ft_extract_line(data);
	data = ft_update_data(data);
	return (line);
}

int main()
{
    int fd = open("test.txt", O_RDONLY);
    char *str;
    while((str = get_next_line(fd)) != NULL)
        printf("%s\n", str);
    free(str);
    return 0;
}
