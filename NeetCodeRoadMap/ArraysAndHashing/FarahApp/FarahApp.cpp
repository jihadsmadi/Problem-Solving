#include <string>
#include <iostream>
#include <fstream>

using namespace std;

string ReadFile(string Path)
{
    string result = "";

    fstream newfile;
    newfile.open(Path, ios::in); //open a file to perform read operation using file object
    if (newfile.is_open()) { //checking whether the file is open
        string line;
        while (getline(newfile, line)) { //read data from file object and put it into string.
            result += line;
        }
        newfile.close(); //close the file object.
    }


    return result;
}

string StepIntoEndUntelSpace(string s,int From,int & index)
{

}

void PrintResult(string content)
{

    string result = content;

    for (int i = 18; i < content.length(); i++)
    {
        cout << content[i];

        if (content[i] == ' ')
        {
            i += 9;

            for (; i < content.length(); i++)
            {

                if (content[i] == ' ')
                {
                    i -= 26;
                }
            }
        }
      
    }
}



int main()
{
    string Content =  ReadFile("C:\\Users\\USER\\Desktop\\FarahFile.txt");







	system("Pause>0");
}

