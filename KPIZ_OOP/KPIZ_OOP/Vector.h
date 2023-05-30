// KPIZ_OOP.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#pragma once
#include <iostream>
#include <iomanip>

template<typename T>
class Vector {
private:
    T* data;   // вказівник на масив даних
    int size;  // розмір вектора
public:
    // Конструктор за замовчуванням
    Vector() {
        size = 0;
        data = nullptr;
    }

    // Конструктор з параметром
    Vector(int n, T value = T()) {
        size = n;
        data = new T[size];
        for (int i = 0; i < size; i++) {
            data[i] = value;
        }
    }

    // Конструктор копіювання
    Vector(const Vector& other) {
        size = other.size;
        data = new T[size];
        for (int i = 0; i < size; i++) {
            data[i] = other.data[i];
        }
    }

    // Деструктор
    ~Vector() {
        delete[] data;
    }

    // Оператор присвоєння
    Vector& operator=(const Vector& other) {
        if (this == &other) {
            return *this;
        }
        delete[] data;
        size = other.size;
        data = new T[size];
        for (int i = 0; i < size; i++) {
            data[i] = other.data[i];
        }
        return *this;
    }

    // Оператор доступу за індексом
    T& operator[](int index) {
        return data[index];
    }

    // Оператор множення векторів
    Vector operator*(const Vector& other) const {
        if (size != other.size) {
            throw std::invalid_argument("Vectors have different sizes.");
        }
        Vector result(size);
        for (int i = 0; i < size; i++) {
            result[i] = data[i] * other.data[i];
        }
        return result;
    }

    // Оператор множення вектора на число
    Vector operator*(T scalar) const {
        Vector result(size);
        for (int i = 0; i < size; i++) {
            result[i] = data[i] * scalar;
        }
        return result;
    }

    // Метод виведення вектора на екран
    void Print() const {
        std::cout << "[";
        for (int i = 0; i < size; i++) {
            std::cout << std::setw(8) << data[i];
        }
        std::cout << " ]\n";
    }
};
