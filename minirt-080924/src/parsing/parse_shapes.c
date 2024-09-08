/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_shapes.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atang <atang@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/11 18:00:19 by atang             #+#    #+#             */
/*   Updated: 2024/09/08 14:34:04 by atang            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

int add_object(Scene *scene, Object *new_object)
{
    if (!scene->objects)
    {
        scene->objects = new_object;
    }
    else
    {
        Object *current = scene->objects;
        while (current->next)
            current = current->next;
        current->next = new_object;
    }
    scene->object_count++;
    return 1;
}

void	free_objects(Scene *scene)
{
	Object	*current;
	Object	*next;

	current = scene->objects;
	while (current)
	{
		next = current->next;
		free(current);
		current = next;
	}
	scene->objects = NULL;
	scene->object_count = 0;
}

Object *create_sphere(void)
{
    Object *new_sphere = malloc(sizeof(Object));
    if (!new_sphere)
        return NULL;
    new_sphere->type = SPHERE;
    new_sphere->next = NULL;
    return new_sphere;
}

int parse_sphere(char *line, Scene *scene)
{
	(void)line;
    Object *new_sphere = malloc(sizeof(Object));
    char *token;

    if (!new_sphere)
        return 0;

    new_sphere->type = SPHERE;
    new_sphere->next = NULL;

    token = strtok(NULL, " \t\n"); // Get the centre
    if (!token || !parse_vector3(token, &new_sphere->data.sphere.centre))
        return free_and_return(new_sphere, 0);

    token = strtok(NULL, " \t\n"); // Get the diameter
    if (!token || !(new_sphere->data.sphere.diameter = parse_float(&token)))
        return free_and_return(new_sphere, 0);

    token = strtok(NULL, " \t\n"); // Get the colour
    if (!token || !parse_colour(token, &new_sphere->data.sphere.colour))
        return free_and_return(new_sphere, 0);

    return add_object(scene, new_sphere);
}

int parse_plane(char *line, Scene *scene)
{
	(void)line;
    Object *new_plane = malloc(sizeof(Object));
    char *token;

    if (!new_plane)
        return 0;

    new_plane->type = PLANE;
    new_plane->next = NULL;

    token = strtok(NULL, " \t\n"); // Get the point
    if (!token || !parse_vector3(token, &new_plane->data.plane.point))
        return free_and_return(new_plane, 0);

    token = strtok(NULL, " \t\n"); // Get the normal
    if (!token || !parse_vector3(token, &new_plane->data.plane.normal))
        return free_and_return(new_plane, 0);

    token = strtok(NULL, " \t\n"); // Get the colour
    if (!token || !parse_colour(token, &new_plane->data.plane.colour))
        return free_and_return(new_plane, 0);

    return add_object(scene, new_plane);
}

int parse_cylinder(char *line, Scene *scene)
{
	(void)line;
    Object *new_cylinder = malloc(sizeof(Object));
    char *token;

    if (!new_cylinder)
        return 0;

    new_cylinder->type = CYLINDER;
    new_cylinder->next = NULL;

    token = strtok(NULL, " \t\n"); // Get the centre
    if (!token || !parse_vector3(token, &new_cylinder->data.cylinder.centre))
        return free_and_return(new_cylinder, 0);

    token = strtok(NULL, " \t\n"); // Get the axis
    if (!token || !parse_vector3(token, &new_cylinder->data.cylinder.axis))
        return free_and_return(new_cylinder, 0);

    token = strtok(NULL, " \t\n"); // Get the diameter
    if (!token || !(new_cylinder->data.cylinder.diameter = parse_float(&token)))
        return free_and_return(new_cylinder, 0);

    token = strtok(NULL, " \t\n"); // Get the height
    if (!token || !(new_cylinder->data.cylinder.height = parse_float(&token)))
        return free_and_return(new_cylinder, 0);

    token = strtok(NULL, " \t\n"); // Get the colour
    if (!token || !parse_colour(token, &new_cylinder->data.cylinder.colour))
        return free_and_return(new_cylinder, 0);

    return add_object(scene, new_cylinder);
}

// Helper function to free object and return 0
int free_and_return(Object *obj, int ret_val)
{
    free(obj);
    return ret_val;
}

/*
// SECOND LOT
int parse_sphere(char *line, Object *new_object)
{
    Object *new_sphere;
    char *token;
	(void) line;

    new_sphere = malloc(sizeof(Object));
    if (!new_sphere)
        return (0);
    new_sphere->type = SPHERE;
    new_sphere->next = NULL;

    if (!get_next_token(&token))
        return (0);
    parse_vector3(token, &new_sphere->data.sphere.centre);

    if (!get_next_token(&token))
        return (0);
    new_sphere->data.sphere.diameter = parse_float(&token);

    if (!get_next_token(&token))
        return (0);
    parse_colour(token, &new_sphere->data.sphere.colour);

    return (add_object(scene, new_sphere));
}

int parse_plane(char *line, Scene *scene)
{
    Object *new_plane;
    char *token;
	(void) line;

    new_plane = malloc(sizeof(Object));
    if (!new_plane)
        return (0);
    new_plane->type = PLANE;
    new_plane->next = NULL;

    if (!get_next_token(&token))
        return (0);
    parse_vector3(token, &new_plane->data.plane.point);

    if (!get_next_token(&token))
        return (0);
    parse_vector3(token, &new_plane->data.plane.normal);

    if (!get_next_token(&token))
        return (0);
    parse_colour(token, &new_plane->data.plane.colour);

    return (add_object(scene, new_plane));
}

int parse_cylinder(char *line, Scene *scene)
{
    Object *new_cylinder;
    char *token;
	(void) line;

    new_cylinder = malloc(sizeof(Object));
    if (!new_cylinder)
        return (0);
    new_cylinder->type = CYLINDER;
    new_cylinder->next = NULL;

    if (!get_next_token(&token))
        return (0);
    parse_vector3(token, &new_cylinder->data.cylinder.centre);

    if (!get_next_token(&token))
        return (0);
    parse_vector3(token, &new_cylinder->data.cylinder.axis);

    if (!get_next_token(&token))
        return (0);
    new_cylinder->data.cylinder.diameter = parse_float(&token);

    if (!get_next_token(&token))
        return (0);
    new_cylinder->data.cylinder.height = parse_float(&token);

    if (!get_next_token(&token))
        return (0);
    parse_colour(token, &new_cylinder->data.cylinder.colour);

    return (add_object(scene, new_cylinder));
}
*/

/*
int parse_plane(char *line, Object *new_object)
{
    char *token;

    new_object->type = PLANE;
    new_object->next = NULL;

    token = strtok(NULL, " \t\n"); // Get the point
    if (!token || !parse_vector3(token, &new_object->data.plane.point))
        return (0);

    token = strtok(NULL, " \t\n"); // Get the normal
    if (!token || !parse_vector3(token, &new_object->data.plane.normal))
        return (0);

    token = strtok(NULL, " \t\n"); // Get the colour
    if (!token || !parse_colour(token, &new_object->data.plane.colour))
        return (0);

    return (1);
}

int parse_cylinder(char *line, Object *new_object)
{
    char *token;

    new_object->type = CYLINDER;
    new_object->next = NULL;

    token = strtok(NULL, " \t\n"); // Get the centre
    if (!token || !parse_vector3(token, &new_object->data.cylinder.centre))
        return (0);

    token = strtok(NULL, " \t\n"); // Get the axis
    if (!token || !parse_vector3(token, &new_object->data.cylinder.axis))
        return (0);

    token = strtok(NULL, " \t\n"); // Get the diameter
    if (!token || !parse_float(token, &new_object->data.cylinder.diameter))
        return (0);

    token = strtok(NULL, " \t\n"); // Get the height
    if (!token || !parse_float(token, &new_object->data.cylinder.height))
        return (0);

    token = strtok(NULL, " \t\n"); // Get the colour
    if (!token || !parse_colour(token, &new_object->data.cylinder.colour))
        return (0);

    return (1);
}
*/

/*
int parse_sphere(char *line, Object *new_object)
{
    char *token;
	(void) line;

    new_object->type = SPHERE;
    new_object->next = NULL;

    token = strtok(NULL, " \t\n"); // Get the centre
    if (!token)
        return (0);
	parse_vector3(token, &new_object->data.sphere.centre)	;
    token = strtok(NULL, " \t\n"); // Get the diameter
    if (!token)
        return (0);
	parse_float(token, &new_object->data.sphere.diameter);
    token = strtok(NULL, " \t\n"); // Get the colour
    if (!token)
        return (0);
	parse_colour(token, &new_object->data.sphere.colour);
    return (1);
}
*/
