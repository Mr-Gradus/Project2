#include "Timer.h"


template <typename T>
auto Swap(const T& a, const T& b)
{
	return (a = b && b = a);
}




int main()
{
	int a{ 3 };
	int b{ 7 };
	std::cout << a << " / " << b;
	auto swap(a, b);
	std::cout << a << " / " << b;






	return 0;
}