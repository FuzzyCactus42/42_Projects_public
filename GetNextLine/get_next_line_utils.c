/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hhailat <hhailat@learner.42.tech>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/10 11:00:34 by hhailat           #+#    #+#             */
/*   Updated: 2026/10/10 11:44:17 by hhailat          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

size_t	ft_strlcat(char *dst, const char *src, size_t size)
{
	size_t	i;
	size_t	j;
	size_t	src_len;
	size_t	dst_len;

	j = 0;
	dst_len = 0;
	src_len = ft_strlen(src);
	while (dst[dst_len] != '\0' && dst_len < size)
		dst_len++;
	i = dst_len;
	if (size == 0)
		return (src_len);
	if (dst_len >= size)
		return (size + src_len);
	while (src[j] != '\0' && (i < size - 1))
		dst[i++] = src[j++];
	if (dst_len != size)
		dst[i] = '\0';
	return (src_len + dst_len);
}

char	*ft_strdup(const char *s)
{
	char	*str;
	int		i;

	i = 0;
	if (s == NULL)
		return (NULL);
	while (s[i] != '\0')
		i++;
	str = malloc((i + 1) * sizeof(char));
	if (str == NULL)
		return (NULL);
	i = 0;
	while (s[i] != '\0')
	{
		str[i] = s[i];
		i++;
	}
	str[i] = '\0';
	return (str);
}

static void	ft_update_rest(char **s, int i)
{
	char	*temp;

	temp = ft_strdup(&(*s)[i]);
	free(*s);
	*s = ft_strdup(temp);
	free(temp);
}

char	*ft_trim_lines(char **s)
{
	char	*p;
	int		i;

	i = 0;
	p = malloc(ft_strlen(*s) + 2);
	if (!p)
		return (NULL);
	while ((*s)[i] != '\n')
	{
		p[i] = (*s)[i];
		i++;
		if ((*s)[i] == '\0')
		{
			p[i] = '\0';
			free(*s);
			*s = NULL;
			return (p);
		}
	}
	p[i++] = '\n';
	p[i] = '\0';
	ft_update_rest(s, i);
	return (p);
}

size_t	ft_strlen(const char *s)
{
	size_t	i;

	if (!s)
		return (0);
	i = 0;
	while (s[i] != '\0')
	{
		i++;
	}
	return (i);
}
