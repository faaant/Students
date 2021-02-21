#include <iostream>
#include <vector>
#include <string>
#include <cmath>
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
