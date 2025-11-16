#include "cub.h"

static int	count_words(const char *s, char c)
{
	int	i;
	int	count;
	int	d;

	count = 0;
	d = 0;
	i = 0;
	while (s[i])
	{
		if (s[i] != c)
			d = 1;
		else if (s[i] == c && d == 1)
		{
			count++;
			d = 0;
		}
		i++;
	}
	if (d == 1)
		count++;
	return (count);
}

static int	lent(const char *s, int i, char c)
{
	int	len;

	len = 0;
	while (s[i] != c && s[i])
	{
		len++;
		i++;
	}
	return (len);
}

static int	fill(const char *s, int i, char *r, char c)
{
	int	index;

	index = 0;
	while (s[i] != c && s[i])
	{
		r[index] = s[i];
		i++;
		index++;
	}
	r[index] = 0;
	return (i);
}

static char	**ft_free(char **r, int in)
{
	while (in >= 0)
	{
		free(r[in]);
		in--;
	}
	free(r);
	return (NULL);
}

char	**ft_split(char const *s, char c)
{
	char	**r;
	int		in;
	int		i;

	in = 0;
	i = 0;
	if (!s)
		return (NULL);
	r = malloc((count_words(s, c) + 1) * (sizeof(char *)));
	if (!r)
		return (NULL);
	while (s[i])
	{
		if (s[i] != c)
		{
			r[in] = malloc(lent(s, i, c) + 1);
			if (!r[in])
				return (ft_free(r, in));
			i = fill(s, i, r[in], c);
			in++;
		}
		else
			i++;
	}
	return (r[in] = 0, r);
}
