#pragma once

#include <iostream>
#include <string>

using std::istream;
using std::ostream;
using std::string;

struct Person
{
    string name;
    string address;

    string const &getName() const { return name; }
    string const &getAddress() const { return address; }

};

istream &read(istream &is, Person &p)
{
    return is >> p.name >> p.address;
}

ostream &write(ostream &os, Person &p)
{
    return os << p.name << p.address;
}
