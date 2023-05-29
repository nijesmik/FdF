/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf_parsing_split.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sejinkim <sejinkim@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/14 16:51:02 by sejinkim          #+#    #+#             */
/*   Updated: 2023/04/30 21:52:35 by sejinkim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

size_t	get_split_size(char const *s, char c)
{
	size_t	size;

	size = 0;
	while (*s)
	{
		while (*s == c)
			s++;
		if (*s)
			size++;
		while (*s && *s != c)
			s++;
	}
	return (size);
}

char	*ft_strndup(char const *s, size_t len)
{
	char	*str;
	size_t	i;

	str = (char *)malloc(sizeof(char) * (len + 1));
	if (!str)
		return (NULL);
	i = 0;
	while (i < len)
	{
		str[i] = s[i];
		i++;
	}
	str[i] = 0;
	return (str);
}

char	**free_ptr(char **ptr)
{
	size_t	i;

	i = 0;
	while (ptr[i])
	{
		free(ptr[i]);
		ptr[i++] = NULL;
	}
	free(ptr);
	ptr = NULL;
	return (NULL);
}

char	**ft_split(char const *s, char c, size_t size)
{
	size_t	i;
	size_t	len;
	char	**ret;

	ret = (char **)malloc(sizeof(char *) * (size + 1));
	if (!ret)
		return (NULL);
	i = 0;
	while (*s && i < size)
	{
		while (*s == c)
			s++;
		len = 0;
		while (s[len] && s[len] != c)
			len++;
		ret[i] = ft_strndup(s, len);
		if (!ret[i])
			return (free_ptr(ret));
		s += len;
		i++;
	}
	ret[i] = 0;
	return (ret);
}
