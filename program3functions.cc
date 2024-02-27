// COPYRIGHT 2024 Apacicco
#include<iostream>
using std::cout;
using std::cin;
using std::endl;
#include<cstdlib>
#include"program3functions.h"
#include<iomanip>
#include"p3compares.h"
using std::setw;

// OUTPUT METHOD FROM BHIPP CLASS CODE
void OutputArray(const int a[], int size) {
  for ( int i = 0; i < size; ++i )
    cout << a[i] << " ";
  cout << endl;
}
// overwritten output method, for chars
void OutputArray(const char a[], int size) {
  for ( int i = 0; i < size; ++i )
    cout << a[i] << " ";
  cout << endl;
}

void RemoveValues(int array[], int size, int removed_number){
 // int found = -999;
  for ( int i = 0; i < size; ++i ){
    if ( array[i] == removed_number ){
	  array[i] = -999;
	} 
  }
  for ( int j = size-1; j > 0; --j) { 
	  for ( int i = 0; i < j; ++i ){
		  if (array[i] == -999){
			  // more from BHIPP
			  int temp = array[i];
			  array[i] = array[i+1];
			  array[i+1] = temp;
		  }
	  }
  }
  OutputArray(array, size);
}

void ShiftArray(int array[], int size, int moved){// moved = 3
 int first_nums[size];
 while(moved < 0)
	 moved += size;// moving it back 2 = moving it forward 8
	 for ( int i = 0; i < size; ++i ) 
		 first_nums[i] = array[(i+moved)%size];
  for(int i = 0; i < size; ++i)
	  array[i] = first_nums[i];
  OutputArray(first_nums, size);
		
}

bool IsAnagram(const char array1[], const char array2[], bool is_matching){
	// matching is for case senstivity	
  bool found = false;
  //int count1, count2;
  
  char temp2[100] = "";// copy of array2
  char temp1[100] = "";// copy of array1
  for(int i = 0; array2[i] != '\0'; ++i) {
	  if(is_matching == false ) {
	    if ( array2[i] >= 'A' && array2[i] <= 'Z' )
		{// set to lower
		  temp2[i] = 'a' + array2[i]-'A';
		}
		else 
		  temp2[i] = array2[i];
	  
	  } else // left alone
		  temp2[i] = array2[i];
  
  } 
  for(int i = 0; array1[i] != '\0'; ++i) {
	  if(is_matching == false ) {
	    if ( array1[i] >= 'A' && array1[i] <= 'Z' )
		{// set to lower
		  temp1[i] = 'a' + array1[i]-'A';
		}
		else 
		  temp1[i] = array1[i];
	  
	  } else 
		  temp1[i] = array1[i];
  } 
   // cout << temp1 << " \n" << temp << endl;
  // tests for sensitivity, a=a, a!=A
  for(int i = 0; temp1[i] != '\0'; ++i){
	  found = false;
	 // cout << temp1[i] << endl;
	  if ( temp1[i] >= 'a' && temp1[i] <= 'z' || temp1[i] >= 'A' && temp1[i] <= 'Z' ){
		for(int j = 0; temp2[j] != '\0' && !found; ++j){
		  if(temp1[i] == temp2[j]){
			found = true;
			temp2[j] = ' '; // removes letter
			// cout << temp << endl;
		  } 
		} 
		if (found == false)
			return false;
	  }
  }
  
  for (int i = 0; i < sizeof(temp2); ++i ) {
	  if (temp2[i] >= 'a' && temp2[i] <= 'z' || temp2[i] >= 'A' && temp2[i] <= 'Z')
		  return false;
	  return true;
  }
  return found;
}

bool Replace1With2(char array[], int size, char find, char replacement1, char replacement2){
	int finds_found = 0;// incrementer for the number of letters we need  to find 
	                    // found. the number it outputs will indicate the number
						// of replacement characters
						// for example, if 'f' is being searched for, and it 
						// twice, this will increment to 4 as 4 replacement
						// letters are necessary
	int nulls_found = 0;// number of null spaces
	int chars_found = 0;// number of characters total
	for ( int i = 0; i < size; ++i ) {
		if ( array[i] == '\0' ){
			++nulls_found;
			// cout << i << " " << array[i] << " is a null" << endl;
		}
		if ( array[i] != '\0' ) {
			if (array[i] == find) {
			  finds_found+=2;
			  // cout << i << " " << array[i] << " is a find" << endl;
		    } else {
			  chars_found++;	
			  // cout << i << " " << array[i] << " is a char" << endl;
			}
		}
	}
	if( finds_found + chars_found >= size ) {
		// cout << finds_found + nulls_found + chars_found << " > " << size << endl;
		OutputArray(array, size);
		return false;
	}		
    else {
		for(int i = 0; i < size; ++i){ // && array[size-1] == '\0' && array[size-2] == '\0'
		  // count finds, count chars, add number of finds + replacements + size if > size then cant do it
		  // finds_found++;
		  if(array[i] == find){
			array[i] = replacement1;
			int j;
			for( j = i+1; array[j] != '\0'; ++j) {
			  
			}
			for(; j > i+1; --j){
			  array[j] = array[j-1];
			}
			array[i+1] = replacement2;
			
		  }
	    }
	  OutputArray(array, size);
	  return true;
	}
	
}


void SwapRowsAndColumns( int array[kSquareSize][kSquareSize] ) {
  int temp[kSquareSize][kSquareSize];
  for( int i = 0; i < kSquareSize; ++i ) {
    for( int j = 0; j < kSquareSize; ++j ) {
	  temp[i][j] = array[i][j];
	}
  }
  for( int i = 0; i < kSquareSize; ++i ) {
	for( int j = 0; j < kSquareSize; ++j ) {
	  array[i][j] = temp[j][i];
	}
  }
}


