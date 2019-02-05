/**
 * Problem 6: Sum Square Difference
 *
 * The sum of the squares of the first ten natural numbers is,
 *      1^2 + 2^2 + ... + 10^2 = 385
 *
 * The square of the sum of the first ten natural numbers is,
 *      (1 + 2 + ... + 10)^2 = 552 = 3025
 *
 * Hence the difference between the sum of the squares of the first
 * ten natural numbers and the square of the sum is 3025 − 385 = 2640.
 *
 * Find the difference between the sum of the squares of the first
 * one hundred natural numbers and the square of the sum.
 */

#include <iostream>

using namespace std;

int main ()
{
    // Method: just calculate it
    // If you're really good at math, use some variation of
    // binomial theorem or something... I'm not good at math
    int sumOfSquares,squareOfSums;
    int difference;

    sumOfSquares = squareOfSums = 0;

    // Sum of numbers of 1-100 and their squares
    for(int i=1; i<=100; i++) {
        sumOfSquares += i*i;
        squareOfSums += i;
    }
    squareOfSums *= squareOfSums;

    difference = squareOfSums - sumOfSquares;

    cout << "The difference is: " << difference << endl;

    return 0;
}
