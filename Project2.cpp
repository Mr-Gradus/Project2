#include "Timer.h"
#include <vector>
#include <algorithm>
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
}

//void countIfFor()


//void forFind()


//void forTwo()





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
	

	//Task 2 test

	std::vector<int> myVec = {45, -6, 8, 46, -5, 0, 4};
	SortPointers(myVec);
	for (int i = 0; i < 7; ++i)
	{
		std::cout << myVec[i] << ", ";
	}


	//Task 3 test

	
	std::ifstream file("Voyina_I_Mir.txt");
	while (file.eof())
	{
		
	}


	return 0;
}