#include "Timer.h"
#include <vector>
#include <algorithm>
#include <string>
#include <fstream>

//========================_Task_1_========================

template <typename T>
void Swap(T *x, T *y)
{
	std::swap( *x, *y);
}

//========================_Task_2_========================

template <typename T>
void SortPointers(std::vector<T> &vec)
{
	std::sort(vec.begin(), vec.end(), [](const auto& vec1, const auto& vec2)
		{
			return vec1 < vec2;
		});
}



//========================_Task_3_========================
const std::string_view vowels{ "ÀÅÈÎÓÛÝÞßàåèîóûýþÿ" };   

void countIfFind(const std::string_view& str)
{
	Timer t("Count vowels - method 1(Count_if & find)");
	
	size_t count = std::count_if(str.begin(), str.end(), [&](const auto& c)
		{
			return vowels.find(c) != std::string::npos;
		});
	
	std::cout << count << std::endl;
	
	t.print();
}

void countIfFor(const std::string_view& str)
{
	Timer t("Count vowels - method 2(Count_if & for)");
	
	size_t count = std::count_if(str.begin(), str.end(), [&](const auto& c)
		{
			for (size_t i = 0; i < vowels.size(); ++i)
			{
				if (vowels[i] == c)
					return true;
			}
			return false;
		});
	std::cout << count << std::endl;
	t.print();
}
void forFind(const std::string_view& str)
{
	Timer t("Count vowels - method 3(For & find)");
	
	size_t count = 0;

	for (size_t i = 0; i < str.size(); ++i)
	{
		if (vowels.find(str[i]) != std::string::npos)
		{
			++count;
		}
	}
	std::cout << count << std:: endl;
	t.print();
}

void twoFor(const std::string_view& str)
{
	Timer t("Count vowels - method 4(For & for)");
	
	size_t count = 0;

	for (size_t i = 0; i < str.size(); ++i)
	{
		for (size_t j = 0; j < vowels.size(); ++j)
		{
			if (vowels[j] == str[i])
			++count;
		}
	}

	std::cout << count << std::endl;
	t.print();
}





int main()
{
	//   Task 1 test
	 
	double a{0.1212};
	double b{3.33};
	std::cout << a << " / " << b << std::endl;;
	std::cout << &a << std::endl;
	Swap(&a, &b);
	std::cout << a << " / " << b << std::endl;
	std::cout << &a << std::endl;
	std::cout << "=========================================" << "\n" << std::endl;

	//Task 2 test

	std::vector<int> myVec = {45, -6, 8, 46, -5, 0, 4};
	SortPointers(myVec);
	for (int i = 0; i < 7; ++i)
	{
		std::cout << myVec[i] << ", ";
	}
	std::cout << "\n" << "\n" << "=========================================" << "\n";
	
	
	//Task 3
		
	std::ifstream file("Voyina_I_Mir.txt");
	file.seekg(0, std::ios::end);
	size_t size = file.tellg();
	file.seekg(0);
	std::string s(size, ' ');
	file.read(&s[0], size);

	countIfFind(s);
	
	countIfFor(s);
	
	forFind(s);
	
	twoFor(s);
	
	
	return 0;
}