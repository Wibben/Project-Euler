/**
 * Problem 3: Largest Prime Factor
 *
 * The prime factors of 13195 are 5, 7, 13 and 29.
 *
 * What is the largest prime factor of the number 600851475143?
 *
 * Note: Interestingly 600851475145 takes much much longer
 * to compute (as in basically forever) since it is 5*120170295029
 */

#include <iostream>
#include <vector>

using namespace std;

// Get the largest prime factor of a given number, assumes number >= 2
long long getLargestPrimeFactor(long long number)
{
    // Finds the largest prime factor by going through all
    // the primes less than the upperLimit/2, if the prime is a factor
    // upperLimit will be divided by that factor until no longer
    // divisible
    long long upperLimit = number;
    long long largestFactor = -1;

    // Holds all the primes smaller than upperLimit
    vector<long long> primes;
    bool isPrime;

    cout << "Upper Limit: " << upperLimit << endl;

    // Add 2 as the first prime number and divide the
    // upperLimit until no longer divisible by 2
    while(upperLimit%2 == 0) {
        upperLimit /= 2;
        largestFactor = 2;
        cout << "2: " << upperLimit << endl;
    }
    primes.push_back(2);

    // Starting from 3, go through all the odd numbers
    // if i is not divisible by any existing primes, it is a prime
    for(long long i=3; i<=upperLimit; i+=2) {
        isPrime = true;
        // Go through current primes, stop if i is found to be non prime
        // Start from 1 because primes[0]=2, which is for sure non-divisible as
        // i is always odd
        for(int j=1; j<primes.size() && isPrime; j++) {
            if(i%primes[j] == 0) isPrime = false;
        }

        if(isPrime) {
            primes.push_back(i);
            // Now check if i is a prime factor of number, if it is,
            // divide upperLimit until no longer divisible by i
            while(upperLimit%i == 0) {
                upperLimit /= i;
                largestFactor = i;
                cout << i << ": " << upperLimit << endl;
            }
        }
    }

    // If no primes are divisible, then the number itself is prime
    return (largestFactor>0 ? largestFactor:number);
}

int main ()
{
    long long number = 600851475143;
    long long factor = getLargestPrimeFactor(number);

    cout << "The largest prime factor of " << number << " is: " << factor << endl;

    return 0;
}

/*
Alternative Solution: Much simpler to code

#include <iostream>

using namespace std;

int main ()
{
    long long number = 600851475143;
    long long savedNumber = number;

    while(number%2 == 0) {
        number /= 2;
        cout << "2: " << number << endl;
    }

    long long divisor = 3;
	while (number > 1) {
		if (0 == (number % divisor)) {
			number /= divisor;
			cout << divisor << ": " << number << endl;
			divisor-=2;
		}
		divisor+=2;
	}

    cout << "The largest prime factor of " << savedNumber << " is: " << divisor << endl;

    return 0;
}

*/