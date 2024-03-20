/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ssottori <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/08 22:11:16 by ssottori          #+#    #+#             */
/*   Updated: 2024/03/20 16:12:36 by ssottori         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

/* Child process that run inside a fork, take the filein, put the output inside
 a pipe and then close with the exec function 
 IPC - Inter Process Communication
 parent process (read argv[1] write to pipe | child process (exec cmd argv[2])
 It allows different processes to communicate with each other even if 
 they are not directly related or part of the same program.
 dup2 allows for seamless communication between input output streams 
 through the shared pipe.*/

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
/* child - input
   parent - output
   both close with exec function
   child -> 
   run inside a fork
   take filein
   put output inside pipe
   close with exec

   parent ->
   take data from pipe
   change output for fileout
   close with exec

   waitpid, fork
*/

int	main(int ac, char **av, char **envp)
{
	int		fd[2];
	pid_t	pid;

	if (ac == 5)
	{
		if (pipe(fd) == -1)
			error();
		pid = fork();
		if (pid == -1)
			error();
		if (pid == 0)
			child_process(av, envp, fd);
		waitpid(pid, NULL, 0);
		parent_process(argv, envp, fd);
	}
	else
		ft_putstr_fd("Error!" 2);
	return (0);
}

/* TO DO:
 * [] get (find the path) and execute the cmd
 * []
 */
