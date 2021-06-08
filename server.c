#include "minitalk.h"

void	loading_circles(void)
{
	int	i;

	i = 0;
	while (i < 6)
	{
		write(1, CYAN"⬤  "CLR_RESET, 14);
		usleep(500000);
		write(1, MAGENTA"⬤  "CLR_RESET, 14);
		usleep(500000);
		i++;
	}
	write(1, "\n", 1);
}

static int 	treat_char(int index, siginfo_t *info, int i)
{
	int	c;

	(void)info;
	c = 0;
	usleep(10);
	if (index == SIGUSR1)
	{
		c += (1 << (7 - i));
	}
	return (c);
}

static void	signal_handler(int index, siginfo_t *info, void *u)
{
	static int	i;
	static int	c;
	int			state;

	(void)u;
	c += treat_char(index, info, i);
	i++;
	if (i == 8)
	{
		if (c == 0)
		{
			state = kill(info->si_pid, SIGUSR1);
			if (state == -1)
				message(4);
		}
		i = 0;
		write(1, &c, 1);
		c = 0;
	}
}

int	main(void)
{
	int					pid;
	int					state;
	struct sigaction	hello;

	loading_circles();
	pid = getpid();
	write(1, GREEN"╔══════════════════════════════════╗\n", 114);
	write(1, "╟  SERVER STARTED WITH PID ", 29);
	ft_putnbr(pid);
	put_spaces(pid);
	write(1, "╢", 3);
	write(1, "\n╚══════════════════════════════════╝\n"CLR_RESET, 114);
	hello.sa_sigaction = signal_handler;
	state = sigaction(SIGUSR2, &hello, 0);
	if (state == -1)
		message(3);
	state = sigaction(SIGUSR1, &hello, 0);
	if (state == -1)
		message(3);
	while (10)
	{
		pause();
	}
}
