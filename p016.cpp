/**
 * Problem 16: Power Digit Sum
 *
 * 2^15 = 32768 and the sum of its digits is 3 + 2 + 7 + 6 + 8 = 26.
 *
 * What is the sum of the digits of the number 2^1000?
 */

#include <iostream>
#include <vector>

using namespace std;

int main ()
{
    // Method: Use a vector to store the individual digits of
    // the power in Big Endian format, and then multiply by base
    // until it reaches the correct power
    int base = 2;
    int power = 1000;
    vector<int> digits;
    int sum = 0;

    // base^0 = 1
    digits.push_back(1);

    // Keep multiplying by base until we've reached the desired power
    for(int i=0; i<power; i++) {
        // Double every digit
        for(unsigned j=0; j<digits.size(); j++) {
            digits[j] *= base;
        }

        // Work out the carries, if there is a carry at digits.back()
        // do a push back, handle everything up to digits.back() first
        for(unsigned j=0; j<digits.size()-1; j++) {
            digits[j+1] += digits[j]/10; // Carry
            digits[j] = digits[j]%10;// Remainder
        }
        // Work on final digit
        if(digits.back()>9) {
            digits.push_back(digits.back()/10); // Carry
            digits[digits.size()-2] = digits[digits.size()-2]%10; // It is no longer digits.back() after the push
        }
    }

    // Add up all of the digits
    for(unsigned i=0; i<digits.size(); i++) {
        sum += digits[i];
    }

    // Output the sum of digits
    cout << "The sum of digits of " << base << "^" << power << " is: " << sum << endl;

    return 0;
}
