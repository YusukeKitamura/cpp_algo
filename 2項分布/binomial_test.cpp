/***********************************************************
	binomial.cpp -- 2€•ª•z
***********************************************************/
#include <iostream>
#include <iomanip>
#include <cstdlib>
#include <cmath>

void error(char *s)
{
	std::cerr << s << std::endl;
	exit(EXIT_FAILURE);
}

int main()
{
	int n;
	double p, q, s, t;

	std::cout << "n, p? "; 
	std::cin >> n;
	std::cin >> p;
	q = 1 - p;
	s = t = pow(q, n);
	if (s == 0) error("n ‚© p ‚ª‘å‚«‚·‚¬‚Ü‚·");
	for (int k = 0; k < n; k++) {
		printf("%4d %7.4f\n", k, s);
		t *= (n - k) * p / ((k + 1) * q);
		s += t;
	}
	std::cout << std::setw(4) << n << " " << std::setw(7) << std::setprecision(4)  << s << std::endl;
	printf("%4d %7.4f\n", n, s);
	return EXIT_SUCCESS;
}
