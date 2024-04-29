// Copyright 2024 apacicco
#ifndef _MONETARYUNIT_H_
#define _MONETARYUNIT_H_

#include<iostream>
using std::cout;
using std::endl;
using std::ostream;
#include<string>
using std::string;

class MonetaryUnit {
 public:
  bool operator == (const MonetaryUnit&) const;
  explicit MonetaryUnit(string name = "US dollars",
   string sym = "$", double amt = 1);
  bool SetName(string name);
  bool SetSymbol(string sym);
  string GetName() const { return _name; }
  string GetSymbol() const { return _sym; }
  bool SetAmountEquivalentTo1Dollar(double amt);
  double GetAmountEquivalentTo1Dollar() const {return _amt; }
// private members
 private:
  string _name;
  string _sym;
  double _amt;
};

#endif  // _HOME_APACICCO_CSCE240WORK_ASSIGNMENT4_MONETARYUNIT_H_
