//==========================================================
//
// Title:      Grade Calculator
// Course:     CSC 2111
// Lab Number: 8
// Author:     Oke Amuwha
// Date:       2/13/21
// Description:
//  Calculates a students grade from average
//  Test scores
//
//==========================================================
#include <cstdlib> // For several general-purpose functions
#include <fstream> // For file handling
#include <iomanip> // For formatted output
#include <iostream> // For cin, cout, and system
#include <string> // For string data type
#include <cmath> // For math

using namespace std; // So "std::cout" may be abbreviated to "cout"

//==========================================================
//  Global Variables
//==========================================================
const int TOTAL = 10;
const int ARRAY_SIZE = 10;

//==========================================================
//  Letter Grade Function
//==========================================================
char letterGrade(int gradeAvg)
{
    // Returns letter grade
    if (gradeAvg >= 90 && gradeAvg <= 100)
    {
        return 'A';
    }
    else if (gradeAvg >= 80 && gradeAvg < 90)
    {
        return 'B';
    }
    else if (gradeAvg >= 70 && gradeAvg < 80)
    {
        return 'C';
    }
    else if (gradeAvg >= 60 && gradeAvg < 70)
    {
        return 'D';
    }
    else
        return 'F';
}

//==========================================================
//  Average Calcularion Function
//==========================================================
void calcAvg(int arr[][5], int avg[], int classAvg[], int students, char grade[])
{
    // Calculates student average
    for (int i = 0; i < students; i++)
    {
        int sum = 0;
        for (int j = 0; j < 5; j++)
        {
            sum = sum + arr[i][j];
        }
        avg[i] = sum / 5;

        grade[i] = letterGrade(avg[i]);
    }
    
    for (int i = 0; i < students; i++)
    {
        avg[i] = avg[i] / 10;
        
        classAvg[i] = avg[i];
    }
}

//==========================================================
//  Store and Display Function
//==========================================================
void display(string studentName[], int avg[], int classAvg[], int scores[][5], int num,  char grade[])
{
    // Displays Student Average and Grade
    cout << setw(9) << "Student" << setw(9) << "Average" << setw(9) << "Grade" << endl;
    for (int i = 0; i < num; i++)
    {
        cout << setw(8) << studentName[i] << setw(8) << avg[i] << setw(8) << grade[i] << endl;
    }
    cout << endl;
    
    cout << "Class Average: " << classAvg << endl;
}
//==========================================================
//  Main
//==========================================================
int main()
{
    // Declare variables
    int avg[ARRAY_SIZE];
    char grade[ARRAY_SIZE];
    int classAvg[ARRAY_SIZE];
    
    // Declare arrays
    string studentName[ARRAY_SIZE] =
    { {"Johnson"},
      {"Aniston"},
      {"Cooper"},
      {"Gupta"},
      {"Blair"},
      {"Clark"},
      {"Kennedy"},
      {"Bronson"},
      {"Sunny"},
      {"Smith"} };
    int scores[ARRAY_SIZE][5] =
    { {85, 83, 77, 91, 76},
      {80, 90, 95, 93, 48},
      {78, 81, 11, 90, 73},
      {92, 83, 30, 69, 87},
      {23, 45, 96, 38, 59},
      {60, 85, 45, 39, 67},
      {77, 31, 52, 74, 83},
      {93, 94, 89, 77, 97},
      {79, 85, 28, 93, 82},
      {85, 72, 49, 75, 63} };

    // Call functions
    calcAvg(scores, avg, classAvg, TOTAL, grade);
    display(studentName, avg, classAvg, scores, TOTAL, grade);
}

