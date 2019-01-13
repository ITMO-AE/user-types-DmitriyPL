#include <iostream>
#include <vector>
#include "eemployee.h"

int main()
{
    std::vector<Eemployee> umichWorks;

    Eemployee empl1("Dmitriy", "Plotitsyn", "male", 30, 2);
    Eemployee empl2("Oleg", "Vlasov", "male", 35, 1);
    Eemployee empl3("Dasha", "Ivanova", "female", 28, 3);

    umichWorks.push_back(empl1);
    umichWorks.push_back(empl2);
    umichWorks.push_back(empl3);

    std::cout << std::endl << "Welcom to umichWorks! Hear are our loyal employees: " << std::endl;
    for (auto Employee: umichWorks)
    {
        std::cout << std::endl;
        Employee.printinfo();
    }

    umichWorks[0].promote();
    umichWorks[1].demote();
    umichWorks[2].demote();

    std::cout << std::endl << "Here is the new info for the employees of umichWorks: " << std::endl;
    for (auto Employee: umichWorks)
    {
        std::cout << std::endl;
        Employee.printinfo();
    }

    return 0;
}
