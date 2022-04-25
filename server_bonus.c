/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server_bonus.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: otakun40 <pjacoby@student.21-school.ru>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/17 20:28:47 by otakun40          #+#    #+#             */
/*   Updated: 2022/03/17 20:28:48 by otakun40         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "server_bonus.h"

void	signal_handler(int signal, siginfo_t *sig, void *context)
{
	static int		i = 0;
	static char		symbol;
	static char		*message = NULL;

	(void) context;
	(void) sig;
	symbol |= (signal == SIGUSR2) << i;
	i++;
	if (i == 8)
	{
		if (symbol != '\0')
		{
			add_char_2_string(&message, symbol);
			kill(sig->si_pid, SIGUSR1);
		}
		else
		{
			ft_printf("%s\n", message);
			free(message);
			message = NULL;
			kill(sig->si_pid, SIGUSR2);
		}
		symbol = 0;
		i = 0;
	}
}

int	main(void)
{
	struct sigaction	sig;

	ft_printf("Server PID: %d\n", getpid());
	sig.sa_flags = SA_SIGINFO;
	sig.sa_sigaction = signal_handler;
	sigaction(SIGUSR1, &sig, NULL);
	sigaction(SIGUSR2, &sig, NULL);
	while (1)
		pause();
}
