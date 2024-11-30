#include <iostream>
#include <string>

using std::string;
using std::cout;
using std::endl;

class Pet {
protected:
    string name;
    int age;
    string sound;

public:
    Pet(const string& name, int age, const string& sound)
        : name(name), age(age), sound(sound) {}

    virtual void makeSound() const {
        cout << name << " says: " << sound << endl;
    }

    void showInfo() const {
        cout << "Name: " << name << "\nAge: " << age << " years" << endl;
    }

    virtual ~Pet() {}
};
class Dog : public Pet {
public:
    Dog(const string& name, int age)
        : Pet(name, age, "Awoof") {}

    void makeSound() const override {
        cout << name << " barks: " << sound << endl;
    }
};

class Cat : public Pet {
public:
    Cat(const string& name, int age)
        : Pet(name, age, "Meow") {}

    void makeSound() const override {
        cout << name << " purrs: " << sound << endl;
    }
};

class Parrot : public Pet {
private:
    string favoriteWord;

public:
    Parrot(const string& name, int age, const string& favoriteWord)
        : Pet(name, age, ""), favoriteWord(favoriteWord) {}

    void makeSound() const override {
        cout << name << " says: " << favoriteWord << endl;
    }
};

int main() {
    Dog dog("Tuzik", 6);
    Cat cat("Murchuk", 3);
    Parrot parrot("Kesha", 2, "SLAVA UKRAINI");

    dog.showInfo();
    dog.makeSound();

    cat.showInfo();
    cat.makeSound();

    parrot.showInfo();
    parrot.makeSound();

    return 0;
}
