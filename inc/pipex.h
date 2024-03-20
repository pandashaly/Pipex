/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ssottori <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/20 15:44:01 by ssottori          #+#    #+#             */
/*   Updated: 2024/03/20 17:12:35 by ssottori         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PIPEX_H
# define PIPEX_H

# include "libft.h"
# include <stdlib.h>

void	child_process(char **av, char **envp, int fd);
void	parent_process(char **av, char **envp, int fd);
char	*cmd_path(char *cmd, char **envp);
void	exec_cmd(char *av, char **envp);
void	p_error(void);

#endif
