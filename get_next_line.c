/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: frmurcia <frmurcia@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/16 16:47:45 by frmurcia          #+#    #+#             */
/*   Updated: 2023/02/18 18:38:42 by frmurcia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"
#include "mlx/mlx.h"

char	*ft_cutword(char *prt)
{
	int		i;
	int		j;
	char	*dest;

	i = 0;
	j = 0;
	while (prt[i] != '\n' && prt[i])
		i++;
	if (!prt[i])
	{
		free(prt);
		return (NULL);
	}
	if (prt[i] == '\n')
		i++;
	dest = malloc(sizeof(char) * (ft_strlen(prt) - i + 1));
	if (!dest)
		return (NULL);
	while (prt[i])
		dest[j++] = prt[i++];
	dest[j] = '\0';
	free(prt);
	return (dest);
}

char	*ft_read(int fd, char *ptr)
{
	int		bytes;
	char	*temp;

	bytes = 1;
	temp = malloc(sizeof(char) * (BUFFER_SIZE + 1));
	if (!temp)
		return (NULL);
	while (!ft_strchr(ptr, '\n') && bytes != 0)
	{
		bytes = read(fd, temp, BUFFER_SIZE);
		if (bytes < 0)
		{
			free(temp);
			free(ptr);
			return (NULL);
		}
		temp[bytes] = '\0';
		ptr = ft_strjoin(ptr, temp);
	}
	free(temp);
	return (ptr);
}

char	*get_next_line(int fd)
{
	static char	*ptr;
	char		*line;
	int			cont;

	cont = 0;
	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	if (!ptr)
		ptr = ft_strdup("");
	ptr = ft_read(fd, ptr);
	if (!ptr)
	{
		free(ptr);
		return (NULL);
	}
	while (ptr[cont] != '\n' && ptr[cont])
		cont++;
	line = ft_substr(ptr, 0, cont + 1);
	ptr = ft_cutword(ptr);
	if (!line || !line[0])
	{
		free(line);
		return (NULL);
	}
	return (line);
}
