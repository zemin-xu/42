/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_display_file.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zexu <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/24 11:50:12 by zexu              #+#    #+#             */
/*   Updated: 2019/06/24 15:11:12 by zexu             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <fcntl.h>

void		display_file(int fd)
{
	char	buffer;

	while (read(fd, &buffer, 1) != 0)
		write(1, &buffer, 1);
}

int			main(int argc, char *argv[])
{
	int		fd;

	if (argc != 2)
	{
		if (argc > 2)
			write(2, "Too many arguments.\n", 20);
		if (argc < 2)
			write(2, "File name missing.\n", 19);
		return (0);
	}
	if ((fd = open(argv[1], O_RDONLY)) == -1)
	{
		write(2, "Cannot read file.\n", 18);
		return (0);
	}
	display_file(fd);
	close(fd);
	return (0);
}
