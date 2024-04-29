// Copyright 2024 apacicco
#include"MonetaryAmount.h"
#include"MonetaryUnit.h"
#include<iostream>
using std::ostream;

bool MonetaryAmount::display_unit_name = false;

MonetaryAmount MonetaryAmount::operator + (const MonetaryAmount& right) const {
  MonetaryAmount sum = right;
  sum.ConvertToUnit(_unit);
  sum._value += _value;
  return sum;
}
bool MonetaryAmount::operator == (const MonetaryAmount& ma) const {
  if ( _value / _unit.GetAmountEquivalentTo1Dollar()
    == ma._value / ma._unit.GetAmountEquivalentTo1Dollar())
    return true;
  return false;
}

bool MonetaryAmount::operator < (const MonetaryAmount& ma) const {
  if ( _value / _unit.GetAmountEquivalentTo1Dollar()
    < ma._value / ma._unit.GetAmountEquivalentTo1Dollar())
    return true;
  return false;
}

bool MonetaryAmount::operator > (const MonetaryAmount& ma) const {
  if ( _value / _unit.GetAmountEquivalentTo1Dollar()
    > ma._value / ma._unit.GetAmountEquivalentTo1Dollar())
    return true;
  return false;
}

ostream& operator << (ostream& whereto, const MonetaryAmount& ma) {
  if ( MonetaryAmount::display_unit_name )
    whereto << ma._value << " " << ma._unit.GetName();
  else
    whereto << ma._unit.GetSymbol() << ma._value;
  return whereto;
}

MonetaryAmount& MonetaryAmount::ConvertToUnit(const MonetaryUnit& new_unit) {
  // convert to Euros
  _value /= _unit.GetAmountEquivalentTo1Dollar();
  // convert from euors
  _value *= new_unit.GetAmountEquivalentTo1Dollar();
  _unit = new_unit;
  return *this;
}


MonetaryAmount::MonetaryAmount(double v, const MonetaryUnit& mu)
  : _unit("US dollars", "$", 1) {
  SetValue(v);
  _unit = mu;
}

bool MonetaryAmount::SetValue(double v) {
  if ( v >= 0 )
    _value = v;
  return _value == v;
}

bool MonetaryAmount::SetUnit(const MonetaryUnit& mu) {
  _unit = mu;
}