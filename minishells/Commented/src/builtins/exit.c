/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exit.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sentry <sentry@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/20 21:03:45 by sentry            #+#    #+#             */
/*   Updated: 2024/04/13 15:59:04 by sentry           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/minishell.h"

/*
// OG ANDY CODE
void	ft_exit(t_msh *msh, t_cmd *cmd)
{
	int		exit_status;

	if (!cmd->arguments)
		exit_status = EXIT_SUCCESS;
	else
	{
		exit_status = ft_atoi((char *)cmd->arguments->data);
		if (!exit_status)
			msh_error_exit(msh, "exit\nvalid numeric argument required");
		else if (cmd->arguments->next != NULL)
			msh_error_exit(msh, "exit\ntoo many arguments");
	}
	ft_printf("exit\n");
	exit(exit_status);
}
*/

/*
int	ft_exit(t_msh *msh, t_cmd *cmd)
{
	int		exit_status;

	if (!cmd->arguments)
		exit_status = EXIT_SUCCESS;
	else
	{
		exit_status = ft_atoi((char *)cmd->arguments->data);
		if (!exit_status)
			msh_error_exit(msh, "exit\nvalid numeric argument required");
		else if (cmd->arguments->next != NULL)
			msh_error_exit(msh, "exit\ntoo many arguments");
	}
	ft_printf("exit\n");
	msh->last_exit_status = exit_status;
	exit(exit_status);
	return (exit_status);
}
*/

static int	is_valid_numeric(const char *arg)
{
	if (arg == NULL || *arg == '\0')
	{
		return (0);
	}
	if (*arg == '+' || *arg == '-')
	{
		arg++;
	}
	while (*arg)
	{
		if (!(*arg >= '0' && *arg <= '9'))
		{
			return (0);
		}
		arg++;
	}
	return (1);
}

+/*
+ * This function handles the builtin command 'exit'.
+ *
+ * If no argument is provided, the function exits the shell with a status of 0,
+ * indicating successful completion.
+ *
+ * If an argument is provided, the function validates that it is a valid
+ * numeric argument. If the argument is not valid, the function exits the shell
+ * with a status of 2 and sends an error message to stderr.
+ *
+ * If the argument is valid, the function converts it to an integer and exits
+ * the shell with that status. If there are more than one argument, the function
+ * exits the shell with a status of 1 and sends an error message to stderr.
+ *
+ * Regardless of how the function exits, it sets the last_exit_status member
+ * of the msh struct to the final exit status before exiting.
+ */
int	ft_exit(t_msh *msh, t_cmd *cmd)
{
	int		exit_status;
	char	*arg;

	exit_status = 0;
+	if (!cmd->arguments)		// no argument provided
	{
		exit_status = EXIT_SUCCESS;
	}
+	else						// argument provided
	{
		arg = (char *)cmd->arguments->data;
+		if (!is_valid_numeric(arg))	// invalid argument
		{
			msh->last_exit_status = 2;
			msh_error_exit(msh, "exit\nvalid numeric argument required");
		}
+		exit_status = ft_atoi(arg);	// valid argument
+		if (cmd->arguments->next != NULL)	// too many arguments
		{
			msh->last_exit_status = EXIT_FAILURE;
			msh_error_exit(msh, "exit\ntoo many arguments");
		}
	}
	ft_printf("exit\n");
	msh->last_exit_status = exit_status;
	exit(exit_status);
	return (exit_status);
}

