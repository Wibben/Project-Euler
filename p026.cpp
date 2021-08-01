/**
 * Problem 26: Reciprocal Cycles
 * 
 * A unit fraction contains 1 in the numerator. The decimal 
 * representation of the unit fractions with denominators 2 to 10 are given:
 * 
 *     1/2	= 	0.5         1/7 	= 	0.(142857)
 *     1/3	= 	0.(3)       1/8 	= 	0.125
 *     1/4	= 	0.25        1/9	    = 	0.(1)
 *     1/5	= 	0.2         1/10	= 	0.1 
 *     1/6	= 	0.1(6)
 * 
 * Where 0.1(6) means 0.166666..., and has a 1-digit recurring cycle. 
 * It can be seen that 1/7 has a 6-digit recurring cycle.
 * 
 * Find the value of d < 1000 for which 1/d contains the 
 * longest recurring cycle in its decimal fraction part.
 */

#include <iostream>
#include <algorithm>
#include <math.h>
#include <vector>

using namespace std;

int get_reciprocal_cycle_length(int divisor)
{
    int digits = 0;
    int dividend = 1; // Start with 1 because reciprocal
    vector<int> prev_dividends;
    vector<int>::iterator it;

    // The cout's can convieniently generate the repeating decimal
    // cout << divisor << ": " << endl;
    do {
        // Multiply dividend by 10 until greater than divisor
        while(dividend < divisor) {
            dividend *= 10;
            // cout << "0";
        }
        // As long as this divisor hasn't been used before, add it to list of used divisors
        // otherwise, we are entering a cycle
        it = find(prev_dividends.begin(),prev_dividends.end(),dividend);
        if(it!=prev_dividends.end()) break;
        else prev_dividends.push_back(dividend);
        // cout << dividend/divisor;
        // The new dividend is the remainder multiplied by 10 (because including next digit)
        dividend = (dividend % divisor)*10;
    } while(dividend!=0);
    // cout << endl;

    // Start from the location where the iterator was found til the end
    // If value has no recurring numbers, it will beggin on prev_dividends.end()
    // Some divisors contribute more than one digit, which this checks
    for(it=find(prev_dividends.begin(),prev_dividends.end(),dividend); it!=prev_dividends.end(); it++) {
        *it = (*it % divisor);
        while(*it < divisor) {
            digits++;
            *it *= 10;
        }
    }

    return digits;
}

int main()
{
    int longest_cycle=0;
    int longest_cycle_num=0;
    int cycle;

    // Go through all the numbers and keep track of the max
    for(int i=2; i<1000; i++) {
        cycle = get_reciprocal_cycle_length(i);

        if(cycle > longest_cycle) {
            longest_cycle = cycle;
            longest_cycle_num = i;
        }
    }

    cout << "The longest recurring cycle for 1/d where d<1000 is: " << longest_cycle << ", from 1/" << longest_cycle_num << endl;

    return 0;
}

