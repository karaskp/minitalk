#include <stdio.h>

int	ft_strlen(char *str)
{
	int	i;

	i = 0;
	while (str[i])
		i++;
	return (i);
}

char	ft_binarytoascii(char *strinbits, int power)
{
	int	result;
	int	power_tmp;
	int	result_tmp;
	int	i;

	i = (ft_strlen(strinbits) - 1);
	result = 0;
	result_tmp = 0;
	while (i >= 0)
	{
		if (strinbits[i] == '1')
		{
			power_tmp = power;
			if (power == 0 )
				result = 1;
			else
				result_tmp = 1;
			while (power_tmp-- > 0)
				result_tmp *=  2;
			result += result_tmp;
		}
		power++;
		i--;
	}
	return (result);
}

int main(int ac, char **av)
{
	(void)ac;

	printf("char final = %c\n", ft_binarytoascii(av[1], 0));
	return (0);
}
