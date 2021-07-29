/**
 * Problem 22: Names Scores
 *
 * Using names.txt (p022.in), a 46K text file containing over five-thousand 
 * first names, begin by sorting it into alphabetical order. Then 
 * working out the alphabetical value for each name, multiply this 
 * value by its alphabetical position in the list to obtain a name score.
 * 
 * For example, when the list is sorted into alphabetical order, COLIN, 
 * which is worth 3 + 15 + 12 + 9 + 14 = 53, is the 938th name in the 
 * list. So, COLIN would obtain a score of 938 × 53 = 49714.
 * 
 * What is the total of all the name scores in the file?
 */

#include <iostream>
#include <fstream>
#include <vector>
#include <algorithm>

using namespace std;

int get_name_score(string name, int index)
{
    int namescore = 0;

    for(int i=0; i<name.length(); i++) {
        namescore += (name[i]-'A'+1);
    }
    namescore *= index;

    return namescore;
}

int main()
{
    // Initialize numbers
    ifstream input ("p022.in");
    string line;
    getline(input,line);

    vector<string> names;
    int total_name_score=0;

    // Extract strings from quotations and put into vector
    bool started = false; // Marks if the quotation is the beginning or end of string
    for(int i=0,start=0; i<line.length(); i++) {
        if(line[i]=='\"') {
            if(!started) start = i;
            else names.push_back(line.substr(start+1,i-start-1));
            started = !started;
        }
    }
    sort(names.begin(),names.end());
    
    // Calculate name scores
    for(int i=0; i<names.size(); i++) {
        total_name_score += get_name_score(names[i], i+1);
    }

    cout << "The total of all name scores are: " << total_name_score << endl;

    return 0;
}