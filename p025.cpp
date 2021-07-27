/**
 * Problem 25: 1000-digit Fibonacci Number
 * 
 * The Fibonacci sequence is defined by the recurrence relation:
 * 
 *   Fn = Fn−1 + Fn−2, where F1 = 1 and F2 = 1.
 * 
 * Hence the first 12 terms will be:
 * 
 *   F1 = 1         F7 = 13
 *   F2 = 1         F8 = 21
 *   F3 = 2         F9 = 34
 *   F4 = 3         F10 = 55
 *   F5 = 5         F11 = 89
 *   F6 = 8         F12 = 144
 * 
 * The 12th term, F12, is the first term to contain three digits.
 * 
 * What is the index of the first term in the Fibonacci sequence 
 * to contain 1000 digits?
 */

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

// Doing this the way of long addition, calculating value of
// each digit first and moving carrying til the very end
vector<int> add(vector<int> a, vector<int> b)
{
    vector<int> sum(max(a.size(),b.size()));

    // Add step
    for(int i=0; i<a.size(); i++) {
        sum[i] += a[i];
    }
    for(int i=0; i<b.size(); i++) {
        sum[i] += b[i];
    }

    // Carrying step
    for(int i=0; i<sum.size()-1; i++) {
        sum[i+1] += sum[i] / 10;
        sum[i] = sum[i] % 10;
    } 
    // Handle carrying of most significant digit
    int carry = sum.back();
    sum.pop_back();
    while(carry > 0) {
        sum.push_back(carry%10);
        carry /= 10;
    }

    return sum;
}

// Numbers will be calculated in little endian - meaning least
// significant digit will be on the first value in the vector
int main()
{
    vector<vector<int>> fibonacci;
    int index = 2; // Start with 2 terms
    int target_digit = 1000;

    // Initialize the first 2 terms and 0th term (0, 1, 1)
    vector<int> one,zero;
    one.push_back(1);
    zero.push_back(0);
    fibonacci.push_back(zero);
    fibonacci.push_back(one);
    fibonacci.push_back(one);

    // Generate rest of Fibonacci sequence
    do {
        fibonacci.push_back(add(fibonacci[index],fibonacci[index-1]));
        index++;
    } while(fibonacci.back().size()<target_digit);

    cout << "The index of the first term with " << target_digit << " digits is: " << index << endl;

    return 0;
}