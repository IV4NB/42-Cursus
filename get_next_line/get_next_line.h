/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iballest <iballest@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/28 08:55:32 by iballest          #+#    #+#             */
/*   Updated: 2023/09/28 08:55:32 by iballest         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iballest <iballest@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/28 08:55:22 by iballest          #+#    #+#             */
/*   Updated: 2023/09/28 08:55:22 by iballest         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# define BUFFER_SIZE 50
# include <stdlib.h>
# include <stdio.h>
# include <unistd.h>
# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>
# include <sys/types.h>
# include <sys/stat.h>
# include <fcntl.h>

size_t ft_strlen(char *str);
int ft_containsnl(char *str);
char	*ft_strjoin(char *s1, char *s2);
char *reader(int fd, char *data);
char *ft_extract_line(char *data);
char *ft_update_data(char *data);
char	*get_next_line(int fd);

#endif