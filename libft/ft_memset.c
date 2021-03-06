/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahouari <ahouari@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/05 08:34:07 by ahouari           #+#    #+#             */
/*   Updated: 2022/06/05 08:37:21 by ahouari          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memset(void *ptr, int x, size_t n)
{
	char	*c;
	size_t	i;

	c = (char *)ptr;
	i = 0;
	while (i < n)
	{
		c[i] = x;
		i++;
	}
	return (ptr);
}
