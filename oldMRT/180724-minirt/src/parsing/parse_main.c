/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_main.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atang <atang@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/04 14:44:24 by atang             #+#    #+#             */
/*   Updated: 2024/08/18 14:59:53 by atang            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

static void print_ambient_light(const AmbientLight *ambient)
{
    printf(B "Ambient Light:\n\n" RST);
    printf("  Ratio: %f\n", ambient->ratio);
    printf("  Colour: %d, %d, %d\n\n", ambient->colour.r, ambient->colour.g, ambient->colour.b);
}

static void print_camera(const Camera *camera)
{
    printf(Y "Camera:\n\n" RST);
    printf("  Position: %f, %f, %f\n", camera->position.x, camera->position.y, camera->position.z);
    printf("  Orientation: %f, %f, %f\n", camera->orientation.x, camera->orientation.y, camera->orientation.z);
    printf("  FOV: %f\n\n", camera->fov);
}

static void print_light(const Light *light)
{
    printf(M "Light:\n\n" RST);
    printf("  Position: %f, %f, %f\n", light->position.x, light->position.y, light->position.z);
    printf("  Brightness: %f\n", light->brightness);
	printf("  Colour: %d, %d, %d\n\n", light->colour.r, light->colour.g, light->colour.b);
}

/*
	parse_rt_file()
	Manages file operations and calls parse_line() for each line read from the 
	file
*/

/*
// ORIGINAL THAT HAS GNL ISSUES
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
*/

int parse_rt_file(const char *filename, Scene *scene)
{
    int     fd;
    char    *line;
    int     result;

	printf(G "\nStarting parse_rt()...\n\n" RST);
    fd = open(filename, O_RDONLY);
    if (fd == -1)
    {
        printf("Error\nCould not open file: %s\n", filename);
        return (0);
    }
    scene->object_count = 0;
    result = 1;
    
    while (1)
    {
        // Allocate memory for line
        line = NULL;
        
        // Call get_next_line and handle memory allocation
        if (get_next_line(fd, &line) == NULL)  // Check if line is NULL
        {
            result = 0;
            free(line);
            break ;
        }

        // Process the line
        if (!parse_line(line, scene)) // parse_line failure
        {
            result = 0;
        }
        
        // Free the allocated memory for line
        free(line);

        // Break the loop if end of file or an error occurred
        if (line == NULL)
            break;
    }
    close(fd);
	print_ambient_light(&scene->ambient_light);
    print_camera(&scene->camera);
    print_light(&scene->light);
    return (result); // success == 1 , failure == 0
}

/*
	parse_line()
	Handles the parsing of scene elements and objects, checking for valid
	idetifiers and managing object count
*/

/*
//OG
int	parse_line(char	*line, Scene	*scene)
{
	char	*token;
	int		parse_success;
	Object	*new_object;

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
		new_object = malloc(sizeof(Object));
		if (!new_object)
			return (0);
		parse_success = 0;
		if (strcmp(token, "sp") == 0)
			parse_success = parse_sphere(line, new_object);
		else if (strcmp(token, "pl") == 0)
			parse_success = parse_plane(line, new_object);
		else if (strcmp(token, "cy") == 0)
			parse_success = parse_cylinder(line, new_object);
		 if (!parse_success)
		{
			free(new_object);
			return (0);
		}
		add_object(scene, new_object);
		return (1);
	}
	else
	{
		printf(RED "Error\nUnknown identifier: %s\n\n" RST, token);
		return (0);
	}
}
*/

int parse_line(char *line, Scene *scene)
{
    char *token;

    token = strtok(line, " \t\n"); // Split the line into tokens
    if (!token) // Empty line
        return (1); // Line is valid but no content to parse

    if (strcmp(token, "A") == 0)
        return (parse_ambient_light(line, &scene->ambient_light));
    else if (strcmp(token, "C") == 0)
        return (parse_camera(line, &scene->camera));
    else if (strcmp(token, "L") == 0)
        return (parse_light(line, &scene->light));

    if (strcmp(token, "sp") == 0 || strcmp(token, "pl") == 0 || strcmp(token, "cy") == 0)
    {
        if (scene->object_count >= MAX_OBJECTS)
        {
            printf("Error\nExceeded maximum number of objects\n");
            return (0);
        }

        Object *new_object = malloc(sizeof(Object));
        if (!new_object)
            return (0); // Memory allocation failed

        int parse_success = 0;

        if (strcmp(token, "sp") == 0)
            parse_success = parse_sphere(line, new_object);
        //else if (strcmp(token, "pl") == 0)
        //    parse_success = parse_plane(line, new_object);
        //else if (strcmp(token, "cy") == 0)
        //    parse_success = parse_cylinder(line, new_object);

        if (!parse_success)
        {
            free(new_object); // Free memory if parsing failed
            return (0);
        }

        // Add new object to the scene
        if (!add_object(scene, new_object))
        {
            free(new_object); // Free memory if adding failed
            return (0);
        }

        return (1);
    }
    else
    {
        printf(RED "Error\nUnknown identifier: %s\n\n" RST, token);
        return (0);
    }
}
