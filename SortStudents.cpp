#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <compare> 

class Student {

    std::string name;
    std::string surname;

public:
    Student(const std::string& name, const std::string& surname)
        : name(name), surname(surname) {}

    std::string getName() const { return name; }
    std::string getSurname() const { return surname; }

    auto operator<=>(const Student& other) const {
        if (auto cmp = surname <=> other.surname; cmp != 0) {
            return cmp; 
        }
        return name <=> other.name;
    }

    friend std::ostream& operator<<(std::ostream& os, const Student& student) {
        os << student.surname << " " << student.name;
        return os;
    }
};

void sortStudents(std::vector<Student>& students) {
    std::sort(students.begin(), students.end());
}

void printStudents(const std::vector<Student>& students) {
    for (const auto& student : students) {
        std::cout << student << std::endl;
    }
}

int main() {
    std::vector<Student> students = {
        Student("Roman", "Sukhanov"),
        Student("Aaaaa", "Aaaaaa"),
        Student("Ddddddd", "Dddd"),
        Student("Kkkkkkk", "Kkkkkkk")
    };
    std::cout << "No sort:" << std::endl;
    printStudents(students);
    sortStudents(students);
    std::cout << "sort:" << std::endl;
    printStudents(students);

    return 0;
}
