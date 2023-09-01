/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atang <atang@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/21 14:48:14 by atang             #+#    #+#             */
/*   Updated: 2023/09/01 17:40:26 by atang            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h" 

char	*extract_completed_line(char **stash)
{
	char	*extracted_line;
	char	*line_terminator;
	char	*remaining_stash;

	extracted_line = NULL;
	line_terminator = *stash;
	while (*line_terminator != '\0' && *line_terminator != '\n')
		line_terminator++;
	if (*line_terminator == '\n')
	{
		*line_terminator = '\0';
		extracted_line = gnl_strdup(*stash);
		remaining_stash = gnl_strdup(line_terminator + 1);
		free(*stash);
		*stash = remaining_stash;
	}
	else if (*line_terminator == '\0')
	{
		free(*stash);
		*stash = NULL;
	}
	return (extracted_line);
}

char	*read_from_fd(int fd)
{
	char	*read_buffer;
	int		bytes_read;

	read_buffer = (char *)malloc(sizeof(char) * (BUFFER_SIZE + 1));
	if (read_buffer == NULL)
		return (NULL);
	bytes_read = read(fd, read_buffer, BUFFER_SIZE);
	if (bytes_read == -1)
	{
		free(read_buffer);
		return (NULL);
	}
	read_buffer[bytes_read] = '\0';
	return (read_buffer);
}

void	free_and_reset_stash(char **stash)
{
	free(*stash);
	*stash = NULL;
}

char	*read_and_process_lines(int fd, char **stash)
{
	char	*line_read;
	char	*completed_line_from_stash;
	char	*temp_combined_stash;

	line_read = read_from_fd(fd);
	if (!line_read)
	{
		if (**stash)
		{
			completed_line_from_stash = gnl_strdup(*stash);
			free_and_reset_stash(stash);
			return (completed_line_from_stash);
		}
		free_and_reset_stash(stash);
		return (NULL);
	}
	if (*stash == NULL)
		temp_combined_stash = gnl_strdup(line_read);
	else
		temp_combined_stash = gnl_strjoin(*stash, line_read);
	free(line_read); 
	if (!temp_combined_stash)
	{
		free_and_reset_stash(stash);
		return (NULL);
	}
	free_and_reset_stash(stash);
	*stash = temp_combined_stash;
	completed_line_from_stash = extract_completed_line(stash);
	return (completed_line_from_stash);
}

char	*get_next_line(int fd)
{
	static char	*stash;
	char		*completed_line;

	if (fd < 0 || BUFFER_SIZE <= 0 || read(fd, NULL, 0) < 0)
	{
		return (NULL);
	}
	if (!stash)
		stash = gnl_strdup("");
	completed_line = extract_completed_line(&stash);
	if (completed_line)
		return (completed_line); 
	completed_line = read_and_process_lines(fd, &stash);
	if (completed_line == NULL && stash)
	{
		free(stash);
		stash = NULL;
	}
	return (completed_line);
}

/* int	main(void)
{
	int		fd = open("example.txt", O_RDONLY);
	char	*line;

	if (fd == -1)
	{
		printf("Error opening file");
		return (1);
	}

	while ((line = get_next_line(fd)) != NULL)
	{
		printf("%s\n", line);
		free(line);
	}
	close(fd);
	return (0);
} */