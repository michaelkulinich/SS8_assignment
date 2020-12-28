#include <iostream>
#include <vector>
#include <ctype.h>

using namespace std;

/*Main method that runs the "cd" command simulation

The simulated command takes two path strings from the command line and prints 
either a new path or an error. The first path is a current directory. 
The second path is a new directory. To make it simple let's assume that 
a directory name can only contain alphanumeric characters. A single dot (".") 
indicates a current directory, and the two dots ("..") indicate a step to a 
previous directory, up from the current one. A single forward slash "/" indicates 
a root directory. Multiple consecutive slashes are treated as equivalent to a single one.

    Typical usage:

        Call from test or another file:
        mycd(current_dir, new_dir)
        
    Example:

        mycd("/abc/def", "..") -> "/abc"
*/
string mycd(string current_dir, string new_dir);

// remove the unecessary slashes from the string path
// returns string 
// ex: "/abc//def///." -> "/abc/def/."
string remove_slashes(string path);

// remove all single dot and two dots for the path
// also if the path consists of an invalid directory or
// a directory that is non alphanumeric, return a message saying file or dir not found 
// otherwise return the updated path of the new directory
// ex: "/abc/def////..///." -> "/abc"
string clean_path(string path);

// split the path string by '/' into a vector.
// return the vector
// ex: "/abc/def" -> {"abc", "def"}
vector<string> split_by_slash(string path);

// MAIN STRING MANIPULATION //
// take out any "." or ".." inside of the path vector and check for invalid entry
// path_vect is passed by reference so it gets updated
// returns true if all entries are valid, false if a directory is invalid
// ex: path_vect = {"abc", "def", "..", "."} -> {"abc"}
bool clean_path_vect(vector<string> &vect);



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
    for (size_t i = 1; i < path.size(); i++) {
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
    for (size_t i = 1; i < path.size(); ++i) {
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
    size_t i = 0;
    while (i < vect.size()) {
        // if single '.' then dont change the path
        // just remove this index from list
        if (vect.at(i) == ".") {
            vect.erase(vect.begin() + i);
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
            for (size_t j = 0; j < vect.at(i).size(); ++j) {
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
