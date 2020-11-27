#ifndef FRACTION_H
#define FRACTION_H
#include<cmath>
#include"wideint.h"

class Fraction
{
public:
	Fraction();
	Fraction(wint num, wint denom)/* { set_frac(num, denom); }*/;
	Fraction(double frac) /*{ set_frac(frac); }*/;
	~Fraction() {};
	//void operator=(Fraction& a);
	Fraction operator+(Fraction& a);
	Fraction operator-(Fraction& a);
	Fraction operator*(Fraction& a);
	Fraction operator/(Fraction& a);
	Fraction operator^(int p);
	bool operator>(Fraction& a);
	bool operator<(Fraction& a);
	bool operator>=(Fraction& a);
	bool operator<=(Fraction& a);
	bool operator==(Fraction& a);
	bool operator!=(Fraction& a);
	void Reduction();
	void set_frac(double frac);
	void set_frac(wint num, wint denom);
	wint get_num();
	wint get_denom();
	wint wpow(wint, int);
private:
	uint64_t k;
	wint num = 0;
	wint denom = 1;
	void FracConverter(double frac);
	wint GCD(wint a, wint b);
	void CD(wint& na, wint& da, wint& nb, wint& db);
	void decimal_to_simple(double frac, wint &n, wint& d);
	void Reduction(wint& n, wint& d);
	bool isPrime(wint a);
	bool hasDivs(wint num, wint denom);
};

#endif // !FRACTION_H
