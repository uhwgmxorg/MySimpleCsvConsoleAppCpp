#pragma once

#include <string>
#include <list>

using namespace std;

#define MAXFLDS 200     // maximum possible number of fields
#define MAXFLDSIZE 32   // longest possible field + 1 = 31 byte field

class MyCsvClass
{

private:
    string m_Name;
    int m_Size;
    FILE *m_pFile;

protected:
    list<string> m_ListOfStrings;
    list<double> m_ListOfDouble;


public:
    MyCsvClass();
    MyCsvClass(string name, int size);
    ~MyCsvClass();

    void CreateRandomCsvFile();
    void CreateRandomCsvFile(string name, int size);
    void ReadCsvFile();
    void WriteCsvFile();
    void PrintCsvFileContent();
    void GetList(list<string>*);
    void SetList(list<string>*);
    void GetList(list<double>*);
    void SetList(list<double>*);

private:
    double  DRand(double fMin, double fMax);
    string  SRand(double fMin, double fMax);
    void Parse(char *record, char *delim, char arr[][MAXFLDSIZE], int *fldcnt);
};

