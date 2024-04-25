/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rush01.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mchaduc <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/21 10:02:42 by mchaduc           #+#    #+#             */
/*   Updated: 2023/05/21 14:47:49 by mchaduc          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
void	ft_putchar(char c);

void	ft_print_1stline(int x)
{
	ft_putchar('/');
	if (x == 1)
	{
		ft_putchar('\n');
		return ;
	}
	else
	{
		x = x - 2;
		while (x > 0)
		{
			ft_putchar('*');
			x--;
		}
		ft_putchar('\\');
	}
	ft_putchar('\n');
}

void	ft_midlines(int x)
{
	x--;
	if (x == 1)
	{
		return ;
	}
	else
	{
		while (x > 1)
		{
			ft_putchar(' ');
			x--;
		}
		ft_putchar('*');
		ft_putchar('\n');
	}
}

void	ft_print_middlelines(int x, int y)
{
	y = y - 2;
	if (y == 0)
	{
		return ;
	}
	else
	{
		while (y > 0)
		{
			ft_putchar('*');
			if (x == 1)
			{
				ft_putchar('\n');
			}
			else
			{
				ft_midlines(x);
			}
			y--;
		}
	}
}

void	ft_print_lastline(int x)
{
	ft_putchar('\\');
	if (x == 1)
	{
		return ;
	}
	else
	{
		x = x - 2;
		while (x > 0)
		{
			ft_putchar('*');
			x--;
		}
	}
	ft_putchar('/');
	ft_putchar('\n');
	return ;
}

void	rush(int x, int y)
{
	if (x == 0)
	{
		return ;
	}
	else if (y == 0)
	{
		return ;
	}
	ft_print_1stline(x);
	if (y == 1)
	{
		return ;
	}
	ft_print_middlelines(x, y);
	ft_print_lastline(x);
}
