#include <iostream>
#include <iomanip>
#include <stdarg.h>
#include <vector>
#include"Fraction.h"

int os_flags;
#define store_flags os_flags=cout.flags();
#define restore_flags cout.flags(os_flags);

using namespace std;

double polynom(double, int, ...);

double Sin(double, int);

void main()
{
	cout << "Value of polynom, where x = 2.0, A = 1.0, B = 5.0 is " << polynom(2.0, 2, 1.0, 5.0) << endl;
	cout << "Value of polynom, where x = 2.0, A = 1.0, B = 5.0, C = 10.0 is " << polynom(2.0, 3, 1.0, 5.0, 10.0) << endl;
	cout << "Value of polynom, where x = 2.0, A = 1.0, B = 5.0, C = 10.0, D = 15.0 is " << polynom(2.0, 4, 1.0, 5.0, 10.0, 15.0) << endl<< endl;

	double frac;
	//long long int na, da/*, nb, db*/;
	Fraction f1, f2, f3;  

	//cout << "Input a numerator and a denomenator of fraction A:	" ;
	//cin >> na >> da;
	//cout << "Input a numerator and a denomenator of fraction B:	";
	//cin >> nb >> db;
	//cout << endl;

	//f1.set_frac(na,da);
	//cout << "For simple  fraction " << na << "/" << da << " is reducted fracnion " << f1.get_num() << "/" << f1.get_denom() << endl;

	//f2.set_frac(nb,db);
	//cout << "For simple  fraction " << nb << "/" << db << " is reducted fracnion " << f2.get_num() << "/" << f2.get_denom() << endl<< endl;

	//f3 = f1 + f2;
	//cout << "Summ of fractions A + B = " << f3.get_num() << "/" << f3.get_denom() << endl;

	//f3 = f1 - f2;
	//cout << "Summ of fractions A - B = " << f3.get_num() << "/" << f3.get_denom() << endl;

	//f3 = f1 * f2;
	//cout << "Summ of fractions A * B = " << f3.get_num() << "/" << f3.get_denom() << endl;

	//f3 = f1 / f2;
	//cout << "Summ of fractions A / B = " << f3.get_num() << "/" << f3.get_denom() << endl;

	//int p; 
	////cout << "Input a degree of fraction A:	";
	////cin >> p ;
	//for (p = 0; p <= 15; p++)
	//{
	//	f3 = f1 ^ p;
	//	cout << p << ": " << f3.get_num() << "/" << f3.get_denom() << endl<< endl;
	//}

	//if(f1==f2) cout << f1.get_num() << "/" << f1.get_denom() << " == " << f2.get_num() << "/" << f2.get_denom() << endl;

	//if(f1!=f2) cout << f1.get_num() << "/" << f1.get_denom() << " != " << f2.get_num() << "/" << f2.get_denom() << endl;

	//if(f1>f2) cout << f1.get_num() << "/" << f1.get_denom() << " > " << f2.get_num() << "/" << f2.get_denom() << endl;

	//if(f1>=f2) cout << f1.get_num() << "/" << f1.get_denom() << " >= " << f2.get_num() << "/" << f2.get_denom() << endl;

	//if(f1<f2) cout << f1.get_num() << "/" << f1.get_denom() << " < " << f2.get_num() << "/" << f2.get_denom() << endl;

	//if(f1<=f2) cout << f1.get_num() << "/" << f1.get_denom() << " <= " << f2.get_num() << "/" << f2.get_denom() << endl<< endl;

	cout << "Input a decimal fraction for conversion:	" ;
	cin >> frac;
	//cout << endl;

	f3.set_frac(frac);
	cout << "For decimal  fraction " << frac << " is simple fraction " << f3.get_num() << "/" << f3.get_denom() << endl;
	//cout << "Inaccuracy calculation of simple fraction [" << frac << " - " << f3.get_num() << "/" << f3.get_denom() << "] is " << frac  - double(f3.get_num()) / f3.get_denom() << endl;
	//cout << "Relative error calculation of simple fraction [" << f3.get_num() << "/" << f3.get_denom() << "] is " << (frac  - double(f3.get_num())*100 / f3.get_denom()) / frac 
	//	<< " %" << endl;

	double x, pi = 3.1415926535897932;
	int n;
	cout << "For calculation sin( pi/4 ) input number of row members n :	";/*x and */
	cin >> /*x >>*/ n;
	x = Sin(pi / 4, n);
	store_flags
	cout << setw(16) << setprecision(15);
	cout << "sin( pi/4 ) is " << x << endl;
	cout << "Relative error calculation of sin( pi/4 ) is " << (1 / sqrt(2) - x) * 100 / (1 / sqrt(2)) << " %" << endl;
	restore_flags
}
