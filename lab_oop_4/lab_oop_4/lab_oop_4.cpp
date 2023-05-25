// lab_oop_4.cpp : This file contains the 'main' function. Program execution begins and ends there.
//


#include <iostream>
#include <string>
#include <vector>

class TObject {
public:
    virtual void Show() const = 0;
    virtual ~TObject() {}
};

class List : public TObject {
protected:
    std::string name;
    struct TItem {
        TObject* obj;
        TItem* next;
    };
    TItem* head;

public:
    List() : name(), head(nullptr) {}
    List(const std::string& nm) : name(nm), head(nullptr) {}
    virtual ~List() {
        while (head) {
            TItem* next = head->next;
            delete head->obj;
            delete head;
            head = next;
        }
    }
    void Insert(TObject* obj) {
        TItem* newItem = new TItem{ obj, nullptr };
        if (head == nullptr) {
            head = newItem;
        }
        else {
            TItem* current = head;
            while (current->next) {
                current = current->next;
            }
            current->next = newItem;
        }
    }
    virtual void Show() const = 0;
};

class AllList : public List {
public:
    AllList() : List() {}
    AllList(const std::string& nm) : List(nm) {}
    ~AllList() {}
    void Show() const override {
        std::cout << "AllList: " << name << std::endl;
        TItem* current = head;
        while (current) {
            current->obj->Show();
            current = current->next;
        }
    }
};

class Ship : public TObject {
protected:
    std::string name;
    int tonnageOfShip;

public:
    Ship(const std::string& nm, int tonnage) : name(nm), tonnageOfShip(tonnage) {}
    ~Ship() {}
    void Show() const override {
        std::cout << "Ship: " << name << ", Tonnage: " << tonnageOfShip << std::endl;
    }
    int GetTonnageOfShip() const {
        return tonnageOfShip;
    }
};

class ShipList : public List {
public:
    ShipList() : List() {}
    ShipList(const std::string& nm) : List(nm) {}
    ~ShipList() {}
    void Show() const override {
        std::cout << "ShipList: " << name << std::endl;
        TItem* current = head;
        while (current) {
            current->obj->Show();
            current = current->next;
        }
    }
    void ForEach(void (*action)(TObject*, int), int tonnage) {
        TItem* current = head;
        while (current) {
            action(current->obj, tonnage);
            current = current->next;
        }
    }
};

void tonnageOfSailboat(TObject* obj, int tonnage) {
    Ship* ship = dynamic_cast<Ship*>(obj);
    if (ship != nullptr && ship->GetTonnageOfShip() <= tonnage) {
        ship->Show();
    }
}

int main() {
    
    Ship sail1("Queen Berry", 4000);
    Ship sail2("White Castle", 4000);
    Ship sail3("Black Queen", 4000);
    Ship sail4("Red Rebbit", 4000);

    ShipList list("-Sailboats-");
    list.Insert(&sail1);
    list.Insert(&sail2);
    list.Insert(&sail3);
    list.Insert(&sail4);

    int tonnageLimit = 1000;
    list.ForEach(tonnageOfSailboat, tonnageLimit);
    list.Show();

    return 0;
}


