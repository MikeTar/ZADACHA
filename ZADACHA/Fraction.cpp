#include"Fraction.h"

Fraction::Fraction()
{
	set_frac(wint(0), wint(1));
}

Fraction::Fraction(wint num, wint denom)
{
	set_frac(num, denom);
}

Fraction::Fraction(double frac)
{
	set_frac(frac);
}

/* Перевод дроби из десятичной в простую дробь*/
void Fraction::FracConverter(double frac)
{
	bool inv = false;
	wint fr[2], inv_fr[2];
	int sign = frac / abs(frac);
	Fraction a, inv_a, b, res;

	decimal_to_simple(1. / frac, inv_fr[0], inv_fr[1]);
	inv_a.set_frac(inv_fr[0], inv_fr[1]);

	decimal_to_simple(frac, fr[0], fr[1]);
	a.set_frac(fr[0], fr[1]);

	bool HasDivs = hasDivs(a.num, a.denom);

	if (isPrime(a.num) && !HasDivs)
	{
		num = a.num;
		denom = a.denom;
		return;
	}
	else if (inv_a.denom == 1)
	{
		denom = inv_a.num;
		num = inv_a.denom;
	}
	else
	{
		wint div1 = GCD(a.num, a.denom);
		wint div2 = GCD(inv_a.num, inv_a.denom);

		if (div1 > div2 || (div1 == 1 && div2 == 1))
		{
			num = a.num;
			denom = a.denom;
		}
		else
		{
			wint tmp = inv_a.num;
			num = inv_a.denom;
			denom = tmp;

		}
		num *= sign;
	}
}

/* Поиск наибольшего общего делителя (НОД) */
wint Fraction::GCD(wint a, wint b)
{
	a = wint::abs(a);
	b = wint::abs(b);
	while ((a != 0) && (b != 0))
	{
		if (a > b)
			a = a % b;
		else
			b = b % a;
	}

	return (a + b);
}

/* Приведение к общему знаменателю */
void Fraction::CD(wint & na, wint & da, wint & nb, wint & db)
{
	na = na * db;
	nb = nb * da;
	da = db = da * db;
}

/* Перевод десятичной дроби в обыкновенную дробь 
(не обязательно в простую)*/
void Fraction::decimal_to_simple(double frac, wint &n, wint& d)
{
	//int i = 1;
	d = wint(1);

	k = 15;

	double ipart = floor(frac);
	double fpart = frac - ipart;

	for (int i = 0; i < k; i++)
	{
		fpart *= 10;
		n = n*10 + (uint64_t)fpart;
		fpart -= floor(fpart);
		d *= 10;
	}
	n += (wint)(ipart*pow(10, k));

	while (!(n % 2) && !(n % 5))
	{
		n /= 10;
		d /= 10;
		k--;
	}
}

Fraction Fraction::operator+(Fraction& a)
{
	wint n, d;
	wint na = num, da = denom;
	wint nb = a.num, db = a.denom;
	CD(na, da, nb, db);
	n = na + nb;
	d = da;
	Reduction(n, d);
	return Fraction(n, d);
}

Fraction Fraction::operator-(Fraction & a)
{
	wint n, d;
	wint na = num, da = denom;
	wint nb = a.num, db = a.denom;
	CD(na, da, nb, db);
	n = na - nb;
	d = da;
	Reduction(n, d);
	return Fraction(n, d);
}

Fraction Fraction::operator*(Fraction & a)
{
	wint n, d;
	n = num * a.num;
	d = denom * a.denom;
	Reduction(n, d);
	return Fraction(n, d);
}

Fraction Fraction::operator/(Fraction & a)
{
	wint n, d;
	n = num * a.denom;
	d = denom * a.num;
	Reduction(n, d);
	return Fraction(n, d);
}

Fraction Fraction::operator^(int p)
{
	wint n, d;
	n = wpow(num, p);
	d = wpow(denom, p);
	Reduction(n, d);

	return Fraction(n, d);
}

bool Fraction::operator>(Fraction & a)
{
	wint na = num, da = denom;
	wint nb = a.num, db = a.denom;
	CD(na, da, nb, db);
	return na > nb;
}

bool Fraction::operator<(Fraction & a)
{
	wint na = num, da = denom;
	wint nb = a.num, db = a.denom;
	CD(na, da, nb, db);
	return na < nb;
}

bool Fraction::operator>=(Fraction & a)
{
	wint na = num, da = denom;
	wint nb = a.num, db = a.denom;
	CD(na, da, nb, db);
	return na >= nb;
}

bool Fraction::operator<=(Fraction & a)
{
	wint na = num, da = denom;
	wint nb = a.num, db = a.denom;
	CD(na, da, nb, db);
	return na <= nb;
}

bool Fraction::operator==(Fraction & a)
{
	wint na = num, da = denom;
	wint nb = a.num, db = a.denom;
	CD(na, da, nb, db);
	return na == nb;
}

bool Fraction::operator!=(Fraction & a)
{
	wint na = num, da = denom;
	wint nb = a.num, db = a.denom;
	CD(na, da, nb, db);
	return na != nb;
}

/* Сокращение дроби */
void Fraction::Reduction()
{
	Reduction(num, denom);
}

void Fraction::Reduction(wint& n, wint& d)
{
	wint div;
	do
	{
		div = GCD(n, d);
		n /= div;
		d /= div;
	} while (div > 1);
}

void Fraction::set_frac(double frac)
{
	FracConverter(frac);
}

void Fraction::set_frac(wint num, wint denom)
{
	if(!!num)
		Reduction(num, denom);
	this->num = num;
	this->denom = denom;
}

/* Получение числителя*/
wint Fraction::get_num()
{
	return num;
}

/* Получение знаменателя*/
wint Fraction::get_denom()
{
	return denom;
}

/* Возведение дроби в целую степень*/
// p - целочисленное значение степени
wint Fraction::wpow(wint wn, int p)
{
	wint res = 1;
	if (p < 0)
	{
		for (int i = 1; i <= abs(p); i++)
			res *= wn;
		return wint(1)/res;
	}
	else
	{
		for (int i = 1; i <= p; i++)
			res *= wn;
		return res;
	}
}

/* Определение является ли число простым */
bool Fraction::isPrime(wint a)
{
	int i = 2;
	wint ndivs = wint::isqrt(a);

	while (!!(a % i))
	{
		if (i % 2)
		{
			++i;
		}
		else if (wint(++i) > ndivs) break;
	}
	if (wint(i)> ndivs)
	{
		return true;
	}
	else if (a != i)
	{
		return false;
	}
	else return true;
}

/* Определение наличия НОД != 1 двух чисел*/
bool Fraction::hasDivs(wint num, wint denom)
{
	return (GCD(num, denom) == 1) ? false : true;
}
