/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   echo.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bylkus <bylkus@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/08 11:38:29 by loadjou           #+#    #+#             */
/*   Updated: 2023/02/24 16:22:11 by bylkus           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

static int multiple_n(char *str)
{
	int i = 1;
	while(str[i])
	{
		if(str[i] == 'n')
			i++;
		else
			break;
	}
	if(i == ft_strlen(str))
		return 1;
	return 0;
}

static void	print_echo(char **cmd, int flag)
{
	int	i;
	int	j;

	j = 0;
	i = flag + 1;
	while (cmd[i])
	{
		j = 0;
		while (cmd[i][j])
		{
			printf("%c", cmd[i][j]);
			j++;
		}
		printf(" ");
		i++;
	}
}

int	echo(char **cmd)
{
	int	i;
	int	j;
	int	flag;

	flag = 0;
	if (!cmd[1])
	{
		printf("\n");
		return (1);
	}
	if (ft_strcmp(cmd[1], "-n") == 0 || multiple_n(cmd[1]) == 1)
		flag = 1;
	if (cmd[1])
		print_echo(cmd, flag);
	if (flag == 0)
	{
		printf("\n");
		return (1);
	}
	return (0);
}

// int	echo(char **cmd)
	// {
	// 	int	i;
	// 	int	j;
	// 	int	flag;

	// 	i = 0;
	// 	flag = 1;	// flag = 1 cuz if "-n" let be spce to write = 1
	// 	while(cmd && cmd[++i])
	// 	{		
	// 		 // {
	// 			// 	printf("\n");
	// 			// 	return (1);
	// 			// }
	// 		if (ft_strcmp(cmd[i], "-n") == 0 || multiple_n(cmd[i]) == 1)
	// 			flag = 0;	// no spce allow to write
	// 		else
	// 			print_echo(cmd[i], flag);
	// 		if (cmd[i] + 1)
	// 			printf(" ");
	// 				// if (flag == 0)
	// 				// 	// printf("\n");
	// 				// 	write(1,"\n",)
	// 				// 	return (1);
	// 				// i++;
	// 	}
	// 	return (write(1, "\n", flag) == 2);
// }