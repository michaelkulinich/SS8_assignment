#include <gtest/gtest.h>
#include "mycd.cpp"

TEST (mycdTest, test1) {
    string current_dir = "/";
    string new_dir = "abc"; 
    EXPECT_EQ("/abc", mycd(current_dir, new_dir));
}

TEST (mycdTest, test2) {
    string current_dir = "/abc/def";
    string new_dir = ".."; 
    EXPECT_EQ("/abc", mycd(current_dir, new_dir));
}

TEST (mycdTest, test3) {
    string current_dir = "/abc/def";
    string new_dir = "/abc"; 
    EXPECT_EQ("/abc", mycd(current_dir, new_dir));
}

TEST (mycdTest, test4) {
    string current_dir = "/abc/def";
    string new_dir = "/abc/klm"; 
    EXPECT_EQ("/abc/klm", mycd(current_dir, new_dir));
}

TEST (mycdTest, test5) {
    string current_dir = "/abc/def";
    string new_dir = "../../.."; 
    EXPECT_EQ("/", mycd(current_dir, new_dir));
}

TEST (mycdTest, test6) {
    string current_dir = "/abc/def";
    string new_dir = "."; 
    EXPECT_EQ("/abc/def", mycd(current_dir, new_dir));
}

TEST (mycdTest, test7) {
    string current_dir = "/abc/def";
    string new_dir = "../gh///../klm/."; 
    EXPECT_EQ("/abc/klm", mycd(current_dir, new_dir));
}

TEST (mycdTest, test8) {
    string current_dir = "/abc/def";
    string new_dir = "/////"; 
    EXPECT_EQ("/", mycd(current_dir, new_dir));
}

TEST (mycdTest, test9) {
    string current_dir = "/abc/def";
    string new_dir = "klm."; 
    EXPECT_EQ("klm.: No such file or directory", mycd(current_dir, new_dir));
}

TEST (mycdTest, test10) {
    string current_dir = "/abc/def";
    string new_dir = "..."; 
    EXPECT_EQ("...: No such file or directory", mycd(current_dir, new_dir));
}

TEST (mycdTest, test11) {
    string current_dir = "/abc/def";
    string new_dir = "..klm"; 
    EXPECT_EQ("..klm: No such file or directory", mycd(current_dir, new_dir));
}

int main(int argc, char **argv) {
  ::testing::InitGoogleTest(&argc, argv);
  return RUN_ALL_TESTS();
}
