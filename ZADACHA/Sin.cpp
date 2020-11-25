#include"Fraction.h"

double Sin(double x)
{
	Fraction X(x);
	Fraction sum, m, f, p(-1, 1);
	m = X;

	for (int i = 1; i <= 8; i++)
	{
		sum = sum + m;
		int tmp = 2 * i * (2 * i + 1);
		f.set_frac(1, tmp);
		m = m * p * (X ^ 2) * f;
	}
	double out = ddiv(sum.get_num(), sum.get_denom());

	return out;
}