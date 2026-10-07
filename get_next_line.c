#include "get_next_line.h"

int	fill_the_line(char *buffer, char **stash, int count_bytes)
{
	static int	i = 0;
	int j;
	int	endl;
	char *temp;

	j = 0;
	endl = 0;
	if (*stash)
	{
		temp = ft_strdup(*stash);
		free(*stash);
		*stash = malloc(i + count_bytes + 1);
		*stash = ft_strlcpy(stash, temp, count_bytes + i);
		free (temp);
	}
	else 
		*stash = malloc(BUFFER_SIZE + 1);
	while (j < count_bytes)
	{
		(*stash)[i] = buffer[j];
		if (buffer[j++] == '\n')
			endl = 1;
		i++;
	}
	if (buffer[j] == '\0')
		return (15);
	return (endl);
}

char	*get_next_line(int fd)
{
	int	i;
	int	count_bytes;
	static char	*stash;
	char		*line;	
	char		buffer[BUFFER_SIZE];
	
	do
	{
		count_bytes = read(fd, buffer, BUFFER_SIZE);
		if (count_bytes == -1)
			return (NULL);
		i = fill_the_line(buffer, &stash, count_bytes);
	} while (!(i == 1 || i == 15));
	line = ft_trim_lines(stash);
	return (line); 
}
#include <fcntl.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include "get_next_line.h"

int	main(int argc, char **argv)
{
	int		fd;
	char	*line;
	int		line_count;

	line_count = 1;
	// 1. فحص ما إذا تم تمرير اسم ملف في التيرمينال
	if (argc == 2)
	{
		fd = open(argv[1], O_RDONLY);
		if (fd == -1)
		{
			perror("خطأ في فتح الملف");
			return (1);
		}
	}
	else
	{
		// 2. إذا لم يمرر ملف، سيقرأ من الإدخال القياسي Terminal (stdin)
		printf("Hello\nWorld");
		fd = 0;
	}

	// 3. استدعاء get_next_line في حلقة حتى ترجع NULL (نهاية الملف)
	while ((line = get_next_line(fd)) != NULL)
	{
		printf("السطر [%d]: %s", line_count++, line);
		free(line); 
	}

	if (fd != 0)
		close(fd);

	return (0);
}