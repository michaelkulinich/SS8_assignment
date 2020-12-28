#include "mycd.cpp"
#include <iostream>

using namespace std;


// string get_invalid_path(string path, string temp, int i);
// int count_parent_directories(string path);
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