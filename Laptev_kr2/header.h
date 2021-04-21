#pragma once
#include <iostream>
#include <string>

using namespace std;

class Student {
protected:
	string name;
	int course, group;
public:
	Student(std::string name, int course, int group) : name(name) {
		if (course <= 0)
		{
			cout << name << " has incorrect course value. Field was filled by default value\n";
			this->course = 1;
		}
		else this->course = course;
		if (group <= 0)
		{
			cout << name << " has incorrect group value. Field was filled by default value\n";
			this->group = 1;
		}
		else this->group = group;
	}
	Student() : name("noname"), course(1), group(1) {}
	string get_name() { return name; }
	int get_course() const { return course; }
	int get_group() const { return group; }
	void print(ostream& os = cout) const {
		os << name << " " << course << "." << group << "\n";
	}
};
class GraduateStudent : public Student {
private:
	string leader;
	int year;
public:
	GraduateStudent(string name, int year, string leader) :
		leader(leader) {
		if (year < 0)
		{
			cout << name << " has incorrect year value. Field was filled by default value\n";
			this->year = 2021;
		}
		else this->year = year;
		this->name = name;
	}
	string get_leader() const { return leader; }
	int get_year() const { return year; }
	void print(ostream& os = cout) const {
		os << name << " " << year << "\n";
		os << "Leader: " << leader << "\n";
	}
};
class Conscript : public Student {
private:
	double height, foot_size;
	int year;
public:
	Conscript(string name, int year, double height, double foot_size) 
	{
		if (year < 0)
		{
			cout << name << " has incorrect year value. Field was filled by default value\n";
			this->year = 2021;
		}
		else this->year = year;
		if (foot_size <= 0)
		{
			cout << name << " has incorrect foot size value. Field was filled by default value\n";
			this->foot_size = 43;
		}
		else this->foot_size = foot_size;
		if (height <= 0)
		{
			cout << name << " has incorrect height value. Field was filled by default value\n";
			this->height = 180;
		}
		else this->height = height;
		this->name = name;
	}
	double get_height() const { return height; }
	double get_foot_size() const { return foot_size; }
	int get_year() const { return year; }
	void print(ostream& os = cout) const {
		os << name << " " << year << "\n";
		os << "Height: " << height << "\n";
		os << "Foot size: " << foot_size << "\n";
	}
};

bool less_course(const Student& s1, const Student& s2) {
	return s1.get_course() < s2.get_course();
}