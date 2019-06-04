/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_occur.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nrivoire <nrivoire@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/04 12:05:13 by nrivoire          #+#    #+#             */
/*   Updated: 2019/06/04 12:07:43 by nrivoire         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int			ft_occur(const char *str, const char c)
{
	int	nb;

	nb = 0;
	if (*str == c)
		nb++;
	while (*++str)
		if (*str == c)
			nb++;
	return (nb);
}
