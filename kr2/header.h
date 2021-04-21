#pragma once
#include <iostream>
#include <string>

class Student {
protected:
	std::string name;
	int course, group;
public:
	Student(std::string name, int course, int group) :
		name(name), course(course), group(group) {}
	Student() : name("noname"), course(1), group(1) {}
	std::string get_name() { return name; }
	int get_course() const { return course; }
	int get_group() const { return group; }
	void print(std::ostream& os = std::cout) const {
		os << name << " " << course << "." << group << std::endl;
	}
};
class GraduateStudent : public Student {
private:
	std::string leader;
	int year;
public:
	GraduateStudent(std::string name, int year, std::string leader) :
		year(year), leader(leader) {
		this->name = name;
	}
	std::string get_leader()const { return leader; }
	int get_year() const { return year; }
	void print(std::ostream& os = std::cout) const {
		os << name << " " << year << "\n";
		os << "Leader: " << leader << "\n";
	}
};
class Conscript : public Student {
private:
	double height, foot_size;
	int year;
public:
	Conscript(std::string name, int year, double height, double foot_size) :
		year(year), height(height), foot_size(foot_size) {
		this->name = name;
	}
	double get_height() const { return height; }
	double get_foot_size() const { return foot_size; }
	int get_year() const { return year; }
	void print(std::ostream& os = std::cout) const {
		os << name << " " << year << "\n";
		os << "Height: " << height << "\n";
		os << "Foot size: " << foot_size << "\n";
	}
};

bool less_course(const Student& s1, const Student& s2) {
	return s1.get_course() < s2.get_course();
}