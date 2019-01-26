#include <stdio.h>

int	find_pivot(int *arr, int n);

int	main(void)
{
	int	arr[] = { 1, 2, 3, 4, 0, 6 };
	int	n = 6;

	printf("return: %i\n", find_pivot(arr, n));
	return (0);
}
