#include "gtest/gtest.h"
#include "gmock/gmock.h"
#include "solution.h"

#include <iostream>
#include <string>

using std::ifstream;
using std::string;
using testing::ElementsAre;

TEST(Solution, Read) {
    Solution s;
    s.saveFile();

    ifstream ifile("example.txt");

    string str;
    int a;
    float b;

    std::getline(ifile, str);
    EXPECT_EQ(str, "First Line.");

    std::getline(ifile, str);
    EXPECT_EQ(str, "Second Line.");

    ifile >> a >> b;
    ifile.close();

    EXPECT_EQ(a, 1024);
    EXPECT_FLOAT_EQ(b, 3.14);
    /* EXPECT_DOUBLE_EQ(b, 3.14); */

}

TEST(Solution, ReadBinary) {
    Solution s;
    s.saveBinary();

    ifstream file("example.bin", std::ios::in | std::ios::binary);
    int i;
    double d;
    int len;
    char *str;

    file.read((char *)&i, sizeof i);
    file.read((char *)&d, sizeof d);
    file.read((char *)&len, sizeof len);
    str = new char[len + 1];
    file.read(str, len);
    str[len] = '\0';

    EXPECT_EQ(i, 1024);
    EXPECT_FLOAT_EQ(d, 3.14);
    EXPECT_EQ(len, 3);
    EXPECT_STREQ(str, "end");
    std::cout << i << "\t" << "\t" << d << "\t" << str << std::endl;
    std::cout << "is eof:" << (file.eof() ? "true" : "false")  << std::endl;
    std::cout << "Use peeck() to check is eof:" << (file.peek() == EOF ? "true" : "false")  << std::endl;
}

TEST(Solution, quicksort) {
    Solution s;

    vector<string> words;
    s.quicksort(words, 0, words.size());
    EXPECT_THAT(words, ElementsAre());

    words = { "apple" };
    s.quicksort(words, 0, words.size());
    EXPECT_THAT(words, ElementsAre("apple"));

    words = { "cat", "jump", "kid", "kidding", "bar", "banana", "a", "apple" };
    s.quicksort(words, 0, words.size());
    EXPECT_THAT(words, ElementsAre("a", "apple", "banana", "bar", "cat"
                , "jump", "kid", "kidding"));
}

TEST(Solution, sharePrefix) {
    Solution s;
    EXPECT_EQ(s.sharePrefix("", ""), 0);
    EXPECT_EQ(s.sharePrefix("", "bar"), 0);
    EXPECT_EQ(s.sharePrefix("bar", ""), 0);
    EXPECT_EQ(s.sharePrefix("bar", "foo"), 0);

    EXPECT_EQ(s.sharePrefix("bar", "banana"), 2);
    EXPECT_EQ(s.sharePrefix("banana", "bar"), 2);
}

TEST(Solution, serialize) {
    Solution s;
    vector<string> words;

    words = { "cat", "jump", "kid", "kidding", "bar", "banana", "a", "apple" };
    s.serialize(words, "encoded-words.bin");
}

TEST(Solution, deserialize) {
    Solution s;

    char str[] = {'h', 'e', '\0', 'f', 'o', '\0'};
    string word{"KID:"};
    word += str;
    std::cout<< "str = " << str << std::endl;
    std::cout<< "word = " << word << std::endl;



    vector<string> words;
    s.deserialize("encoded-words.bin", words);
    EXPECT_THAT(words, ElementsAre("a", "apple", "banana", "bar", "cat"
                , "jump", "kid", "kidding"));
    for (auto w : words) {
        std::cout<< w << "\t";
    }
    std::cout << std::endl;
}
