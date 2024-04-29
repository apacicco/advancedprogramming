//  COPYRIGHT apacicco
#include<iostream>
#include"Rectangle.h"
#include<string>
using std::cout;
using std::endl;
using std::string;

namespace CSCE240_Program6 {
	Rectangle::Rectangle( int length, int width, char pixel) :
	  PixelShape("rectangle", pixel), _length(2), _width(1){
	    SetWidth(width);
		SetLength(length);
		
	  }		  
	
	Rectangle& Rectangle::operator *= (double right) {
    double product_length = _length * right;
	double product_width = _width * right;
	if ( product_length >= 1 && product_width >= 1 ) {
	  _width = product_width;
      _length = product_length;
	} 
	 return *this;
  }
  
  void Rectangle::Print(bool fill) const {
    cout << GetName() << endl;
	if ( fill == true ) { //  TO BE FILLED
	 for ( int i = 1; i < GetLength() + 1; ++i){
       for (int j = 0; j < GetWidth(); ++j) {
	     cout << GetPixel() << " ";
       }
       cout << endl;
     }
	} else { // not to be filled
	    for ( int i = 1; i < GetLength() + 1; ++i) {
           for ( int j = 0; j < GetWidth(); ++j ){
		     if (  j == GetWidth() - 1|| j == 0 || i == GetLength() || i == 1)  {
				 cout << GetPixel() << " ";
		     } else 
				 cout << "  ";		 
		    }
			cout << endl;
	    }
     }
  }
}

