/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sentry <sentry@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/03 13:59:30 by atang             #+#    #+#             */
/*   Updated: 2024/10/19 12:08:01 by sentry           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

size_t	ft_strlen(const char *s)
{
	int	i;

	i = 0;
	while (s[i] != '\0')
		i++;
	return (i);
}

int	ft_strncmp(const char *s1, const char *s2, size_t n)
{
	unsigned char	u1;
	unsigned char	u2;

	while (n > 0)
	{
		if (*s1 != *s2)
		{
			u1 = (unsigned char)*s1;
			u2 = (unsigned char)*s2;
			return (u1 - u2);
		}
		if (*s1 == '\0' && *s2 == '\0')
		{
			break ;
		}
		s1++;
		s2++;
		n--;
	}
	return (0);
}

int	err_free_exit(struct Object *current, t_Scene *scene)
{
	struct Object	*next;
	struct Object	*object;

	if (scene && scene->mlx.mlx_ptr && scene->mlx.win_ptr)
	{
		mlx_destroy_window(scene->mlx.mlx_ptr, scene->mlx.win_ptr);
	}
	if (current)
	{
		free(current);
		current = NULL;
	}
	if (scene && scene->objects)
	{
		object = scene->objects;
		while (object)
		{
			next = object->next;
			free(object);
			object = next;
		}
		scene->objects = NULL;
	}
	free(scene);
	exit(1);
}

int	err_return(const char *message)
{
	printf(RED "\nError! %s\n\n" RST, message);
	return (FAILURE);
}

int err_exit(t_Error error)
{
    printf(RED "\nError! ");
	if (error == 0)
		printf("Invalid float value\n\n");
    else if (error == 1)
        printf("Invalid integer value\n\n");
	else if (error == 2)
        printf("Invalid vector value\n\n");
	else if (error == 3)
        printf("Missing input value(s)\n\n");
	else if (error == 4)
        printf("Colour value outside of range (0 to 255)\n\n");
	else if (error == 5)
        printf("Ambient light ratio outside of range (0.0 to 1.0)\n\n");
    else if (error == 6)
        printf("Light brightness ratio outside of range (0.0 to 1.0)\n\n"); 
	else if (error == 7)
        printf("Camera FOV outside of range (0 to 180)\n\n");
	printf("Exiting...\n\n" RST);
	exit(1);
}
