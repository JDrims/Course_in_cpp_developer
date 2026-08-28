#include "extended_array.h"
#include <cassert>

void test_mean_empty()
{
	ExtArray<int> empty(0);

	assert(empty.mean() == 0.0);

	std::cout << "Test mean empty. OK" << std::endl;
}

void test_mean_not_empty()
{
	ExtArray<int> empty{1};

	assert(empty.mean() != 0.0);

	std::cout << "Test mean not empty. OK" << std::endl;
}

void test_median_empty()
{
	ExtArray<int> empty(0);

	assert(empty.median() == 0.0);

	std::cout << "Test median empty. OK" << std::endl;
}

void test_median_not_empty()
{
	ExtArray<int> empty{ 1, 2, 3 };

	assert(static_cast<double>(empty.median()) != 0.0);

	std::cout << "Test median not empty. OK" << std::endl;
}

void test_mode_empty()
{
	ExtArray<int> empty(0);

	std::pair<int, int> result = empty.mode();
	int val = result.first;
	int cnt = result.second;

	assert(val == 0);
	assert(cnt == 0);

	std::cout << "Test mode empty. OK" << std::endl;
}

void test_mode_not_empty()
{
	ExtArray<int> empty{ 1, 2, 3, 4 };

	std::pair<int, int> result = empty.mode();
	int val = result.first;
	int cnt = result.second;

	assert(val != 0);
	assert(cnt != 0);

	std::cout << "Test mode not empty. OK" << std::endl;
}