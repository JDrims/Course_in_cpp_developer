#include "Counter.h"

Counter::Counter() : value(1) {
}

Counter::Counter(int newNum) : value(newNum) {

}

void Counter::printCurrentNumber() {
	std::cout << value << std::endl;
}

void Counter::increaseNum() {
	value++;
}

void Counter::reduceNum() {
	value--;
}