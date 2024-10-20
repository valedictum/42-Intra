/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_objects.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atang <atang@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/11 12:12:23 by atang             #+#    #+#             */
/*   Updated: 2024/10/11 16:53:00 by atang            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

void	print_sphere(const struct Object *object)
{
	if (object->type != SPHERE)
		return ;
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

void	print_plane(const struct Object *object)
{
	if (object->type != PLANE)
		return ;
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

void	print_cylinder(const struct Object *object)
{
	if (object->type != CYLINDER)
		return ;
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

void	print_all_objects(const t_Scene *scene)
{
	struct Object	*current;
	int				position;

	current = scene->objects;
	printf(G "\nEntering" RST " print_all_objects...\n\n");
	printf("Number of objects in scene: %d\n\n", scene->object_count);
	if (!current)
		printf("No objects in the scene.\n\n");
	position = 1;
	while (current)
	{
		printf("Object list position: %d\n", position);
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
			printf("Unknown object type\n");
		current = current->next;
		position++;
	}
	printf(RED "Exiting" RST " print_all_objects...\n");
}
