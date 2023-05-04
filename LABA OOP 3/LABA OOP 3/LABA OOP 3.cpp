// LABA OOP 3.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <vector>
#include <string>
using namespace std;

class Ship {
protected:
    static int count;// Статична змінна для підрахунку кількості створених об'єктів класу
    // Поля класу
    string name;
    int length, maxSpeed;

public:
    // Конструктор класу, ініціалізує поля класу та збільшує лічильник створених об'єктів
    Ship(const string& name, int length, int maxSpeed) : name(name), length(length), maxSpeed(maxSpeed) { count++; }
    virtual ~Ship() { count--; }// Віртуальний деструктор, зменшує лічильник при знищенні об'єкта
    // Віртуальний метод, який виводить інформацію про корабель
    virtual void printInfo() const { cout << "Ship " << name << ", length " << length << ", max speed " << maxSpeed << endl; }
    static int getCount() { return count; }// Статичний метод, який повертає кількість створених об'єктів
};

int Ship::count = 0;// Ініціалізація статичної змінної count

class Steamship : public Ship {
    int maxSpeed;

public:
    // Конструктор класу, викликає конструктор базового класу і ініціалізує додаткове поле
    Steamship(const string& name, int length, int maxSpeed) : Ship(name, length, maxSpeed), maxSpeed(maxSpeed) {}
    // Перевизначений віртуальний метод, який виводить інформацію про пароплав
    void printInfo() const override { cout << "Steamship " << name << ", length " << length << ", max speed " << maxSpeed << endl; }
};

class SailingShip : public Ship {
    int mastCount;

public:
    // Конструктор класу, викликає конструктор базового класу і ініціалізує додаткове поле
    SailingShip(const string& name, int length, int mastCount) : Ship(name, length, 0), mastCount(mastCount) {}
    // Перевизначений віртуальний метод, який виводить інформацію про вітрильник
    void printInfo() const override { cout << "Sailing ship " << name << ", length " << length << ", mast count " << mastCount << endl; }
};

class Corvette : public Steamship {
    int gunCount;

public:
    // Конструктор класу, викликає конструктор батьківського класу Steamship і ініціалізує додатове поле
    Corvette(const string& name, int length, int maxSpeed, int gunCount) : Steamship(name, length, maxSpeed), gunCount(gunCount) {}
    // Перевизначений віртуальний метод, який виводить інформацію про корвет
    void printInfo() const override { cout << "Corvette " << name << ", length " << length <<  ", gun count " << gunCount << endl; }
};

void printShips(const vector<Ship*>& ships) {// Оголошуємо функцію, яка виводить інформацію про всі кораблі з вектора
    for (const auto& ship : ships) {// Проходимося циклом по вектору кораблів
        ship->printInfo();// Викликаємо функцію printInfo() для кожного корабля
        cout << "\n";// Виводимо символ переносу рядка
    }
} 

int main() { 
    vector<Ship*> ships; 
    // Додаємо до вектора об'єкти різних класів, що успадковують від класу Ship
    ships.push_back(new Steamship("Titanic", 269, 42)); 
    ships.push_back(new SailingShip("Cutty Sark", 85, 3)); 
    ships.push_back(new Corvette("Thunderbolt", 56, 28, 6)); 

    cout << "Created " << Ship::getCount() << " ships." << endl;// Виводимо кількість створених кораблів, використовуючи статичний метод getCount() класу Ship
    printShips(ships); 

    for (auto& ship : ships) {// Звільняємо пам'ять, виділену під об'єкти вектора, і присвоюємо кожному елементу вектора значення nullptr
        delete ship;
        ship = nullptr;       
    }
    // Виводимо кількість кораблів, які залишилися (0), використовуючи статичний метод getCount() класу Ship
    cout << "Deleted " << Ship::getCount() << " ships." << endl;

    return 0;
}


