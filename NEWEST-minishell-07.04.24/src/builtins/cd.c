/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cd.c                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sentry <sentry@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/17 11:53:35 by sentry            #+#    #+#             */
/*   Updated: 2024/04/07 01:04:20 by sentry           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/minishell.h"

static char	*get_new_path(t_cmd	*cmd_struct)
{
	char	*path;
	char	*cwd;

	cwd = getcwd(NULL, 0);
	if (!cmd_struct->arguments)
		path = ft_strdup(getenv("HOME"));
	else if (ft_strcmp(cmd_struct->arguments->data, ".") == 0)
		path = ft_strdup(cwd);
	else if (ft_strcmp(cmd_struct->arguments->data, "..") == 0)
		path = NULL;
	else
		path = ft_strdup(cmd_struct->arguments->data);
	free(cwd);
	return (path);
}

static void	update_env_vars(t_msh	*msh, char	*old_pwd, char	*new_pwd)
{
	t_dlist	*current;
	t_envv	*env_var;

	current = msh->envvar;
	while (current)
	{
		env_var = (t_envv *)current->data;
		if (ft_strcmp(env_var->env_key, "PWD") == 0)
		{
			free(env_var->env_value);
			env_var->env_value = ft_strdup(new_pwd);
		}
		current = current->next;
	}
	update_node_value(find_envvar_node(msh->envvar, "OLDPWD"), old_pwd);
}

static void	free_resources(char *path, char *old_pwd)
{
	if (path && path != NULL)
	{
		free(path);
	}
	if (old_pwd && old_pwd != NULL)
	{
		free(old_pwd);
	}
}

static void	free_and_return(char	*path, char	*old_pwd)
{
	free_resources(path, old_pwd);
	return ;
}

void	ft_cd(t_msh	*msh, t_cmd *cmd_struct)
{
	char	cwd[PATH_MAX];
	char	*old_pwd;
	char	*new_pwd;
	char	*path;

	path = get_new_path(cmd_struct);
	if (path && access(path, F_OK) != 0)
	{
		perror("");
		free_resources(path, NULL);
		set_last_exit_status(msh, 1); // Set non-zero exit status for failure
		return ;
	}
	if (!path && chdir("..") != 0)
	{
		set_last_exit_status(msh, 1); // Set non-zero exit status for failure
		return ;
	}
	old_pwd = getcwd(NULL, 0);
	if (!old_pwd)
	{
		set_last_exit_status(msh, 1); // Set non-zero exit status for failure
		free_and_return(path, old_pwd);
	}
	if (path)
	{
		if (chdir(path) != 0)
		{
			set_last_exit_status(msh, 1); // Set non-zero exit status for failure
			free_and_return(path, old_pwd);
		}
	}
	new_pwd = getcwd(cwd, sizeof(cwd));
	if (!new_pwd)
	{
		set_last_exit_status(msh, 1); // Set non-zero exit status for failure
		free_and_return(path, old_pwd);
	}
	update_env_vars(msh, old_pwd, new_pwd);
	free_resources(path, old_pwd);
	set_last_exit_status(msh, 0); // Set 0 exit status for success
}