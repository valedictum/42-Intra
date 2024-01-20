/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atang <atang@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/12 17:11:10 by atang             #+#    #+#             */
/*   Updated: 2024/01/19 18:29:32 by atang            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

/*
Helper function that checks is a file with a given name exists. Fn opens the
file in read only mode with fopen. If successfully opened (i.e. != NULL, it 
means the file exists). Fn then closes file using fclose and returns 1 to 
indicate the file exists (returns 0 if file does not exist). 
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
are checked to ensure they are the correct .fdf format using ft_strn_cmp()
*/

int	file_name_error(char	*file_name)
{
	size_t	file_name_len;

	file_name_len = ft_strlen(file_name);
	if (ft_strncmp(&file_name[file_name_len - 4], ".fdf", 4))
		return (1);
	return (0);
}

/*
Helper function which destroys the window specified by the win_ptr,
frees the memory allocated for data, then exits the program 
*/

void	handle_exit(t_fdf *data)
{
	mlx_destroy_window(data->mlx_ptr, data->win_ptr);
	free(data);
	exit(1);
}
