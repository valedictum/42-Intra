/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_file.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atang <atang@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/31 13:05:15 by atang             #+#    #+#             */
/*   Updated: 2024/01/01 19:25:33 by atang            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

/*
1. Read file 
- get height (# lines of text)
- get width (# in lines)
- allocate memory for **int by using width and height - use ft_split
- read file and write number into **int matrx - use ft_split() and atoi()
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

// NICK V VIDEO GET_HEIGHT
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

// NICK_V VIDEO GET_WIDTH
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
// ORIGINAL FILL MATRIX
// NICK V VIDEO FILL_MATRIX
void	fill_matrix(int *data, char *line)
{
	char	**nums;
	int		i;

	(void) data;
	nums = ft_split(line, ' ');
	i = 0;
	while (nums[i])
	{
		data[i] = ft_atoi(nums[i]);
		free(nums[i]);
		i++;
	}
	free(nums);
}
*/

// FILL MATRIX THAT SUPERSEDES THE ABOVE USING MALLOC
void fill_matrix(int **data, char *line)
{
    char **nums;
    int i;
    int num_count = 0;

    nums = ft_split(line, ' ');

    // Count the number of elements in nums
    while (nums[num_count])
        num_count++;

    // Dynamically allocate memory for data
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

// NICK V VIDEO READ_FILE
void	read_file(char	*file_name, fdf	*data)
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
