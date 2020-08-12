#pragma once

#include <iostream>
#include <string>

using std::istream;
using std::ostream;
using std::string;

struct Sales_data
{
    Sales_data() = default;
    Sales_data(const string &s):bookNo(s) {}
    Sales_data(const string &s, unsigned n, double p):bookNo(s), units_sold(n), revenue(n * p){}
    Sales_data(istream &is);

    string isbn() const { return bookNo; }
    Sales_data &combine(const Sales_data&);

    string bookNo;
    unsigned units_sold = 0;
    double revenue = 0.0;
};

istream &read(istream &is, Sales_data &item)
{
    double price;
    is >> item.bookNo >> item.units_sold >> price;
    item.revenue = item.units_sold * price;
    return is;
}

ostream &print(ostream &os, Sales_data &item)
{
    os << item.bookNo << " " << item.units_sold << " " << item.revenue;
    return os;
}

Sales_data add(const Sales_data &s1, const Sales_data &s2)
{
    Sales_data sum = s1;
    sum.combine(s2);
    return sum;
}

Sales_data::Sales_data(istream &is)
{
    read(is, *this);
}

Sales_data &Sales_data::combine(const Sales_data &s)
{
    units_sold += s.units_sold;
    revenue += s.revenue;
    return *this;
}













