#ifndef _RECTANGLE_H_
#define _RECTANGLE_H_
using std::cout;
using std::endl;
using std::cin;
using std::string;
#include<iostream>
#include"PixelShape.h"

namespace CSCE240_Program6 {
  class Rectangle : public PixelShape {
   public:
	explicit Rectangle ( int length = 2, int width = 1, char pixel = '*');
	virtual ~Rectangle() {};
	void SetLength( int length ) {
		if ( length > 0 )
			_length = length;
	}
	int GetLength() const { return _length; }
	void SetWidth( int width ) {
		if (width > 0 )
			_width = width;
	}
	int GetWidth() const { return _width; }
	Rectangle& operator *= (const double);
	void Print( bool fill = true ) const override;
   private:
    int _width;
    int _length;	
  };


}

#endif