#include "Func.h"
int main()
{
    int percent,
        mark;
    string name_of_directory;
    cout<<"Enter the percentes of students that will have a stypendia: ";
    cin>>percent;
    cout<<"Enter mark: ";
    cin>>mark;
    cin.ignore();
    setlocale(LC_ALL, "Ukrainian");
    vector<TStudent> Student;
    Read_from_file(Student,name_of_directory,mark);
    sort_Students(Student);
    Output_rating(Student,name_of_directory,percent);
    cout<<"Minimal average mark for stypendia: "<<minGrade(Student,percent);
}
