/**
 * Problem 2: Even Fibonacci Numbers
 *
 * Each new term in the Fibonacci sequence is generated by
 * adding the previous two terms. By starting with 1 and 2,
 * the first 10 terms will be:
 *
 * 1, 2, 3, 5, 8, 13, 21, 34, 55, 89, ...
 *
 * By considering the terms in the Fibonacci sequence whose values
 * do not exceed four million, find the sum of the even-valued terms.
 */

#include <iostream>

using namespace std;

int main ()
{
    int sum = 2; // Start from 2 because the the second term is a 2
    int fib1,fib2,fibNext;

    // Initial values
    fib1 = 1;
    fib2 = 2;

    while(fib2 < 4000000) {
        fibNext = fib1 + fib2;
        fib1 = fib2;
        fib2 = fibNext;

        // Sum of all even terms
        if(fib2%2==0) sum += fib2;
    }

    cout << "The sum of all even-valued terms is: " << sum << endl;

    return 0;
}