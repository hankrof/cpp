#ifndef __PERSON_H__
#define __PERSON_H__
#include <string>
namespace domain
{
    class Person
    {
    public:
        std::string firstName;
        std::string lastName;
        int age;
        inline bool operator==(const Person& p) const {
            return firstName == p.firstName &&
              lastName == p.lastName &&
              age == p.age;
        }
        inline bool operator!=(const Person& p) const {
            return !(*this == p);
        }
    };
}
#endif
