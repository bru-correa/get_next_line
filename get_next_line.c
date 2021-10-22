/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_Line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bcorrea- <bruuh.cor@gmail.com>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/04 14:57:47 by bcorrea-          #+#    #+#             */
/*   Updated: 2021/10/05 17:26:34 by bcorrea-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*get_next_line(int fd)
{
}

/* Reads the file until \n or \0. Returns the text */
char	*get_text(int fd)
{
	char	*text;
	char	*buffer;
	char	*current_buffer;

	buffer = malloc(BUFFER_SIZE * sizeof(char) + 1);
	if (!buffer)
		return (NULL);
	text = ft_strdup("");
	while (read(fd, buffer, BUFFER_SIZE))
	{
		current_buffer = text;
		text = ft_strjoin(current_buffer, buffer);
		if (ft_strchr(text, '\n'))
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
	if (text == NULL)
		return (NULL);
	while (text[i] != '\n' && text[i] != '\0')
		 i++;
	line = malloc((i + 1) * sizeof(char));
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

int	main(void)
{
	int		fd;
	char	*line;

	fd = open("text2.txt", O_RDONLY);
	line = get_text(fd);
	line = get_line(line);
	printf("%s", line);

	line = get_text(fd);
	line = get_line(line);
	printf("%s", line);

	line = get_text(fd);
	line = get_line(line);
	printf("%s", line);
	free(line);
	return (0);
}

