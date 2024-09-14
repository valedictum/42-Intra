/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sentry <sentry@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/03 13:29:18 by atang             #+#    #+#             */
/*   Updated: 2024/09/14 17:27:58 by sentry           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

int main(int argc, char **argv)
{
	//t_mrt	*mrt;
	//t_data	*data;
	Scene	scene;
	//int		parse_result;

	//mrt = NULL;
	//data = NULL;
	//i = 0;
	if (argc != 2 || filename_error(argv[1]))
		printf(RED "Error!\n" RST G "Correct usage is: ./mini_rt <filename>.rt\n" RST);
	else if (file_exists(argv[1]))
	{
		printf(B "\nFile found...\n" RST);

		int	empty_check = file_empty(argv[1]); 
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
