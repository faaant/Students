#include <iostream>
#include <vector>
#include <string>
#include <cmath>
#include <direct.h>
#include <fstream>
using namespace std;

struct TStudent
{
    string name;
    int grade[5];
    bool contract;
    int averageG;
};

int Average (int*);
int minGrade (vector<TStudent>&);
int* sortM (int*, int);
void Read_from_file(vector<TStudent> &);

