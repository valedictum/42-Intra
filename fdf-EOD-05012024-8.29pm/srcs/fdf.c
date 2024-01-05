/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atang <atang@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/17 16:56:00 by atang             #+#    #+#             */
/*   Updated: 2024/01/05 20:26:16 by atang            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

/*
--- int deal_key() ---
-> Handles keyboard input events and takes the following 
parameters as input: 
- an integer (key - a key code to represent the pressed key) 
- a pointer (data) to an fdf structure that contains program data

Key codes:
- Movement (display moved up/down/left/right):
126 = up, 125 = down, 123 = left, 124 = right
- Zoom (in/out):
69 = + (plus), 78 = - (minus)
- Exit (destroy window, free memory, and exit the program)
53 = Esc (escape)

mlx_clear_window() is used to clear the window and draw() is called
to redraw the window (e.g. when moved or zoomed).
*/

int	deal_key(int key, t_fdf *data)
{
	fprintf(stdout, "%d\n", key);
	if (key == 126)
		data->shift_y -= 10;
	if (key == 125)
		data->shift_y += 10;
	if (key == 123)
		data->shift_x -= 10;
	if (key == 124)
		data->shift_x += 10;
	if (key == 69)
		data->zoom += 1;
	if (key == 78)
		data->zoom -= 1;
	if (key == 53)
	{
		mlx_destroy_window(data->mlx_ptr, data->win_ptr);
		free(data->mlx_ptr);
		exit(1);
	}
	mlx_clear_window(data->mlx_ptr, data->win_ptr);
	draw (data);
	return (0);
}

/*
--- main() ---
-> The main:
- allocates memory for the t_fdf structure and assigns it to the data pointer
- reads the file specified by argv[1] and stores the data in the 'data'
structure
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
*/

int	main(int argc, char **argv)
{
	t_fdf	*data;

	(void)argc;
	data = (t_fdf *)malloc(sizeof(t_fdf));
	read_file(argv[1], data);
	data->mlx_ptr = mlx_init();
	data->win_ptr = mlx_new_window(data->mlx_ptr, 1000, 1000, "FDF");
	data->zoom = 20;
	draw (data);
	mlx_key_hook(data->win_ptr, deal_key, data);
	mlx_loop(data->mlx_ptr);
}
