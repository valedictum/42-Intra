/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_elements.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atang <atang@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/11 17:59:55 by atang             #+#    #+#             */
/*   Updated: 2024/10/06 16:14:45 by atang            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

int parse_ambient_light(char *line, AmbientLight *ambient_light)
{
    printf(G "Entering" RST " parse_ambient_light...\n");
    char *token;

    (void) line;
    if (!get_next_token(&token))
        return (0);
    ambient_light->ratio = parse_float(&token);
    if (ambient_light->ratio < 0.0f || ambient_light->ratio > 1.0f)
        return (err_ret("   Ambient light ratio out of range (0.0 to 1.0)"));
    printf("   Parsed ratio: %f\n", ambient_light->ratio);
    
    if (!get_next_token(&token))
        return (0);
    printf("   Color token: %s\n", token);
    parse_colour(token, &ambient_light->colour);
    //printf("   Parsed colour: R = %d, G = %d, B = %d\n", ambient_light->colour.r, ambient_light->colour.g, ambient_light->colour.b);
    
    printf(RED "Exiting" RST " parse_ambient_light...\n");
    return (1);
}

int parse_camera(char *line, Camera *camera)
{
    printf(G "Entering" RST " parse_camera...\n");
    char *token;
	(void)line;
    
    // Parse position
    if (!get_next_token(&token))
        return (printf("   Failed to get X position for camera\n"), 0);
    camera->position.x = atof(token);
    if (!get_next_token(&token))
        return (printf("   Failed to get Y position for camera\n"), 0);
    camera->position.y = atof(token);
    if (!get_next_token(&token))
        return (printf("   Failed to get Z position for camera\n"), 0);
    camera->position.z = atof(token);
    printf("   Parsed position: x = %f, y = %f, z = %f\n", camera->position.x, camera->position.y, camera->position.z);
    
    // Parse orientation
    if (!get_next_token(&token))
        return (printf("   Failed to get X orientation for camera\n"), 0);
    camera->orientation.x = atof(token);
    if (!get_next_token(&token))
        return (printf("   Failed to get Y orientation for camera\n"), 0);
    camera->orientation.y = atof(token);
    if (!get_next_token(&token))
        return (printf("   Failed to get Z orientation for camera\n"), 0);
    camera->orientation.z = atof(token);
    printf("   Parsed orientation: x = %f, y = %f, z = %f\n", camera->orientation.x, camera->orientation.y, camera->orientation.z);
    
    // Parse FOV
    if (!get_next_token(&token))
        return (printf("   Failed to get FOV for camera\n"), 0);
    camera->fov = atof(token);
    printf("   Parsed FOV: %f\n", camera->fov);
    
    if (camera->fov < 0 || camera->fov > 180)
        return (printf("   Camera FOV out of range (0 to 180)\n"), 0);
    
    printf(RED "Exiting" RST " parse_camera...\n");
    return 1;
}

int	parse_light(char *line, Light *light)
{
	printf(G "Entering" RST " parse_light...\n");
	char	*token;

	(void) line;
	if (!get_next_token(&token))
		return (0);
	parse_vector3(token, &light->position);
	if (!get_next_token(&token))
		return (0);
	light->brightness = parse_float(&token);
	if (light->brightness < 0.0f || light->brightness > 1.0f)
		return (err_ret("Light brightness ratio out of range (0.0 to 1.0)"));
	if (!get_next_token(&token))
		return (0);
	parse_colour(token, &light->colour);
	printf(RED "Exiting" RST " parse_light...\n");
	return (1);
}
