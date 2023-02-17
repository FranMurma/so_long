/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   aux.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: frmurcia <frmurcia@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/03 14:50:25 by frmurcia          #+#    #+#             */
/*   Updated: 2023/02/16 16:50:33 by frmurcia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"
#include "mlx/mlx.h"

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
	int		cont_s1;
	int		cont_s2;
	char	*s3;

	s3 = malloc(sizeof(char) * (ft_strlen(s1) + ft_strlen(s2) + 1));
	if (!s3)
		return (NULL);
	cont_s1 = 0;
	cont_s2 = 0;
	while (s1[cont_s1])
	{
		s3[cont_s1] = s1[cont_s1];
		cont_s1++;
	}
	free(s1);
	while (s2[cont_s2])
	{
		s3[cont_s1 + cont_s2] = s2[cont_s2];
		cont_s2++;
	}
	s3[cont_s1 + cont_s2] = '\0';
	free(s2);
	return (s3);
}

char	*ft_strchr(const char *s, int c)
{
	int	cont;

	cont = 0;
	while (s[cont] != '\0')
	{
		if (s[cont] == (char)c)
			return ((char *)(s + cont));
		cont++;
	}
	if (s[cont] == (char)c)
		return ((char *)(s + cont));
	return (NULL);
}

char	*ft_strdup(char *s1)
{
	char	*str_nueva;
	int		cont;
	int		len;

	len = 0;
	while (s1[len])
		len++;
	str_nueva = malloc(sizeof(char) * (len + 1));
	if (!str_nueva)
		return (NULL);
	cont = 0;
	while (s1[cont])
	{
		str_nueva[cont] = s1[cont];
		cont++;
	}
	str_nueva[cont] = '\0';
	return (str_nueva);
}
