#include "animal.h"
#include <string>

class Cat : public Animal
{
private:
	std::string breed; //порода

public:
	Cat() : Animal() {}

	Cat(std::string owner_, std::string name_, int age_) : Cat() //можно и ... :Animal()
	{
		owner = owner_;
		animalType = "cat";
		name = name_;
		age = age_;
	}

	std::string ToEat()
	{
		std::string message;
		message =  "Cat " + name + " wants eat!\n";
		return message;
	}

	std::string ToSleep()
	{   std::string message;
		message = "Cat " + name + " want to sleep!\n";
		return message;
	}

	std::string Say()
	{
		std::string message = " meows\n";
		return name + message;
	}
};
