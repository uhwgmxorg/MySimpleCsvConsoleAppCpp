#include "stdafx.h"
#include "MyCsvClass.h"

//////////////////////////////////
//   Constructors Destructor
//////////////////////////////////
#pragma region Constructors Destructor

// Constructur
MyCsvClass::MyCsvClass()
{
}

// Constructur
MyCsvClass::MyCsvClass(string name, int size)
{
    m_Name = name;
    m_Size = size;
}

// Destuctor
MyCsvClass::~MyCsvClass()
{
}

#pragma endregion

//////////////////////////////////
//       Public Functions
//////////////////////////////////
#pragma region Public Functions

// CreateRandomCsvFile
void MyCsvClass::CreateRandomCsvFile()
{
    CreateRandomCsvFile(m_Name, m_Size);
}

// CreateRandomCsvFile
void MyCsvClass::CreateRandomCsvFile(string name, int size)
{
    string strHelp;
    m_Name = name;
    m_Size = size;

    int err = fopen_s(&m_pFile, name.c_str(), "w+");

    for (int i = 0; i < size; i++)
    {
        strHelp = SRand(0, 10);
        fputs((strHelp + ';').c_str(), m_pFile);
        m_ListOfStrings.push_back(strHelp);
        m_ListOfDouble.push_back(atof(strHelp.c_str()));
    }

    fclose(m_pFile);
}

// ReadCsvFile
void MyCsvClass::ReadCsvFile()
{
    char tmp[1024] = { 0x0 };
    int fldcnt = 0;
    char arr[MAXFLDS][MAXFLDSIZE] = { 0x0 };
    int recordcnt = 0;
    FILE *file;
    
    fopen_s(&file,m_Name.c_str(), "r");

    m_ListOfStrings.clear();
    m_ListOfDouble.clear();

    while (fgets(tmp, sizeof(tmp), file) != 0)
    {
        int i = 0;
        char *delim = ";";
        recordcnt++;
        printf("Record number: %d\n", recordcnt);
        Parse(tmp, delim, arr, &fldcnt);
        for (i = 0; i<fldcnt; i++)
        {
            printf("\tField number: %3d=%s\n", i, arr[i]);
            m_ListOfStrings.push_back(arr[i]);
            m_ListOfDouble.push_back(atof(arr[i]));
        }
    }
    fclose(file);
}

// WriteCsvFile
void MyCsvClass::WriteCsvFile()
{
    int err = fopen_s(&m_pFile, m_Name.c_str(), "w+");

    for (string item : m_ListOfStrings)
    {
        item += ';';
        fputs(item.c_str(), m_pFile);
    }

    fclose(m_pFile);
}

// PrintCsvFileContent
void MyCsvClass::PrintCsvFileContent()
{
    for each (string s in m_ListOfStrings)
        printf("%s;",s.c_str());
}

// GetList
void MyCsvClass::GetList(list<string> *pstrlist)
{
    pstrlist = &m_ListOfStrings;
}

// SetList
void MyCsvClass::SetList(list<string> *pstrlist)
{
    m_ListOfStrings.clear();
    m_ListOfDouble.clear();
    for (string item : *pstrlist)
    {
        m_ListOfStrings.push_back(item);
        m_ListOfDouble.push_back(atof(item.c_str()));
    }
}

// GetList
void MyCsvClass::GetList(list<double> *pstrlist)
{
    pstrlist = &m_ListOfDouble;
}

// SetList
void MyCsvClass::SetList(list<double> *pstrlist)
{
    string strHelp;
    m_ListOfStrings.clear();
    m_ListOfDouble.clear();
    for (double item : *pstrlist)
    {
        strHelp = std::to_string(item);
        m_ListOfStrings.push_back(strHelp);
        m_ListOfDouble.push_back(item);
    }
}

#pragma endregion

//////////////////////////////////
//       Private Functions
//////////////////////////////////
#pragma region Private Functions

// DRand
double  MyCsvClass::DRand(double fMin, double fMax)
{
    double f = (double)rand() / RAND_MAX;
    return fMin + f * (fMax - fMin);
}

// SRand
string  MyCsvClass::SRand(double fMin, double fMax)
{
    double f = DRand(fMin, fMax);
    string str = std::to_string(f);
    return str;
}

// Parse
void MyCsvClass::Parse(char *record, char *delim, char arr[][MAXFLDSIZE], int *fldcnt)
{
    char *next_token1 = NULL;
    char *p = strtok_s(record, delim, &next_token1);
    int fld = 0;

    while (p != NULL)
    {
        strcpy_s(arr[fld], p);
        fld++;
        p = strtok_s(NULL, delim, &next_token1);
    }
    *fldcnt = fld;
}

#pragma endregion
