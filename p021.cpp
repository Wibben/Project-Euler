/**
 * Problem 21: Amicable Numbers
 *
 * Let d(n) be defined as the sum of proper divisors of n 
 * (numbers less than n which divide evenly into n).
 * If d(a) = b and d(b) = a, where a ≠ b, then a and b are 
 * an amicable pair and each of a and b are called amicable numbers.
 * 
 * For example, the proper divisors of 220 are 1, 2, 4, 5, 10, 11, 20, 
 * 22, 44, 55 and 110; therefore d(220) = 284. The proper divisors of 
 * 284 are 1, 2, 4, 71 and 142; so d(284) = 220.
 * 
 * Evaluate the sum of all the amicable numbers under 10000.
 */

#include <iostream>
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

int main()
{
    vector<int> all_divisor_sum;
    int sum_of_amical_numbers = 0;

    all_divisor_sum.push_back(0); // Zero
    // Calculate divisor sums
    for(int i=1; i<10000; i++) {
        all_divisor_sum.push_back(get_divisor_sum(i));
    }

    // Find amicable numbers
    int val;
    for(int i=1; i<10000; i++) {
        val = all_divisor_sum[i];
        if(val<10000 && val!=i && all_divisor_sum[val]==i) sum_of_amical_numbers += val;
    }

    cout << "Sum of all amicable numbers under 10000 is: " << sum_of_amical_numbers << endl;

    return 0;
}