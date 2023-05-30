/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmina-ni <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/29 16:12:48 by tmina-ni          #+#    #+#             */
/*   Updated: 2023/05/29 17:28:08 by tmina-ni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

size_t	ft_linelen(char *str)
{
	size_t	len;

	len = 0;
	while (str[len] || str[len] == '\n')
		len++;
}
