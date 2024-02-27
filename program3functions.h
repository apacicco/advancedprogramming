//HEADER 2024 apacicco
#ifndef _FEB8_H
#define _FEB8_H
#include"p3compares.h"
void RemoveValues(int array[], int size, int removed_number);
void ShiftArray(int array[], int size, int moved);
bool IsAnagram(const char array1[], const char array2[], bool is_matching = false);
bool Replace1With2(char array[], int size, char find, char replacement1, char replacement2);
void SwapRowsAndColumns(int arr[kSquareSize][kSquareSize]);
#endif