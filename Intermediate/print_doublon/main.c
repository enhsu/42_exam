void	print_doublon(int *a, int na, int *b, int nb);

int		main(void)
{
	int	a[] = { -5,  2, 10, 15, 50, 70, 100, 200, 300, 1200, 5000 };
	int	na = 11;
	int b[] = {  2,  4,  5,  6,  7, 10,  40,  70 };
	int	nb = 8;

	print_doublon(a, na, b, nb);
}
