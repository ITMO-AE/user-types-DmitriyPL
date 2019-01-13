#include "person.h"
#include <iostream>
#include <vector>
#include <iterator>
#include <algorithm>
#include <set>

Person::Person(std::string first_name, std::string last_name, int year_of_birth):
    f_name(first_name),
    l_name(last_name),
    year(year_of_birth)
{
    Note n;

    n.f_name = f_name;
    n.l_name = l_name;
    n.year = year;
    n.change_f_name = false;
    n.change_l_name = false;

    person_data.insert(n);
}

Person::~Person()
{}

void Person::ChangeFirstName(int year, const std::string& first_name)
{
    auto it = person_data.rend();

    Note n;

    n.f_name = first_name;
    n.l_name = it->l_name;
    n.year = year;
    n.change_f_name = true;
    n.change_l_name = false;

    person_data.insert(n);

    std::cout << n;

}

void Person::ChangeLastName(int year, const std::string& last_name)
{
    Note n;

    n.l_name = last_name;
    n.year = year;

    person_data.insert(n);
}

std::string Person::GetFullName(int year)
{
    /*if (person_data[0].year > year ){
        std::string res = "No person";
        return  res;
    }*/



    /*auto Comparer = [year](const Note& item)
    {
            return item.year == year;
    };

    auto iter = std::find_if(person_data.begin(), person_data.end(), Comparer);
    */

    //std::set <Note> :: iterator it = person_data.end();
    std::cout << *(person_data.begin());

    return "aa";
}

