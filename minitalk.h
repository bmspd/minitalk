#ifndef MINITALK_H
# define MINITALK_H
# include <unistd.h>
# include <signal.h>
# include <stdlib.h>
# define RED     "\x1b[31m"
# define GREEN   "\x1b[32m"
# define MAGENTA "\x1b[35m"
# define CYAN    "\x1b[36m"
# define CLR_RESET   "\x1b[0m"

void	ft_putnbr(int n);
void	ft_putstr(char *string);
int		ft_atoi(const char *str);
void	message(int type);
void	put_spaces(int number);
#endif