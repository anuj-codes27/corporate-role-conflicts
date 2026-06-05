#include <iostream>
using namespace std;

class Person {
protected:
    string name;
    int id;

public:
    Person(string n, int i) {
        name = n;
        id = i;
        cout << "Person Constructor" << endl;
    }
};

/*
❌ Diamond Problem (without virtual inheritance)

class Manager : public Person {};
class Engineer : public Person {};
→ This creates TWO copies of Person in TechLead
*/

class Manager : virtual public Person {
protected:
    string department;

public:
    Manager(string n, int i, string dept)
        : Person(n, i) {
        department = dept;
        cout << "Manager Constructor" << endl;
    }
};

class Engineer : virtual public Person {
protected:
    string project;

public:
    Engineer(string n, int i, string proj)
        : Person(n, i) {
        project = proj;
        cout << "Engineer Constructor" << endl;
    }
};

class TechLead : public Manager, public Engineer {
public:
    TechLead(string n, int i, string dept, string proj)
        : Person(n, i),      // Only ONE Person object
          Manager(n, i, dept),
          Engineer(n, i, proj) {
        cout << "TechLead Constructor" << endl;
    }

    void display() {
        cout << "Name: " << name
             << " ID: " << id
             << " Dept: " << department
             << " Project: " << project << endl;
    }
};

int main() {
    string name, dept, project;
    int id;

    cin >> name >> id >> dept >> project;

    TechLead t(name, id, dept, project);

    t.display();

    return 0;
}
