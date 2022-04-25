/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client_bonus.h                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: otakun40 <pjacoby@student.21-school.ru>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/17 21:09:34 by otakun40          #+#    #+#             */
/*   Updated: 2022/03/17 21:10:48 by otakun40         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CLIENT_BONUS_H
# define CLIENT_BONUS_H

# include <stdlib.h>
# include <signal.h>
# include "ft_printf_bonus.h"

long	ft_atoi(const char *nptr);
size_t	ft_strlen(char *str);
void	add_char_2_string(char **old, char sym);
void	exit_failure(char *message);
int		check_pid(char *str);

#endif