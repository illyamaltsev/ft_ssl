//
// Created by Illya MALTSEV on 12/19/18.
//

#include "libft.h"

void		ft_get_all(int fd, char **line)
{
    char	tmp[BUFF_SIZE_READ];
    int		i;
    int     j;

    *line = NULL;
    j = 0;
    while (1)
    {
        i = 0;
        while (i < BUFF_SIZE_READ && read(fd, &tmp[i], 1))
            i++;
        j += i;
        *line = ft_realloc_free(*line , j + 1);
        ft_memcpy(*line + j - i, tmp, i);
        if (i < BUFF_SIZE_READ)
            break;
    }
}