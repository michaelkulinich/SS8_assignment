"""
A program simulating a "cd" Unix command.

The simulated command takes two path strings from the command line and prints 
either a new path or an error. The first path is a current directory. 
The second path is a new directory. To make it simple let's assume that 
a directory name can only contain alphanumeric characters. A single dot (".") 
indicates a current directory, and the two dots ("..") indicate a step to a 
previous directory, up from the current one. A single forward slash "/" indicates 
a root directory. Multiple consecutive slashes are treated as equivalent to a single one.

    Typical usage example:
    
    From command line:
    $ python3 mycd_python.py <current directory path> <new directory path>
    
    Call from another module:
    mycd(current_dir, new_dir)
"""

import sys
# Simulates the Unix "cd" command
def mycd(current_dir, new_dir):
    """Simulates the Unix "cd" command.

    Removes unecessary multiple consecutive slashes, '.' and ".." 
    frome the path

    Args:
        current_dir: A string representing current directory path
        new_dir: A string New directory path

    Returns:
        A string of the path after the given "cd" command.
        If the file or directory is not valid, it returns an error message

        Example:
            mycd("/home", "Documents) -> "/home/Documents"
            mycd("/home", "..) -> "/home"
    """

    # if the new directory starts at root, then it is the absolute path
    # and we dont need to worry about what was in the current path
    if new_dir[0] == '/':
        final_path = remove_slashes(new_dir)

    # new directory is a relative path, so we concatenate both paths together
    else:
        final_path = remove_slashes(current_dir + '/' + new_dir)

    # # if path is just root, return root
    # if final_path == '/':
    #     return '/'

    # split the string path by '/' to create list with each element 
    # representing a directory.
    # then update the list to remove any '.' or ".." 
    # ex: "/home/Documents/../Downloads/." -> 
    #      ["home", "Documents", "..", "Downloads", "."] ->
    #      ["home", "Downloads"]
    path_list = final_path.split('/')
    path_list = clean_path_list(path_list)

    # list is empty so the path is only root directory
    if not path_list:
        return "/"

    # if one of the directories was invalid (not alphanumeric)
    # then the list has 1 element which is an error message, return error message
    if "No such file or directory" in path_list[0]:
        return path_list[0]

    # Join the list back to a string with '/', starting with root
    final_path = "/" + "/".join(path_list)
    return final_path


# remove multiple consecutive slashes from the path string
def remove_slashes(path):
    """Removes multiple consecutive slashes.

    Args:
        path: A string representing the path
    
    Returns:
        A string of the updated path which replaces
            multiple consecutive slashes with a single slash
    
    Example:
        remove_slashes("/home//Documents/////foo") -> "/home/Documents/foo"
    """

    previous = path[0]
    new_path = ''
    for i in path[1:]:  # start from 1st index
        if i == '/':
            if previous != '/':
                new_path += '/'
        else:
            new_path += i
        previous = i
    return new_path

# update the path list to only contain directory names
def clean_path_list(path_list):
    """Updates the list representing the directory path

    Args:
        path_list: A list consisting of the directories in the path
    
    Returns:
        A list without single dots and two dots. If a directory is 
        non alphanumeric then it returns a list with an error message
    
    Example:
        clean_path_list(["home", "Documents", "..", "."]) -> ["home"]
        clean_path_list(["home", "Do#@cuments"]) ->
            ["Do#@cuments: No such file or directory"]
    """
    # if the list consists of an empty string, return empty list
    if path_list == ['']:
        return []
    
    i = 0
    while i < len(path_list):
        # if the index consists of a single dot
        # then we don't do anything to change the path
        # and remove this index from list
        if path_list[i] == '.':
            if i != 0:
                path_list.pop(i)
                i -= 1
            else:
                path_list.pop(i)
        
        # if the index constists of two dots
        # then we need to step to previous directory
        # and remove both this index and previous index from list
        elif path_list[i] == '..':
            if i != 0:
                path_list.pop(i)
                path_list.pop(i-1)
                i -=2
            
            # if this is only element in list, just remove it and don't
            # decrement i because i is already equal to 0
            else:
                path_list.pop(i)
        
        # this element should represent a valid directory
        # check that is is alphanumeric, if not then update the list 
        # to only contain an error messge
        else:
            if not path_list[i].isalnum():
                path_list = [path_list[i] + ": No such file or directory"]
                break
        i += 1

    return path_list


def main():
    if len(sys.argv) != 3:
        print("Error: {} <current dir> <new dir>".format(sys.argv[0]))
    else:
        print(mycd(sys.argv[1], sys.argv[2]))

if __name__ == "__main__":
    main()




# python -m unittest test
# python test.py
# how can I make this work on windows