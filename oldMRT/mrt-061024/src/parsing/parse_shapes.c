/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_shapes.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atang <atang@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/11 18:00:19 by atang             #+#    #+#             */
/*   Updated: 2024/10/06 16:14:41 by atang            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

int add_object(Scene *scene, Object *new_object)
{
    printf("Entering add_object function. Adding new object of type: %d\n", new_object->type);
    
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
    
    // Determine the object type as a string
    const char *object_type_str = "Unknown";

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
        Object *current = scene->objects;
        while (current->next)
        {
            printf("Traversing object list. Current object type: %s\n", 
                   (current->type == SPHERE) ? "SPHERE" : 
                   (current->type == PLANE) ? "PLANE" : 
                   (current->type == CYLINDER) ? "CYLINDER" : "Unknown");
            current = current->next;
        }
        current->next = new_object;
        printf("Object of type %s added to the end of the scene's object list.\n", object_type_str);
    }
    
    scene->object_count++;
    printf("Object added. New count: %d\n", scene->object_count);

    // Print the full list of objects
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

    return 1; // Indicate success
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
    printf(G "Entering" RST " parse_sphere...\n");
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
	printf("   Parsed diameter: %f\n", new_sphere->data.sphere.diameter);
    token = strtok(NULL, " \t\n"); // Get the colour
    if (!token || !parse_colour(token, &new_sphere->data.sphere.colour))
	{
		printf(RED "Exiting" RST " parse_sphere...\n");
		return free_and_return(new_sphere, 0);
	}
	printf(Y "Sphere parsed and added successfully.\n" RST);
	printf(RED "Exiting" RST " parse_sphere...\n");
    return add_object(scene, new_sphere);
}

int parse_plane(char *line, Scene *scene)
{
    printf(G "Entering" RST " parse_plane...\n");

    (void)line;  // Assuming you handle line parsing elsewhere
    Object *new_plane = malloc(sizeof(Object));
    char *token;

    if (!new_plane) {
        printf(RED "Error: Memory allocation failed for plane object.\n" RST);
        return 0;
    }

    // Set object type and initialize its next pointer
    new_plane->type = PLANE;
    new_plane->next = NULL;

    // Parse point
    token = strtok(NULL, " \t\n");  // Get the point
    if (!token || !parse_vector3(token, &new_plane->data.plane.point)) {
        printf(RED "Error: Failed to parse point for plane.\n" RST);
        return free_and_return(new_plane, 0);  // Free memory on failure
    }

    // Parse normal
    token = strtok(NULL, " \t\n");  // Get the normal
    if (!token || !parse_vector3(token, &new_plane->data.plane.normal)) {
        printf(RED "Error: Failed to parse normal for plane.\n" RST);
        return free_and_return(new_plane, 0);  // Free memory on failure
    }

    // Parse colour
    token = strtok(NULL, " \t\n");  // Get the colour
    if (!token || !parse_colour(token, &new_plane->data.plane.colour)) {
        printf(RED "Error: Failed to parse colour for plane.\n" RST);
        return free_and_return(new_plane, 0);  // Free memory on failure
    }

    // Add the new object to the scene
    if (!add_object(scene, new_plane)) {
        printf(RED "Error: Failed to add plane to the scene.\n" RST);
        return free_and_return(new_plane, 0);  // Free memory if adding fails
    }

    // If everything is successful, print a success message
    printf(Y "Plane parsed and added successfully.\n" RST);
    printf(RED "Exiting" RST " parse_plane...\n");
    
    return 1;  // Return success
}

int parse_cylinder(char *line, Scene *scene)
{
    printf(G "Entering" RST " parse_cylinder...\n");
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
	printf("   Parsed diameter: %f\n", new_cylinder->data.cylinder.diameter);
    token = strtok(NULL, " \t\n"); // Get the height
    if (!token || !(new_cylinder->data.cylinder.height = parse_float(&token)))
        return free_and_return(new_cylinder, 0);
	printf("   Parsed height: %f\n", new_cylinder->data.cylinder.height);
    token = strtok(NULL, " \t\n"); // Get the colour
    if (!token || !parse_colour(token, &new_cylinder->data.cylinder.colour))
	{
		printf(RED "Exiting" RST " parse_cylinder...\n");
        return free_and_return(new_cylinder, 0);
	}
	printf(Y "Cylinder parsed and added successfully.\n" RST);
    printf(RED "Exiting" RST " parse_cylinder...\n");
    add_object(scene, new_cylinder);
	return (1);
}

// Helper function to free object and return 0
int free_and_return(Object *obj, int ret_val)
{
    free(obj);
    return ret_val;
}
