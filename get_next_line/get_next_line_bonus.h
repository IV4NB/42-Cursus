/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.h                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iballest <iballest@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/11 17:06:37 by iballest          #+#    #+#             */
/*   Updated: 2023/10/11 17:07:18 by iballest         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_BONUS_H
# define GET_NEXT_LINE_BONUS_H

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 1
# endif

# include <fcntl.h>
# include <stdio.h>
# include <stdlib.h>
# include <sys/stat.h>
# include <sys/types.h>
# include <unistd.h>

size_t	ft_strlen(char *str);
int		ft_contains(char *str, char c);
char	*ft_strjoin(char *s1, char *s2);
char	*reader(int fd, char *data);
char	*ft_extract_line(char *data);
char	*ft_update_data(char *data);
char	*get_next_line(int fd);

#endif
