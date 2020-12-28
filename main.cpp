#include "mycd.cpp"
#include <iostream>

using namespace std;

/*
A program simulating a "cd" Unix command.

The simulated command takes two path strings from the command line and prints 
either a new path or an error. The first path is a current directory. 
The second path is a new directory. To make it simple let's assume that 
a directory name can only contain alphanumeric characters. A single dot (".") 
indicates a current directory, and the two dots ("..") indicate a step to a 
previous directory, up from the current one. A single forward slash "/" indicates 
a root directory. Multiple consecutive slashes are treated as equivalent to a single one.

    Typical usage:
    
        From command line:
        $ g++ main.cpp -o mycd
        $ ./mycd <current directory> <new directory>

    Example:

        $ ./mycd /abc/def ../klm
        ./abc/klm
*/

int main(int argc, char* argv[])
{
    string final_path;  // path of the new directory after "cd" command

    // Check if two arguments for current and new directory are specified
    if (argc != 3) {
        cout << "Error: " << argv[0] << " <current dir>" << " <new dir>\n";
        return 1;
    }

    // get the final path for new directory after 
    // we remove all unecessary single dots and two dots from path
    // as well as check for invalid entry and print out invalid entry
    // this is where the majority string manipulation takes place
    // ex: "/abc/def////..///." -> "/abc"
    final_path = mycd(argv[1], argv[2]);
    cout << final_path << endl;
    return 0;
}