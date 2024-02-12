#include "animal.h"
#include <string>

class Dog : public Animal
{
private:
	std::string breed;  //порода

public:
	Dog() : Animal() {}

	Dog(std::string owner_, std::string name_, int age_) : Dog() //можно и ... :Animal()
	{
		owner = owner_;
		animalType = "dog";
		name = name_;
		age = age_;
	}

	std::string ToEat()
	{
		std::string message;
		message = "Dog " + name + " wants eat!\n";
		return message;
	}

	std::string ToSleep()
	{
		std::string message;
		message = "Dog " + name + " want to sleep!\n";
		return message;
	}

	std::string woof()
	{
		std::string message = " says woof\n";
		return name + message;
	}

};
