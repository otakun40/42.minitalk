/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_bonus.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pjacoby <pjacoby@student.21-school.ru>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/24 22:12:43 by pjacoby           #+#    #+#             */
/*   Updated: 2022/04/24 22:12:46 by pjacoby          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <unistd.h>

size_t	ft_strlen(char *str)
{
	size_t	i;

	i = 0;
	if (!str)
		return (0);
	while (*str++)
		i++;
	return (i);
}

void	add_char_2_string(char **old, char sym)
{
	char	*new;
	char	*temp;
	int		i;

	i = 0;
	temp = *old;
	new = malloc(sizeof(char) * (ft_strlen(temp) + 2));
	if (!new)
		exit(EXIT_FAILURE);
	if (temp)
	{
		while (temp[i])
		{
			new[i] = temp[i];
			i++;
		}
	}
	new[i] = sym;
	new[i + 1] = '\0';
	if (temp)
		if (*temp)
			free(temp);
	*old = new;
}

int	check_pid(char *str)
{
	while (*str)
	{
		if (!(*str >= '0' && *str <= '9'))
			return (0);
		str++;
	}
	return (1);
}

void	exit_failure(char *message)
{
	if (*message)
		write(2, message, ft_strlen(message));
	exit(EXIT_FAILURE);
}
