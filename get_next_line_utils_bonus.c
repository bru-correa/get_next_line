/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils_bonus.c                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bcorrea- <bruuh.cor@gmail.com>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/03 05:34:52 by bcorrea-          #+#    #+#             */
/*   Updated: 2021/11/03 06:29:00 by bcorrea-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"

void	*reset_ptr(void *ptr)
{
	free(ptr);
	return (NULL);
}

size_t	ft_strlen(const char *s)
{
	int	len;

	len = 0;
	while (s[len])
		len++;
	return (len);
}

char	*ft_strchr(const char *s, int c)
{
	if (!s)
		return (NULL);
	if (c > 127)
		c %= 256;
	while (*s)
	{
		if (*s == c)
			return ((char *) s);
		s++;
	}
	if (*s == c)
		return ((char *) s);
	return (NULL);
}

char	*ft_strjoin(const char *s1, const char *s2)
{
	char	*output;
	size_t	size;
	char	*output_start;

	if (!s1 || !s2)
		return (NULL);
	size = (ft_strlen(s1) + ft_strlen(s2) + 1) * sizeof(char);
	output = (char *)malloc(size);
	if (!output)
		return (NULL);
	output_start = output;
	while (*s1)
		*output++ = *s1++;
	while (*s2)
		*output++ = *s2++;
	*output = '\0';
	return (output_start);
}

char	*ft_strdup(const char *s)
{
	char	*dup;
	size_t	size;
	size_t	i;

	if (s == NULL)
		return (NULL);
	size = (ft_strlen(s) + 1) * sizeof(char);
	dup = malloc(size);
	if (!dup)
		return (NULL);
	i = 0;
	while (size--)
	{
		dup[i] = s[i];
		i++;
	}
	return (dup);
}
