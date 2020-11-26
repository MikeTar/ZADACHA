/* Функция принимающая n параметров
и возвращающая сумму полинома с параметрами в качестве
коэффициентов, то есть p1*x^n+...+pn*x */
#include <stdarg.h>
#include<cmath>

double polynom(double x, int n, ...)
{
	double sum = 0;
	va_list p;

	va_start(p, n);

	while (n--)
	{
		sum += va_arg(p, double)*pow(x, n);
	}

	va_end(p);

	return sum;
}
