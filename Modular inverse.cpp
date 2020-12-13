int extended_euclidean(int a, int b, int& x, int& y) {
    if (b == 0) {
        x = 1;
        y = 0;
        return a;
    }
    int x1, y1;
    int d = gcd(b, a % b, x1, y1);
    x = y1;
    y = x1 - y1 * (a / b);
    return d;
}
int modularInverse(int a,int m){
int x, y,a,b;
int g = extended_euclidean(a, m, x, y);
    x = (x % m + m) % m;
    return x;
}
//modular inverse from 1 to n
// C++ program to find modular inverse of
// all numbers from 1 to n using naive
// method
#include<iostream>
using namespace std;

// A naive method to find modular
// multiplicative inverse of 'a'
// under modulo 'prime'
int modInverse(int a, int prime)
{
    a = a % prime;
    for (int x=1; x<prime; x++)
       if ((a*x) % prime == 1)
          return x;

    return -1;
}

void printModIverses(int n, int prime)
{
    for (int i=1; i<=n; i++)
      cout << modInverse(i, prime) << " ";
}

// Driver Program
int main()
{
    int n = 10, prime = 17;
    printModIverses(n, prime);
    return 0;
}
