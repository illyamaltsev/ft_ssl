//
// Created by Illya MALTSEV on 6/9/18.
//

#include "libft.h"

char    *ft_realloc_free(char *str, size_t size)
{
	size_t      i;
	char     *new_str;
	size_t   len;

	i = 0;
	new_str = ft_strnew(size);
	if (str != NULL)
	{
        len = ft_strlen(str);
        while (i < len)
        {
            new_str[i] = str[i];
            i++;
        }
        free(str);
    }
	return new_str;
}
