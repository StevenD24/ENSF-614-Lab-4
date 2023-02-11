/*
 *  File Name: lab4ExB.cpp
 *  Assignment: ENSF 614 Lab 4 Exercise B
 *  Lab Section: Lab B01
 *  Completed by: Steven Duong (30022492)
 *  Submission Date: Feb 12, 2023
 */

#include<vector>
#include<string>
#include <iostream>
using std::cout;
using std::cerr;
using std::endl;
using std::vector;
using std::string;

typedef vector<string> String_Vector;

String_Vector transpose(const String_Vector& sv);
// REQUIRES:
//    sv.size() >= 1
//    All the strings in sv are the same length, and that length is >= 1.
// PROMISES:
//    Return value is the "transpose" of sv, as defined in the Exercise B
//    instructions.

int main() {

    const int ROWS = 5;
    const int COLS = 4;

    char c = 'A';
    String_Vector sv;
    sv.resize(ROWS);

    for(int i = 0; i < ROWS; i++)
        for(int j = 0; j < COLS; j++) {
            sv.at(i).push_back(c);
            c++;
            if(c == 'Z' + 1)
                c = 'a';
            else if (c == 'z' + 1)
                c = 'A';
        }


    for(int i = 0; i < ROWS; i++) {
        cout<< sv.at(i);
        cout << endl;
    }

    String_Vector vs = transpose(sv);
    for(int i = 0; i < (int)vs.size(); i++)
        cout << vs.at(i) << endl;

    return 0;
}



String_Vector transpose (const String_Vector& sv) {

    String_Vector vs(sv[0].size()); // creates a vector of strings with size equal to the number of columns in sv
    for (int i = 0; i < sv.size(); i++) { // loop through each row of sv
        for (int j = 0; j < sv[i].size(); j++) { // loop through each character in the current row
            vs[j].push_back(sv[i][j]); // add the current character to the string in the corresponding column of vs
        }
    }
    return vs; // return the transposed vector of strings

}
