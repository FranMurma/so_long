/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   aux_bonus.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: frmurcia <frmurcia@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/09 15:10:03 by frmurcia          #+#    #+#             */
/*   Updated: 2023/03/09 18:10:58 by frmurcia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_bonus.h"
#include "mlx/mlx.h"
#include "ft_printf/ft_printf.h"

size_t	ft_strlen(const char *s)
{
	size_t	i;

	i = 0;
	while (s[i] != '\0')
		i++;
	return (i);
}

int	ft_file_term(char *file_name, char *file_end)
{
	int	count1;
	int	count2;

	count1 = 0;
	count2 = 0;
	while (file_name[count1])
		count1++;
	count1 = count1 -4;
	while (file_end[count2])
	{
		if (file_name[count1] == file_end[count2] && file_name[count1] != '\0')
		{
			count1++;
		}
		count2++;
	}
	if (file_name[count1] == '\0')
		return (1);
	else if (file_name[count1] != '\0')
		return (-1);
	return (0);
}

char	*ft_strjoin(char *s1, char *s2)
{
	char	*s3;
	int		cont;
	int		conts3;

	cont = -1;
	conts3 = 0;
	if (!s1)
	{
		s1 = (char *)malloc(sizeof(char) * 1);
		s1[0] = '\0';
	}
	if (!s1 || !s2)
		return (0);
	s3 = malloc(sizeof(char) * (ft_strlen(s1) + ft_strlen(s2) + 1));
	if (!s3)
		return (0);
	while (s1[++cont])
		s3[cont] = s1[cont];
	while (s2[conts3])
		s3[cont++] = s2[conts3++];
	s3[cont] = '\0';
	free(s1);
	return (s3);
}

char	*ft_strchr(char *s, int c)
{
	int	cont;

	cont = 0;
	if (!s)
		return (0);
	if (c == '\0')
		return ((char *)(s + cont));
	while (s[cont] != '\0')
	{
		if (s[cont] == (char)c)
			return ((char *)(s + cont));
		cont++;
	}
	return (0);
}

char	*ft_strdup(char *s1)
{
	int		cont;
	char	*s2;
	int		len;

	cont = 0;
	if (!s1)
		return (0);
	len = ft_strlen(s1);
	s2 = (char *)malloc(sizeof(char) * (len + 1));
	if (!s2)
		return (NULL);
	while (s1[cont] != '\0')
	{
		s2[cont] = *((char *)(s1 + cont));
		cont++;
	}
	s2[cont] = '\0';
	return (s2);
}
