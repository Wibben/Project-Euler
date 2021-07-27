/**
 * Problem 20: Factorial Digit Sum
 *
 * n! means n × (n − 1) × ... × 3 × 2 × 1
 * 
 * For example, 10! = 10 × 9 × ... × 3 × 2 × 1 = 3628800, 
 * and the sum of the digits in the number 10! is 
 * 3 + 6 + 2 + 8 + 8 + 0 + 0 = 27.
 * 
 * Find the sum of the digits in the number 100!
 */

#include <iostream>
#include <vector>

using namespace std;

// Doing this the way of long multiplication, calculating value of
// each digit first and moving carrying til the very end
// Initial vector size needed = a.size() + b.size() - 1:
// A  A  A
// B  C
// --------
// AB AB AB
//    AC AC AC
vector<int> multiply(vector<int> a, vector<int> b)
{
    vector<int> product(a.size() + b.size() - 1);

    // Multiply step
    for(int i=0; i<b.size(); i++) {
        for(int j=0; j<a.size(); j++) {
            product[i+j] += b[i] * a[j];
        }
    }

    // Carrying step
    for(int i=0; i<product.size()-1; i++) {
        product[i+1] += product[i] / 10;
        product[i] = product[i] % 10;
    } 
    // Handle carrying of most significant digit
    int carry = product.back();
    product.pop_back();
    while(carry > 0) {
        product.push_back(carry%10);
        carry /= 10;
    }

    return product;
}

// Numbers will be calculated in little endian - meaning least
// significant digit will be on the first value in the vector
int main()
{
    vector<int> factorial;
    int digit_sum = 0;

    factorial.push_back(1); // Start with 1!

    for(int i=2; i<=100; i++) {
        // Convert i to little endian
        vector<int> little_endian_num;
        int j=i;
        while(j>0) {
            little_endian_num.push_back(j%10);
            j /= 10;
        }

        factorial = multiply(factorial,little_endian_num);
    }

    for(int i=0; i<factorial.size(); i++) {
        digit_sum += factorial[i];
    }

    cout << "100! = ";
    for(int i=factorial.size()-1; i>=0; i--) {
        cout << factorial[i];
    } cout << endl;

    cout << "The digit sum of 100! is: " << digit_sum << endl;

    return 0;
}