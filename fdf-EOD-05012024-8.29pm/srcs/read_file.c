/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_file.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atang <atang@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/31 13:05:15 by atang             #+#    #+#             */
/*   Updated: 2024/01/05 20:26:19 by atang            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

/*
Used below to calculate width (# of elements in line)
*/

static int	count_words(char const *s, char c)
{
	int	count;
	int	in_word_flag;

	count = 0;
	in_word_flag = 0;
	if (s == NULL)
	{
		return (0);
	}
	while (*s != '\0')
	{
		if (*s == c)
			in_word_flag = 0;
		else if (in_word_flag == 0)
		{
			in_word_flag = 1;
			count++;
		}
		s++;
	}
	return (count);
}

/*
--- get_height() ---
-> Takes a file name and returns the # of lines in the file.
- the specified file_name is opened in read-only mode before
get_next_line() is used to read each line of the file, height++
- line is then freed and once all line shave been read, the file
is closed and height (# of lines) is returned 
*/

int	get_height(char	*file_name)
{
	char	*line;
	int		fd;
	int		height;

	line = NULL;
	fd = open(file_name, O_RDONLY, 0);
	height = 0;
	while (get_next_line(fd, &line))
	{
		height++;
		free(line);
	}
	close (fd);
	return (height);
}

/*
--- get_width() ---
-> Takes a file name and returns the # of elements in the first 
line of the file.
- the specified file_name is opened in read-only mode before
get_next_line() is used to read the first line of the file and 
stores it in 'line'
- count_words() is called to count the # of 'words' in line
- memory allocated for line is freed, the file is closed using 
the fd, and the # of words counted is returned as the width of the 
file
*/

int	get_width(char	*file_name)
{
	char	*line;
	int		fd;
	int		width;

	line = NULL;
	fd = open(file_name, O_RDONLY, 0);
	get_next_line(fd, &line);
	width = count_words(line, ' ');
	free(line);
	close(fd);
	return (width);
}

/*
--- fill_matrix() ---
-> Takes in a double pointer to an integer (**data) and a string 
(*line) to fill the memory pointed at by 'data' with integers parsed 
from the string 'line'
- the string (line) is split into an array of strings using ft_split()
with the resulting array stored in nums before the # of elements in 
nums is counted and stored in num_count
- memory is allocated for *data to store 'num_count' # of integers
(with memory allocation check)
- each element of nums is then looped through and converted to an int
using ft_atoi() and stored in the the *data array
- memory for the current element in nums is then freed and the loop 
continues until all elements in nums have been processed before 
the memory for the nums itself is freed
*/

void	fill_matrix(int **data, char *line)
{
	char	**nums;
	int		i;
	int		num_count;

	num_count = 0;
	nums = ft_split(line, ' ');
	while (nums[num_count])
		num_count++;
	*data = (int *)malloc(sizeof(int) * num_count);
	if (*data == NULL)
	{
		return ;
	}
	i = 0;
	while (nums[i])
	{
		(*data)[i] = ft_atoi(nums[i]);
		free(nums[i]);
		i++;
	}
	free(nums);
}

/*
--- read_file() ---
-> Reads a file and populates the 'data' structure of type t_fdf with 
the contents of the file.
- get_height() is called to determine # of lines in the file and assigns 
the result to data->height
- get_width() is called to deteermine # of elements in each line of the 
file and assigns the result to data->width
- memory is allocated for a 2D array (z_matrix) to store the data read 
from the file (size determined by height and width from above)
- file is opened for reading and each line of the file is read using 
get_next_line(). Inside this loop, fill_matrix() is called to parse the 
line and populate the i-th row of z_matrix with parased values before 
memory allocated for line is freed, and i is incremented
- file is then closed (once outside of loop) and the i-th row of z_matrix 
is set to NULL to indicate the end of the array.
*/

void	read_file(char	*file_name, t_fdf	*data)
{
	int		fd;
	char	*line;
	int		i;

	line = NULL;
	data->height = get_height(file_name);
	data->width = get_width(file_name);
	data->z_matrix = (int **)malloc (sizeof(int *) * (data->height + 1));
	i = 0;
	while (i <= data->height)
		data->z_matrix[i++] = (int *)malloc(sizeof(int) * (data->width + 1));
	fd = open (file_name, O_RDONLY, 0);
	i = 0;
	while (get_next_line(fd, &line))
	{
		fill_matrix(&data->z_matrix[i], line);
		free(line);
		i++;
	}
	close(fd);
	data->z_matrix[i] = NULL;
}