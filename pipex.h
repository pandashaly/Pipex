
#ifndef "PIPEX_H"
# define "PIPEX_H"

# include "libft.h"
# include <stdlib.h>



void	child_process(char **av, char **envp, int fd);
void	parent_process(char **av, char **envp, int fd);


