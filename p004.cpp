/**
 * Problem 4: Largest Palindrome Product
 *
 * A palindromic number reads the same both ways. The largest
 * palindrome made from the product of two 2-digit numbers is
 * 9009 = 91 × 99.
 *
 * Find the largest palindrome made from the product of two 3-digit numbers
 */

#include <iostream>

using namespace std;

// Checks if a number is a palindrome by breaking it down
// into 2 strings (forwards and backwards) and comparing them
bool isPalindrome(int number)
{
    string forwards,backwards;

    forwards = backwards = "";

    // Break down the number by mod 10 and then divide 10
    while(number>0) {
        char digit = number%10+'0';
        forwards = digit + forwards;
        backwards = backwards + digit;
        number /= 10;
    }

    // If they are the same, it is a palindrome, otherwise not
    return forwards==backwards;
}

int main ()
{
    // Highly brute force method:
    // Generate all products of 3 digit numbers and
    // find the largest product that is a palindrome
    int largestPalindrome = 0;

    // Generate all sums of 3 digit numbers and then sort
    for(int i=100; i<1000; i++) {
        for(int j=100; j<1000; j++) {
            if(isPalindrome(i*j)) largestPalindrome = max(largestPalindrome,i*j);
        }
    }

    cout << "The largest palindrome made from the product of two 3-digit numbers is: " << largestPalindrome << endl;

    return 0;
}
