/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sentry <sentry@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/12 17:11:10 by atang             #+#    #+#             */
/*   Updated: 2024/01/15 22:28:49 by sentry           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

/*
Helper function that take a file name and checks if it exists. It tries to 
open the specified file in read-only mode using fopen() and returns 1 if the 
file exists, otherwise it returns 0. It then closes the file using fclose().
*/


int	file_exists(char *file_name)
{
	FILE	*file;

	file = fopen(file_name, "r");
	if (file != NULL)
	{
		fclose(file);
		return (1);
	}
	return (0);
}

/*
Helper function that checks if a given file name has the correct format i.e. 
.fdf. 1 is returned if the file name is invalid, 0 if valid. Length of file name 
is calculated using ft_strlen() before the last four characters of the file name 
are checked to ensure they are the correct .fdf format using ft_strn_cmp().
*/

int	ft_file_name_error(char	*file_name)
{
	size_t	file_name_len;

	file_name_len = ft_strlen(file_name);
	if (ft_strncmp(&file_name[file_name_len - 4], ".fdf", 4))
		return (1);
	return (0);
}

/*
Helper function which destroys the window specified by the win_ptr,
frees the memory allocated for mlx_ptr and data, then exits the program.
*/
void	handle_exit(t_fdf *data)
{
	mlx_destroy_window(data->mlx_ptr, data->win_ptr);
	free(data->mlx_ptr);
	free(data);
	exit(1);
}
