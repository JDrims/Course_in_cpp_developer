#pragma once
#include <stdexcept>
#include <string>

class FigureException : public std::domain_error
{
	std::string nameFigure;
public:
	explicit FigureException(const std::string& nameFigure, const std::string& message);
	std::string getNameFigure() const { return nameFigure; };
};