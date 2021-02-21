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
    double grade[5];
    bool contract;
    double averageG;
};

double Average (int*);
double minGrade (vector<TStudent>&);
double* sortM (int*, int);
void Read_from_file(vector<TStudent> &);

