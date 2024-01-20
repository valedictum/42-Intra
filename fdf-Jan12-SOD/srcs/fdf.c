/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atang <atang@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/17 16:56:00 by atang             #+#    #+#             */
/*   Updated: 2024/01/11 21:08:51 by atang            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int	file_exists(char *file_name)
{
	FILE	*file;

	if ((file = fopen(file_name, "r")) != NULL)
	{
		fclose(file);
		return (1);
	}
	return (0);
}

/*
Helper function that checks if a given file name has the correct format i.e. 
.fdf. 1 is returned if the file name is invalid, 0 if valid. Length of file name 
is calculated using ft_strlen() before the last four characters of the file name 
are checked to ensure they are the correct .fdf format using ft_strn_cmp()
*/

static int	ft_file_name_error(char	*file_name)
{
	size_t	file_name_len;

	file_name_len = ft_strlen(file_name);
	if (ft_strncmp(&file_name[file_name_len - 4], ".fdf", 4))
		return (1);
	return (0);
}

/*
Helper function which destroys the window specified by thewin_ptr,
frees the memory allocated for mlx_ptr and data, then exits the program 
*/
void	handle_exit(t_fdf *data)
{
	mlx_destroy_window(data->mlx_ptr, data->win_ptr);
	free(data->mlx_ptr);
	free(data);
	exit(1);
}

/*
--- deal_key() ---
-> Handles keyboard input events and takes the following 
parameters as input: 
- an integer (key - a key code to represent the pressed key) 
- a pointer (data) to an fdf structure that contains program data

Key codes:
- Pan (display moved up/down/left/right):
126 = up, 125 = down, 123 = left, 124 = right
- Zoom (in/out):
69 = + (plus), 78 = - (minus)
- Amplify (+/-):
67 = increase amplification, 75 = reduce amplification 
- Exit (destroy window, free memory, and exit the program)
53 = Esc (escape)

mlx_clear_window() is used to clear the window and draw() is called
to redraw the window (e.g. when moved or zoomed).
*/

int	deal_key(int key, t_fdf *data)
{
	ft_printf("%d\n", key);
	if (key == 126)
		data->shift_y -= 10;
	else if (key == 125)
		data->shift_y += 10;
	else if (key == 123)
		data->shift_x -= 10;
	else if (key == 124)
		data->shift_x += 10;
	else if (key == 69)
		data->zoom += 1;
	else if (key == 78)
		data->zoom -= 1;
	else if (key == 67)
		data->amplify += 1;
	else if (key == 75)
		data->amplify -= 1;
	else if (key == 53)
		handle_exit(data);
	mlx_clear_window(data->mlx_ptr, data->win_ptr);
	draw (data);
	return (0);
}

/*
--- main() ---
-> The main:
- checks for correct # and format of parameters
- allocates memory for the t_fdf structure and assigns it to the data pointer
- reads the file specified by argv[1] and stores the data in the 'data'
structure
- amplification is initialised to 1
- initialises the mlx library and assigns the returned pointer to data->mlx_ptr
(mlx_init() establishes connection to the X-Window server (i.e. creates a 
structure and returns the address of a struct (Xvar) that has all the things 
minilibx needs to work including display which is another large struct)
- creates a new window of 1000x1000 pixels titled FDF using mlx_new_window
and assigns the returned pointer to data->win_ptr (malloc-ed new window)
- sets the zoom level to 20
- calls draw() to display the initial image
- registers deal_key() as the keyboard event handler using mlx_key_hook()
(Hooks 'hook' into an event (i.e. they react to events). In this case, when a 
key is pressed(the event), deal_key() is called. Note: every event is linked to 
its own prototype handler. All hooks in MiniLibX are nothing more than a 
function that gets called whenever a event is triggered.).
N.B int	mlx_key_hook (void *win_ptr, int (*funct_ptr)(), void *param) where 
win_ptr is pointer to the window which registers for the event and funct_ptr 
is a pointer to a function that returns an int and that takes undefined 
parameters (i.e. any set of arguments)
- starts the event loop using mlx_loop(), which essentially is an infinite loop
which keeps the process alive waiting for events (which were registered before 
the loop started) to be triggered e.g. pressing a key
- data, mlx_ptr, and z_matrix are freed as required
*/

/*
// OG MAIN
int	main(int argc, char **argv)
{
	t_fdf		*data;

	data = NULL;
	if (argc != 2 || ft_file_name_error(argv[1]))
		ft_printf("Error!\nUsage: ./fdf <filename>.fdf\n");
	if (file_exists(argv[1]))
	{
		data = (t_fdf *)malloc(sizeof(t_fdf));
		data->amplify = 1;
		read_file(argv[1], data);
		data->mlx_ptr = mlx_init();
		data->win_ptr = mlx_new_window(data->mlx_ptr, 1920, 1080, "FDF");
		data->zoom = 20;
		draw (data);
		mlx_key_hook(data->win_ptr, deal_key, data);
		mlx_loop(data->mlx_ptr);
		free(data->mlx_ptr);
		free(data->z_matrix);
	}
	else
		ft_printf("Error! File not found or unable to open.\n");
	free(data);
	return (0);
}
*/

// THE COPY
int	main(int argc, char **argv)
{
	t_fdf		*data;

	data = NULL;
	if (argc != 2 || ft_file_name_error(argv[1]))
		ft_printf("Error!\nUsage: ./fdf <filename>.fdf\n");
	if (file_exists(argv[1]))
	{
		data = (t_fdf *)malloc(sizeof(t_fdf));
		if (data == NULL)
		{
			ft_printf("Memory allocation failure.\n");
			return (1);
		}
		data->amplify = 1;
		read_file(argv[1], data);
		data->mlx_ptr = mlx_init();
		data->win_ptr = mlx_new_window(data->mlx_ptr, 1920, 1080, "FDF");
		data->zoom = 20;
		draw (data);
		mlx_key_hook(data->win_ptr, deal_key, data);
		mlx_loop(data->mlx_ptr);
		free(data->z_matrix);
		free(data);
	}
	else
		ft_printf("Error! File not found or unable to open.\n");
	return (0);
}
