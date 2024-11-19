#include <unistd.h>
#include <signal.h>
#include <stdlib.h>
#include <stdio.h>

void	send_char(pid_t pid, char c)
{
	int	bit;
	int	i;

	i = 0;
	while (i < 8)
	{
		bit = (c >> i) & 1;
		if (bit == 1)
			kill(pid, SIGUSR1);
		else
			kill(pid, SIGUSR2);
		usleep(100);
		i++;
	}
}

int	main(int argc, char **argv)
{
	pid_t	server_pid;
	char	*message;
	int		i;

	if (argc != 3)
	{
		printf("Usage: %s <server_pid> <message>\n", argv[0]);
		return (1);
	}
	server_pid = atoi(argv[1]);
	if (server_pid <= 0)
	{
		printf("Invalid PID\n");
		return (1);
	}
	message = argv[2];
	i = 0;
	while (message[i])
	{
		send_char(server_pid, message[i]);
		i++;
	}
	return (0);
}
