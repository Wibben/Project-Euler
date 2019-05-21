/**
 * Problem 67: Maximum Path Sum II
 *
 * By starting at the top of the triangle below and moving to adjacent
 * numbers on the row below, the maximum total from top to bottom is 23.
 *
 *    3
 *   7 4
 *  2 4 6
 * 8 5 9 3
 *
 * That is, 3 + 7 + 4 + 9 = 23.
 *
 * Find the maximum total from top to bottom in triangle.txt
 * a 15K text file containing a triangle with one-hundred rows.
 */

#include <iostream>
#include <fstream>
#include <vector>

using namespace std;

int main ()
{
    // Method: Use a vector to store each row, and a second vector to
    // store the maximum value of adding either of the adjacent in the row
    // above, starting from the second row, so each row will record the maximum
    // total possible to arrive in each position, then only the final row needs
    // to be checked to find the maximum value
    int rows = 100;
    vector<long> numbers[rows],sum[rows];
    long maxTotal = 0;

    // Initialize numbers
    ifstream input ("p067.in");
    for(int i=0; i<rows; i++) {
        numbers[i].resize(i+1);
        sum[i].resize(i+1);
        for(int j=0; j<i+1; j++) {
            input >> numbers[i][j];
        }
    }

    // First row has no rows above
    sum[0][0] = numbers[0][0];

    // Progress through the vector top down and record the maximum sum at each position
    for(int i=1; i<rows; i++) {
        // First and last positions only have one adjacent number above it
        sum[i][0] = sum[i-1][0] + numbers[i][0];
        sum[i][i] = sum[i-1][i-1] + numbers[i][i];

        // All positions in between will have 2 adjacent numbers above
        for(int j=1; j<i; j++) {
            sum[i][j] = max(sum[i-1][j-1],sum[i-1][j]) + numbers[i][j];
        }
    }

    // Find the maximum total in the last row
    for(int i=0; i<rows; i++) {
        maxTotal = max(maxTotal,sum[rows-1][i]);
    }

    // Output the maximum total
    cout << "The maximum total is " << maxTotal << endl;

    return 0;
}
