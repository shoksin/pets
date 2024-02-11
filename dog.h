#include "animal.h"
#include <string>

class Dog : public Animal
{
private:
	std::string breed;
public:
	Dog() : Animal(){}

	Dog(std::string owner_, std::string animalType_, std::string name_, int age_) : Animal(){
		owner = owner_;
		animalType = animalType_;
		name = name_;
		age = age_;
	}


	std::string woof()
	{
		std::string message = " says woof";
		return name + message;
	}

	void fdf()
	{
	}
};

