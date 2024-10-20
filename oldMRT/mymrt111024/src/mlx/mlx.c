/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mlx.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atang <atang@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/13 17:58:17 by atang             #+#    #+#             */
/*   Updated: 2024/10/16 12:32:45 by atang            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

void	initialise_data(t_Scene	*scene)
{
	scene->mlx.amplify = 1;
	scene->mlx.mlx_ptr = mlx_init();
	scene->mlx.win_ptr = mlx_new_window(scene->mlx.mlx_ptr, 1024, 768,
			"miniRT");
	scene->mlx.img_ptr = mlx_new_image(scene->mlx.mlx_ptr, 1024, 768);
	//data->img_data = (unsigned int *)mlx_get_data_addr(data->img_ptr,
	//		&data->bpp, &data->size_line, &data->endian);
	//mlx_hook(data->win_ptr, 17, 0, close_button_hook, data);
	scene->mlx.zoom = 20;
}

int	deal_key(int key, t_Scene *scene)
{
	printf("%d\n", key);
	if (key == 126)
		scene->mlx.shift_y -= 50;
	else if (key == 125)
		scene->mlx.shift_y += 50;
	else if (key == 123)
		scene->mlx.shift_x -= 50;
	else if (key == 124)
		scene->mlx.shift_x += 50;
	else if (key == 53)
		handle_exit(scene);
	return (0);
}

int	close_button_hook(t_Scene *scene)
{
	handle_exit(scene);
	return (0);
}

void	handle_exit(t_Scene *scene)
{
	mlx_destroy_window(scene->mlx.mlx_ptr, scene->mlx.win_ptr);
	printf(RED "\nExiting...\n\n" RST);
	exit(1);
}
