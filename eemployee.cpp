#include "eemployee.h"
#include <iostream>

Eemployee::Eemployee(std::string first_name_in,
                     std::string last_name_in,
                     std::string gender_in,
                     int age_in,
                     int category_in):
    first_name(first_name_in),
    last_name(last_name_in),
    gender(gender_in),
    age(age_in),
    category(category_in)
{}

Eemployee::~Eemployee()
{}

int Eemployee::promote()
{
   return category++;
}

int Eemployee::demote()
{
    int res;
    if ( category <= 0 ){
         res = 0;

    } else {
        res = category--;
    }

    return res;
}

void Eemployee::printinfo()
{
    std::cout << "First name: " << first_name << std::endl;
    std::cout << "Last name: " << last_name << std::endl;
    std::cout << "Gender: " << gender << std::endl;
    std::cout << "Age: " << age << std::endl;
    std::cout << "Category: " << category << std::endl;
}
