/* Inheritance.cpp - Create a Person / Teacher / MathTeacher hierarchy of classes (Midterm)
 * Author:     Chris Merrill
 * Module:     10
 * Project:    Midterm Problem 4
 * Problem statement: Create a hierarchy of Person / Teacher / MathTeacher, each
 *   with a profession (string) and age (int) stored in Person, and which inherit
 *   getters and setters for those two properties.  In addition, the Teacher
 *   and MathTeacher classes have a "teach" function.
 */

#include <iostream>
using namespace std;

class Person {
private:
    string profession;
    int age;

public:

    // Add constructor which takes a profession and age, and uses an initialization
    // list to initialize both instance members
    Person(string p, int a) : profession(p), age(a){}

    // Add getters and setters
    string getProfession() const {
        return profession;
    }

    void setProfession(string p) {
        profession = p;
    }

    int getAge() const {
        return age;
    }

    void setAge(int a) {
        age = a;
    }
};

class Teacher : public Person {                 // make a child of Person

public:

    // Add a constructor which takes an age, calls Person constructor with "Teacher" as profession
    Teacher(int a, string p = "Teacher") : Person(p, a) {

    }
    // Add another constructor which takes both a profession and an age, then passes
    // both up to Person constructor
    Teacher(int a, string p) : Person(p, a) {

    }

    // Create a function teach() which prints on the console:
    //      The <profession> is teaching
    void teach() {
        cout << "The " + getProfession() + " is teaching";
    }
};

class MathTeacher : public Teacher {            // make a child of Teacher
public:
    // Add a constructor which takes an age, calls Teacher constructor with "Math Teacher" as profession
    MathTeacher(int a, string p = "Math Teacher") : Teacher(a, p) {

    }

};

#include <iostream>

int main() {

    // Create a Person object, a Teacher object, and a MathTeacher object
    Person person("Worker", 27);
    Teacher teacher(42);
    MathTeacher mathTeacher(39);

    cout << "The person's profession is: " << person.getProfession()
        << " and is " << person.getAge() << " years old" << endl;
    cout << "The teacher's profession is: " << teacher.getProfession()
        << " and is " << teacher.getAge() << " years old" << endl;
    cout << "The mathTeacher's profession is: " << mathTeacher.getProfession()
        << " and is " << mathTeacher.getAge() << " years old" << endl << endl;

    teacher.teach();
    mathTeacher.teach();

    return 0;
}