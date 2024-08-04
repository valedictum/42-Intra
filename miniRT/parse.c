/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atang <atang@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/04 14:44:24 by atang             #+#    #+#             */
/*   Updated: 2024/08/04 17:58:54 by atang            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

int	parse_rt_file(const char	*filename)
{
	int fd = open(filename, O_RDONLY)
	if (fd == -1)
		perror("Error\nCould not open file");
}