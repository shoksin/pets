#include <iostream>
#include <fstream>
#include "cat.h"
#include "dog.h"
#include "fish.h"
#include <set>
#include <map>

std::vector<Animal *> anims;//объявляю глобальными, чтобы было видо во всех task
std::vector<Person> owners;

std::string ToLower(std::string &s)
{
    for (int i = 0; i < s.size(); ++i)
    {
        s[i] = tolower(s[i]);
    }
    return s;
}

void reading(){
    std::ifstream file("input.txt");
    if (!file.is_open())
    {
        std::cerr << "File is not open!";
        exit(1);
    }
    if (file.peek() == EOF)
    {
        std::cerr << "The file is empty!";
        exit(1);
    }

    std::string owner_name = "";
    std::string str_OwnerAge = "";
    std::string animal_type = "";
    std::string breed = "";
    std::string animal_name = "";
    std::string animal_age = "";
    int ownerAge;
    int animalAge;

    while (!file.eof())
    {
        getline(file, owner_name, ',');
        getline(file, str_OwnerAge, ';');
        getline(file, animal_type, ',');
        getline(file, breed, ';');
        getline(file, animal_name, ';');
        getline(file, animal_age);
        ownerAge = stoi(str_OwnerAge);
        animalAge = stoi(animal_age);
        if (breed == ",,")
        {
            breed = "None";
        }
        if(animal_name == ",,"){
            animal_name = "None";
        }

        if (animal_type == "cat")
        {
            anims.push_back(new Cat(animal_name, animalAge, breed));
            Person pr(owner_name, ownerAge, anims[anims.size() - 1]);
            bool isFind = 0;
            for (auto &ps : owners)
            {
                if (ps.GetOwnerName() == owner_name && ps.GetOwnerAge() == ownerAge)
                {
                    ps.Push_Animal(anims[anims.size() - 1]);
                    isFind = 1;
                    break;
                }
            }
            if (!isFind)
            {
                owners.push_back(pr);
            }
        }
        if (animal_type == "dog")
        {
            anims.push_back(new Dog(animal_name, animalAge, breed));
            Person pr(owner_name, ownerAge, anims[anims.size() - 1]);
            bool isFind = 0;
            for (auto &ps : owners)
            {
                if (ps.GetOwnerName() == owner_name && ps.GetOwnerAge() == ownerAge)
                {
                    ps.Push_Animal(anims[anims.size() - 1]);
                    isFind = 1;
                    break;
                }
            }
            if (!isFind)
            {
                owners.push_back(pr);
            }
        }
        if (animal_type == "fish")
        {
            anims.push_back(new Fish(animal_name, animalAge, breed));
            Person pr(owner_name, ownerAge, anims[anims.size() - 1]);
            bool isFind = 0;
            for (auto &ps : owners)
            {
                if (ps.GetOwnerName() == owner_name && ps.GetOwnerAge() == ownerAge)
                {
                    ps.Push_Animal(anims[anims.size() - 1]);
                    isFind = 1;
                    break;
                }
            }
            if (!isFind)
            {
                owners.push_back(pr);
            }
        }

        std::string owner_name = "";
        std::string str_OwnerAge = "";
        std::string animal_type = "";
        std::string breed = "";
        std::string animal_name = "";
        std::string animal_age = "";
        int ownerAge = 0;
        int animalAge = 0;
    }
}
