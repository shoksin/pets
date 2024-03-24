#include"reading.cpp"

int main(){
    Cat cat1 = Cat("artem",15,"english");
    std::cout<<cat1;
    Cat cat2 = Cat("Msiha",22,"brit");
    std::cout<<cat2;
    cat2 = std::move(cat1);
    Cat cat4 = std::move(cat1);
    std::cout<<cat2;
    std::cout<<cat4;
    Dog dog1 = Dog("gosha",25,"ital");
    std::cout<<dog1;
    Dog dog2 = Dog("oleg",45,"germ");
    std::cout<<dog2;
    dog2 = dog2;
    std::cout<<dog2;

    Cat cat3 = Cat("Lesha",88,"france");
    cat3 = cat1;
    std::cout<<cat3;
    
}