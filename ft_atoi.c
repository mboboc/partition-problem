/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mboboc <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/30 17:19:26 by mboboc            #+#    #+#             */
/*   Updated: 2018/07/31 20:31:49 by mboboc           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int		ft_atoi(char *str)
{
	int		number;
	char	*aux;
	int		sign;

	aux = str;
	number = 0;
	sign = 1;
	while (*aux == ' ' || (*aux >= 9 && *aux <= 13))
		aux++;
	if (*aux == '-')
		sign = -1;
	if (*aux == '+' || *aux == '-')
		aux++;
	while (*aux >= '0' && *aux <= '9')
	{
		number = number * 10 + sign * (*aux - '0');
		aux++;
	}
	return (number);
}
