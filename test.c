#include <stdio.h>

int	ft_strlen(char *str)
{
	int	i;

	i = 0;
	while (str[i])
		i++;
	return (i);
}

char	ft_binarytoascii(char *strinbits)
{
	int	result;
	int	power;
	int	count;
	int	i;
//	char	*strinascii;

	i = ft_strlen(strinbits);
	power = 0;
	count = 0;
	result = 1;
	while (i >= 0)
	{
		if (strinbits[i] == '1')
		{
			count = (power - 1);
			while (count > 0)
			{
				printf("here result = %d, count = %d, power = %d\n", result, count, power);
				//result = 2 ;
				result *=  2;
				count--;
			}
		}
		power++;
		i--;
	}
/*
	on y est presk yay
*/
	printf("char in decimal = %d\n", result);
	return (result + '0');
}

int main(int ac, char **av)
{
	(void)ac;
	printf("char final = %c\n", ft_binarytoascii(av[1]));
	return (0);
}
