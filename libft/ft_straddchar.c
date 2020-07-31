/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_straddchar.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nforay <nforay@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/31 17:08:44 by mbourand          #+#    #+#             */
/*   Updated: 2020/07/31 17:08:44 by nforay           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_straddchar(char **str, char c, size_t len)
{
	size_t	i;
	size_t	str_len;
	char	*tmp;

	tmp = *str;
	str_len = ft_strlen(tmp);
	if (!(*str = malloc(sizeof(char) * (str_len + len + 1))))
		return (NULL);
	ft_strcpy(*str, tmp);
	i = 0;
	while (i < len)
	{
		(*str)[str_len + i] = c;
		i++;
	}
	(*str)[str_len + len] = 0;
	ft_free(&tmp);
	return (*str);
}
