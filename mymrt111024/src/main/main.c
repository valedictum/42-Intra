/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atang <atang@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/03 13:29:18 by atang             #+#    #+#             */
/*   Updated: 2024/10/11 16:46:59 by atang            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

int	main(int argc, char **argv)
{
	t_Scene	scene;
	int		empty_check;
	//t_mrt	*mrt;
	//t_data	*data;
	//int		parse_result;
	//mrt = NULL;
	//data = NULL;
	if (argc != 2 || filename_error(argv[1]))
		printf(RED "Error!\n" RST G
			"Correct usage is: ./mini_rt <filename>.rt\n" RST);
	else if (file_exists(argv[1]))
	{
		printf(B "\nFile found...\n" RST);
		empty_check = file_empty(argv[1]);
		if (empty_check == 1 || empty_check == -1)
		{
			return (1);
		}
		parse_rt_file(argv[1], &scene);
		//data = (t_mrt *)malloc(sizeof(t_mrt));
		//if (data == NULL)
		//	return (1);
		//init_mrt(mrt);
	}
	else
	{
		printf(RED "Error! File not found\n" RST);
		return (1);
	}
	return (0);
}
