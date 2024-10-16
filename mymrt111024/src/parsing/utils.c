/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atang <atang@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/03 13:59:30 by atang             #+#    #+#             */
/*   Updated: 2024/10/16 18:16:03 by atang            ###   ########.fr       */
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

int	err_ret(const char *error_message)
{
	printf("Error - %s\n", error_message);
	return (0);
}

/*
int	free_and_return(struct Object *obj, int ret_val)
{
	free(obj);
	return (ret_val);
}
*/

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

void	err_exit(const char *message)
{
	printf(RED "\nError! %s\nExiting...\n\n" RST, message);
	exit (1);
}
