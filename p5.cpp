/**
 * Problem 5: Smallest Multiple
 *
 * 2520 is the smallest number that can be divided by each of
 * the numbers from 1 to 10 without any remainder
 *
 * What is the smallest positive number that is evenly
 * divisible by all of the numbers from 1 to 20?
 */

#include <iostream>

using namespace std;

int main ()
{
    // Somewhat brute force method:
    // Uses the concept of relative primes
    // Start with an array of all of the numbers, find the relative
    // prime of each number in accordance to all of the previous numbers
    // The final product is the sum of all the relative prime remanents
    // I know the terminology isn't correct here but I think it's understandable enough...
    int lowerBound,upperBound;
    lowerBound = 1;
    upperBound = 20;

    int numElements = upperBound-lowerBound+1;
    int numbers[numElements];

    // Initialize the array
    for(int i=0; i<numElements; i++) {
        numbers[i] = lowerBound+i;
    }

    // Find the relative primes of each number:
    // e.g. if a given set is 1 2 3 4 5 6, 2 is 4's relative prime as 4%2=0 and 4/2 = 2,
    // leaving 1 2 3 2 5 6, and 1 is 6's relative prime as 6%2=0, 6/2 = 3, 3%3=0, 3/3=1
    for(int i=0; i<numElements; i++) {
        // Can for sure stop once numbers[i] = 1
        for(int j=0; j<i && numbers[i]>1; j++) {
            if(numbers[i]%numbers[j]==0) numbers[i] /= numbers[j];
        }
    }

    // Get the product to find the lowest multipls
    int product = 1;
    for(int i=0; i<numElements; i++) {
        product *= numbers[i];
    }

    cout << "The smallest positive number evenly divisible by all of the numbers from 1 to 20 is: " << product << endl;

    return 0;
}
