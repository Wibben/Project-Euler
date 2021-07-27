/**
 * Problem 17: Number Letter Counts
 *
 * If the numbers 1 to 5 are written out in words: one, two, three, four, five, 
 * then there are 3 + 3 + 5 + 4 + 4 = 19 letters used in total.
 * 
 * If all the numbers from 1 to 1000 (one thousand) inclusive were written 
 * out in words, how many letters would be used?
 * 
 * NOTE: Do not count spaces or hyphens. For example, 342 (three hundred 
 * and forty-two) contains 23 letters and 115 (one hundred and fifteen) 
 * contains 20 letters. The use of "and" when writing out numbers is in 
 * compliance with British usage.
 */

#include <iostream>

using namespace std;

int main()
{
    // zero, one, two, three, four, five, six, seven, eight, nine
    const int ones[10] = { 0, 3, 3, 5, 4, 4, 3, 5, 5, 4 };
    // ten, eleven, twelve, thirteen, fourteen, fifteen, sixteen, seventeen, eighteen, nineteen
    const int teens[10] = { 3, 6, 6, 8, 8, 7, 7, 9, 8, 8 };
    // zero, ten, twenty, thirty, forty, fifty, sixty, seventy, eighty, ninety
    const int tens[10] = { 0, 3, 6, 6, 5, 5, 5, 7, 6, 6 };
    const int hundred = 7;
    const int thousand = 8;
    const int word_and = 3;

    int total_letter_count = 0;

    for(int i=1; i<=1000; i++) {
        if(i>=1000) { // Thousands
            total_letter_count += thousand;
            total_letter_count += ones[i/1000];
        }
        if(i%1000>=100) { // Hundreds
            total_letter_count += hundred;
            total_letter_count += ones[(i%1000)/100];
            if (i%100 > 0) total_letter_count += word_and;
        }
        if(i%100>=10 && i%100<=19) { // Teens
            total_letter_count += teens[i%10]; 
        } else { // 0-9 and 20-99
            total_letter_count += tens[(i%100)/10];
            total_letter_count += ones[i%10];
        }
        // cout << i << " - " << total_letter_count << endl;
    }

    cout << "The sum of letters from 1 to 1000 is: " << total_letter_count << endl;

    return 0;
}