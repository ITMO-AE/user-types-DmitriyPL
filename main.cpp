#include <iostream>
#include "person.h"


int main()
{
    Person person("Polina", "Sergeeva", 1960);

    person.ChangeFirstName(1970, "Appolinaria");

    person.GetFullName(1960);

    /*person.ChangeFirstName(1965, "Polina");
    person.ChangeLastName(1967, "Sergeeva");
    for (int year : {1900, 1965, 1990}) {
       std::cout << person.GetFullName(year) << std::endl;
    }

    person.ChangeFirstName(1970, "Appolinaria");
    for (int year : {1969, 1970}) {
      std::cout << person.GetFullName(year) << std::endl;
    }

    person.ChangeLastName(1968, "Volkova");
    for (int year : {1969, 1970}) {
      std::cout << person.GetFullName(year) << std::endl;
    }
    */
    return 0;
}
