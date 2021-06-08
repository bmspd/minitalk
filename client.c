#include "minitalk.h"

static void	treat_char(char c, int pid)
{
	int	i;
	int	state;

	i = 0;
	while (i < 8)
	{
		if ((c << i) & 128)
			state = kill(pid, SIGUSR1);
		else
			state = kill(pid, SIGUSR2);
		i++;
		if (state == -1)
			message(4);
		usleep(100);
	}
}

static void	signal_handler(int index, siginfo_t *info, void *u)
{
	(void)info;
	(void)u;
	if (index == SIGUSR1)
	{
		write(1, GREEN"✓✓✓ Server processed message successfully ✓✓✓\n"
			CLR_RESET, 67);
		exit(0);
	}
}

void	treat_string(char *string, int pid)
{
	int	i;

	i = 0;
	while (string[i])
	{
		treat_char(string[i], pid);
		i++;
	}
	treat_char(string[i], pid);
}

int	main(int argc, char **argv)
{
	struct sigaction	hello;
	int					pid;

	if (argc != 3)
		message(1);
	hello.sa_sigaction = signal_handler;
	sigaction(SIGUSR1, &hello, 0);
	//sigaction(SIGUSR2, &hello, 0);
	pid = ft_atoi(argv[1]);
	treat_string(argv[2], pid);
	while (1)
	{
		pause();
	}
}
