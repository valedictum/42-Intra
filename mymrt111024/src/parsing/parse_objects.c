/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_objects.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atang <atang@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/11 18:00:19 by atang             #+#    #+#             */
/*   Updated: 2024/10/13 19:28:35 by atang            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

/*

--> OLDE VERISON

int	add_object(Scene *scene, Object *new_object)
{
	const char	*object_type_str;
	Object		*current;

    printf("Entering add_object function. Adding new object of type: %d\n",
		new_object->type);
    if (!scene)
    {
        printf("Error: Scene is NULL.\n");
        return 0;
    }
    if (!new_object)
    {
        printf("Error: New object is NULL.\n");
        return 0;
    }
    object_type_str = "Unknown";
    if (new_object->type == SPHERE)
        object_type_str = "SPHERE";
    else if (new_object->type == PLANE)
        object_type_str = "PLANE";
    else if (new_object->type == CYLINDER)
        object_type_str = "CYLINDER";
    if (!scene->objects)
    {
        scene->objects = new_object;
        printf("First object of type %s added to the scene.\n", object_type_str);
    }
    else
    {
        current = scene->objects;
        while (current->next)
        {
            printf("Traversing object list. Current object type: %s\n",
                   (current->type == SPHERE) ? "SPHERE" :
                   (current->type == PLANE) ? "PLANE" :
                   (current->type == CYLINDER) ? "CYLINDER" : "Unknown");
            current = current->next;
        }
        current->next = new_object;
        printf("Object of type %s added to the end of the scene's
			object list.\n", object_type_str);
    }
    scene->object_count++;
    printf("Object added. New count: %d\n", scene->object_count);
    Object *temp = scene->objects;
    printf("Current objects in scene:\n");
    while (temp)
    {
        printf("Object type: %s\n", 
               (temp->type == SPHERE) ? "SPHERE" : 
               (temp->type == PLANE) ? "PLANE" : 
               (temp->type == CYLINDER) ? "CYLINDER" : "Unknown");
        temp = temp->next;
    }
    return 1;
}
*/

/*
static const char	*get_object_type_str(int type)
{
	if (type == SPHERE)
		return ("SPHERE");
	else if (type == PLANE)
		return ("PLANE");
	else if (type == CYLINDER)
		return ("CYLINDER");
	else
		return ("Unknown");
}

static void	print_objects_in_scene(Object	*objects)
{
	Object		*temp;
	const char	*type_str;

	temp = objects;
	printf("Current objects in scene:\n");
	while (temp)
	{
		type_str = get_object_type_str(temp->type);
		printf("Object type: %s\n", type_str);
		temp = temp->next;
	}
}

int	add_object(Scene *scene, Object *new_object)
{
	const char	*object_type_str;
	Object		*current;
	const char	*current_type_str;

	printf("Entering add_object function. Adding new object of type: %d\n",
		new_object->type);
	if (!scene)
	{
		printf("Error: Scene is NULL.\n");
		return (0);
	}
	if (!new_object)
	{
		printf("Error: New object is NULL.\n");
		return (0);
	}
	object_type_str = get_object_type_str(new_object->type);
	if (!scene->objects)
	{
		scene->objects = new_object;
		printf("First object of type %s added to the scene.\n",
			object_type_str);
	}
	else
	{
		current = scene->objects;
		while (current->next)
		{
			current_type_str = get_object_type_str(current->type);
			printf("Traversing object list. Current object type: %s\n",
				current_type_str);
			current = current->next;
		}
		current->next = new_object;
		printf
		("Object of type %s added to the end of the scene's object list.\n",
			object_type_str);
	}
	scene->object_count++;
	printf("Object added. New count: %d\n", scene->object_count);
	print_objects_in_scene(scene->objects);
	return (1);
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
*/

int	parse_sphere(char *line, t_Scene *scene)
{
	struct Object	*new_sphere;
	char			*token;

	(void)line;
	printf(G "Entering" RST " parse_sphere()\n\n");
	new_sphere = malloc(sizeof(struct Object));
	if (!new_sphere)
		return (0);
	new_sphere->type = SPHERE;
	new_sphere->next = NULL;
	token = strtok(NULL, " \t\n");
	if (!token || !parse_vector3(token, &new_sphere->u_data.sphere.centre))
		return (free_and_return(new_sphere, 0));
	token = strtok(NULL, " \t\n");
	new_sphere->u_data.sphere.diameter = parse_float(&token);
	if (!token || !new_sphere->u_data.sphere.diameter)
		return (free_and_return(new_sphere, 0));
	printf("   Parsed diameter: %f\n", new_sphere->u_data.sphere.diameter);
	token = strtok(NULL, " \t\n");
	if (!token || !parse_colour(token, &new_sphere->u_data.sphere.colour))
	{
		printf(RED "Exiting" RST " parse_sphere()\n");
		return (free_and_return(new_sphere, 0));
	}
	if (!add_object(scene, new_sphere))
	{
		printf(RED "Error: Failed to add sphere to the scene.\n" RST);
		return (free_and_return(new_sphere, 0));
	}
	printf(G "   SUCCESS - Sphere parsed and added!\n\n" RST);
	printf(RED "Exiting" RST " parse_sphere()\n");
	return (1);
	//return (add_object(scene, new_sphere));
}

int	parse_plane(char *line, t_Scene *scene)
{
	struct Object	*new_plane;
	char			*token;

	(void)line;
	printf(G "Entering" RST " parse_plane()\n\n");
	new_plane = malloc(sizeof(struct Object));
	if (!new_plane)
	{
		printf(RED "Error: Memory allocation failed for plane object.\n" RST);
		return (0);
	}
	new_plane->type = PLANE;
	new_plane->next = NULL;
	token = strtok(NULL, " \t\n");
	if (!token || !parse_vector3(token, &new_plane->u_data.plane.point))
	{
		printf(RED "Error: Failed to parse point for plane.\n" RST);
		return (free_and_return(new_plane, 0));
	}
	token = strtok(NULL, " \t\n");
	if (!token || !parse_vector3(token, &new_plane->u_data.plane.normal))
	{
		printf(RED "Error: Failed to parse normal for plane.\n" RST);
		return (free_and_return(new_plane, 0));
	}
	token = strtok(NULL, " \t\n");
	if (!token || !parse_colour(token, &new_plane->u_data.plane.colour))
	{
		printf(RED "Error: Failed to parse colour for plane.\n" RST);
		return (free_and_return(new_plane, 0));
	}
	if (!add_object(scene, new_plane))
	{
		printf(RED "Error: Failed to add plane to the scene.\n" RST);
		return (free_and_return(new_plane, 0));
	}
	printf(G "   SUCCESS - Plane parsed and added!\n\n" RST);
	printf(RED "Exiting" RST " parse_plane()\n");
	return (1);
}

int	parse_cylinder(char *line, t_Scene *scene)
{
	struct Object	*new_cylinder;
	char			*token;

	(void)line;
	printf(G "Entering" RST " parse_cylinder()\n\n");
	new_cylinder = malloc(sizeof(struct Object));
	if (!new_cylinder)
		return (0);
	new_cylinder->type = CYLINDER;
	new_cylinder->next = NULL;
	token = strtok(NULL, " \t\n");
	if (!token || !parse_vector3(token, &new_cylinder->u_data.cylinder.centre))
		return (free_and_return(new_cylinder, 0));
	token = strtok(NULL, " \t\n");
	if (!token || !parse_vector3(token, &new_cylinder->u_data.cylinder.axis))
		return (free_and_return(new_cylinder, 0));
	token = strtok(NULL, " \t\n");
	new_cylinder->u_data.cylinder.diameter = parse_float(&token);
	if (!token || !new_cylinder->u_data.cylinder.diameter)
		return (free_and_return(new_cylinder, 0));
	printf("   Parsed diameter: %f\n", new_cylinder->u_data.cylinder.diameter);
	token = strtok(NULL, " \t\n");
	new_cylinder->u_data.cylinder.height = parse_float(&token);
	if (!token || !new_cylinder->u_data.cylinder.height)
		return (free_and_return(new_cylinder, 0));
	printf("   Parsed height: %f\n", new_cylinder->u_data.cylinder.height);
	token = strtok(NULL, " \t\n");
	if (!token || !parse_colour(token, &new_cylinder->u_data.cylinder.colour))
	{
		printf(RED "Exiting" RST " parse_cylinder()\n");
		return (free_and_return(new_cylinder, 0));
	}
	if (!add_object(scene, new_cylinder))
	{
		printf(RED "Error: Failed to add cylinder to the scene.\n" RST);
		return (free_and_return(new_cylinder, 0));
	}
	printf(G "   SUCCESS - Cylinder parsed and added!\n\n" RST);
	printf(RED "Exiting" RST " parse_cylinder()\n");
	//add_object(scene, new_cylinder);
	return (1);
}
