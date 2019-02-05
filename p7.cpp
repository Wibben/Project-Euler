/**
 * Problem 7: 10001st Prime
 *
 * By listing the first six prime numbers: 2, 3, 5, 7, 11, and 13,
 * we can see that the 6th prime is 13.
 *
 * What is the 10001st prime number?
 */

#include <iostream>

using namespace std;

int main ()
{
    // Method: Calculate prime numbers using pre-existing primes
    // If it is divisible by any found primes, it is not prime
    // if it is not divisible by any found primes, it is prime
	int nthPrime = 10001;
	int foundPrimes;
    bool isPrime;
	
	int primes[nthPrime];

    // 2 is the first and only even prime number
	foundPrimes = 1;
    primes[0] = 2;

    // Keep finding primes until the number of found primes reaches 10001
    // Only need to look at odd numbers as all even numbers are divisible by 2
    for(int i=3; foundPrimes<nthPrime; i+=2) {
        isPrime = true;
        // Assuming the number is prime, if it is found to be non prime set the flag
        // to false and exit loop to check indivisibility
        for(int j=0; j<foundPrimes && isPrime; j++) {
            if(i%primes[j]==0) isPrime = false;
        }

        if(isPrime) primes[foundPrimes++] = i;
    }

    // Indexing starts from 0, so the 10001st prime is at index 10000
    cout << "The 10001st prime is: " << primes[nthPrime-1] << endl;

    return 0;
}
