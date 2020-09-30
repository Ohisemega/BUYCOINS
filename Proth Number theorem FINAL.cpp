#include <iostream>
#include<cmath>
//#include <boost/multiprecision/cpp_int.hpp>
using namespace std;
void eratosthenesPrimeSieve(long int);//function prototype of eratosthenesPrimeSieve
void prothPrime(int, int[], int);//function prototype of prothPrime
int main()
	{
	int val;//variable to 
	cout<<"Enter the number you wish to test or -1 to quit! ";//prompts the user to enter the maximum range of values
	while (val != -1)
	      {
	       cin>>val;//store the value in variable val
	       eratosthenesPrimeSieve(val);//pass by value to the function eratosthenesPrimeSieve
	       cout<<"Enter the number you wish to test or -1 to quit! ";
          }
	}

void eratosthenesPrimeSieve(long int n)
	{
	int u = 0;
	int pow[n];
	//we start by using the algorithm for eratosthenes Prime Sieve
	//to determine if the number n is a prime or not
	bool PrimeNum[n+1];//create a one dimensional boolean array of n+1 boolean values.

	//use a for loop to loop through the entire array and set each boolean value as true
	for (int k = 0; k <= n+1; k++)
		{
		  PrimeNum[k] = true;
		}

	    // Update all multiples of p 
        // greater than or equal to 
        // the square of it numbers 
        // which are multiple of p and are 
        // less than p^2 are already been marked. 
	for (int p = 2; p*p <= n; p++)
		{
	   	if (PrimeNum[p]==true)//
			{
			 for (int t = p*p; t<=n; t = t+p)//
			 PrimeNum[t] = false;//
			}
		}
	
	//for loop to count the number of primes before n
	for (int q = 2; q <= n; q++)
		{
		if (PrimeNum[q])
			{
			 pow[u] = q;
			 u++;
			}
		}
	//the boolean value of primeNum[n] the input variable in the array is true
	//n is a prime number!
	if (PrimeNum[n]==true)
	   {
		 prothPrime(n, pow, u);
	   }
	else
	cout<<n<<" is NOT a prime number!"<<endl;
   }
   
   
void prothPrime(int proth, int r[], int u)
{
	int result = proth - 1;//from proth's formular: n-1 == val-1
	int k, n, k1, n1;//k and n are the tempoary store variables, k1 and n1 are the permanent store variables
	// in the proth formular: [k*(2^n)] + 1
	
	//using nested loops to search for two varaibles k and n that satisfy the conditions
	for (k=1; k<result; k += 2)
	   {
	   for (n=1; pow(2, n)<=result; n++)
	       {
	       	//if the tempoary varibles meet the requirement, store in permanent variables
	         if(result == k * pow(2, n))
	            {
                 k1 = k;
	     	     n1 = n;
				}
		   }
       }
    
    //if k1 < 2^n1 according to proth's prime algorithm
if (k1 < pow(2, n1))
    {
    	//loop through numbers for a varaible b = m^((n1-1)/2) 
		//that satisfies the 
     for(int m = 1; m <= u; m++)
         {
          long long int b = pow(m, result/2);
          long long int det = (b+1) % proth;//det is the remainder of the division between b and val 
    
          if (det == 0)//if the remainder is 0, val is a Proth Prime
        	 {
        	  cout<<proth<<" is a Proth Prime number"<<endl;
        	  break;
			 }
         }
    }
 else
 cout<<proth<<" is a prime Number but not a Proth Prime"<<endl;
}

