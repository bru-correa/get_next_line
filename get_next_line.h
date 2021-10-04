/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bcorrea- <bruuh.cor@gmail.com>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/04 14:50:06 by bcorrea-          #+#    #+#             */
/*   Updated: 2021/10/04 14:56:50 by bcorrea-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# include <stdlib.h>

/**
 * @brief Write a function which returns a line read from a file descriptor
 *
 * @param fd File descriptor to read from
 * @return Read line or NULL if nothing else to read or an error accurred
*/
char	*get_next_line(int fd);
#endif
