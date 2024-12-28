/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_2.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aaleixo- <aaleixo-@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/28 17:13:27 by aaleixo-          #+#    #+#             */
/*   Updated: 2024/12/28 17:13:27 by aaleixo-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./lib/so_long.h"

int ft_char_count(const char *str, char c)
{
    int count = 0;
    while (*str) 
    {
        if (*str == c)
            count++;
        str++;
    }
    return count;
}
