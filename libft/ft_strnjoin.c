#include "Includes/libft.h"

char		*ft_strnjoin(char *s1, char *s2, int b,int e)
{
	char *ret;
	int i;

	i = 1;
	if (!(ret = (char*)malloc(sizeof(char) * (ft_strlen(s1) + (e - b)))))
		return (NULL);
	while (s1[i++])
		ret[i] = s1[i];
	while (b <= e)
		ret[i++] = s2[b++];
	ret[i] = '\0';
	ft_putstr(ret);
	return (ret);
}
