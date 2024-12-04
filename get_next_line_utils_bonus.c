/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils_bonus.c                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ababa-ai <ababa-ai@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/15 11:53:51 by ababa-ai          #+#    #+#             */
/*   Updated: 2024/06/03 14:44:06 by ababa-ai         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"

char	*ft_strchr(char *s, int c)
{
	int	i;

	i = 0;
	if (!s)
		return (0);
	if (c == '\0')
		return ((char *)&s[ft_strlen(s)]);
	while (s[i] != '\0')
	{
		if (s[i] == (char) c)
			return ((char *)&s[i]);
		i++;
	}
	return (0);
}

size_t	ft_strlen(const char *s)
{
	int	i;

	i = 0;
	while (s[i] != '\0')
	{
		i++;
	}
	return (i);
}

char	*ft_strjoin(char *l_limit, char *buff)
{
	size_t	i;
	size_t	j;
	char	*str;

	if (!l_limit)
	{
		l_limit = (char *)malloc(1 * sizeof(char));
		l_limit[0] = '\0';
	}
	if (!l_limit || !buff)
		return (NULL);
	str = malloc(sizeof(char) * ((ft_strlen(l_limit) + ft_strlen(buff)) + 1));
	if (str == NULL)
		return (NULL);
	i = -1;
	j = 0;
	if (l_limit)
		while (l_limit[++i] != '\0')
			str[i] = l_limit[i];
	while (buff[j] != '\0')
		str[i++] = buff[j++];
	str[ft_strlen(l_limit) + ft_strlen(buff)] = '\0';
	free(l_limit);
	return (str);
}

char	*ft_get_current_line(char *line_limit)
{
	int		i;
	char	*str;

	i = 0;
	if (!line_limit[i])
		return (NULL);
	while (line_limit[i] && line_limit[i] != '\n')
		i++;
	str = (char *)malloc(sizeof(char) * (i + 2));
	if (!str)
		return (NULL);
	i = 0;
	while (line_limit[i] && line_limit[i] != '\n')
	{
		str[i] = line_limit[i];
		i++;
	}
	if (line_limit[i] == '\n')
	{
		str[i] = line_limit[i];
		i++;
	}
	str[i] = '\0';
	return (str);
}

char	*ft_new_line_limit(char *line_limit)
{
	int		i;
	int		j;
	char	*str;

	i = 0;
	while (line_limit[i] && line_limit[i] != '\n')
		i++;
	if (!line_limit[i])
	{
		free(line_limit);
		return (NULL);
	}
	str = (char *)malloc(sizeof(char) * (ft_strlen(line_limit) - i + 1));
	if (!str)
	{
		free(str);
		return (NULL);
	}
	i++;
	j = 0;
	while (line_limit[i])
		str[j++] = line_limit[i++];
	str[j] = '\0';
	free(line_limit);
	return (str);
}
