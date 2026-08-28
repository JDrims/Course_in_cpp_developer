#include <iostream>
using namespace std;

struct point
{
    double m_x;
    double m_y;
    point(double x, double y)
    {
        m_x = x;
        m_y = y; // присваивает значение параметра y самому себе
    }
}; // требуется точка с запятой ";"

void print_point(const point &point_object)
{
    std::cout << "x:" << point_object.m_x
              << ", y: " << point_object.m_y << std::endl;
}

int main() // main() а не Main()
{
    int i;
    for (i = 0; i < 5; i++)
    //; // лишняя точка с запятой
    {
        point my_point(i, 2 * i);
        print_point(my_point);
    }
    return 0;
}

// void print_point(const point &point_object) // дублировае функции print_point()
// {
//     std::cout << "x:" << point_object.m_x << ", y: "
//               << point_object.m_y << std::endl;
// }