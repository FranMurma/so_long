/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: frmurcia <frmurcia@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/16 16:47:45 by frmurcia          #+#    #+#             */
/*   Updated: 2023/02/17 17:38:45 by frmurcia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"
#include "mlx/mlx.h"

#define BUFFER_SIZE 1
// return 0 if EOF has been reached
// return -1 if an error happens
// return 1 if you read one line
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
	temp = malloc(sizeof(char) * (1 + 1));
	if (!temp)
		return (NULL);
	printf("I\n");
	//bytes = read(fd, temp, 1);
	while (!ft_strchr(ptr, '\n') && bytes != 0)
	{
		printf("while\n");
		printf("HE LEIDO: %s\n", ptr);
		bytes = read(fd, temp, 1);
		
		if (bytes < 0)
		{
			free(temp);
			free(ptr);
			return (NULL);
		}
		temp[1] = '\0';
		ptr = ft_strjoin(ptr, temp);
	}
	printf("SALGO\n");
	free(temp);
	return (ptr);
}

char	*get_next_line(int fd)
{
	static char	*ptr;
	char		*line;
	int			cont;

	cont = 0;
	if (fd < 0)
		return (NULL);
	if (!ptr)
		ptr = ft_strdup("");
	printf("A\n");
	ptr = ft_read(fd, ptr);
	printf("U\n");
	if (!ptr)
	{
		free(ptr);
		return (NULL);
	}
	printf("B\n");
	while (ptr[cont] != '\n' && ptr[cont])
		cont++;
	printf("C\n");
	line = ft_substr(ptr, 0, cont + 1);
	ptr = ft_cutword(ptr);
	printf("D\n");
	if (!line || !line[0])
	{
		free(line);
		return (NULL);
	}
	return (line);
}
