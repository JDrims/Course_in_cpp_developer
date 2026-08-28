#include "Figure.h"

DLL_API Figure::Figure() : name("Фигура") {}

std::string DLL_API Figure::get_name()
{
	return name;
}