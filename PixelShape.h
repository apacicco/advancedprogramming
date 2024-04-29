//  COPYRIGHT apacicco
#ifndef _PIXELSHAPE_H_
#define _PIXELSHAPE_H_
#include<iostream>
using std::cout;
using std::endl;
using std::cin;
using std::string;
using std::ostream;

namespace CSCE240_Program6 {
class PixelShape {
  // because there no way to implement in this class, it has to be pure
  // can't multiply a string and a character
  // don't need left hand argument because it's already a pixel shape
  // pixelshape x*=5 == x.operator*=(5)
 public:
  virtual PixelShape& operator *= (const double) = 0;
  explicit PixelShape ( string name = "?", char pc = '*');
  virtual ~PixelShape () {
     // cout << "in pixel shape destructor" << endl;
  }
  void SetName( string name ) {
    if (name.length() >= 1)
		_name = name;
  }
  void SetPixel( char pixel ) {
    if ( pixel >= 33 && pixel <= 126 )
		_pixel = pixel;
  }
  string GetName() const { return _name; }
  char GetPixel() const { return _pixel; }
  
  virtual void Print( bool boolean = true ) const;
  
 private:
  string _name;
  char _pixel;
  
 };

}
#endif