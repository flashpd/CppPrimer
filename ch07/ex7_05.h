#pragma once

#include <string>

using std::string;

class ex7_05
{
public:
    string get_name() const { return this->name; }
    string get_address() const { return this->address; }
private:
    string name;
    string address;
};

