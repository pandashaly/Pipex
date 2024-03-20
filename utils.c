/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ssottori <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/20 15:39:08 by ssottori          #+#    #+#             */
/*   Updated: 2024/03/20 16:16:23 by ssottori         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

void	child_process(char **av, char **envp, int *fd)
{
	int	infile;

	infile = open(av[1], O_RDONLY, 0777);
	if (infile == -1)
		p_error();
	dup2(fd[1], STDOUT_FILENO);
	dup2(infile, STDIN_FILENO);
	close(fd[1]);
}

void	parent_process(char **av, char **envp, int *fd)
{
	int	outfile;

	outfile = open(av[1], O_WRONLY | O_CREAT | O_TRUNC, 0777);
	if (outfile == -1)
		p_error();
	dup2(fd[1], STDOUT_FILENO);
	dup2(outfile, STDIN_FILENO);
	close(fd[1]);
}

void	p_error(void)
{
	perror("Error");
	exit(EXIT_FALIURE);
}
