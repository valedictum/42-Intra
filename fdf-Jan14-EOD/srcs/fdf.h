/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atang <atang@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/17 16:55:45 by atang             #+#    #+#             */
/*   Updated: 2024/01/14 18:10:02 by atang            ###   ########.fr       */
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

typedef struct s_point
{
	float	x;
	float	y;
	int		z;
}			t_point;

typedef struct s_step
{
	float	x_step;
	float	y_step;
	float	x;
	float	y;
	float	x1;
	float	y1;
}			t_step;

typedef struct s_fdf
{
	int				width;
	int				height;
	int				**z_matrix;
	int				zoom;
	int				colour;
	int				amplify;
	int				shift_x;
	int				shift_y;
	void			*mlx_ptr;
	void			*win_ptr;
	int				offset_x;
	int				offset_y;
	//Added 14/01
	void			*img_ptr;
	unsigned int	*img_data;
	int				bpp;
	int				size_line;
	int				endian;
	//
	t_point			start;
	t_point			end;
}			t_fdf;

//--- error.c ---//
int		file_exists(char *file_name);
int		ft_file_name_error(char	*file_name);
void	handle_exit(t_fdf *data);

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
float	mod(float a);
//void	isometric(int *x, int *y, int z);
void	isometric(float	*x, float *y, int z);
//--- draw.c ---//
//void	bresenham(float x, float y, float x1, float y1, t_fdf *data);
//Change to this if we can use data structure only
void	bresenham(t_point start, t_point end, t_fdf *data);
void	my_mlx_pixel_put(t_fdf *data, int x, int y, int colour);
//Original above
void	draw(t_fdf *data);
//--- fdf.c ---//
int		file_exists(char *file_name);
void	handle_exit(t_fdf *data);
int		deal_key(int key, t_fdf *data);

#endif
