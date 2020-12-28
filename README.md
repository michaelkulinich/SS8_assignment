# SS8_assignment
Write a program simulating a "cd" Unix command that changes a current directory in an abstract file system. The simulated command takes two path strings from the command line and prints either a new path or an error.

The first path is a current directory. The second path is a new directory. To make it simple let's assume that a directory name can only contain alphanumeric characters. A single dot (".") indicates a current directory, and the two dots ("..") indicate a step to a previous directory, up from the current one. A single forward slash "/" indicates a root directory. Multiple consecutive slashes are treated as equivalent to a single one.

The program needs to check that the new directory path is valid without relying on any OS system call such as chdir() for verification, to construct a new path, and print it out. Since it is a simulator, it should be OS-independent.

## Getting Started
These instructions will get you a the project up and running on your local machine. See deployment for notes on how to deploy the project on your system. The test automation frameworks used are **gtest** for the C++ program and **unittest** for the Python program 

### Requirements
- C++ compiler and Python3
- gtest needs to be installed for test automation [instructions](https://github.com/google/googletest/tree/master/googletest)
- Python unittest

# Compilation and Deployment
## Test Automation
**For a C++ program**
- make a new directory named 'build' and cd into it
```
mkdir build
cd build 
```
- Compile and run the test
```
cmake ../
make
./runtest
```

**For a Python program**
```
python -m unittest -v test
```
## Run Individually
**For a C++ program**
- Compile (used g++ in this example)
```
g++ main.cpp -o mycd
```
- Run
```
./mycd <current directory> <new directory>
```

**For a Python program**
- Run
```
python3 mycd_python.py <current directory> <new directory>
```
## [Sample output](sample_output.md)

### Source code
- mycd.cpp
- main.cpp
- mycd_python.py
