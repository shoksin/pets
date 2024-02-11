#include "animal.h"
#include <string>

class Cat : public Animal
{
private:
	std::string breed;
public:
	Cat() : Animal(){}

	Cat(std::string owner_, std::string animalType_, std::string name_, int age_) : Animal(){
		owner = owner_;
		animalType = animalType_;
		name = name_;
		age = age_;
	}

	std::string Say(){
		std::string message = " meows";
		return name + message;
	}
};
