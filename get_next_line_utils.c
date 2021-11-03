/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bcorrea- <bruuh.cor@gmail.com>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/04 14:58:41 by bcorrea-          #+#    #+#             */
/*   Updated: 2021/10/29 22:26:22 by bcorrea-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

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

void	*ft_memcpy(void *dest, const void *src, size_t n)
{
	void	*dest_start;

	dest_start = dest;
	if (src == NULL && dest == NULL)
		return (dest);
	while (n--)
		*(unsigned char *) dest++ = *(unsigned char *) src++;
	return (dest_start);
}

char	*ft_strdup(const char *s)
{
	char	*dup;
	size_t	size;

	size = (ft_strlen(s) + 1) * sizeof(char);
	dup = (char *)malloc(size);
	if (!dup)
		return (NULL);
	ft_memcpy(dup, s, size);
	return (dup);
}

void	*ft_memset(void *dest, int c, size_t len)
{
	void	*dest_start;

	dest_start = dest;
	while (len-- > 0)
		*(unsigned char *) dest++ = (unsigned char) c;
	return (dest_start);
}

void	*ft_calloc(size_t nmemb, size_t size)
{
	size_t	total_size;
	void	*mem;

	total_size = nmemb * size;
	mem = malloc(total_size);
	if (!mem)
		return (NULL);
	mem = ft_memset(mem, 0, total_size);
	return (mem);
}
