/**
 * Problem 15: Lattice Paths
 *
 * Starting in the top left corner of a 2×2 grid, and only being
 * able to move to the right and down, there are exactly 6 routes
 * to the bottom right corner.
 *
 * How many such routes are there through a 20×20 grid?
 */

#include <iostream>
#include <iomanip>

using namespace std;

// Computes the factorial of a number n, since doubles only work
// for storing factorials of small n (n<=171), efficiency doesn't
// really matter. A recursive method is used because it's only 2 lines
double factorial(double n)
{
    if(n==0 || n==1) return 1;
    return n * factorial(n-1);
}

int main ()
{
    // Mathod: The numeber of ways to reach the bottom right corner
    // of an N x N grid is actually the number at row n=2*N and column k=N
    // of the Pascal's Triangle. Which can be computed by nCk = n!/(k!*(n-k)!)
    int N = 20;
    int n = 2*N;
    int k = N;

    // Compute nCk
    double routes = factorial(n)/(factorial(k)*factorial(n-k)) ;

    cout << "There are " << setprecision(15) << routes << " routes from the top left to the bottom right of an ";
    cout << N << " x " << N  << " grid" << endl;

    return 0;
}
