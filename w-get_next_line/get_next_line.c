/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atang <atang@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/21 14:48:14 by atang             #+#    #+#             */
/*   Updated: 2023/08/26 17:45:35 by atang            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h" 

char	*extract_line(char **stash)
{
	char	*line;
	char	*line_end;
	char	*new_stash;

	line = NULL;
	line_end = *stash;
	while (*line_end != '\0' && *line_end != '\n')
		line_end++;
	if (*line_end == '\n')
	{
		*line_end = '\0';
		line = ft_strdup(*stash);
		new_stash = ft_strdup(line_end + 1);
		free(*stash);
		*stash = new_stash;
	}
	else if (*line_end == '\0')
	{
		free(*stash);
		*stash = NULL;
	}
	return (line);
}

char	*read_from_fd(int fd)
{
	char		*buffer;
	ssize_t		bytes_read;

	buffer = (char *)malloc(sizeof(char) * (BUFFER_SIZE + 1));
	if (!buffer)
		return (NULL);
	bytes_read = read(fd, buffer, BUFFER_SIZE);
	if (bytes_read == -1)
	{
		free(buffer);
		return (NULL);
	}
	buffer[bytes_read] = '\0';
	return (buffer);
}

char	*get_next_line(int fd)
{
	static char	*stash;
	char		*temp_stash;
	char		*line_being_read;
	char		*line;

	if (fd < 0 || BUFFER_SIZE <= 0 || read(fd, NULL, 0) < 0)
	{
		free(stash);
		stash = NULL;
		return (NULL);
	}
	if (!stash)
		stash = ft_strdup("");
	line = extract_line(&stash);
	if (line)
		return (line);
	line_being_read = read_from_fd(fd);
	if (!line_being_read)
	{
		line = ft_strdup(stash);
		free(stash);
		stash = NULL;
		return (NULL);
	}
	temp_stash = ft_strjoin(stash, line_being_read);
	free(stash);
	stash = temp_stash;
	free(line_being_read); 
	return (get_next_line(fd));
}

/* 
//Call `get_next_line()` with a file descriptor
	//Declare a static variable `stash` to hold the leftovers after a line 
	is extracted
	//Declare a variable to store the current data that was read
	//Declare a variable to store the extracted line in which our function 
	returns

//Check for file descriptor, BUFFER_SIZE, and read() errors

//Account for the first call of the function, where `stash` will be empty
	//Initialise it to an empty string, preparing for an accumulation of 
	characters next read

//If there is a complete line processed, extract it
	//Return the line

//If there is more data to read
	//Append the new data to the stash
	//Call `get_next_line()` again. Possibly use recursion

//If there is no more data to read
	//Return the leftovers from the stash
 */	
