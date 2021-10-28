/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bcorrea- <bruuh.cor@gmail.com>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/04 14:50:06 by bcorrea-          #+#    #+#             */
/*   Updated: 2021/10/26 18:06:01 by bcorrea-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# include <stdlib.h>
# include <unistd.h>
# include <limits.h>

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 42
# endif

/* REMOVE LATER */
# include <stdio.h>
# include <fcntl.h>

/**
 * @brief Write a function which returns a line read from a file descriptor
 *
 * @param fd File descriptor to read from
 * @return Read line or NULL if nothing else to read or an error accurred
*/
char	*get_next_line(int fd);

char	*get_text(int fd, char **remainder);
char	*get_line(char *text);
char	*get_remainder(char *text);

/**
 * @brief Calculates the length of the string s, excluding the terminatig null
 * byte
 *
 * @param s Constant string to be analysed
 * @return size_t Returns the number of bytes in the string s
*/
size_t	ft_strlen(const char *s);

/**
 * @brief Copies n bytes from memory area src to memory area dest. The memory
 * areas must not overlap
 *
 * @param dest Pointer to destination memory area address
 * @param src Pointer to source memory area address
 * @param n Buffer size in bytes
 * @return void* Returns dest
*/
void	*ft_memcpy(void *dest, const void *src, size_t n);

/**
 * @brief Returns a pointer to the first occurrence of the character in the
 * string s
 *
 * @param s The source string
 * @param c The character to be found
 * @return char* Returns the pointer to c if found or NULL if not
*/
char	*ft_strchr(const char *s, int c);

/**
 * @brief Allocates (with malloc(3)) and returns a new string, which is the
 * result of the concatenation of 's1' and 's2'
 *
 * @param s1 The prefix string
 * @param s2 The suffix string
 * @return char* The new string. NULL if the allocation fails
*/
char	*ft_strjoin(char const *s1, char const *s2);

/**
 * @brief Returns a pointer to a new string which is a duplicate of the string
 * s. Memory for the new string is obtained with malloc
 *
 * @param s The string to be copied
 * @Return char* Returns a pointer to the duplicated string, or NULL if
 * insufficient memory was available
*/
char	*ft_strdup(const char *s);

#endif
