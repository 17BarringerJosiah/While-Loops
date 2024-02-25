// Project4.cpp : This file contains the 'main' function. Program execution begins and ends there.
//


// <Project4> -- Programming: While Loops Assignment
// CSIS111-<B01>

#include <iostream>
#include <fstream>
#include <iomanip>
#include <string>
using namespace std;

int main()
{
    cout << "Josiah Barringer -- CSIS111_B01" << endl << endl;

    string songs;

    ifstream inputFile;
    inputFile.open("songs.txt");

    if (!inputFile) {
        cerr << "Error opening input file: songs.txt" << endl;
        return 1;
    }

    int cdTotalTime = 80;
    int songLength;
    int cdUsedTime = 0;
    int cdremainingTime = 0;
    int lineNumber = 1;
    int totalMinutes = 0;
    int totalSeconds = 0;
    string songName;


    cout << setw(10) << left << "Song" << setw(10) << left << "Duration" << left << "Total CD Duration" << endl;
    cout << setfill('-') << setw(50) << "-" << setfill(' ') << endl;


    while (inputFile >> songLength) {
        getline(inputFile, songName);

        int minutes = songLength / 60;
        int seconds = songLength % 60;
        cdUsedTime += songLength;
        totalMinutes += minutes;
        totalSeconds += seconds;
        cdremainingTime = (cdTotalTime * 60) - cdUsedTime; 

        cout << setw(10) << left << lineNumber++ << setw(2) << minutes << "m " << setw(2) << seconds << "s   " << setw(2) << totalMinutes << "m " << setw(2) << totalSeconds << "s" << endl;

    }



    cout << cdUsedTime << " is the total used seconds on the CD." << endl;
    cout << cdremainingTime << " is the total remaining seconds available on the CD." << endl;

    cout << cdUsedTime / 60 << " is the total used minutes on the CD." << endl;
    cout << cdremainingTime / 60 << " is the total remaining minutes available on the CD." << endl;


    inputFile.close();
    

    return 0;



}

// Run program: Ctrl + F5 or Debug > Start Without Debugging menu
// Debug program: F5 or Debug > Start Debugging menu

// Tips for Getting Started: 
//   1. Use the Solution Explorer window to add/manage files
//   2. Use the Team Explorer window to connect to source control
//   3. Use the Output window to see build output and other messages
//   4. Use the Error List window to view errors
//   5. Go to Project > Add New Item to create new code files, or Project > Add Existing Item to add existing code files to the project
//   6. In the future, to open this project again, go to File > Open > Project and select the .sln file
