#include"Fraction.h"

double Sin(double x, int n)
{
	Fraction X(x);
	Fraction sum, m, f, p;
	//double sum = 0, m, f, p;
	m = /*x*/X;

	p.set_frac(-1, 1);
	//p = -1;

	for (int i = 1; i <= n; i++)
	{
		sum = sum + m;
		f.set_frac(1, 2*i * (2*i + 1));
		//f = 1. / (2 * i * (2 * i + 1));
		m = m * p * (X ^ 2 /*pow(x,(int)2)*/) * f;
	}
	//sum.Reduction();
	cout << sum.get_num()<< endl << sum.get_denom() << endl;
	double out = /*sum*/ddiv(sum.get_num(), sum.get_denom());

	return out;
}