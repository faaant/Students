#include "Func.h"

void Read_from_file(vector<TStudent> &Student)
{
    int number_of_students;
    string name_of_directory,
           name,
           name_of_file,
           reader;
    TStudent student;
    cout<<"Enter the name of directory: ";
    getline(cin,name_of_directory);
    char way_to_files[name_of_directory.length()+5];
    for (int i=0;i<name_of_directory.length();i++)
    {
        way_to_files[i]=name_of_directory[i];
    }

    way_to_files[name_of_directory.length()]='/';
    way_to_files[name_of_directory.length()+1]='*';
    way_to_files[name_of_directory.length()+2]='.';
    way_to_files[name_of_directory.length()+3]='c';
    way_to_files[name_of_directory.length()+4]='s';
    way_to_files[name_of_directory.length()+5]='v';
    _finddata_t data;
    intptr_t handle = _findfirst(way_to_files, &data);
    do
    {
        cout<< data.name <<endl;

    }while(_findnext(handle,&data)==0);
    _findclose(handle);
}


