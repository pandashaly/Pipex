/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ssottori <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/20 15:39:08 by ssottori          #+#    #+#             */
/*   Updated: 2024/03/20 17:14:05 by ssottori         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

void	p_error(void)
{
	perror("Error");
	exit(EXIT_FALIURE);
}

void	child_process(char **av, char **envp, int *fd)
{
	int	infile;

	infile = open(av[1], O_RDONLY, 0777);
	if (infile == -1)
		p_error();
	dup2(fd[1], STDOUT_FILENO);
	dup2(infile, STDIN_FILENO);
	close(fd[1]);
	exec_cmd(av[1], envp);
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
	exec_cmd(av[1], envp);
}

char	*cmd_path(char **cmd, char **envp)
{
}

void	exec_cmd(char *av, char **envp)
{
	char	**cmd;
	char	*path;
	int		i;

	i = 0;
	cmd = ft_split(av, ' ');
	path = cmd_path(cmd, envp);
	if (!path)
	{
		while (cmd[i++])
			free(cmd[i]);
		free(cmd);
		p_error();
	}
	if (exceve(path, cmd, envp) == -1)
		p_error();
}
