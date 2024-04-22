/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jlyu <jlyu@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/26 15:32:25 by jlyu              #+#    #+#             */
/*   Updated: 2023/08/09 17:31:30 by jlyu             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/push_swap.h"

static void	free_str(char **data)
{
	char	**tem;

	tem = data;
	while (*tem)
	{
		free(*tem);
		tem++;
	}
	free(data);
}

int	main(int argc, char *argv[])
{
	char	**data;
	int		flag;

	flag = 0;
	if (argc > 1)
	{
		data = argv + 1;
		if (argc == 2)
		{
			data = ft_split(argv[1], ' ');
			flag = 1;
		}
		push_swap(data);
		if (flag == 1)
			free_str(data);
	}
	return (0);
}
