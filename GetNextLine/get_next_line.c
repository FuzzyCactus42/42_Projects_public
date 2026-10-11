/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hhailat <hhailat@learner.42.tech>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/10 10:48:55 by hhailat           #+#    #+#             */
/*   Updated: 2026/10/10 11:44:22 by hhailat          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

static void	free_stash(char **stash, int count_bytes, int i, char **temp)
{
	if (*stash)
	{
		*temp = ft_strdup(*stash);
		free(*stash);
		*stash = malloc(i + count_bytes + 1);
		if (!*stash)
			return ;
		(*stash)[0] = '\0';
		ft_strlcat(*stash, *temp, (count_bytes + i + 1));
		free(*temp);
	}
	else
	{
		*stash = malloc(count_bytes + 1);
		if (!*stash)
			return ;
	}
}

static int	fill_the_line(char *buffer, char **stash, int count_bytes)
{
	int		i;
	int		j;
	int		endl;
	char	*temp;

	i = ft_strlen(*stash);
	j = 0;
	endl = 0;
	free_stash(stash, count_bytes, i, &temp);
	while (j < count_bytes && buffer[j] != '\0')
	{
		(*stash)[i] = buffer[j];
		if (buffer[j++] == '\n')
			endl = 1;
		i++;
	}
	(*stash)[i] = '\0';
	return (endl);
}

int	initialize_buffer(int fd, char **buffer)
{
	if (fd < 0 || BUFFER_SIZE < 0)
		return (-1);
	*buffer = malloc(BUFFER_SIZE);
	if (*buffer == NULL)
		return (-1);
	return (1);
}

char	*get_next_line(int fd)
{
	int			i;
	int			count_bytes;
	static char	*stash;
	char		*buffer;

	if (initialize_buffer(fd, &buffer) == -1)
		return (NULL);
	i = 0;
	count_bytes = 1;
	while (!(i == 1 || !count_bytes))
	{
		count_bytes = read(fd, buffer, BUFFER_SIZE);
		if (count_bytes == -1)
		{
			free(buffer);
			if (stash)
				free(stash);
			return (NULL);
		}
		i = fill_the_line(buffer, &stash, count_bytes);
	}
	free(buffer);
	if (!stash || !*stash)
		return (NULL);
	return (ft_trim_lines(&stash));
}
