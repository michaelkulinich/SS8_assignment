#include <iostream>
// #include <fstream>
// #include <filesystem>
#include <vector>
#include <ctype.h>

using namespace std;


string mycd(string current_dir, string new_dir);
// remove the unecessary slashes from the string path
// returns string 
// ex: "/abc//def///." -> "/abc/def/."
string remove_slashes(string path);

// remove all single dot and two dots for the path
// also if the path consists of an invalid directory or
// a directory that is non alphanumeric, return a message saying file or dir not found 
// otherwise return the updated path of the new directory
string clean_path(string path);

// split the path string by '/' into a vector.
// return the vector
vector<string> split_by_slash(string path);

// MAIN STRING MANIPULATION //
// take out any "." or ".." inside of the path vector and check for invalid entry
// path_vect is passed by reference so it gets updated
// returns true if all entries are valid, false if a directory is invalid
// ex: path_vect = {"abc", "def", "..", "."} -> {"abc"}
bool clean_path_vect(vector<string> &vect);



// // string get_invalid_path(string path, string temp, int i);
// // int count_parent_directories(string path);
// int main(int argc, char* argv[])
// {
//     string final_path;  // path of the new directory after "cd" command

//     // Check if two arguments for current and new directory are specified
//     if (argc != 3) {
//         cout << "Error: " << argv[0] << " <current dir>" << " <new dir>\n";
//         return 1;
//     }

//     // get the final path for new directory after 
//     // we remove all unecessary single dots and two dots from path
//     // as well as check for invalid entry and print out invalid entry
//     // this is where the majority string manipulation takes place
//     // ex: "/abc/def////..///." -> "/abc"
//     final_path = mycd(argv[1], argv[2]);
//     cout << final_path << endl;
//     return 0;
// }

string mycd(string current_dir, string new_dir) 
{
   
    string combined;  // current + new directory
    string final_path;  // path of the new directory after "cd" command

    combined = current_dir + "/" + new_dir; 

    // Case: If the new directory begins with a '/' - starting at root
    // then we only need to care about the new_dir because it is 
    // this absolute path
    if (new_dir[0] == '/') {
        final_path = remove_slashes(new_dir); // remove consecutive multiple slashes
    }

    //new directory is a relative path, so we concatenate both strings
    else {
        final_path = remove_slashes(combined); // remove consecutive multiple slashes
    }

    // get the final path for new directory after 
    // we remove all unecessary single dots and two dots from path
    // as well as check for invalid entry and print out invalid entry
    // this is where the majority string manipulation takes place
    // ex: "/abc/def////..///." -> "/abc"
    final_path = clean_path(final_path);
    return final_path;
}

string remove_slashes(string path) 
{
    string updated_path = "";
    updated_path += path[0];

    // iterate through path and remove multiple consecutive slashes
    for (int i = 1; i < path.size(); i++) {
        if (path[i] == '/') {
            if (updated_path[updated_path.size() -1] != '/') {
                // updated_path = updated_path + '/';
                updated_path += '/';
            }
        }
        else {
            updated_path += path[i];
        }
    }
    return updated_path;
}

string clean_path(string path) 
{
    string updated_path = "";  // new path after all of the updates
    vector<string> path_vect;
    bool valid;  // false if a directory contains non alphanumeric characters

    // split the string path into a vector by '/' character
    // ex: path = /abc/def/../.
    //     path_vect = {"abc", "def", "..", "."}
    path_vect = split_by_slash(path);

    // clean the path vector to get rid of single dots and two dots
    // return false if the new directory is invalid
    valid = clean_path_vect(path_vect);

    // if a directory is invalid that return the error message from the vector
    if (!valid) {
        return path_vect.at(0);
    }

    // iterate through vector to join it into a string by '/'
    for (auto i = path_vect.begin(); i != path_vect.end(); ++i) {
        updated_path += "/" + *i;
    }

    // if the path is empty, then we are at root
    if (updated_path == "") {
        return "/";
    }

    return updated_path;
    
}

vector<string> split_by_slash(string path) 
{
    vector<string> split_path;

    // a temporary string used to fill up the vector
    string temp = "";  

    // start at 1 because 0th element SHOULD ALWAYS BE '/'
    for (int i = 1; i < path.size(); ++i) {
        if (path[i] == '/') {
            split_path.push_back(temp);
            temp = ""; 
        }
        else {
            temp += path[i];
        }
    }

    // used for the leftover directory after the last slash
    if (temp != "") {
        split_path.push_back(temp);
    }
    return split_path;
}

// MAIN STRING MANIPULATION
bool clean_path_vect(vector<string> &vect)
{
    int i = 0;
    while (i < vect.size()) {
     
    // for (int i = 0; i != path_vect.size(); ++i) {
        // just one '.'
        if (vect.at(i) == ".") {
                if (i != 0) {
                    vect.erase(vect.begin() + i);
                }
                else {
                    vect.erase(vect.begin() + i);
                }
        }

        // if two '.' then go up  directory
        // first remove this index ".." from the vector because we dont need it
        // then remove the previous index, check for boundary cases
        else if (vect.at(i) == "..") {
            if (i != 0) {
                vect.erase(vect.begin() + i);
                vect.erase(vect.begin() + i -1);
                i -= 1;
            }
            else {
                vect.erase(vect.begin() + i);
            }
        }

        // this element should be a directory name
        else {
            // check that each element is alphanumeric, if not clear the vector
            // and add the error message
            for (int j = 0; j < vect.at(i).size(); ++j) {
                if (!isalnum(vect.at(i)[j])) {
                    string invalid_entry = vect.at(i) + ": No such file or directory";
                    vect.clear();
                    vect.push_back(invalid_entry);
                    return false;
                }
            }
            i++;
        }
        

    }
    return true;
}
