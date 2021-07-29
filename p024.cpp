/**
 * Problem 24: Lexicographic Permutations
 * 
 * A permutation is an ordered arrangement of objects. For example, 
 * 3124 is one possible permutation of the digits 1, 2, 3 and 4. 
 * If all of the permutations are listed numerically or alphabetically, 
 * we call it lexicographic order. 
 * The lexicographic permutations of 0, 1 and 2 are:
 *                  012   021   102   120   201   210
 * 
 * What is the millionth lexicographic permutation of the digits 
 * 0, 1, 2, 3, 4, 5, 6, 7, 8 and 9?
 */

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main()
{
    vector<int> digits;

    // Populate digits
    for(int i=0; i<10; i++) {
        digits.push_back(i);
    }

    // We will use next_permutation to cheese it
    for(int i=1; i<1000000; i++) {
        next_permutation(digits.begin(),digits.end());
    }

    cout << "The 1000000th permutation of 0,1,2,3,4,5,6,7,8,9 is: ";
    for(int i=0; i<digits.size(); i++) {
        cout << digits[i];
    } cout << endl;
}