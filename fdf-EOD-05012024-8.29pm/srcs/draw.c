/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atang <atang@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/01 13:15:56 by atang             #+#    #+#             */
/*   Updated: 2024/01/05 20:26:15 by atang            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"
#include <math.h>

#define MAX(a, b) (a > b ? a : b)
#define MOD(a) ((a < 0) ? -a : a)

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

float	mod(float i)
{
	return (i < 0) ? -i : i;
}

void	isometric(float	*x, float *y, int z)
{
	*x = (*x - *y) * cos(0.8);
	*y = (*x + *y) * sin(0.8) - z;
}

/*
This function is designed to join two points.
*/
void	bresenham(float x, float y, float x1, float y1, t_fdf *data) // e.g. [1:1] [3:12]
{
	float	x_step;
	float	y_step;
	int		max;
	int		z;
	int		z1;

	//colour depends on the z co-ordinate so we get z from the map.
	z = data->z_matrix[(int)y][(int)x];
	z1 = data->z_matrix[(int)y1][(int)x1];

	// ---ZOOM---
	x *= data->zoom;
	y *= data->zoom;
	x1 *= data->zoom;
	y1 *= data->zoom;
	// ---COLOUR---
	data->colour = (z || z1) ? 0xe80c0c : 0xffffff;
	// ---3D---
	isometric(&x, &y, z);
	isometric(&x1, &y1, z1);
	// ---SHIFT---
	/*
	x += 50;
	y += 50;
	x1 += 50;
	y1 += 50;
	*/
	// To move around with keys
	x += data->shift_x;
	y += data->shift_y;
	x1 += data->shift_x;
	y1 += data->shift_y;
	x_step = x1 - x; // -2 
	y_step = y1 - y; // -11 
	// Instead of increasing x by 1 and y by about 5 times as much,
	// we can increase y by 1 and x by 5 times less.
	max = MAX(MOD(x_step), MOD(y_step)); // Finding the maximum by absolute value without sign
	x_step /= max; // Divide x-step and y-step by maximum of themselves
	y_step /= max; // Divide x-step and y-step by maximum of themselves
	// We stop this loop when x1 reaches x2 and y1 reaches y2, int cos it stops when it is close
	while ((int)(x -x1) || (int)(y - y1))
	{
		// Using my_mlx_pixel_put instead of Nick V's standard mlx_pixel_put
		// my_mlx_pixel_put(data->mlx_ptr, x, y, data->colour);
		mlx_pixel_put(data->mlx_ptr, data->win_ptr, x, y, data->colour);
		// Increase x and y for every step of the loop  
		x += x_step;
		y += y_step;
	}
}

/*
3. Function which draws lines between every dot
- example:
	0->		0->		0->		0
	|		|		|		|
	
	0->		10->	10->	0
	|		|		|		|

	0->		10->	10->    0
	|		|		|		|

	0->		0->		0->		0
'->' and '|'are lines between dots 
every dot has two lines (right and down):	0->
											|
*/

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
				bresenham(x, y, x + 1, y, data); // L to R line
			if (y < data->height - 1)
				bresenham(x, y, x, y + 1, data); // T to B linelen
			x++;
		}
		y++;
	}
}
