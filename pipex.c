/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ssottori <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/08 22:11:16 by ssottori          #+#    #+#             */
/*   Updated: 2024/03/20 22:07:44 by ssottori         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

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
			p_error();
		pid = fork();
		if (pid == -1)
			p_error();
		if (pid == 0)
			child_process(av, envp, fd);
		waitpid(pid, NULL, 0);
		parent_process(av, envp, fd);
	}
	else
		ft_putstr_fd("Error!", 2);
	return (0);
}

/* TO DO:
 * [] get (find the path) and execute the cmd
 * []
 */
