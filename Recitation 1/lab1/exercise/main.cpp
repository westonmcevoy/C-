#include "addStudent.hpp"
#include <sstream>

int main(int argc, char* argv[])
{
    //check for number of arguments
    if(argc<2)
    {
        cout<< "file name missing"<<endl;
        return -1;
    }
    
    string fileName = argv[1];  //TODO 1: collect the correct argument
    student array[4];
    
    //open the file
    ifstream myfile;
    myfile.open(fileName);
    
    string line;
    string name;
    string emailid;
    string birthday;
    int length=0;
    
    if(myfile.is_open())//check existance of the file
    {
        //TODO 2:  Read each line from the file
        //          for each line do the following
        //              extract name, extract email, exract birthday
        //              call the addAstudent function to add them in the array
        while(getline(myfile, line))
        {
            stringstream stream(line);
            getline(stream, name, ',');
            getline(stream, emailid, ',');
            getline(stream, birthday, ',');
            length = addAstudent(array, name, birthday, emailid, length);
        }
    }
    else{
        cout<< "err: can not open file"<<endl;
    }
    
    for(int i=0;i<4;i++)
    {
        cout<< "name:"<<array[i].name<<" email:"<<array[i].email<<" bday:"<<array[i].birthday<<endl;
    }
    
    return 0;
}