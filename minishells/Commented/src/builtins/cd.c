/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cd.c                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sentry <sentry@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/17 11:53:35 by sentry            #+#    #+#             */
/*   Updated: 2024/04/13 15:59:07 by sentry           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/minishell.h"

+/**
+ * This function determines the new path to change the current directory to,
+ * based on the arguments passed to the 'cd' builtin.
+ *
+ * @param cmd_struct The cmd struct containing the arguments to 'cd'.
+ *
+ * @return The new path to change the current directory to, or NULL if the
+ *         new path cannot be determined.
+ */
static char	*get_new_path(t_cmd	*cmd_struct)
{
	char	*path;
	char	*cwd;

+	/* Get the current working directory. */
	cwd = getcwd(NULL, 0);
+
+	/* If no arguments were passed, change to the user's home directory. */
	if (!cmd_struct->arguments)
+	{
		path = ft_strdup(getenv("HOME"));
+	}
+
+	/* If the argument is ".", change to the current directory. */
	else if (ft_strcmp(cmd_struct->arguments->data, ".") == 0)
+	{
		path = ft_strdup(cwd);
+	}
+
+	/* If the argument is "..", change to the parent directory. */
	else if (ft_strcmp(cmd_struct->arguments->data, "..") == 0)
+	{
		path = NULL;
+	}
+
+	/* Otherwise, change to the directory specified by the argument. */
	else
+	{
		path = ft_strdup(cmd_struct->arguments->data);
+	}
+
+	/* Free the memory allocated for the current working directory, since we
+	 * don't need it anymore. */
	free(cwd);
+
	return (path);
}

+/**
+ * This function updates the environment variables "PWD" and "OLDPWD" to
+ * reflect the current working directory and the previous working directory,
+ * respectively.
+ *
+ * The function iterates through the list of environment variables, and for
+ * each environment variable, it checks if the key is "PWD". If it is, it
+ * updates the value of the environment variable to the new current working
+ * directory.
+ *
+ * After updating the "PWD" variable, the function calls the function
+ * find_envvar_node() to find the node in the list of environment variables
+ * that has the key "OLDPWD". The function update_node_value() is then called
+ * to update the value of the "OLDPWD" variable to the old working directory.
+ *
+ * @param msh The current Minishell instance.
+ * @param old_pwd The old working directory.
+ * @param new_pwd The new working directory.
+ */
static void	update_env_vars(t_msh	*msh, char	*old_pwd, char	*new_pwd)
{
+	t_dlist	*current;		// The current node in the list of environment variables.
+	t_envv	*env_var;		// The current environment variable.
-	t_dlist	*current;
-	t_envv	*env_var;

+	/* Iterate through the list of environment variables. */
	current = msh->envvar;
	while (current)
	{
+		/* Get the current environment variable. */
		env_var = (t_envv *)current->data;
+
+		/* If the key of the current environment variable is "PWD", update its value. */
		if (ft_strcmp(env_var->env_key, "PWD") == 0)
		{
			free(env_var->env_value);
			env_var->env_value = ft_strdup(new_pwd);
		}
+
+		/* Move on to the next node in the list of environment variables. */
		current = current->next;
	}
+
+	/* Find the node in the list of environment variables that has the key "OLDPWD". */
+	current = find_envvar_node(msh->envvar, "OLDPWD");
+
+	/* Update the value of the "OLDPWD" variable. */
+	update_node_value(current, old_pwd);
-	update_node_value(find_envvar_node(msh->envvar, "OLDPWD"), old_pwd);
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

int		ft_cd(t_msh	*msh, t_cmd *cmd_struct)
--//void	ft_cd(t_msh	*msh, t_cmd *cmd_struct)
{
+	/* The new path to change to (if any). */
+	char	*path;
+	/* The old working directory before the cd. */
-	char	cwd[PATH_MAX];
	char	*old_pwd;
+	/* The new working directory after the cd. */
	char	*new_pwd;
+	/* The current working directory. */
+	char	cwd[PATH_MAX];
-	char	*path;

+	/* If there are more than one argument, print an error message and return 1. */
	if (cmd_struct->arguments && cmd_struct->arguments->next != NULL)
	{
		ft_printf("cd: too many arguments\n");
		return (1);
	}
+	/* Get the new path to change to. */
	path = get_new_path(cmd_struct);
+	/* If the new path is invalid, print an error message and return 1. */
	if (path && access(path, F_OK) != 0)
	{
		perror("");
		free_resources(path, NULL);
		return (1);
	}
+	/* If the new path is NULL (meaning cd ..), change to the parent directory. */
	if (!path && chdir("..") != 0)
		return (1);
+	/* Get the old working directory before the cd. */
	old_pwd = getcwd(NULL, 0);
+	/* If we failed to get the old working directory, free the resources and return 1. */
	if (!old_pwd)
+	{
+		free_resources(path, old_pwd);
+		return (1);
+	}
+	/* If we have a new path, change to that. */
-		free_and_return(path, old_pwd);
	if (path)
	{
+		/* If we failed to change to the new path, free the resources and return 1. */
		if (chdir(path) != 0)
+		{
+			free_resources(path, old_pwd);
+			return (1);
+		}
-			free_and_return(path, old_pwd);
	}
+	/* Get the new working directory after the cd. */
	new_pwd = getcwd(cwd, sizeof(cwd));
+	/* If we failed to get the new working directory, free the resources and return 1. */
	if (!new_pwd)
+	{
+		free_resources(path, old_pwd);
+		return (1);
+	}
+	/* Update the environment variables "PWD" and "OLDPWD". */
-		free_and_return(path, old_pwd);
	update_env_vars(msh, old_pwd, new_pwd);
+	/* Free the resources. */
	free_resources(path, old_pwd);
+	/* Return 0 (success). */
	return (0);
}

