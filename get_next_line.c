/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bcorrea- <bruuh.cor@gmail.com>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/04 14:57:47 by bcorrea-          #+#    #+#             */
/*   Updated: 2021/11/03 03:10:36 by bcorrea-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

static char	*get_text(int fd, char *remainder);
static char	*read_file(int fd, char *total_buffer);
static char	*get_line(char *text);
static char	*get_remainder(char *text);

char	*get_next_line(int fd)
{
	char			*line;
	char			*text;
	static char		*remainder;

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	if (ft_strchr(remainder, '\n') != NULL)
		text = remainder;
	else
		text = get_text(fd, remainder);
	if (text == NULL)
		return (NULL);
	remainder = get_remainder(text);
	line = get_line(text);
	free(text);
	if (line == NULL)
	{
		free(line);
		line = NULL;
	}
	return (line);
}

static char	*get_text(int fd, char *remainder)
{
	char	*text;

	if (remainder == NULL)
		text = ft_strdup("");
	else
		text = remainder;
	text = read_file(fd, text);
	if (*text == '\0')
	{
		free(text);
		text = NULL;
	}
	return (text);
}

static char	*read_file(int fd, char *total_buffer)
{
	char	*current_buffer;
	char	*previous_buffer;
	size_t	read_len;

	current_buffer = malloc((BUFFER_SIZE + 1) * sizeof(char));
	if (!current_buffer)
		return (NULL);
	while (ft_strchr(total_buffer, '\n') != NULL || !read_len != NULL)
	{
		read_len = read(fd, current_buffer, BUFFER_SIZE);
		if (read_len <= 0 || read_len > BUFFER_SIZE)
			break ;
		current_buffer[read_len] = '\0';
		previous_buffer = total_buffer;
		total_buffer = ft_strjoin(previous_buffer, current_buffer);
		free(previous_buffer);
		previous_buffer = NULL;
	}
	free(current_buffer);
	return (total_buffer);
}

/* Get the text before \n or \0 */
static char	*get_line(char *text)
{
	char	*line;
	int		i;

	i = 0;
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

static char	*get_remainder(char *text)
{
	char	*remainder;
	size_t	len;
	size_t	i;

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

// void	test_gnl(char *path)
// {
// 	char	*line;
// 	int		fd;

// 	fd = open(path, O_RDONLY);
// 	do
// 	{
// 		line = get_next_line(fd);
// 		if (line)
// 			printf("%s", line);
// 		free(line);
// 	} while (line != NULL);
// 	printf("-END-\n");
// 	close(fd);
// }

// int	main(void)
// {
// 	// test_gnl("./gnlTester/files/41_no_nl");
// 	test_gnl("text2.txt");
// 	return (0);
// }

// int	main(void)
// {
// 	static char	*remainder;
// 	int			i;

// 	if (!remainder)
// 		i = 1;
// 	if (remainder == NULL)
// 		i = 1;
// 	return (0);
// }
