#include "person.h"
#include <iostream>
#include <vector>
#include <string>
#include <iterator>
#include <algorithm>

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

    person_data.push_back(n);
}

Person::~Person()
{}

void Person::ChangeFirstName(int year, const std::string& first_name)
{
    if (person_data[0].year > year){
        std::cout << "ChangeFirstName - No person" << std::endl;
        return;
    }

    Note n;

    n.f_name = first_name;
    n.year = year;
    n.change_f_name = true;

    n.change_l_name = false;
    n.l_name = "";

    person_data.push_back(n);

    std::sort(person_data.begin(), person_data.end());

    auto Comparer = [year](const Note& item)
    {
            return item.year == year;
    };

    auto iter = std::find_if(person_data.begin(), person_data.end(), Comparer);

    iter->l_name = (iter-1)->l_name;
    iter->change_l_name =(iter-1)->change_l_name;

    for(auto x = iter; x != person_data.end(); x++){
        x->f_name = iter->f_name;
        x->change_l_name = iter->change_l_name;
    }
}

void Person::ChangeLastName(int year, const std::string& last_name)
{
    if (person_data[0].year > year){
        std::cout << "No person";
        return;
    }

    Note n;

    n.l_name = last_name;
    n.year = year;
    n.change_l_name = true;

    n.f_name = "";
    n.change_f_name = false;

    person_data.push_back(n);

    std::sort(person_data.begin(), person_data.end());

    auto Comparer = [year](const Note& item)
    {
            return item.year == year;
    };

    auto iter = std::find_if(person_data.begin(), person_data.end(), Comparer);

    iter->f_name = (iter-1)->f_name;
    iter->change_f_name =(iter-1)->change_f_name;

    for(auto x = iter; x != person_data.end(); x++){
        x->l_name = iter->l_name;
        x->change_f_name = iter->change_f_name;
    }
}

std::string Person::GetFullName(int year)
{
    auto Comparer = [year](const Note& item)
    {
            return item.year == year;
    };

    auto iter = std::find_if(person_data.begin(), person_data.end(), Comparer);

    if (iter == person_data.end()){
        iter--;
        while (iter->year > year) {
            iter--;
        }
    }

    std::string result;

    if (person_data[0].year > year){

        result = "No person";

    } else if ( (iter->change_f_name == false) && (iter->change_l_name == false) ) {

        result = "Incognito";

    } else if ( (iter->change_f_name == false) && (iter->change_l_name == true) ) {

        result = iter->l_name + " with unknown first name";

    } else if ( (iter->change_f_name == true) && (iter->change_l_name == false) ) {

        result = iter->f_name + " with unknown last name";

    } else {

        result = iter->f_name + " " + iter->l_name;
    }

    return result;
}

void Person::GetFullNameWithHistory(int year)
{
    if (person_data[0].year > year){
        std::cout <<"No person" << std::endl << std::endl;
        return;
    }

    auto Comparer = [year](const Note& item)
    {
            return item.year == year;
    };

    auto iter = std::find_if(person_data.begin(), person_data.end(), Comparer);

    if (iter == person_data.end()){
        iter--;
        while (iter->year > year) {
            iter--;
        }
    }

    std::cout << iter->f_name + " " + iter->l_name + " ";
    std::cout << iter->year << std::endl;

    std::cout << "History: " << std::endl;

    for(auto x = person_data.begin(); x < iter; x++){
        std::cout << x->f_name << " "
                  << x->l_name << " "
                  << x->year << std::endl;
    }
    std::cout << std::endl;
}
