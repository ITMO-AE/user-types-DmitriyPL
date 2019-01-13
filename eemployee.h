#ifndef EEMPLOYEE_H
#define EEMPLOYEE_H

#include <string>

class Eemployee
{

public:
    Eemployee(std::string first_name_in,
              std::string last_name_in,
              std::string gender_in,
              int age_in,
              int category_in);
    ~Eemployee();
    int promote();
    int demote();
    void printinfo();

private:
    std::string first_name;
    std::string last_name;
    std::string gender;
    int age;
    int category;
};

#endif // EEMPLOYEE_H
