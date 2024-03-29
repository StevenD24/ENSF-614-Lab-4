/*
 *  File Name: lab4ExC.cpp
 *  Assignment: ENSF 614 Lab 4 Exercise C
 *  Lab Section: Lab B01
 *  Completed by: Steven Duong (30022492)
 *  Submission Date: Feb 12, 2023
 */

#include <iostream>
#include <fstream>
#include <sstream>
#include <stdlib.h>

const int size = 6;
using namespace std;
struct City {
    double x, y;
    char name[30];
};

void write_binary_file(City cities[], int size, char* filename);
/* PROMISES: attaches an ofstream object to a binary file named "filename" and
 * writes the content of the array cities into the file.
 */

void print_from_binary(char* filename);
/* PROMISES: uses ifstream library object to open the binary file named
 * "filename", reads the content of the file which are objects of struct City
 * (one record at a time), and displays them on the screen. It also saves the records
 * into a text-file that its name must be the filename argument, but with the extension
 * of .txt
 */


int main() {
    char bin_filename[] = "cities.bin";

    City cities[::size] = {{100, 50, "Calgary"},
                         {100, 150, "Edmonton"},
                         {50, 50, "Vancouver"},
                         {200, 50, "Regina"},
                         {500, 50, "Toronto"},
                         {200, 50, "Montreal"}};

    write_binary_file(cities, ::size, bin_filename);
    cout << "\nThe content of the binary file is:" << endl;
    print_from_binary(bin_filename);
    return 0;
}

void write_binary_file(City cities[], int size, char* filename){
    ofstream stream(filename, ios::out | ios::binary);
    if(stream.fail()){
        cerr << "failed to open file: " << filename << endl;
        exit(1);
    }

    for(int i =0; i < size; i++)
        stream.write((char*)&cities[i], sizeof(City));
    stream.close();
}

void print_from_binary(char* filename) {
    ifstream stream(filename, ios::in | ios::binary);
    if(stream.fail()){
        cerr << "failed to open file: " << filename << endl;
        exit(1);
    }

    string text_filename = string(filename) + ".txt";
    ofstream text_file(text_filename);
    if(text_file.fail()){
        cerr << "failed to open file: " << text_filename << endl;
        exit(1);
    }

    City city;
    while(stream.read((char*)&city, sizeof(City))) {
        cout << "Name: " << city.name << ", x coordinate: " << city.x << ", y coordinate: " << city.y << endl;
        text_file << "Name: " << city.name << ", x coordinate: " << city.x << ", y coordinate: " << city.y << endl;
    }

    stream.close();
    text_file.close();

    cout << "\nThe content of the text file is:" << endl;
    ifstream text_file_in(text_filename);
    if(text_file_in.fail()){
        cerr << "failed to open file: " << text_filename << endl;
        exit(1);
    }
    string line;
    while(getline(text_file_in, line)) {
        cout << line << endl;
    }
    text_file_in.close();
}

