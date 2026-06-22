/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: omatalla <omatalla@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/07 12:53:38 by omatalla          #+#    #+#             */
/*   Updated: 2026/06/22 17:11:06 by omatalla         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static size_t	word_count(char const *s, char c)
{
	size_t	count;
	size_t	in_word;

	if (!*s)
		return (0);
	count = 0;
	in_word = 0;
	while (*s)
	{
		if (*s == c)
			in_word = 0;
		else if (in_word == 0)
		{
			count++;
			in_word = 1;
		}
		s++;
	}
	return (count);
}

static void	free_all(char **array, size_t used)
{
	size_t	i;

	i = 0;
	while (i < used)
		free(array[i++]);
	free(array);
}

static int	add_word(char const *s, size_t len, char **array, size_t i)
{
	char	*temp;

	temp = ft_substr(s, 0, len);
	if (!temp)
		return (0);
	array[i] = temp;
	return (1);
}

static int	fill(char const *s, char c, char **array)
{
	size_t	i;
	size_t	len;

	i = 0;
	while (*s)
	{
		while (*s && *s == c)
			s++;
		if (*s)
		{
			if (!ft_strchr(s, c))
				len = ft_strlen(s);
			else
				len = ft_strchr(s, c) - s;
			if (!add_word(s, len, array, i))
				return (free_all(array, i), 0);
			i++;
			s += len;
		}
	}
	array[i] = NULL;
	return (1);
}

char	**ft_split(char const *s, char c)
{
	char	**array;

	if (!s)
		return (NULL);
	array = malloc((word_count(s, c) + 1) * sizeof(char *));
	if (!array)
		return (NULL);
	if (!fill(s, c, array))
		return (NULL);
	return (array);
}
