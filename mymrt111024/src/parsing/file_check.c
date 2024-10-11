/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   file_check.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atang <atang@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/03 13:26:47 by atang             #+#    #+#             */
/*   Updated: 2024/10/11 14:03:09 by atang            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

/*
Checks if a file with a given name exists. Fn opens the file in read only mode 
with fopen. If successfully opened, the file exists). Fn then closes file using 
fclose and returns 1 to indicate the file exists (returns 0 if file does not 
exist). 
*/

int	file_exists(char *filename)
{
	FILE	*file;

	file = fopen(filename, "r");
	if (file != NULL)
	{
		fclose(file);
		return (1);
	}
	return (0);
}

/*
Checks if a given file name has the correct format i.e. ".rt". 1 is returned 
if the file name is invalid, 0 if valid. Length of file name is calculated
using ft_strlen() before the last three characters of the file name 
are checked to ensure they are the correct .rt format using ft_strn_cmp()
*/

int	filename_error(char	*filename)
{
	size_t	filename_len;

	filename_len = ft_strlen(filename);
	if (ft_strncmp(&filename[filename_len - 3], ".rt", 3))
		return (1);
	return (0);
}

int	file_empty(const char	*filename)
{
	int		fd;
	char	buffer;
	ssize_t	bytes_read;

	fd = open(filename, O_RDONLY);
	if (fd == -1)
	{
		perror ("\nFailed to open file\n");
		return (-1);
	}
	bytes_read = read(fd, &buffer, 1);
	close(fd);
	if (bytes_read == -1)
	{
		perror("\nFailed to read file\n");
		return (-1);
	}
	if (bytes_read == 0)
	{
		printf(RED "\nFile is empty!\n\n" RST);
		return (1);
	}
	return (0);
}
