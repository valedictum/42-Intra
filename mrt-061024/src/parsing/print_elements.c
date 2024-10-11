/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_elements.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atang <atang@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/11 12:01:41 by atang             #+#    #+#             */
/*   Updated: 2024/10/11 16:36:02 by atang            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

void	print_ambient_light(t_AmbientLight *ambient)
{
	printf(B "\nAmbient Light:\n\n" RST);
	printf("  Ratio: %f\n", ambient->ratio);
	printf("  Colour: %d, %d, %d\n\n", ambient->colour.r,
		ambient->colour.g, ambient->colour.b);
}

void	print_camera(const t_Camera *camera)
{
	printf(Y "Camera:\n\n" RST);
	printf("  Position: %f, %f, %f\n", camera->position.x, camera->position.y,
		camera->position.z);
	printf("  Orientation: %f, %f, %f\n", camera->orientation.x,
		camera->orientation.y, camera->orientation.z);
	printf("  FOV: %f\n\n", camera->fov);
}

void	print_light(const t_Light *light)
{
	printf(M "Light:\n\n" RST);
	printf("  Position: %f, %f, %f\n", light->position.x, light->position.y,
		light->position.z);
	printf("  Brightness: %f\n", light->brightness);
	printf("  Colour: %d, %d, %d\n\n", light->colour.r, light->colour.g,
		light->colour.b);
}
