#pragma once
#include <iostream>

class Counter
{
	int value;

public:
	Counter();
	Counter(int newNum);
	void printCurrentNumber();
	void increaseNum();
	void reduceNum();
};