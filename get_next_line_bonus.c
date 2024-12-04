/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ababa-ai <ababa-ai@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/15 11:52:06 by ababa-ai          #+#    #+#             */
/*   Updated: 2024/06/10 15:56:24 by ababa-ai         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"

char	*ft_read_til_limit(int fd, char *line_limit)
{
	char	*buff;
	int		rd_bytes;

	buff = malloc((BUFFER_SIZE + 1) * sizeof(char));
	if (!buff)
		return (NULL);
	rd_bytes = 1;
	while (!ft_strchr(line_limit, '\n') && rd_bytes != 0)
	{
		rd_bytes = read(fd, buff, BUFFER_SIZE);
		if (rd_bytes == -1)
		{
			free(buff);
			return (NULL);
		}
		buff[rd_bytes] = '\0';
		line_limit = ft_strjoin(line_limit, buff);
	}
	free(buff);
	return (line_limit);
}

char	*get_next_line(int fd)
{
	char		*line;
	static char	*line_limit[MAXFD];

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (0);
	line_limit[fd] = ft_read_til_limit(fd, line_limit[fd]);
	if (!line_limit[fd])
		return (NULL);
	line = ft_get_current_line(line_limit[fd]);
	line_limit[fd] = ft_new_line_limit(line_limit[fd]);
	return (line);
}

int main()
{
    int fd1;
	int	fd2;
    char *line;

    fd1 = open("numbers.dict", O_RDONLY);
    fd2 = open("essai", O_RDONLY);
	if (fd1 < 0 || fd2 < 0)
        return 1;
    else
    {
        line = get_next_line(fd1);
        if (line)
        {
            write(1, line, 8);
            free(line);
        }
        line = get_next_line(fd2);
        if (line)
        {
            write(1, line, 15);
            free(line);
        }
        line = get_next_line(fd1);
        if (line)
        {
            write(1, line, 7);
            free(line);
        }
		line = get_next_line(fd2);
        if (line)
        {
            write(1, line, 19);
            free(line);
        }
		        line = get_next_line(fd1);
        if (line)
        {
            write(1, line, 10);
            free(line);
        }
        line = get_next_line(fd2);
        if (line)
        {
            write(1, line, 17);
            free(line);
        }
        line = get_next_line(fd1);
        if (line)
        {
            write(1, line, 9);
            free(line);
        }
    }
    close(fd1);
	close(fd2);
    return 0;
}