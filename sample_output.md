### gtest 
```
[mk@amk build]$ ./runTests 
[==========] Running 11 tests from 1 test suite.
[----------] Global test environment set-up.
[----------] 11 tests from mycdTest
[ RUN      ] mycdTest.test1
[       OK ] mycdTest.test1 (0 ms)
[ RUN      ] mycdTest.test2
[       OK ] mycdTest.test2 (0 ms)
[ RUN      ] mycdTest.test3
[       OK ] mycdTest.test3 (0 ms)
[ RUN      ] mycdTest.test4
[       OK ] mycdTest.test4 (1 ms)
[ RUN      ] mycdTest.test5
[       OK ] mycdTest.test5 (0 ms)
[ RUN      ] mycdTest.test6
[       OK ] mycdTest.test6 (0 ms)
[ RUN      ] mycdTest.test7
[       OK ] mycdTest.test7 (0 ms)
[ RUN      ] mycdTest.test8
[       OK ] mycdTest.test8 (0 ms)
[ RUN      ] mycdTest.test9
[       OK ] mycdTest.test9 (0 ms)
[ RUN      ] mycdTest.test10
[       OK ] mycdTest.test10 (0 ms)
[ RUN      ] mycdTest.test11
[       OK ] mycdTest.test11 (0 ms)
[----------] 11 tests from mycdTest (1 ms total)

[----------] Global test environment tear-down
[==========] 11 tests from 1 test suite ran. (1 ms total)
[  PASSED  ] 11 tests.
```
### unittest 
```
[mk@amk SS8_assignment]$ python -m unittest -v test
test1 (test.TestMycd)
# mycd / abc -> /abc ... ok
test10 (test.TestMycd)
# mycd /abc/def klm. -> klm.: No such file or directory ... ok
test11 (test.TestMycd)
# mycd /abc/def ..klm -> ..klm: No such file or directory ... ok
test2 (test.TestMycd)
# mycd /abc/def /abc -> /abc ... ok
test3 (test.TestMycd)
# mycd /abc/def .. -> /abc ... ok
test4 (test.TestMycd)
# mycd /abc/def /abc/klm -> /abc/klm ... ok
test5 (test.TestMycd)
# mycd /abc/def ../../.. -> / ... ok
test6 (test.TestMycd)
# mycd /abc/def . -> /abc/def ... ok
test7 (test.TestMycd)
# mycd /abc/def ../gh///../klm/. -> /abc/klm ... ok
test8 (test.TestMycd)
# mycd /abc/def ////// -> / ... ok
test9 (test.TestMycd)
# mycd /abc/def ... -> ...: No such file or directory ... ok

----------------------------------------------------------------------
Ran 11 tests in 0.001s

OK
```
### Running C++ individually
```
[mk@amk SS8_assignment]$ g++ main.cpp -o mycd
[mk@amk SS8_assignment]$ ./mycd /abc/def ../klm
/abc/klm
```
#### Running Python individually
```
[mk@amk SS8_assignment]$ python3 mycd_python.py /abc/def ..
/abc
```
