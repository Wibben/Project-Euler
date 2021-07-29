/**
 * Problem 23: Non-abundant Sums
 *
 * A perfect number is a number for which the sum of its proper 
 * divisors is exactly equal to the number. For example, the sum 
 * of the proper divisors of 28 would be 1 + 2 + 4 + 7 + 14 = 28, 
 * which means that 28 is a perfect number.
 * 
 * A number n is called deficient if the sum of its proper divisors 
 * is less than n and it is called abundant if this sum exceeds n.
 * 
 * As 12 is the smallest abundant number, 1 + 2 + 3 + 4 + 6 = 16, 
 * the smallest number that can be written as the sum of two abundant 
 * numbers is 24. By mathematical analysis, it can be shown that 
 * all integers greater than 28123 can be written as the sum of 
 * two abundant numbers. However, this upper limit cannot be reduced 
 * any further by analysis even though it is known that the greatest 
 * number that cannot be expressed as the sum of two abundant numbers 
 * is less than this limit.
 * 
 * Find the sum of all the positive integers which cannot be written as the sum of two abundant numbers.
 */

#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

int get_divisor_sum(int num)
{
    int divisor_sum = 0;

    for(int i=2; i<=num/2; i++) {
        if(num%i == 0) divisor_sum += (i + num/i);
    }

    // Each divisor is counted twice, 1 and the number itself are also divisors, but number itself isn't counted
    divisor_sum = divisor_sum/2 + 1;

    return divisor_sum;
}

// Since all numbers >28123 can be the sum of 2 abundant numbers,
// we can narrow our search to the combination of abundant
// numbers in the range [1,28123], the sum of the non-abundant
// numbers in this range is the sum of numbers in [1,28123] minus
// all of the numbers that are abundant sums
int main()
{
    int non_abundant_sum = (1+28123) * 28123 / 2; // Assume all numbers are non-abundant sums
    vector<int> abundant,abundant_sums;

    // Create list of abundant numbers and at the same time create list
    // of abundant sums, as there may be 2 sets of abundant numbers
    // that sum to the same value, we will generate the list first then
    // get all unique values from it
    int divisor_sum;
    for(int i=1; i<=28123; i++) {
        divisor_sum = get_divisor_sum(i);
        // Every time we find an abundant number, we can generate a new set of abundant sums
        if(divisor_sum > i) {
            abundant.push_back(i);
            for(int j=0; j<abundant.size(); j++) {
                // We only care about abundant sums in range of 28123, we can exit the 
                // loop early in that case since the abundant vector is increasing
                if(abundant[j]+i > 28123) break;
                abundant_sums.push_back(abundant[j]+i);
            }
        }
    }

    // Removing all duplicate values
    vector<int>::iterator ip;

    sort(abundant_sums.begin(), abundant_sums.end());
    ip = unique(abundant_sums.begin(), abundant_sums.end());
    abundant_sums.resize(distance(abundant_sums.begin(), ip));


    // Subtract list of abundant sums from total sum
    for(int i=0; i<abundant_sums.size(); i++) {
        non_abundant_sum -= abundant_sums[i];
    }

    cout << "The sum of all positive integers that are not the sum of 2 abundant numbers is: " << non_abundant_sum << endl;

    return 0;
}