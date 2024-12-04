/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ababa-ai <ababa-ai@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/15 11:52:06 by ababa-ai          #+#    #+#             */
/*   Updated: 2024/06/12 15:56:01 by ababa-ai         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

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
	static char	*line_limit;

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (0);
	line_limit = ft_read_til_limit(fd, line_limit);
	if (!line_limit)
		return (NULL);
	line = ft_get_current_line(line_limit);
	line_limit = ft_new_line_limit(line_limit);
	return (line);
}

int main()
{
    int fd;
    char *line;

    fd = open("numbers.dict", O_RDONLY);
    if (fd < 0)
        return 1;
    else
    {
        line = get_next_line(fd);
        if (line)
        {
            write(1, line, 8);
            free(line);
        }
        line = get_next_line(fd);
        if (line)
        {
            write(1, line, 8);
            free(line);
        }
        line = get_next_line(fd);
        if (line)
        {
            write(1, line, 8);
            free(line);
        }
    }
    close(fd);
    return 0;
}
