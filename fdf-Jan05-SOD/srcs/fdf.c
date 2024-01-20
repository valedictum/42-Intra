/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atang <atang@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/17 16:56:00 by atang             #+#    #+#             */
/*   Updated: 2024/01/01 19:25:21 by atang            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

#define RED_PIXEL 0x00FF0000
/*
-- CAN DEFINE WINDOWS HERE INSTEAD --
Alternatively, you can use these here:
# define WINDOW_WIDTH 600
# define WINDOW_HEIGHT 300

then use them like:
mlx_new_window(mlx_ptr, WINDOW_WIDTH, WINDOW_HEIGHT, "My first window!") in 
the code block.

-- CAN DEFINE MLX_ERROR HERE
#define MLX_ERROR 1

then used in code like:
if (mlx_ptr == NULL)
	return (MLX_ERROR);
*/

/*
-- EXPLANATION --

A computer scrren is a 2D object that has x and y co-ordinates, with the top 
left corner being the origin (x = 0, y = 0) where x is the row, y is the 
column.

void *mlx_init() returns a void pointer (a void pointer is basicially 
an address which the compiler doesn't know what type this address is pointing 
to i.e. to build a generic in C).

mlx_init establishes connection to the X-Window server (i.e. it returns the 
address of an Xvar variable which contains many things, most importantly a 
pointer to a display (connexion identifier used to communicate with the X 
server) which is opened with XOpenDisplay). It creates a structure and 
returns the address of a struct (Xvar) that has all the things minilibx 
needs to work including display which is another large struct.

Once we have finished with our program, we want to free our resources (call free
and pass it to mlx_ptr). There will still be leaks because the display hasn't 
been closed. mlx_destroy_display function needs to be called before free 
because we need to access the mlx_ptr to retrieve the display variable. 

XCloseDisplay cleans up and closes down a connection to an X-server 
ensuring that the windows and the resources associated with that connection 
are destroyed.

void *mlx_new_window(void *mlx_ptr, int size_x, int size_y, char *title)
mlx_new_window is a malloc-ed new window (mlx connection pointer that we got 
from mlx_init, width(x), height(y), title i.e name of window).

mlx_loop is an event loop function that keeps the process alive, basically an 
infinite loop in which events happen e.g. clicking anywhere in the window 
with the mouse or pressing a key. BEFORE the mlx_loop function is called, 
mlx allows us to register events that are able to triggered after the loop 
has started - mlx calls these functions hooks.   

mlx_data struct is used to pass more elements.

Hooks 'hook' into an event (i.e. they react to events). In this case, when a 
key is pressed, handleinput() is triggered. Note: every event is linked to 
its own prototype handler. All hooks in MiniLibX are nothing more than a 
function that gets called whenever a event is triggered.

The different hook functions are: 

int	mlx_mouse_hook (void *win_ptr, int (*funct_ptr)(), void *param);
int	mlx_key_hook (void *win_ptr, int (*funct_ptr)(), void *param);
int	mlx_expose_hook (void *win_ptr, int (*funct_ptr)(), void *param);
int	mlx_loop_hook (void *mlx_ptr, int (*funct_ptr)(), void *param);
int	mlx_hook(void *win_ptr, int x_event, int x_mask, int (*funct)(), 
	void *param);

where win_ptr is the pointer to the window (this window will register for 
the given event), func_ptr is a pointer to a fucntion that returns an int 
and that takes undefined parameters, param is the address of the element 
you want to access in your fucn_ptr when you'll be handling events (param 
is NOT used by mlx, so it'll just help to pass arguments).
(NOTE: (*func_ptr)() is not the same as (*func_ptr)(void): the last means
NO argument while the first means "any set of arguments".) You can register 
keyboard and mouse related event, as well as expose events. Expose events are 
triggered when the content of a window gets lost (for example, when the 
minilibx's window is covered partially or entirely by another) and needs to 
be re-drawn.

Consider an image as a buffer which you would then push to screen.

int	mlx_pixel_put(void *mlx_ptr, void *win_ptr, int x, int y, int color);
We've already explained what mlx_ptr and win_ptr are, and the others 
parameters are self-explanatory. x and y are the coordinate of the pixel, 
according to the metric considerations we just discussed.
We can either:

1)
int	encode_rgb(uint8_t red, uint8_t green, uint8_t blue)
{
    return (red << 16 | green << 8 | blue);
} 
(We can simply set the bits of the integer directly, using 
the << (left shift). This code will simply encode the red, green, and blue 
values into the returned integer.)
OR
2)
Hexadecimal is widely used when using encoded values because it allows us 
to clearly distiguish the bytes that form an integer. To do so, we need to 
think about an hexadecimal number as groups of two digits. One group of two 
digits represents an entire byte. Be aware tho, that in hexadecimal we have 
a total of sixteen digits used to represent a number 
(0123456789 ((abcdef) || (ABCDEF))).

minilibx complies wit h the true colour standard. True colour is an RGB 
color model standard that specifies 256 shades for red, green and blue 
spaces, totaling 16 million colors, much more than what the human eye 
can distinguish, which is only 10 million colors. This allows for very 
complex graphics and images, hence the name. With the minilibx, we need to 
make the color fit into an int datatype. That means that we need the int 
datatype to be 32 bits on our system. We need to encode our color into an 
int by setting the three least significant bits to the amount of red, 
green and blue, respectively.

mlx_loop is an event loop function that keeps the process alive, basically an 
infinite loop in which events happen e.g. clicking anywhere in the window 
with the mouse or pressing a key. Before the mlx_loop function is called,
mlx allows us to register events that are able to triggered after the loop 
has started - mlx calls these functions hooks.   
*/

/*
int	mlx_destroy_display(t_var *xvar)
{
	XCloseDisplay(xvar->display);
}
*/

/*
int	handle_no_event(void *t_mlx_data)
{
	(void)t_mlx_data;
	// This function needs to exist, but it is useless for the moment
    return (0);
}
*/

/*
-- HANDLER FUNCTION EXPLANATION --
This funciton is called every time a key is pressed.
A keycode is a hardware-specific code sent by the keyboard for a key press, a 
keysym is its abstract representation often used in software to identify the 
key regardless of hardware (minilibx mac uses keycodes).
The function that will be executed each time a key is released is handle_input. 
This is the duty of this function to check which key has been released, and to 
do things accordingly. We also pass the address of data which is the t_data 
object that contains all the stuff that we need to access inside handle_input.
The handle_input function checks if the key's symbol corresponds to the escape 
key. We included the X11/keysym.h header in order to get the values of all the 
available symbols.
*/

/*
-- HANDLER FUNCTION --
int	handle_input (int keysym, t_mlx_data *data)
{
	if (keysym == XK_Escape)
	{
		printf("The %d ESC key has been pressed\n\n", keysym);
		mlx_destroy_window(data->mlx_ptr, data->win_ptr);
		free(data->mlx_ptr);
		exit(1);
	}
	printf("The %d key has been pressed\n\n", keysym);
	return (0);
}
*/

/*
-- COLOURS --
We can use two methods to encode and decode colors:

1) BitShifting
Since each byte contains 2^8 = 256 values (1 byte = 8 bits), and RGB values 
range from 0 to 255, we can perfectly fit a integer (as an int is 4 bytes). 
In order to set the values programatically we use bitshifting

e.g.

int	create_trgb(int t, int r, int g, int b)
{
	return (t << 24 | r << 16 | g << 8 | b);
}

Because ints are stored from right to left, we need to bitshift each value 
the according amount of bits backwards. We can also do the exact opposite 
and retrieve integer values from a encoded TRGB integer.

e.g.

int	get_t(int trgb)
{
	return ((trgb >> 24) & 0xFF);
}

int	get_r(int trgb)
{
	return ((trgb >> 16) & 0xFF);
}

int	get_g(int trgb)
{
	return ((trgb >> 8) & 0xFF);
}

int	get_b(int trgb)
{
	return (trgb & 0xFF);
}

2) char/int conversion

Since each byte contains 2^8 = 256 values (1 byte = 8 bits), and RGB values
range from 0 to 255, we can perfectly fit a unsigned char for each TRGB 
parameters {T, R, G, B} (char is 1 byte) and fit a int for the TRGB value 
(int is 4 bytes). In order to set the values programatically we use type 
converting.

int	create_trgb(unsigned char t, unsigned char r, unsigned char g, 
	unsigned char b)
{
	return (*(int *)(unsigned char [4]){b, g, r, t});
}

unsigned char	get_t(int trgb)
{
	return (((unsigned char *)&trgb)[3]);
}

unsigned char	get_r(int trgb)
{
	return (((unsigned char *)&trgb)[2]);
}

unsigned char	get_g(int trgb)
{
	return (((unsigned char *)&trgb)[1]);
}

unsigned char	get_b(int trgb)
{
	return (((unsigned char *)&trgb)[0]);
}

*/

/*
int	render(t_mlx_data *data)
{
	//If there is a window!
	if (data->win_ptr != NULL)
		mlx_pixel_put(data->mlx_ptr, data->win_ptr, 2, 2, RED_PIXEL);
	return(0);
}
*/


//	NOT USED YET
// NICK V VIDEO
int	deal_key(int key, fdf *data)
{
	(void)data;
	fprintf(stdout, "%d\n", key);
	/*
	if (key == 126)
		data->shift_y -= 10;
	if (key == 125)
		data->shift_y += 10;
	if (key == 123)
		data->shift_x -= 10;
	if (key == 124)
		data->shift_x += 10;
	draw (data);
	*/
	return (0);
}

// TO TEST TO OPEN A WINDOW AND PRNT A LINE 
int	main(int argc, char **argv)
{
	fdf	*data;

	(void)argc;
	data = (fdf *)malloc(sizeof(fdf));
	read_file(argv[1], data);
	data->mlx_ptr = mlx_init();
	data->win_ptr = mlx_new_window(data->mlx_ptr, 1000, 1000, "FDF");
	data->zoom = 20;
	// bresenham(10, 10, 600, 300, data);
	draw (data);
	mlx_key_hook(data->win_ptr, deal_key, data);
	mlx_loop(data->mlx_ptr);
}





/*
// NICK V VIDEO MAIN TO PRINT OUT FDF MAPS
int	main(int argc, char **argv)
{
	fdf	*data;
	int	i;
	int	j;

	(void)argc;
	data = (fdf *)malloc(sizeof(fdf));
	read_file(argv[1], data);
	i = 0;
	while (i < data->height)
	{
		j = 0;
		while (j < data->width)
		{
			fprintf(stdout, "%d", data->z_matrix[i][j]);
			j++;
		}
		write(1, "\n", 1);
		i++;
	}
}
*/

/*
// THIS IS TO GO WITH PROPER MAIN
This function mimics mlx_pixel_put but will be much faster.
The bytes are not aligned so that means that line_length differs 
from the actual window width. As such, we need to calculate the memory 
offset using the line length set by 'mlx_get_data_addr'. 

void	my_mlx_pixel_put(t_img *data, int x, int y, int colour)
{
	char	*dest;

	dest = data ->addr + (y * data ->line_length + x
			* (data->bits_per_pixel / 8));
	*(unsigned int *)dest = colour;
}
*/

/*
// THIS IS MY PROPER MAIN BEFORE NICK V VIDEO
int	main(void)
{
	void		*mlx;
	void		*mlx_win;
	t_img		img;

	mlx = mlx_init();
	mlx_win = mlx_new_window(mlx, 1920, 1080, "Hello world!");
	img.img = mlx_new_image(mlx, 1920, 1080);
	// After creating an image, we call 'mlx_get_data_addr' and pass
	// bits_per_pixels, line_length, and 'endian' by reference. These will
	// then be set accordingly by mlx for the current data address.
	img.addr = mlx_get_data_addr(img.img, &img.bits_per_pixel, &img.line_length,
								&img.endian);
	my_mlx_pixel_put(&img, 500, 500, 0x00FF0000);
	mlx_put_image_to_window(mlx, mlx_win, img.img, 0, 0);
	mlx_loop(mlx);
}
*/

/*
-- MAIN MAIN --
int	main(void)
{
	t_mlx_data	data;	

	data.mlx_ptr = mlx_init();
	// Next two lines per Oceano video (needed as there is a malloc of Xvar 
	// variable in init which needs to be freed)
	if (data.mlx_ptr == NULL)
		return (1);
	data.win_ptr = mlx_new_window(data.mlx_ptr, 1920, 1080, "Hello world!");
	// Next 5 lines per Oceano video (needed as there is a malloc which
	// needs to be freed
	if (data.win_ptr == NULL)
	{
		free(data.win_ptr);
		return (1);
	}
	// These next lines are from: 
	// https://aurelienbrabant.fr/blog/getting-started-with-the-minilibx
	// which is bad as you are made to force-killing the process so the code 
	// after the infinite loop will not run, which results in memory leaks.
	//while (1)
	//	;
	data.img.img_ptr = mlx_new_image(data.mlx_ptr, 1920, 1080);
	data.img.img_pixels_ptr = mlx_get_data_addr(data.img.img_ptr, 
		&data.img.bits_per_pixel, &data.img.line_len, &data.img.endian);
	// -- SETUP HOOKS --
	mlx_loop_hook(data.win_ptr, &render, &data);
	//mlx_key_hook(data.win_ptr, &handle_input, &data);
	mlx_loop(data.mlx_ptr);
	//mlx_destroy_window(data.mlx_ptr, data.win_ptr);
	//mlx_destroy_display(data.mlx_ptr);
	free(data.mlx_ptr);
}
*/

/* 
-- EXERCISE TO OPEN 2 WINDOWS FROM OCEANO VIDEO --
int	main(void)
{
	void	*mlx_connect;
	void	*mlx_win_1;
	// TO MAKE 2ND WINDOW 
	//void	*mlx_win_2;
	// TO DESTROY WINDOW
	//void	*mlx_destroy_display;

	mlx_connect = mlx_init();
	// Next two lines per Oceano video (needed as there is a malloc of Xvar 
	// variable in init which needs to be freed)
	if (mlx_connect == NULL)
		return (1);
	mlx_win_1 = mlx_new_window(mlx_connect, 1920, 1080, "Hello world!");
	// Next 5 lines per Oceano video (needed as there is a malloc which
	// needs to be freed
	if (mlx_win_1 == NULL)
	{
		//mlx_destroy_display(mlx_connect);
		free(mlx_connect);
		return (1);
	}
	//
	TO MAKE A 2ND WINDOW
	mlx_win_2 = mlx_new_window(mlx_connect, 1280, 720, "2nd window!");
	// Next 5 lines per Oceano video (needed as there is a malloc which
	// needs to be freed
	if (mlx_win_2 == NULL)
	{
		//mlx_destroy_display(mlx_connect);
		free(mlx_connect);
		return (1);
	}
	//
	mlx_loop(mlx_connect);
}
*/
