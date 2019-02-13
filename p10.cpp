/**
 * Problem 10: Summation of Primes
 *
 * The sum of the primes below 10 is 2 + 3 + 5 + 7 = 17.
 *
 * Find the sum of all the primes below two million.
 */

#include <iostream>
#include <vector>
#include <cmath>

using namespace std;

int main ()
{
    // Method: Calculate primes using pre-existing primes
    // up to 2 million, then add all the primes
    vector<int> primes;
    bool isPrime;
    int maxNumber = 2000000;
    long long sum;

    // 2 is the first and only even prime
    primes.push_back(2);
    sum = 2;

    // Keep trying to find primes until the tested number
    // is over maxNumber, only need to look at odd numbers
    for(int i=3; i<maxNumber; i+=2) {
        isPrime = true;
        // Assume the number is prime until it is found to be non-prime
        // NOTE: Adding in the primes[j] <= sqrti massively improves runtime
        // sqrt(i) takes a while to run so calculating it once and storing it
        // will make the program much faster (in the case of 2000000 almost 2x faster)
        int sqrti = sqrt(i);
        for(int j=0; j<primes.size() && isPrime && primes[j]<=sqrti; j++) {
            if(i%primes[j]==0) isPrime = false;
        }

        // If it is prime, add it to the list of primes and update sum
        if(isPrime) {
            primes.push_back(i);
            sum += i;
        }
    }

    // Output the final sum
    cout << "The sum of all prime numbers below " << maxNumber << " is: " << sum << endl;

    return 0;
}
