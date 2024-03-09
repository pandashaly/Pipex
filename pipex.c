/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ssottori <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/08 22:11:16 by ssottori          #+#    #+#             */
/*   Updated: 2024/03/08 22:12:17 by ssottori         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

/* Child process that run inside a fork, take the filein, put the output inside
 a pipe and then close with the exec function 
 open
 dup
 close
 exec*/

 /* IPC - Inter Process Communication
 parent process (read argv[1] write to pipe | child process (exec cmd argv[2])
 It allows different processes to communicate with each other even if they are not directly related or part of the same program.
 dup2 allows for seamless communication between input output streams through the shared pipe.*/

void	child_process(char **av, char **envp, fd)
{
	int	input;

	input = 
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

   use open, dup2, close, ft_exec

   lookup things like stdin_fileno, stdout_fileno, o_rdonly, 0777, o_creat, o_trunc,
   waitpid, fork
*/

int	main(int ac, char **av, char **envp)
{
	int	fd[2];
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
		wait
		parent_process(argv, envp, fd);
	}
	else
	{
		ft_putstr_fd("Error: Bad args");

	}
}
/*
* TO DO:
* [] init pipex
* [] check args
* [] parse cmds
* [] pares args
* [] while cmds
* [] ft_exec
* [] ft_cleanup
* */
