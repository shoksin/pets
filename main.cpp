#include <iostream>
#include <fstream>
#include "cat.h"
#include "dog.h"
#include "fish.h"
#include <map>
#include <string>
#include <vector>
#include <set>

std::string ToUpper(std::string &s) //функция приведения к верхнему регистру
{
    for (int i = 0; i < s.size(); ++i)
    {
        s[i] = toupper(s[i]);
    }
    return s;
}

std::string ToNormal(std::string s) //функция приведения к виду(Word)[слово начинается с большой буквы]
{
    s[0] = toupper(s[0]);
    for (int i = 1; i < s.size(); ++i)
    {
        s[i] = tolower(s[i]);
    }
    return s;
}

int main()
{
    std::multimap<std::string, Cat> cat_map;
    std::multimap<std::string, Dog> dog_map;
    std::multimap<std::string, Fish> fish_map;
    std::multimap<std::string, Animal> animal_map;
    std::map<std::string, std::set<std::string>> unique_animals; //для задания номер 1

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

    std::string check = "";
    std::string word;
    std::vector<std::string> words;

    while (!file.eof())
    {
        getline(file, check);
        word = "";
        for (int i = 0; i < check.size(); ++i)
        {
            if (check[i] == ';')
            {
                words.push_back(word);
                word = "";
            }
            else
            {
                word += check[i];
            }
        }
        words.push_back(word);

        if (words[1] == "cat") // проверка на тип животного
        {
            Cat c = Cat(words[0], words[1], ToUpper(words[2]), stoi(words[3]));
            std::pair<std::string, Cat> pr1(words[0], c);
            std::pair<std::string, Animal> own1(words[0], c);
            cat_map.insert(pr1);
            animal_map.insert(own1);
        }
        else if (words[1] == "dog")
        {
            Dog d = Dog(words[0], words[1], ToUpper(words[2]), stoi(words[3]));
            std::pair<std::string, Dog> pr2(words[0], d);
            std::pair<std::string, Animal> own2(words[0], d);
            dog_map.insert(pr2);
            animal_map.insert(own2);
        }
        else if (words[1] == "fish")
        {
            Fish f = Fish(words[0], words[1], ToUpper(words[2]), stoi(words[3]));
            std::pair<std::string, Fish> pr3(words[0], f);
            std::pair<std::string, Animal> own3(words[0], f);
            fish_map.insert(pr3);
            animal_map.insert(own3);
        }
        unique_animals[words[0]].insert(words[1]);

        words.clear();
    }

    std::cout << "\n";
    file.close();

    for(const auto& animal:unique_animals){
       std::cout<<"Owner "<<animal.first<<" has "<<animal.second.size()<<" different animals\n";
    }

    std::cout << "-----------------------------------------------------------\n";
    std::cout << "What type of animal should I check?(Enter[CAT,DOG,FISH])\n";
    std::string checkForType;
    std::cin >> checkForType;
    checkForType = ToUpper(checkForType);

    if (checkForType == "CAT")
    {
        std::map<std::string, std::string> aboutCats;
        for (auto cats : cat_map)
        {
            std::pair<std::string, std::string> _pair(cats.first, cats.second.GetAnimalName());
            aboutCats.insert(_pair);
        }

        std::cout << "Cats:\n";

        for (auto &cats : aboutCats)
        {
            std::cout << cats.first << " " << ToNormal(cats.second) << ";\t";
        }
    }
    else if (checkForType == "DOG")
    {
        std::map<std::string, std::string> aboutDogs;
        for (auto dogs : dog_map)
        {
            std::pair<std::string, std::string> _pair(dogs.first, dogs.second.GetAnimalName());
            aboutDogs.insert(_pair);
        }

        std::cout << "Dogs:\n";

        for (auto &dogs : aboutDogs)
        {
            std::cout << dogs.first << " " << ToNormal(dogs.second) << ";\t";
        }
    }
    else if (checkForType == "FISH")
    {
        std::map<std::string, std::string> aboutFish;
        for (auto fish : fish_map)
        {
            std::pair<std::string, std::string> _pair(fish.first, fish.second.GetAnimalName());
            aboutFish.insert(_pair);
        }

        std::cout << "Fish:\n";

        for (auto &fish : aboutFish)
        {
            std::cout << fish.first << " " << ToNormal(fish.second) << ";\t";
        }
    }
    else
    {
        std::cout << "We don't have this animal(" << checkForType << ")\n";
    }

    std::cout << "\n-----------------------------------------------------------\n";

    std::string animalName = "";
    std::cout << "Enter name of animal:";
    std::cin >> animalName;
    animalName = ToNormal(animalName);
    std::cout << animalName << "\n";

    std::map<std::string, int> counter;

    for (auto &anim : animal_map)
    {
        std::string name_ = ToNormal(anim.second.GetAnimalName());
        if (animalName == name_)
        {
            std::pair<std::string, int> _pair(anim.second.GetAnimalType(), 1);
            counter.insert(_pair);
        }
    }

    std::cout << counter.size() << " types of animals with names " << animalName;

    std::cout << "\n-----------------------------------------------------------\n";

    int the_oldestAge = 0;
    int the_youngestAge = INT_MAX;

    Animal the_oldest;
    Animal the_youngest;

    for (auto anim : animal_map)
    {
        if (anim.second.GetAnimalAge() > the_oldestAge)
        {   
            the_oldest = anim.second;
            the_oldestAge = anim.second.GetAnimalAge();
        }
        if (anim.second.GetAnimalAge() < the_youngestAge)
        {
            the_youngest = anim.second;
            the_youngestAge = anim.second.GetAnimalAge();
        }
    }

    std::cout<<"The oldest animal: "<< the_oldest;
    std::cout<<"The youngest animal: "<< the_youngest;
}
