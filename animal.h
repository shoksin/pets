#include <iostream>
#pragma once
#include <string>

class Animal
{

protected:
	std::string name;
	std::string animalType;
	std::string owner;
	int age;

public:
	Animal()
	{
		owner = "none";
		age = 0;
		name = "";
		animalType = "";
	}

    int exeption;

	Animal(std::string owner_, std::string animalType_, std::string name_, int age_)
	{
		owner = owner_;
		try
		{
			if (animalType_ != "cat" && animalType_ != "dog" && animalType_ != "fish")
			{
				throw exeption;
			}
			else
			{
				animalType = animalType_;
			}
		}
		catch (int e)
		{
        std::cerr<<"Not avaiable!";
		exit(1);
		}
		name = name_;
		age = age_;
	}

	~Animal(){

	}

	virtual std::string ToEat() // virtual
	{
		std::string message;
		message = name + " want to eat!\n";
		return message; // возвращаю строку,чтобы вывод можно было сделать в файл
	}

	virtual std::string ToSleep()
	{
		std::string message;
		message = name + " want to sleep!\n";
		return message;
	}

	void SetAnimalOwner()
	{
		std::cin >> owner;
	}

	std::string GetAnimalOwner()
	{
		return owner;
	}

	void SetAnimalName()
	{
		std::cin >> name;
	}

	std::string GetAnimalName()
	{
		return name;
	}

	void SetAnimalAge()
	{
		std::cin >> age;
	}

	int GetAnimalAge()
	{
		return age;
	}

	std::string GetAnimalType()
	{
		return animalType;
	}

	Animal operator=(const Animal &a);

	void PrintOwnerAndName(const Animal &a)
	{
		std::cout << a.owner << " " << a.name << "\n";
	}
};

Animal Animal::operator=(const Animal &a)
{ // оператор присваивания
	owner = a.owner;
	animalType = a.animalType;
	name = a.name;
	age = a.age;
	return *this;
}

std::ostream &operator<<(std::ostream &ostream, Animal a)
{
	std::string owner_ = a.GetAnimalOwner();
	std::string animalType_ = a.GetAnimalType();
	std::string name_ = a.GetAnimalName();
	int age_ = a.GetAnimalAge();
	ostream << owner_ << " " << animalType_ << " " << name_ << " " << age_;
	ostream << "\n";
	return ostream;
}