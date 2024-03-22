/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cd.c                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sentry <sentry@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/17 11:53:35 by sentry            #+#    #+#             */
/*   Updated: 2024/03/20 22:31:00 by sentry           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/minishell.h"

void    ft_cd(t_msh    *msh)
{
    char        *home_dir_path;
    t_dlist     *curr_dir_node;
    t_dlist     *new_node;
    char        cwd[1024];
    char        *path;

    curr_dir_node = NULL;
	home_dir_path = get_env_value(msh->envvar, "HOME");
    if (home_dir_path == NULL)
    {
        error_exit("HOME environment variable not found");
        return;
    }
    if (msh->tokens->next == NULL)
    {
        if (chdir(home_dir_path) != 0)
        {
            perror("chdir(home_dir_path) != 0");
        }
    }
    else
    {
        path = msh->tokens->next->data;
        if (chdir(path) != 0)
        {
            perror("cd");
        }
        else
        {
            new_node = malloc (sizeof(t_dlist));
            if (new_node == NULL)
            {
                perror("malloc");
                return ;
            }
            new_node->data = malloc(ft_strlen(path) + 1);
            if (new_node->data == NULL)
            {
                perror("malloc");
                free(new_node);
                return ;
            }
            ft_strlcpy(new_node->data, path, ft_strlen(path));
            new_node->prev = curr_dir_node;
            if (curr_dir_node != NULL)
            {
                curr_dir_node->next = new_node;
            }
            curr_dir_node = new_node;
        }
    }
    if (getcwd(cwd, sizeof(cwd)) != NULL)
    {
        setenv("PWD", cwd, 1);
    }
    else 
    {
        perror("getcwd");
    }
}