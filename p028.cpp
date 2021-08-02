/**
 * Problem 28: Number Spiral Diagonals
 * 
 * Starting with the number 1 and moving to the right in a 
 * clockwise direction a 5 by 5 spiral is formed as follows:
 *                  21 22 23 24 25
 *                  20  7  8  9 10
 *                  19  6  1  2 11
 *                  18  5  4  3 12
 *                  17 16 15 14 13
 * 
 * It can be verified that the sum of the numbers on the diagonals is 101.
 * 
 * What is the sum of the numbers on the diagonals in a 1001 by 1001 spiral formed in the same way?
 */

#include <iostream>

using namespace std;

// There is a fairly simple pattern, starting from 1, the next 4 numbers
// added differ by 2 (3, 5, 7, 9), the next 4 differ by 4 (13, 17, 21, 25),
// the next 4 differ by 6 (31, 37, 43, 49), and so on and do forth
// Therefore, we just have to add it until the last number reaches 1001*1001 = 1002001
// Of course, you can just generate a polynomial using the first/second differences
// between each diagonal sum
int main()
{
    int diagonal_sum = 1; // Start from 1

    for(int next_val=3,increment=2,counter=1; next_val<=1002001; next_val+=increment,counter=(counter+1)%4) {
        if(counter == 0) increment += 2; // The increments increase by 2 for every 4 values (1 trip around the square)
        diagonal_sum += next_val;
    }

    cout << "The diagonal sum for a 1001 x 1001 square is: " << diagonal_sum << endl;

    return 0;
}