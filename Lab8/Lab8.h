#pragma once
#include <iostream>
#include <string>
#include <exception>

using namespace std;

class Array {
private:
	int n;
	int* arr;
public:
	Array(); //конструктор по умолчанию
	Array(int _n, int x = 0); //конструктор с параметрами
	Array(const Array& other); //конструктор копии
	~Array(); // деструктор
	// методы
	int length() const;
	Array operator+(const Array& arr);
	Array operator+=(const Array& arr);
	Array operator+(const int x);
	Array& operator=(const Array& arr);
	int& operator[](int i);
	int operator[](int i) const;
	int operator==(const Array& arr) const;
	int operator!=(const Array& arr) const;
	int find_index(int value) const;
	void resize(int new_size);
	Array& push(int value);
	Array& insert(int value, int idx);
	Array& remove_by_index(int idx);

	// дружественные функции
	friend ostream& operator << (ostream& out, const Array& arr);
	friend istream& operator >> (istream& in, Array& arr);
};

class Person {
private: // îáðàòèòå âíèìàíèå!!! ïîëÿ çàêðûòû äëÿ ïîòîìêîâ!
	string name;
	int age;
public:
	Person(const string& name = "noname", int age = 18) :
		name(name), age(age) {}
	friend ostream & operator<< (ostream & os, const Person & p);
};

class Student : public Person
{
private:
	string univ; // Óíèâåðñèòåò
	Array marks; // Îöåíêè
public:
	Student();
	Student(const string& name, int age, const string& u, int count);
	Student(const Student& s);
	~Student();

	Student& operator=(const Student& s);
	
	void setMark(int i, int mark);
	
	friend ostream & operator<< (ostream & os, const Student & s);
};

class ErrMark : public exception { //íàñëåäåì îò áàçîâîãî òèïà èñêëþ÷åíèé
private:
	int mark;
public:
	ErrMark(int n) :mark(n) {};
	const char* what() const { return "Error in mark"; }
	int getmark() const{return mark;}
 };


