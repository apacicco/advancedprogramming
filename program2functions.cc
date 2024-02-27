//COPYRIGHT 2024 apacicco
#include<iostream>
#include<cmath>
using std::cout;
using std::cin;
using std::endl;
#include"./program2functions.h"
#include<string>


//COPIED FROM BHIPP NOTES, I SWEAR HE LET ME DO IT	

bool isPrime(int n) {
  if ( n < 2 )
    return false;
  bool found_divisor = false;
  for ( int i = 2; i < n && !found_divisor; i++ )
    found_divisor = n % i == 0;
  return !found_divisor;
}


// WORKS
int ToClosestPrime(int p){// PASSED
  bool isNotPrime = true;
  int answer;// for nums 0 - p
  //for nums p - closest prime >= p, P IS INCLUSIVE
  // p will be manipulated, so it's good to store the value inputted
  

  isPrime(p);// if num is prime
  for(int i = 0; isNotPrime; i++){// I'm thinking that if we can iterate through every number between 0 & p, we can find the closest
    
	if(isPrime(p+i)){
		answer = i;// because this is first, it'll be returned and not the negative value
		isNotPrime = false;
	}
	else if(isPrime(p-i)){
		answer = -1 * i;
		isNotPrime = false;
	}
  }// end forloop
	return answer;
}




// why is this printing the upper bound
// why is it giving me random numbers
int PrintPrimesBetween(int l, int h, bool b){// higher, lower, need ambersand so it can be modified
 // cout << "int print primes b";
	int num_printed = 0;
	
	if(b == true){
	if(isPrime(l)){
	cout << l;
	num_printed++;
	}
	  for(int i = l+1; i < h; i++){
		  //cout << "in here63";
	   if(h - l <= 1){
		   break;
	   }
	   if(isPrime(i)){
		   //cout << "in here67";
		  if(num_printed == 0)
			cout << i;
			else{
			cout << ", " << i;
			
			}
			num_printed++;
		}
	  }
	  if(isPrime(h)){
		if(num_printed == 0)
			cout << h;
			else{
			cout << ", " << h;
			
			}
			num_printed++;
	  }
	}
	//BOUNDS NOT INCLUDED
	else{
	for(int i = l+1; i < h; i++){
		 //cout << "int print primes b";

		//cout << "in here76";
	   if(h - l <= 1){
		   break;
	   }
	   if(isPrime(i)){
		  if(i == h)
			  break;
		//cout << "in here82"; 
		if(num_printed == 0)
			cout << i;
		else{
		cout << ", " << i;
		}
		num_printed++;
		}
	 }
	//  cout << "int print primes b END";
	}
 
}
   



int LargestPrimeSequence(int num){// was int
  
//std::oi 
//bool prime;

	int check;
	int bigger_prime = -1;
	int modulo = 1;
	int num_copy;
  while(modulo < num){
	  modulo *= 10;
	  num_copy = num;// maintained the original num val, but needed because it allows me to cut off the digits as I move through
		while(num_copy > 0){
			check = num_copy % modulo;
			//cout << num % 10000 << endl;// this prints 
			num_copy /= 10;
			if(isPrime(check)){
				if(check > bigger_prime)
					bigger_prime = check;
			}
		}
		
  }
//for((num % 100) / 10) // for the 4th example, num % 100 = 02, / 10 = 0
  return bigger_prime;

}

int PrintAsDollarsAndCents(int num){// PASSED
	int cent_version;
	cent_version = num % 100; // final two number
	num /= 100;
	cout << "$" << num << ".";
	if(cent_version < 10){
		cout << "0" << cent_version;
	} else 
	cout << cent_version;
}

bool MakePurchase(int cost, int& twenties, int& tens, int& fives, int& ones,
                   int& quarters, int& dimes, int& nickels, int& pennies) 
	{
    int total = (twenties * 2000) 
	+ (tens * 1000) 
	+ (fives * 500) 
	+ (ones * 100) 
	+ (quarters * 25) 
	+ (dimes * 10) 
	+ (nickels * 5) 
	+ pennies;
   
    if (total < cost) 
		return false;
 
    while (cost > 1000 && twenties > 0) {// covers 17.28 by itself, do COST > 0 THROUGHOUT
        twenties -= 1;
        cost = cost - 2000;
    }
	
    while (cost > 500 && tens > 0) {
        tens -= 1;
        cost -= 1000;

    }

    while (cost > 100 && fives > 0) {
        fives -= 1;
        cost -= 500;
    }

    while (cost > 25 && ones > 0) {
        ones -= 1;
        cost -= 100;
    }

    while (cost > 10 && quarters > 0) {
        quarters -= 1;
        cost -= 25;
    }

    while (cost > 5 && dimes > 0) {
        dimes -= 1;
        cost -= 10;
    }

    while (cost > 1 && nickels > 0) {
        nickels -= 1;
        cost -= 5;
		
    }

    while (cost > 0 && pennies > 0) {
        pennies -= 1;
        cost -= 1;
		
    }
	
	
	int change = cost * -1;
	//cout << "change: " << change << endl;

	/*
		if change < 0
		
		put back through old while loops, but adding instead of subtracting
		
		use old while loop conditions to find actual change
	*/
	
	while (change >= 2000 && twenties >= 0) {// covers 17.28 by itself, do COST > 0 THROUGHOUT
        twenties++;
        change -= 2000;

    }
	
    while (change >= 1000 && tens >= 0) {
        tens++;
        change -= 1000;

    }

    while (change >= 500 && fives >= 0) {
        fives++;
        change -= 500;
		cout << "change w/ 5s: " << fives << endl;
		cout << change << endl;
    }

    while (change >= 100 && ones >= 0) {
        ones++;
        change -= 100;
    }

    while (change >= 25 && quarters >= 0) {
        quarters++;
        change -= 25;
    }

    while (change >= 10 && dimes >= 0) {
        dimes++;
        change -= 10;
    }

    while (change >= 5 && nickels >= 0) {
        nickels++;
        change -= 5;	
    }

    while (change >= 1 && pennies >= 0) {
        pennies++;
        change -= 1;
    }
    return true;
}


/*
int main() {
  int large = 123454321;
  int min = 5;
  
  cout << LargestPrimeSequence(large) << endl;
  
  
  
  
  //cout << PrintAsDollarsAndCents(dollars) << endl;
 
  
  
	
	
}

*/

/*

 //make purchase 
  int c = 1400;
  int t = 3;
  int te = 1;
  int f = 5; 
  int o = 12;
  int q = 8;
  int d = 20;
  int n = 20;
  int p = 100;
  
  MakePurchase(c, t, te, f, o, q, d, n, p);




*/
