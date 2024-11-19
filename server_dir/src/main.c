#include <unistd.h>
#include <signal.h>
#include <stdlib.h>
#include <stdio.h>

static void	handle_signal(int signum)
{
	static int	bit_count = 0;
	static char	c = 0;

	if (signum == SIGUSR1)
		c |= (1 << bit_count);
	bit_count++;
	if (bit_count == 8)
	{
		write(1, &c, 1);
		bit_count = 0;
		c = 0;
	}
}

int	main(void)
{
	pid_t	pid;

	pid = getpid();
	write(1, "Server PID: ", 11);
	printf("%d\n", pid);
	signal(SIGUSR1, handle_signal);
	signal(SIGUSR2, handle_signal);
	while (1)
		pause();
	return (0);
}
