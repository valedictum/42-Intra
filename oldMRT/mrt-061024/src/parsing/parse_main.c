/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_main.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atang <atang@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/04 14:44:24 by atang             #+#    #+#             */
/*   Updated: 2024/10/06 16:14:42 by atang            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

static void print_ambient_light(const AmbientLight *ambient)
{
    printf(B "\nAmbient Light:\n\n" RST);
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

void print_sphere(const Object *object)
{
    if (object->type != SPHERE) return;

    printf(C "Sphere:\n\n" RST);
    printf("  Center: %f, %f, %f\n", 
        object->data.sphere.centre.x, 
        object->data.sphere.centre.y, 
        object->data.sphere.centre.z);
    printf("  Diameter: %f\n", object->data.sphere.diameter);
    printf("  Colour: %d, %d, %d\n\n", 
        object->data.sphere.colour.r, 
        object->data.sphere.colour.g, 
        object->data.sphere.colour.b);
}

static void print_plane(const Object *object)
{
    if (object->type != PLANE) return;

    printf(G "Plane:\n\n" RST);
    printf("  Point: %f, %f, %f\n", 
        object->data.plane.point.x, 
        object->data.plane.point.y, 
        object->data.plane.point.z);
    printf("  Normal: %f, %f, %f\n", 
        object->data.plane.normal.x, 
        object->data.plane.normal.y, 
        object->data.plane.normal.z);
    printf("  Colour: %d, %d, %d\n\n", 
        object->data.plane.colour.r, 
        object->data.plane.colour.g, 
        object->data.plane.colour.b);
}

static void print_cylinder(const Object *object)
{
    if (object->type != CYLINDER) return;

    printf(Y "Cylinder:\n\n" RST);
    printf("  Center: %f, %f, %f\n", 
        object->data.cylinder.centre.x, 
        object->data.cylinder.centre.y, 
        object->data.cylinder.centre.z);
    printf("  Axis: %f, %f, %f\n", 
        object->data.cylinder.axis.x, 
        object->data.cylinder.axis.y, 
        object->data.cylinder.axis.z);
    printf("  Diameter: %f\n", object->data.cylinder.diameter);
    printf("  Height: %f\n", object->data.cylinder.height);
    printf("  Colour: %d, %d, %d\n\n", 
        object->data.cylinder.colour.r, 
        object->data.cylinder.colour.g, 
        object->data.cylinder.colour.b);
}

static void print_all_objects(const Scene *scene)
{
    Object *current = scene->objects;

    printf(G "\nEntering" RST " print_all_objects...\n\n");
    printf("Number of objects in scene: %d\n\n", scene->object_count);
    
    if (!current) {
        printf("No objects in the scene.\n\n");
    }

    int position = 1; // Initialize position counter
    while (current)
    {
        printf("Object list position: %d\n", position); // Print position
        printf("Printing object of type: ");
        
        if (current->type == SPHERE)
        {
            printf("SPHERE\n");
            print_sphere(current);
        }
        else if (current->type == PLANE)
        {
            printf("PLANE\n");
            print_plane(current);
        }
        else if (current->type == CYLINDER)
        {
            printf("CYLINDER\n");
            print_cylinder(current);
        }
        else
        {
            printf("Unknown object type\n");
        }
        
        current = current->next;
        position++; // Increment position counter
    }
    
    printf(RED "Exiting" RST " print_all_objects...\n");
}

/*
	parse_rt_file()
	Manages file operations and calls parse_line() for each line read from the 
	file
*/

int parse_rt_file(const char *filename, Scene *scene)
{
    int     fd;
    char    *line;
    int     result;

	scene->objects = NULL;
    scene->object_count = 0;
	printf(B "\nStarting parse_rt()...\n" RST);
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
			printf("get_next_line returned NULL.\n");
            result = 0;
            free(line);
            break ;
        }
		printf("Read line: %s\n", line); 
        // Process the line
        if (!parse_line(line, scene)) // parse_line failure
        {
            result = 0;
			printf("Error parsing line: %s\n", line);
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
	print_all_objects(scene);
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
    printf("\nParsing line with token: %s\n", token);
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
			return (parse_sphere(line, scene));
		else if (strcmp(token, "pl") == 0)
			return (parse_plane(line, scene));
		else if (strcmp(token, "cy") == 0)
			return (parse_cylinder(line, scene));
	}
	else
	{
		printf(RED "Error\nUnknown identifier: %s\n\n" RST, token);
		return (0);
	}
	return (0);
}
