/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_main.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atang <atang@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/04 14:44:24 by atang             #+#    #+#             */
/*   Updated: 2024/08/11 17:09:53 by atang            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"


/*
	parse_rt_file()
	Manages file operations and calls parse_line() for each line read from the 
	file
*/

int	parse_rt_file(const char	*filename, Scene	*scene)
{
	int		fd;
	char	*line;
	int		result;

	fd = open(filename, O_RDONLY);
	if (fd == -1)
	{
		printf("Error\nCould not open file: %s\n", filename);
		return (0);
	}
	scene->object_count = 0;
	line = get_next_line(fd);
	result = 1;
	while (line != NULL)
	{
		if (!parse_line(line, scene)) // parse_line failure
		{
			result = 0;
			free(line);
			break ;
		}
		free(line);
		line = get_next_line(fd);
	}
	close(fd);
	return (result); // success == 1 , failure == 0
}


/*
	parse_line()
	Handles the parsing of scene elements and objects, checking for valid
	idetifiers and managing object count
*/

int	parse_line(char	*line, Scene	*scene)
{
	char	*token;

	token = strtok(line, " \t\n"); // split the line into tokens based on " ", \t, and \n
	if (!token) // i.e empty line
		return (1); // line is valid but no content to parse
	if (strcmp(token, "A") == 0)
		return (parse_ambient_light(line, &scene->ambient_light));
	else if (strcmp(token, "C") == 0)
		return (parse_camera(line, &scene->camera));
	else if (strcmp(token, "L") == 0)
		return (parse_light(line, &scene->light));
	if (strcmp(token, "sp") == 0 || strcmp(token, "pl") == 0 ||
		strcmp(token, "cy") == 0)
	{
		if (scene->object_count >= MAX_OBJECTS)
		{
			printf("Error\nExceeded maximum number of objects\n");
			return (0);
		}
		if (strcmp(token, "sp") == 0)
			return (parse_sphere(line, &scene->objects[scene->object_count++]));
		else if (strcmp(token, "pl") == 0)
			return (parse_plane(line, &scene->objects[scene->object_count++]));
		else if (strcmp(token, "cy") == 0)
			return (parse_cylinder(line, &scene->objects[scene->object_count++]));
	}
	else
	{
		printf("Error\nUnknown identifier: %s\n", token);
		return (0);
	}
}
