/**
 * Problem 14: Longest Collatz Sequence
 *
 * The following iterative sequence is defined for the set of positive integers:
 *
 * n → n/2 (n is even)
 * n → 3n + 1 (n is odd)
 *
 * Using the rule above and starting with 13, we generate the following sequence:
 * 13 → 40 → 20 → 10 → 5 → 16 → 8 → 4 → 2 → 1
 *
 * It can be seen that this sequence (starting at 13 and finishing at 1) contains 10 terms.
 * Although it has not been proved yet (Collatz Problem), it is thought that all
 * starting numbers finish at 1.
 *
 * Which starting number, under one million, produces the longest chain?
 * NOTE: Once the chain starts the terms are allowed to go above one million.
 */

#include <iostream>
#include <vector>
#include <cmath>

using namespace std;

// Counts the number of terms for a collatz sequence given a number
int countCollatzSequence(long long n)
{
    // All sequences supposedly end with 1
    int count = 1;

    // Go through the sequence and count the number of times it has been done
    while(n>1) {
        // n = n/2 if even
        // n = 3n+1 if odd
        if(n%2==0) n = n/2;
        else n = 3*n+1;
        count++;
    }

    return count;
}

int main ()
{
    // Method: Brute force, go through all numbers from 1 to 1 million
    // and keep track of the number that produces the longest chain
    int longestCount = 0;
    int longestCountNumber = 0;

    // Go through all numbers from 1-1000000
    for(int i=1; i<1000000; i++) {
        int sequenceCount = countCollatzSequence(i);

        // Update number that produces longest sequence
        if(sequenceCount>=longestCount) {
            longestCount = sequenceCount;
            longestCountNumber = i;
            cout << longestCountNumber << ": " << longestCount << endl;
        }
    }

    // Output the number that produces the longest chain
    cout << "The starting number that produces the longest chain is: " << longestCountNumber << endl;

    return 0;
}

