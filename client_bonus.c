/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client_bonus.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: otakun40 <pjacoby@student.21-school.ru>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/17 21:09:17 by otakun40          #+#    #+#             */
/*   Updated: 2022/03/17 21:09:18 by otakun40         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "client_bonus.h"
#include "string.h"

size_t	g_message_len;

void	signal_handler(int signal)
{
	static size_t	symbols_counter = 0;

	if (signal == SIGUSR1)
		symbols_counter++;
	else
	{
		if (g_message_len == symbols_counter)
			ft_printf("Message received by server\n");
		else
			write(2, "Message didn't receive by server completely\n", 44);
	}
}

void	send_char(int pid, char sym)
{
	int	i;

	i = 0;
	while (i < 8)
	{
		if (sym & 1 << i)
			kill(pid, SIGUSR2);
		else
			kill(pid, SIGUSR1);
		i++;
		usleep(30);
	}
}

int	main(int argc, char **argv)
{
	char	*string;
	pid_t	server_pid;

	signal(SIGUSR1, signal_handler);
	signal(SIGUSR2, signal_handler);
	if (argc != 3)
		exit_failure("Wrong number of arguments\n");
	if (!check_pid(argv[1]))
		exit_failure("PID is incorrect\n");
	server_pid = ft_atoi(argv[1]);
	string = argv[2];
	g_message_len = ft_strlen(string);
	if (!*string)
		exit_failure("You should enter not empty string\n");
	else
	{
		while (*string)
			send_char(server_pid, *string++);
		send_char(server_pid, '\0');
	}
	usleep(10000);
}
