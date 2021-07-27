/**
 * Problem 19: Counting Sundays
 *
 * You are given the following information, but you may 
 * prefer to do some research for yourself.
 * 
 * - 1 Jan 1900 was a Monday.
 * - Thirty days has September,
 *   April, June and November.
 *   All the rest have thirty-one,
 *   Saving February alone,
 *   Which has twenty-eight, rain or shine.
 *   And on leap years, twenty-nine.
 * - A leap year occurs on any year evenly divisible by 4, 
 *   but not on a century unless it is divisible by 400.
 * 
 * How many Sundays fell on the first of the month during 
 * the twentieth century (1 Jan 1901 to 31 Dec 2000)?
 */

#include <iostream>

using namespace std;

int main()
{
    int year = 1900;
    // Jan, Feb. Mar, Apr, May, June, July, Aug, Sept, Oct, Nov, Dec
    int days[12] = { 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31 };
    int sunday_count = 0;
    int day_count = 1;

    // Add up the days in 1900 first
    for(int i=0; i<12; i++) {
        day_count += days[i];
    }

    // Since Jan 1, 1900 is a Monday, if daycount is divisible by 7 it is a Sunday
    for(int year=1901; year<=2000; year++) {
        // Leap year check
        if ( year%4==0 && (year%100!=0 || year%400==0)) days[1] = 29;
        else days[1] = 28;

        // Check is done first as we start at Jan 1, 1901, the addition brings us to Feb 1, 1901
        for(int i=0; i<12; i++) {
            // Sunday Check
            if(day_count%7==0) sunday_count++;
            day_count += days[i];
        }
    }

    cout << sunday_count << " Sundays fell on the first of the month in the twentieth century" << endl;

    return 0;
}