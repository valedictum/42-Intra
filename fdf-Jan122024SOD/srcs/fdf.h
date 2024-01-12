/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atang <atang@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/17 16:55:45 by atang             #+#    #+#             */
/*   Updated: 2024/01/11 21:01:10 by atang            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FDF_H
# define FDF_H

# include <unistd.h>
# include <stdlib.h>
# include <stdio.h>
# include <fcntl.h>
# include "../libs/ft_printf/ft_printf.h"
# include "../libs/libft/libft.h"
# include "../minilibx/mlx.h"

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 42
# endif

typedef struct s_fdf
{
	int		width;
	int		height;
	int		**z_matrix;
	int		zoom;
	int		colour;
	int		amplify;
	int		shift_x;
	int		shift_y;
	void	*mlx_ptr;
	void	*win_ptr;
	//Adding the below
	float	x;
	float	y;
	float	x1;
	float	y1;
	//
}			t_fdf;

// GNL
size_t	gnl_strlen(const char *str);
char	*gnl_strchr(char *str, int target_char);
char	*gnl_strjoin(char *first_str, char *second_str);
char	*gnl_initialise_str(void);
char	*read_and_append_lines(int fd, char	*stash);
char	*extract_line_from_stash(char	*stash);
char	*remaining_stash_after_extraction(char *stash);
char	*get_next_line(int fd, char **line);
//--- read_file.c ---// 
void	read_file(char	*file_name, t_fdf	*data);
//--- draw_utils.c ---//
int		max(int a, int b);
int		mod(int a);
void	isometric(float	*x, float *y, int z);
//--- draw.c ---//
void	bresenham(float x, float y, float x1, float y1, t_fdf *data);
//Change to this if we can use data structure only
//void	bresenham(t_fdf *data);
void	my_mlx_pixel_put(t_fdf *data, int x, int y, int colour);
//Original above
void	draw(t_fdf *data);
//--- fdf.c ---//
int		file_exists(char *file_name);
void	handle_exit(t_fdf *data);
int		deal_key(int key, t_fdf *data);

#endif
