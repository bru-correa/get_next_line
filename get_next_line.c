/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bcorrea- <bruuh.cor@gmail.com>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/04 14:57:47 by bcorrea-          #+#    #+#             */
/*   Updated: 2021/10/28 17:28:17 by bcorrea-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*get_next_line(int fd)
{
	char			*line;
	char			*text;
	static char		*remainder = NULL;

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	if (remainder != NULL && ft_strchr(remainder, '\n') != NULL)
		text = remainder;
	else
		text = get_text(fd, &remainder);
	remainder = get_remainder(text);
	line = get_line(text);
	free(text);
	if (line == NULL)
		free(line);
	return (line);
}

char	*get_text(int fd, char **remainder)
{
	char	*text;
	char	*buffer;
	char	*current_buffer;
	size_t	read_len;

	buffer = malloc((BUFFER_SIZE + 1) * sizeof(char));
	if (!buffer)
		return (NULL);
	if (*remainder != NULL)
	{
		text = ft_strdup(*remainder);
		free(*remainder);
		*remainder = NULL;
	}
	else
		text = ft_strdup("");
	read_len = 1;
	while (read_len > 0)
	{
		read_len = read(fd, buffer, BUFFER_SIZE);
		if (read_len <= 0)
		{
			free(buffer);
			free(text);
			return (NULL);
		}
		buffer[read_len] = '\0';
		current_buffer = text;
		text = ft_strjoin(text, buffer);
		free(current_buffer);
		current_buffer = NULL;
		if (text != NULL && ft_strchr(text, '\n'))
		{
			free(buffer);
			return (text);
		}
	}
	free(buffer);
	return (text);
}


/* Get the text before \n or \0 */
char	*get_line(char *text)
{
	char	*line;
	int		i;

	i = 0;
	if (!text)
		return (NULL);
	while (text[i] != '\n' && text[i] != '\0')
		i++;
	line = malloc((i + 2) * sizeof(char));
	if (!line)
		return (NULL);
	line[i + 1] = '\0';
	while (i > -1)
	{
		line[i] = text[i];
		i--;
	}
	return (line);
}

char	*get_remainder(char *text)
{
	char	*remainder;
	size_t	len;
	size_t	i;

	if (!text)
		return (NULL);
	remainder = ft_strchr(text, '\n');
	if (!remainder)
		return (NULL);
	remainder++;
	text = remainder;
	len = ft_strlen(remainder);
	remainder = malloc((len + 1) * sizeof(char));
	i = 0;
	while (i < len)
	{
		remainder[i] = text[i];
		i++;
	}
	remainder[i] = '\0';
	return (remainder);
}

void	test_gnl(int fd)
{
	char	*line;
	do
	{
		line = get_next_line(fd);
		if (line)
			printf("%s", line);
		free(line);
	} while (line != NULL);
	printf("-END-\n");
}

int	main(void)
{
	int		fd;

	fd = open("text2.txt", O_RDONLY);
	test_gnl(fd);
	fd = open("text.txt", O_RDONLY);
	test_gnl(fd);
	return (0);
}
