#include <stddef.h>
#include "parser.h"
#include "../cub3d.h"
#include "get_next_line.h"

int	create_trgb(int t, int r, int g, int b)
{
	return (t << 24 | r << 16 | g << 8 | b);
}

int	ft_atoi(const char *str)
{
	long long	res;
	long		pos;

	res = 0;
	pos = 0;
	if (str[pos] < '0' || str[pos] > '9')
		return (-1);
	while (str[pos] >= '0' && str[pos] <= '9')
	{
		res = res * 10 + (str[pos++] - '0');
		if (res > 256)
			break ;
	}
	return (res);
}

size_t	ft_strlcpy(char *dst, const char *src,
					 size_t dstsize)
{
	size_t	pos;
	long	src_len;

	if ((char *)dst == NULL)
		return (0);
	pos = 0;
	src_len = ft_strlen((char *)src);
	if (dstsize == 0)
		return (src_len);
	while (pos < dstsize - 1)
	{
		if (*((char *)src + pos) == '\0')
			break ;
		((char *)dst)[pos] = ((char *)src)[pos];
		pos++;
	}
	((char *)dst)[pos] = '\0';
	return (src_len);
}

int	ft_strncmp(const char *s1, const char *s2, size_t n)
{
	size_t	pos;

	pos = 0;
	while (pos < n)
	{
		if (*(s1 + pos) != *(s2 + pos))
			return ((unsigned char)*(s1 + pos) - \
			(unsigned char)*(s2 + pos));
		if (*(s1 + pos) == 0 || *(s2 + pos) == 0)
			break ;
		pos++;
	}
	return (0);
}
