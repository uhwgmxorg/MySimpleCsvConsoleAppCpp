// MySimpleCsvConsoleAppCpp.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"

#include <string>
#include <iostream>
#include <conio.h>

#include "MyCsvClass.h"

#define FILE_NAME "MyCsvFile.csv"
#define FILE_CONTENT_SIZE 100

using namespace std;

void SetConsoleColor(int c);

// PrintAllColors
void PrintAllColors()
{
    for (int i = 0; i < 16; i++)
    {
        SetConsoleColor(i);
        std::cout << "Color is: " << i << std::endl;
    }
}

// SetConsoleColor
void SetConsoleColor(int c)
{
    HANDLE hConsole;
    hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
    SetConsoleTextAttribute(hConsole, c);
}

// main
int main()
{
    string Version = "1.3.0.0";
    list<string> listOfStrings;  // locals for test MyCsvClass
    list<double> listOfDouble;
    char c;
    MyCsvClass *pMyCsvClass = new MyCsvClass(FILE_NAME, FILE_CONTENT_SIZE);

    do
    {
        // Print Header
        system("cls");
        SetConsoleColor(11);
        cout << " Program MyStructStreamConsoleAppCpp C++ Version " << Version;
        SetConsoleColor(7);
        cout << endl << endl;

        // Console Menu
        cout << " p Print first 16 colors" << endl;
        cout << " r Read Csv File " << FILE_NAME << endl;
        cout << " f Fill the Csv File with random values" << endl;
        cout << " i Print Csv File on screen" << endl;
        cout << " s Set MyCsvClass list from extern list<double>" << endl;
        cout << " w Write Csv data to Csv File " << FILE_NAME << endl;

        cout << endl << " q Quit" << endl;

        SetConsoleColor(10);
        cout << endl << "\n\r press Return to continue q to quit ";
        SetConsoleColor(7);

        // Wait until a key command is pressed
        c = _getch();

        // Command Dispatcher
        switch (c)
        {
            case 'p':
                system("cls");
                PrintAllColors();
                SetConsoleColor(7);
                system("pause");
                break;
            case 'r':
                system("cls");
                cout << "Read Csv File " << FILE_NAME << endl;
                cout << endl;
                SetConsoleColor(15);

                pMyCsvClass->ReadCsvFile();

                cout << endl << endl;
                SetConsoleColor(7);
                system("pause");
                break;
            case 'f':
                system("cls");
                cout << "Fill the Csv File with random values" << endl;
                cout << endl;

                pMyCsvClass->CreateRandomCsvFile();

                SetConsoleColor(7);
                system("pause");
                break;
            case 'i':
                system("cls");
                cout << "Print Csv File on screen" << endl;
                cout << endl;

                pMyCsvClass->PrintCsvFileContent();

                cout << endl << endl;
                SetConsoleColor(7);
                system("pause");
                break;
            case 's':
                system("cls");
                cout << "Set MyCsvClass list from extern list<double>" << endl;
                cout << endl;

                // Do stuff here
                listOfStrings.push_back("1.1");
                listOfStrings.push_back("2.2");
                listOfStrings.push_back("3.3");
                listOfStrings.push_back("4.4");
                listOfStrings.push_back("5.5");
                pMyCsvClass->SetList(&listOfStrings);


                SetConsoleColor(7);
                system("pause");
                break;
            case 'w':
                system("cls");
                cout << "Write Csv data to Csv File " << FILE_NAME << endl;
                cout << endl;

                pMyCsvClass->WriteCsvFile();

                SetConsoleColor(7);
                system("pause");
                break;
            default:
                if (c == 'q') break;
                system("cls");
                SetConsoleColor(12);
                cout << '\a'; // Beep
                cout << "You have pressed a wrong key" << endl;
                cout << endl;

                SetConsoleColor(7);
                system("pause");
                break;
        }

    } while (c != 'q');

    delete pMyCsvClass;

    return 0;
}

