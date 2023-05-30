#include <iostream>
#include "Vector.h"



class MyType {
private:
    int value;
public:
    MyType() : value(0) {}
    MyType(int val) : value(val) {}

    MyType operator*(const MyType& other) const {
        return MyType(value * other.value);
    }

    friend std::ostream& operator<<(std::ostream& os, const MyType& obj);
};

std::ostream& operator<<(std::ostream& os, const MyType& obj) {
    os << obj.value;
    return os;
}

int main() {
    // Тестування шаблону класу Vector зі стандартними типами даних
    Vector<int> a(3, 1), b(3, 2);
    std::cout << "a = ";
    a.Print();
    std::cout << "b = ";
    b.Print();
    std::cout << "a * b = ";
    try {
        Vector<int> c = a * b;
        c.Print();
    }
    catch (const std::invalid_argument& e) {
        std::cout << "Error: " << e.what() << std::endl;
    }

    std::cout << "a * 2 = ";
    Vector<int> d = a * 2;
    d.Print();

    // Тестування шаблону класу Vector з користувацьким типом даних
    Vector<MyType> e(3, MyType(1)), f(3, MyType(2));
    std::cout << "e = ";
    e.Print();
    std::cout << "f = ";
    f.Print();
    std::cout << "e * f = ";
    try {
        Vector<MyType> g = e * f;
        g.Print();
    }
    catch (const std::invalid_argument& e) {
        std::cout << "Error: " << e.what() << std::endl;
    }

    std::cout << "e * 2 = ";
    Vector<MyType> h = e * MyType(2);
    h.Print();

    return 0;
}

