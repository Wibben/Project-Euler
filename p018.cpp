/**
 * Problem 18: Maximum Path Sum I
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
 * Find the maximum total from top to bottom of the triangle below:
 *
 *                             75
 *                           95  64
 *                         17  47  82
 *                       18  35  87  10
 *                     20  04  82  47  65
 *                   19  01  23  75  03  34
 *                 88  02  77  73  07  63  67
 *               99  65  04  28  06  16  70  92
 *             41  41  26  56  83  40  80  70  33
 *           41  48  72  33  47  32  37  16  94  29
 *         53  71  44  65  25  43  91  52  97  51  14
 *       70  11  33  28  77  73  17  78  39  68  17  57
 *     91  71  52  38  17  14  91  43  58  50  27  29  48
 *   63  66  04  68  89  53  67  30  73  16  69  87  40  31
 * 04  62  98  27  23  09  70  98  73  93  38  53  60  04  23
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
    int rows = 15;
    vector<int> numbers[rows],sum[rows];
    int maxTotal = 0;

    // Initialize numbers
    ifstream input ("p018.in");
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
