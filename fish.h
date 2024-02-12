#include <iostream>
#include "animal.h"

class Fish : public Animal
{
private:
    std::string color;

public:
    Fish() : Animal() {}

    Fish(std::string owner_, std::string name_, int age_) : Fish() //можно и ... :Animal()
    {
        owner = owner_;
        animalType = "fish";
        name = name_;
        age = age_;
    }

    std::string ToEat()
    {
        std::string message;
        message = "Fish " + name + " wants eat!\n";
        return message;
    }

    std::string ToSleep()
    {
        std::string message;
        message = "Fish " + name + " want to sleep!\n";
        return message;
    }

    std::string Swim()
    {
        std::string message = name + " is swinmming\n";
        return message;
    }
};
