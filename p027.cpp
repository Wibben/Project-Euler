/**
 * Problem 27: Quadratic Primes
 * 
 * Euler discovered the remarkable quadratic formula:
 * 
 *          n^2 + n + 41
 * 
 * It turns out that the formula will produce 40 primes for the 
 * consecutive integer values [0,39]. However, when n=40, 
 * 40^2 + 41*(40) + 41 is divisible by 41, and certainly when n=41,
 * which is clearly divisible by 41.
 * 
 * The incredible formula n^2 - 79n + 1601 was discovered, which 
 * produces 80 primes for the consecutive values [0,79]. The product of 
 * the coefficients, −79 and 1601, is −126479.
 * 
 * Considering quadratics of the form:
 * 
 *          n^2 + an + b, where |a|<1000 and |b|<=1000
 * 
 * Find the product of the coefficients, a and b, for the quadratic 
 * expression that produces the maximum number of primes for 
 * consecutive values of n, starting with n=0.
 */

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

// Due to the fact that n=0 must produce a prime, b must be a prime number
// We can factor the formula out to be n(n+a) + b, and look at it in terms of
// differences between primes, where p(x+1) - p(x) is divisible by n
int main()
{
    vector<int> primes;
    vector<pair<int,int>> ab;
    int n, n_sq;
    int max_ab = -1000000000;
    bool is_prime;

    // Start by generating a list of primes <1000
    // 2 is the first and only even prime number
    primes.push_back(2);

    // Only need to look at odd numbers as all even numbers are divisible by 2
    // for(int i=3; i<2001000; i+=2) {
    for(int i=3; i<2001000; i+=2) {
        is_prime = true;
        // Assuming the number is prime, if it is found to be non prime set the flag
        // to false and exit loop to check indivisibility
        for(int j=0,max_check=i; j<primes.size() && is_prime && primes[j]<max_check; j++) {
            if(i%primes[j]==0) is_prime = false;
            max_check = i/primes[j];
        }

        if(is_prime) primes.push_back(i);
    }

    cout << primes.size() << " primes genarated" << endl;

    // Create pairs of ab to test
    for(int i=-999; i<=999; i+=2) {
        for(int j=0; j<primes.size() && primes[j]<1000; j++) {
            ab.push_back(make_pair(i,primes[j]));
        }
    }

    // Since n^2 + an + b must produce primes for consecutive value of n, we can
    // walk n up from 0/1 and eliminate the pairs as they stop producing primes
    // we can skip 0 since b is a prime
    for(int i=1; ab.size()>1; i++) {
        n = i; n_sq = i*i;
        vector<pair<int,int>> next_ab;

        // If n^2 + an + b does produce a prime, add it to the list for the next n
        for(int j=0; j<ab.size(); j++) {
            if(binary_search(primes.begin(),primes.end(),n_sq+ab[j].first*n+ab[j].second)) next_ab.push_back(ab[j]);
        } 

        ab = next_ab;
    }

    cout << "The maximum product ab is: " << ab[0].first * ab[0].second << endl;

    return 0;
}