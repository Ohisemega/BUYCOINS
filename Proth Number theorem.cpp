#include <iostream>
#include<cmath>
//#include <boost/multiprecision/cpp_int.hpp>
using namespace std;
int eratosthenesPrimeSieve(long int);
long int prothPrime(int, int[], int);
int main()
	{
	int val;
	cout<<"Enter the Maximum number: ";//prompts the user to enter the maximum range of values
	while (val != -1)
	{
	cout<<"Enter the Maximum number: ";//prompts the user to enter the maximum range of values
	cin>>val;//store the value in variable val
	eratosthenesPrimeSieve(val);//pass by value to the function eratosthenesPrimeSieve
	}

	}

int eratosthenesPrimeSieve(long int n)
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

	//
	for (int p = 2; p*p <= n; p++)
		{
	   	if (PrimeNum[p]==true)//
			{
			 for (int t = p*p; t<=n; t = t+p)//
			 PrimeNum[t] = false;//
			}
		}


	for (int q = 2; q <= n; q++)
		{
		if (PrimeNum[q])
			{
			 pow[u] = q;
			 u++;
			}
		}

    for (int s = 0; s < u; s++)
		{
		  cout<<pow[s]<<" ";
		}
		cout<<endl;

	for (int p = 2; p <= n; p++)
		{
		if(p==n)
		   {
		    if (PrimeNum[p]==true)
			   {
			    cout<<p<<" is a prime number"<<endl;
			    prothPrime(p, pow, u);
			    break;
			   }
			else
			cout<<p<<" is NOT a prime number!"<<endl;
		   }
		}
	}

long int prothPrime(int val, int r[], int u)
{
	int result = val - 1;
	cout<<"The value of result is "<<result<<endl;
	int k, n;
	int k1, n1;
	for (k=1; k<result; k += 2)
	{
	  for (n=1; pow(2, n)<=result; n++)
	      {
	       if(result == k * pow(2, n))
	           {
                k1 = k;
	     	    n1 = n;
	     	    break;
				}
		   }
    }
    cout<<"k = "<<k1<<endl;
    cout<<"n = "<<n1<<endl;
if (k1 < pow(2, n1))
    {
    for (int m = 1; m <= u; m++)
        {
        long long int b = pow(m, result/2);
        cout<<"result/2 = "<<result/2<<endl;
        cout<<"b = "<<b<<endl;
        long long int det = (b+1) % val;
        if (det == 0)
        	{
        	 cout<<val<<" is a Proth Prime number"<<endl;
        	 break;
			}
		if (m==u)
		     cout<<val<<" is not a Proth Prime number"<<endl;
        }
    }
    else
    cout<<val<<" is a prime Number but not a Proth Prime"<<endl;
    //break;

}

