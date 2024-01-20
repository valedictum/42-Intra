/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atang <atang@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/17 16:55:45 by atang             #+#    #+#             */
/*   Updated: 2024/01/01 19:25:31 by atang            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FDF_H
# define FDF_H

# include <unistd.h>
# include <stdlib.h>
# include <stdio.h>
# include <fcntl.h>
// # include <X11/X.h>
// # include <X11/keysym.h>
# include "../libs/libft/libft.h"
# include "../minilibx/mlx.h"

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 42
# endif

typedef struct
{
	int		width;
	int		height;
	int		**z_matrix;
	int		zoom;
	int		colour;
	//int		shift_x;
	//int		shift_y;


	void	*mlx_ptr;
	void	*win_ptr;
}			fdf;

// GNL
size_t	gnl_strlen(const char *str);
char	*gnl_strchr(char *str, int target_char);
char	*gnl_strjoin(char *first_str, char *second_str);
char	*gnl_initialise_str(void);
char	*read_and_append_lines(int fd, char	*stash);
char	*extract_line_from_stash(char	*stash);
char	*remaining_stash_after_extraction(char *stash);
char	*get_next_line(int fd, char **line);

// FDF
void	read_file(char	*file_name, fdf	*data);
void	bresenham(float x, float y, float x1, float y1, fdf *data);
void	draw(fdf *data);

/*
// MY PROPER MAIN STRUCTS, S_IMG AND S_MLX_DATA

typedef	struct	s_img
{
	void	*img;
	char	*addr;
	//char	*img_pixels_ptr;
	int		bits_per_pixel;
	int		endian;
	int		line_length;
}		t_img;

This is an mlx data struct which stores all the important data - we need 
this as we need to pass arguments to the hook functions but we are only able 
to pass a single void pointer i.e. by creating a structure, we can pass multiple 
arguments by passing a pointer to the structure.


typedef struct	s_mlx_data
{
	int		width;
	int		height;
	int		**z_matrix;
	void	*mlx_ptr;
	void	*win_ptr;
	t_img	img;
}		t_mlx_data;
*/

#endif
