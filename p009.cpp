/**
 * Problem 9: Special Pythagorean Triplet
 *
 * A Pythagorean triplet is a set of three natural numbers,
 * a < b < c, for which,
 *       a^2 + b^2 = c^2
 *
 * For example, 3^2 + 4^2 = 9 + 16 = 25 = 5^2.
 *
 * There exists exactly one Pythagorean triplet for which
 * a + b + c = 1000. Find the product abc.
 */

#include <iostream>
#include <vector>
#include <cmath>

using namespace std;

int main ()
{
    // Method: Check all sets of triplets to see if they match the criteron:
    // To run less loops, the one criteria is: a + b + sqrt(a*a + b*b) = abcSum
    int abcSum;
    vector<int> product;

    abcSum = 1000;

    // Loop and check for all a < b, find all products of abc that have the sum
    for(int a=1; a<=abcSum; a++) {
        for(int b=a; b<=abcSum; b++) {
            if(a+b+sqrt(a*a+b*b) == abcSum) product.push_back(a*b*sqrt(a*a+b*b));
        }
    }

    // Output all product(s)
    cout << "The products abc of all Pythagorean triples such that a+b+c = " << abcSum << " are:" << endl;
    for(int i=0; i<product.size(); i++) {
        cout << product[i] << endl;
    }

    return 0;
}
