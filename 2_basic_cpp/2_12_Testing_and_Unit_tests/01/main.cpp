#include "test_extarray.h"

int main()
{
	test_mean_empty();
	test_median_empty();
	test_mode_empty();

	test_mean_not_empty();
	test_median_not_empty();
	test_mode_not_empty();

	return 0;
}