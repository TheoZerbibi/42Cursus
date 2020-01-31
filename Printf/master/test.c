#include <stdarg.h>
#include <stdio.h>

/*void f (int n, ...)
{
	va_list va;
	va_start(va, n);
	for (int i = 0; i < n; i++)
	{
		int c = va_arg (va, int);
		putchar(c);
	}
	putchar('\n');
	va_end(va);
}

int main (void)
{
	f(3, 'a', 'b', 'c');
	f(4, 'x', 'y', 'z', 't');
	return (0);
}*/

int main(void)
{
	char test[5];
	int res = sizeof(test);
	for (int i = 0; i < res; i++)
	{
		test[i] = i;
	}
	for (int i = 0; i < res ; i++)
	{
		printf("%c\n", test[i]);
	}

	printf("%d\n", res);
	return (0);
}
