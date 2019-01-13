#ifndef PERSON_H
#define PERSON_H

#include <string>
#include <vector>
#include <iostream>

class Person
{
public:
    Person(std::string first_name, std::string last_name, int year_of_birth);
    ~Person();

    void ChangeFirstName (int year, const std::string& first_name);
    void ChangeLastName (int year, const std::string& last_name);
    std::string GetFullName (int year);
    void GetFullNameWithHistory (int year);

private:

    std::string f_name;
    std::string l_name;
    int year;

    struct Note
    {

        std::string f_name;
        std::string l_name;
        int year;
        bool change_f_name;
        bool change_l_name;

        bool operator < (const Note& n) const
        {
            return year < n.year;
        }

        friend std::ostream& operator << (std::ostream &stream, const Note &obj)
        {
            stream << obj.f_name << " "
                   << obj.l_name << " "
                   << obj.year << " "
                   << obj.change_f_name << " "
                   << obj.change_l_name << " "
                   << std::endl;

            return stream;
        }

    };

    std::vector<Note> person_data;

};

#endif // PERSON_H
