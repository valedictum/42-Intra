/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sentry <sentry@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/01 13:15:56 by atang             #+#    #+#             */
/*   Updated: 2024/01/13 08:01:24 by sentry           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"
#include <math.h>

/*
2. Drawing line function (google Bresenham algorithm)
- find by how much we need to increase x and by how much we need to increase y
by using float. Example:
	x = 2; x1 = 4;
	y = 2; y1 = 6;
	steps for x: 2
	steps for y: 4
	that means that y should grow 2 times faster than x
	every loop step: y += 1 and x += 0.5
	after 4 steps x and y will be equal with x1, y1

					real x:y		x:y     pixels				
		start:		2.0 : 2.0		2:2        .
		step 1:		2.5 : 3.0		2:3        .
		step 2:		3.0 : 4.0		3:4         .
		step 3:		3.5 : 5.0		3:5         .
		step 4:		4.0 : 6.0		4:6          .
			
	that works because (float)2.5 turns to (int)2 in func. mlx_pixel_put()
*/

/*
//OG COLOUR
static int	calculate_colour(int z, int z1)
{
	if (z || z1)
	//	return (0xe80c0c); OG Red
		return (0xFF0000);
	else
		return (0xffffff);
}
*/

/*
static int calculate_colour(int z, int z1)
{
    int color1 = 0xFF0000; // Starting color
    int color2 = 0xFFFFFF; // Ending color

    // Calculate the intermediate color based on the difference between z and z1
    float t = (float)(z1 - z) / (float)(z1 - z + 1);
    float red = ((color1 >> 16) & 0xFF) * t + ((color2 >> 16) & 0xFF) * (1 - t);
    float green = ((color1 >> 8) & 0xFF) * t + ((color2 >> 8) & 0xFF) * (1 - t);
    float blue = (color1 & 0xFF) * t + (color2 & 0xFF) * (1 - t);

    // Combine the RGB values to create the final color
    int final_color = ((int)red << 16) | ((int)green << 8) | (int)blue;

    return final_color;
}
*/

static int	calculate_colour(int z, int z1)
{
	int	neg_colour;
	int	zero_colour;
	int	pos_colour;
	int	final_colour;

	neg_colour = 0xFF0000;
	zero_colour = 0xFFFFFF;
	pos_colour = 0x00FF00;
	if (z < 0 || z1 < 0)
		return (neg_colour);
	else if (z == 0 && z1 == 0)
		return (zero_colour);
	else if (z >= 0 && z1 >= 0)
		return (pos_colour);
	else
	{
		final_colour = pos_colour + ((neg_colour - pos_colour) * z) / (z + z1);
		return (final_colour);
	}
}

/*
--- bresenham() ---
-> Implements the Bresenham's line algorithm to draw a line on a graphics 
window. It takes the start and end co-ordinates of the line as well as a 
structure pointer 'data' that contains information such as zoom level,
colour, shift value etc. Fn calculates the step size for each co-ordinate based
on the difference between the start and end points, then plots pixels by 
iteration using mlx_pixel_put().

Inputs are: floats x and y (the x, y of the starting point of the line) 
and floats x1 and y1 (the x, y of the end point of the line), and a pointer
to the structure that contains addtional line-drawing information.

- retrieves the z-values of the starting and ending points from the z_matrix 
in the 'data' structure
- scales the co-ordinates by the zoom level specified in 'data'
- applies isometric transformation to the co-ordinates using isometric()
- adjusts the co-ordiantes by the shift values specified in the 'data' structure
- calculates the step size for each co-ordiante based on the difference between
the start and end points
- normalises the step sizes by dividing them by their maximum absolute 
difference between the co-ordinates
- iterates over the line by incrementing the co-ordinates by the step sizes and 
plots pixels using mlx_pixel_put() 
*/

void	calculate_steps(float x_step, float y_step, float x,
	float y, float x1, float y1)
{
	float	max_value;

	max_value = max(mod(x1 - x), mod(y1 - y));
	x_step = (x1 - x) / max_value;
	y_step = (y1 - y) / max_value;
}

// WORKING COPY BRESENHAM()
void	bresenham(t_point start, t_point end, t_fdf *data)
{
	float	x;
	float	y;
	float	x1;
	float	y1;
	float	max_value;

	x = (int)start.x * data->zoom + data->shift_x;
	y = (int)start.y * data->zoom + data->shift_y;
	x1 = (int)end.x * data->zoom + data->shift_x;
	y1 = (int)end.y * data->zoom + data->shift_y;
	data->colour = calculate_colour((int)start.z, (int)end.z);
	isometric(&x, &y, (int)start.z * data->amplify);
	isometric(&x1, &y1, (int)end.z * data->amplify);
	max_value = max(mod(x1 - x), mod(y1 - y));
	calculate_steps(((x1 - x) / max_value), ((y1 - y) / max_value),
		x, y, x1, y1);
	while ((int)(x - x1) || (int)(y - y1))
	{
		mlx_pixel_put(data->mlx_ptr, data->win_ptr, x, y, data->colour);
		x += (x1 - x) / max_value;
		y += (y1 - y) / max_value;
	}
}

/*
//PREVIOUS
void	bresenham(t_point start, t_point end, t_fdf *data)
{
	float	x_step;
	float	y_step;
	int		max_value;
	float	z_start;
	float	z_end;

	float x = (int)start.x;
	float y = (int)start.y;
	float x1 = (int)end.x;
	float y1 = (int)end.y;
	z_start = data->z_matrix[(int)y][(int)x];
	z_end = data->z_matrix[(int)y1][(int)x1];
	x *= data->zoom;
	y *= data->zoom;
	x1 *= data->zoom;
	y1 *= data->zoom;
	data->colour = calculate_colour((int)z_start, (int)z_end);
	isometric(&x, &y, (int)z_start * data->amplify);
	isometric(&x1, &y1, (int)z_end * data->amplify);
	x += data->shift_x;
	y += data->shift_y;
	x1 += data->shift_x;
	y1 += data->shift_y;
	x_step = x1 - x;
	y_step = y1 - y;
	max_value = max(mod(x_step), mod(y_step));
	x_step /= max_value;
	y_step /= max_value;
	while ((int)(x - x1) || (int)(y - y1))
	{
		mlx_pixel_put(data->mlx_ptr, data->win_ptr, x, y, data->colour);
		x += x_step;
		y += y_step;
	}
}
*/

/*
--- draw() ---
-> Iterates over height and width of the 'data' structure and 
calls bresenham() to draw lines between each dot on the grid, taking 
a pointer to the t_fdf 'data' structure as input.

Draws lines between every dot as below:

	0->		0->		0->		0
	|		|		|		|
	
	0->		10->	10->	0
	|		|		|		|

	0->		10->	10->    0
	|		|		|		|

	0->		0->		0->		0
'->' and '|'are lines between dots

Every dot has two lines (right and down):	0->
											|
(Boundary dots are exceptions)

- inside the nested loop which iterates over height and width, it
checks if x is less than width - 1 (if so, bresenham() is called to 
draw a line from the current dot to the dot on its right). then y is
checked to see if it is less than height - 1 (if so, bresenham() is 
called to draw a line from the current dot to the dot below it)
- x++, then when out of the inner loop, y++ until y reaches the height 
of the grid 

N.B By - 1 from height and width, we are only drawing lines within the
valid range of the grid i.e (width - 1) to ensure it is not the last dot
in the row (draws L to R), and (height - 1) to ensure it is not the last
dot in the column (draws T to B)
*/

// WORKING COPY DRAW()
void	draw(t_fdf *data)
{
	int		x;
	int		y;
	int		z;

	z = 0;
	y = 0;
	while (y < data->height)
	{
		x = 0;
		while (x < data->width)
		{
			if (x < data->width - 1)
				bresenham((t_point){x, y, data->z_matrix[y][x]},
					(t_point){x + 1, y, data->z_matrix[y][x + 1]}, data);
			if (y < data->height - 1)
				bresenham((t_point){x, y, data->z_matrix[y][x]},
					(t_point){x, y + 1, data->z_matrix[y + 1][x]}, data);
			x++;
		}
		y++;
	}
}

/*
// ORIGINAL WORKING BRESENHAM() - DO NOT TOUCH
void	bresenham(float x, float y, float x1, float y1, t_fdf *data)
{
	float	x_step;
	float	y_step;
	int		max_value;
	int		z;
	int		z1;

	z = data->z_matrix[(int)y][(int)x];
	z1 = data->z_matrix[(int)y1][(int)x1];
	x *= data->zoom;
	y *= data->zoom;
	x1 *= data->zoom;
	y1 *= data->zoom;
	data->colour = calculate_colour(z, z1);
	isometric(&x, &y, z * data->amplify);
	isometric(&x1, &y1, z1 * data ->amplify);
	x += data->shift_x;
	y += data->shift_y;
	x1 += data->shift_x;
	y1 += data->shift_y;
	x_step = x1 - x;
	y_step = y1 - y;
	max_value = max(mod(x_step), mod(y_step));
	x_step /= max_value;
	y_step /= max_value;
	while ((int)(x - x1) || (int)(y - y1))
	{
		mlx_pixel_put(data->mlx_ptr, data->win_ptr, x, y, data->colour);
		x += x_step;
		y += y_step;
	}
}
*/

/*
// ORIGINAL WORKING DRAW() - DO NOT TOUCH
void	draw(t_fdf *data)
{
	int	x;
	int	y;

	y = 0;
	while (y < data->height)
	{
		x = 0;
		while (x < data->width)
		{
			if (x < data->width - 1)
				bresenham(x, y, x + 1, y, data);
			//	bresenham(line); //If we can use less arguments //
			if (y < data->height - 1)
				bresenham(x, y, x, y + 1, data);
			//	bresenham(line); // If we can use less arguments //
			x++;
		}
		y++;
	}
}
*/
