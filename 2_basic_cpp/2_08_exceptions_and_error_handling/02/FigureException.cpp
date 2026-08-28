#include "FigureException.h"

FigureException::FigureException(const std::string& nameFigure, const std::string& message)
    : std::domain_error(message), nameFigure(nameFigure)
{
}