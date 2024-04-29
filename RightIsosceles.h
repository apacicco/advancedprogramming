//  COPYRIGHT apacicco
#ifndef _RIGHTISOSCELES_H_
#define _RIGHTISOSCELES_H_
using std::cout;
using std::endl;
using std::cin;
using std::string;
#include<iostream>
#include"PixelShape.h"

namespace CSCE240_Program6  {
class RightIsosceles : public PixelShape {
 public:
  RightIsosceles& operator *= (const double);
  explicit RightIsosceles( int leg = 2, char pixel = '*');
  virtual ~RightIsosceles() { }
  void SetLeg( int leg ) {
    if ( leg >= 2 )
		_leg = leg;
  }
  int GetLeg() const { return _leg; }
  void Print( bool boolean = true ) const override;
 private:
  int _leg;
 }; 
}

#endif