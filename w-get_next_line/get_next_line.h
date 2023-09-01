/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atang <atang@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/21 14:49:29 by atang             #+#    #+#             */
/*   Updated: 2023/09/01 12:31:23 by atang            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# include <unistd.h>
# include <stdio.h>
# include <stdlib.h>
# include <fcntl.h>
# include <stddef.h>

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 1024
# endif

size_t	gnl_strlen(const char *s);
char	*gnl_strdup(const char *s1);
void	*gnl_memcpy(void *dst, const void *src, size_t n);
char	*gnl_strjoin(char const *s1, char const *s2);
char	*extract_completed_line(char **stash);
char	*read_from_fd(int fd);
char	*read_and_process_lines(int fd, char **stash);
char	*get_next_line(int fd);

#endif
