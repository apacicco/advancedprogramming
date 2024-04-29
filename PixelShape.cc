//  COPYRIGHT apacicco
#include<iostream>
#include"PixelShape.h"
using std::cout;
using std::endl;
using std::cin;
using std::string;
using std::ostream;

namespace CSCE240_Program6 {
  PixelShape::PixelShape(string name, char c) : 
    _name("?"), _pixel('*'){
    SetName(name);
	SetPixel(c);
  }
  
  void PixelShape::Print( bool boolean ) const {
    cout << _name << endl;
  }
  
} 


