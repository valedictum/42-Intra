/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_mrt.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tluanamn <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/22 13:40:34 by tluanamn          #+#    #+#             */
/*   Updated: 2024/09/22 13:40:36 by tluanamn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mrt.h"

void	free_obj(t_mrt *mrt)
{
	printf("Freeing objects...\n");
	if (mrt->spheres)
	{
		free(mrt->spheres);
		mrt->spheres = NULL;
	}
	if (mrt->planes)
	{
		free(mrt->planes);
		mrt->planes = NULL;
	}
	if (mrt->cylinders)
	{
		free(mrt->cylinders);
		mrt->cylinders = NULL;
	}
}

void	free_mrt(t_mrt *mrt)
{
	free_obj(mrt);
}
