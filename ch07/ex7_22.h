#pragma once

#include <iostream>
#include <string>

using std::istream;
using std::ostream;
using std::string;
using std::cout;
using std::endl;

class Person
{
    friend istream &read(istream &is, Person &person);
    friend ostream &print(ostream &os, const Person &person);
public:
    Person() = default;
    Person(const string sname, const string saddr):name(sname), address(saddr){}
    Person(istream &is){ read(is, *this); }
    
    string getName() const { return name; }
    string getAddress() const { return address; }

private:
    string name;
    string address;

};

istream &read(istream &is, Person &person)
{
    is >> person.name >> person.address;
    return is;
}

ostream &print(ostream &os, const Person &person)
{
    os << person.name << " " << person.address;
    return os;
}


