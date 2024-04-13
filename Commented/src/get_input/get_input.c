/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_input.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atang <atang@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/04 20:50:49 by tday              #+#    #+#             */
/*   Updated: 2024/03/24 17:13:36 by atang            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/minishell.h"

/*
//ORIGINAL
char	*get_input(t_msh *msh, char *prompt)
{
	char	*line;

	line = readline(prompt);
	if (!line)
	{
		if (isatty(STDIN_FILENO))
			error("readline error");
		free_everything(msh);
		exit(EXIT_FAILURE); // update to last exit status
	}
	if (line[0] != '\0')
	{
		add_history(line);
	}
	return (line);
}
*/

char	*get_input(t_msh *msh, char *prompt)
{
	char	*line;

	line = readline(prompt);
	if (!line)
	{
		if (feof(stdin))
		{
			printf("\nExiting shell...\n");
			free_everything(msh);
			exit(EXIT_SUCCESS); // Exit with success if EOF is encountered
		}
		else
		{
			perror("readline error");
			free_everything(msh);
			exit(EXIT_FAILURE); // Exit with failure if an error occurred
		}
	}
	if (*line)
	{
		add_history(line);
	}
	return (line);
}