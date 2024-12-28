/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aaleixo- <aaleixo-@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/08 15:22:42 by aaleixo-          #+#    #+#             */
/*   Updated: 2024/12/28 17:51:22 by aaleixo-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strchr(const char *str, int c)
{
	while (*str) 
	{
        if (*str == c)
            return (char *)str;
        str++;
    }
    return NULL;
}
/*
#include <stdio.h>

int	main(void)
{
	char str[] = "boas pessoal";
	printf("%s\n", ft_strchr(str, 'b' + 256));
	printf("%s\n", strchr(str, 'b' + 256));
} */