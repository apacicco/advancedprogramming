// Copyright 2024 APACICCO
#ifndef _MONETARYAMOUNT_H_
#define _MONETARYAMOUNT_H_

#include"MonetaryUnit.h"
#include<iostream>
using std::ostream;
class MonetaryAmount {
 public:  // make constructor explicit
  static bool display_unit_name;
  explicit MonetaryAmount(double value = 0,
   const MonetaryUnit& mu = MonetaryUnit("US dollars", "$", 1));
  bool SetValue(double v);
  bool SetUnit(const MonetaryUnit& mu);
  double GetValue() const { return _value; }
  MonetaryUnit GetUnit() const { return _unit; }
  MonetaryAmount& ConvertToUnit(const MonetaryUnit& new_unit);
  bool operator == (const MonetaryAmount& right) const;
  MonetaryAmount operator + (const MonetaryAmount& right) const;
  // the left (or only) operand is an obj of the class, it can be a memeber of 
  // that class
  bool operator < (const MonetaryAmount& right) const;
  bool operator > (const MonetaryAmount& right) const;
  friend ostream& operator << (ostream& whereto, const MonetaryAmount& ma);
  // must be a freind because cout/cin are not data members to the class
 private:
  double _value;  // US DOLLARS
  MonetaryUnit _unit;
};


#endif  // _HOME_APACICCO_CSCE240WORK_ASSIGNMENT4_MONETARYAMOUNT_H_"
