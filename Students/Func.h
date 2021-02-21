#include <iostream>
#include <vector>
#include <string>
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
void Read_from_file(vector<TStudent> &);
