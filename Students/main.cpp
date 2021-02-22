#include "Func.h"
int main()
{
    string name_of_directory;
    setlocale(LC_ALL, "Ukrainian");
    vector<TStudent> Student;
    Read_from_file(Student,name_of_directory);
    sort_Students(Student);
    Output_rating(Student,name_of_directory);
    cout<<"Minimal average mark for stypendia: "<<minGrade(Student);
}
