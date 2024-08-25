/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_elements.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atang <atang@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/11 17:59:55 by atang             #+#    #+#             */
/*   Updated: 2024/08/18 15:12:49 by atang            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

int	parse_ambient_light(char *line, AmbientLight *ambient_light)
{
	char	*token;

	(void) line;
	if (!get_next_token(&token))
		return (0);
	ambient_light->ratio = parse_float(token, &ambient_light->ratio);
	if (ambient_light->ratio < 0.0f || ambient_light->ratio > 1.0f)
		return (err_ret("Ambient light ratio out of range (0.0 to 1.0)"));
	parse_colour(token, &ambient_light->colour);
	return (1);
}

int	parse_camera(char *line, Camera *camera)
{
	char	*token;

	(void) line;
	if (!get_next_token(&token))
		return (0);
	parse_vector3(token, &camera->position);
	if (!get_next_token(&token))
		return (0);
	parse_vector3(token, &camera->orientation);
	if (camera->orientation.x < -1 || camera->orientation.x > 1 ||
		camera->orientation.y < -1 || camera->orientation.y > 1 ||
		camera->orientation.z < -1 || camera->orientation.z > 1)
		return
			(err_ret("Camera orientation vector ratio out of range (-1 to 1)"));
	if (!get_next_token(&token))
		return (0);
	camera->fov = parse_float(token, &camera->fov);
	if (camera->fov < 0 || camera->fov > 180)
		return (err_ret("Camera FOV out of range (0 to 180)"));
	return (1);
}

int	parse_light(char *line, Light *light)
{
	char	*token;

	(void) line;
	if (!get_next_token(&token))
		return (0);
	parse_vector3(token, &light->position);
	if (!get_next_token(&token))
		return (0);
	light->brightness = parse_float(token, &light->brightness);
	if (light->brightness < 0.0f || light->brightness > 1.0f)
		return (err_ret("Light brightness ratio out of range (0.0 to 1.0)"));
	if (!get_next_token(&token))
		return (0);
	parse_colour(token, &light->colour);
	return (1);
}
