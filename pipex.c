/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ssottori <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/08 22:11:16 by ssottori          #+#    #+#             */
/*   Updated: 2024/03/25 23:15:36 by ssottori         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

/*
fix - error management
*/

int	main(int ac, char **av, char **envp)
{
	int		fd[2];
	pid_t	pid;

	if (ac == 5)
	{
		if (pipe(fd) == -1)
			p_error();
		pid = fork();
		if (pid == -1)
			p_error();
		if (pid == 0)
			child_process(av, envp, fd);
		waitpid(pid, NULL, WNOHANG);
		parent_process(av, envp, fd);
	}
	else
		ft_putstr_fd("Error!", 2);
	return (0);
}
