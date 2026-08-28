#include "Greeter.h"

std::string Greeter::greet(const std::string& name) const 
{
    return "Здравствуйте, " + name + "!";
}