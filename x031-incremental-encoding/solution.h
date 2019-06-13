#ifndef LEET_ALL_BSTS__
#define LEET_ALL_BSTS__

#include <fstream>
#include <string>
#include <vector>
#include <cassert>

using std::string;
using std::ofstream;
using std::ifstream;
using std::vector;

class Solution {
public:
    void saveFile() {
        ofstream myfile;
        int a = 1024;
        double pi = 3.14l;
        myfile.open("example.txt");
        myfile << "First Line." << std::endl;
        myfile << "Second Line." << std::endl;
        myfile << a << "\t" << pi;
        myfile.close();
    }

    void saveBinaryFile () {
        ofstream myfile("example.bin", std::ios::out | std::ios::binary);
        int a = 1024;
        double pi = 3.14l;
        myfile << a << pi;
        string str = "end";
        myfile << str;
        myfile.close();
    }

    void saveBinary () {
        ofstream myfile("example.bin", std::ios::out | std::ios::binary);
        int a = 1024;
        double pi = 3.14l;
        string str = "end";
        int len;

        myfile.write((char *)&a, sizeof a);
        myfile.write((char *)&pi, sizeof pi);

        len = str.size();

        myfile.write((char *)&len, sizeof len);
        myfile.write(str.c_str(), str.size());
        myfile.close();
    }

    void quicksort(vector<string> &words, int start, int end) {
        if (start < end) {
            int i = partition(words, start, end);
            quicksort(words, start, i);
            quicksort(words, i + 1, end);
        }
    }

    int partition(vector<string> &words, int start, int end) {
        string pivot = words[end - 1];
        int i = start - 1;
        for (int j = start; j < end; ++j) {
            if (words[j] < pivot) {
                std::swap(words[++i], words[j]);
            }
        }
        std::swap(words[++i], words[end - 1]);
        return i;
    }

    /*
     * Incremental Encoding for words and save to filename.
     */
    void serialize(vector<string> &words, string filename) {
        int wsLen = words.size();
        if (words.empty()) return;
        assert(!filename.empty());

        quicksort(words, 0, wsLen);

        ofstream file(filename, std::ios::out | std::ios::binary);

        size_t char_len = sizeof(char);
        char nShared, nUnshared;

        for (int i = 0; i < wsLen; ++i) {
            int len = words[i].size();
            if (i == 0) {
                nShared = 0;
            } else {
                nShared = sharePrefix(words[i - 1], words[i]);
            }
            nUnshared = len - nShared;

            file.write((char *)&nShared, char_len);
            file.write((char *)&nUnshared, char_len);
            file.write(words[i].substr(len - nUnshared, len).c_str(), nUnshared);
        }
        file.close();
    }

    void deserialize(string filename, vector<string> &words) {
        ifstream file(filename, std::ios::in | std::ios::binary);

        string preWord = "";
        int char_len = sizeof(char);
        char nShared, nUnshared;
        char *word = new char[255];

        // while (!file.eof()) , 不用 file.eof() 去判断. 用 eof 会多一次。
        while (file.peek() != EOF) {
            file.read((char *)&nShared, char_len);
            file.read((char *)&nUnshared, char_len);
            file.read(word, nUnshared);
            word[(size_t)nUnshared] = '\0';

            if (nShared == 0) {
                words.push_back(word);
                preWord = word;
            } else {
                preWord = preWord.substr(0, nShared) + word;
                words.push_back(preWord);
            }
        }
        delete []word;
        file.close();
    }

    int sharePrefix(string str1, string str2) {
        if (str2.size() < str1.size()) {
            return sharePrefix(str2, str1);
        }

        int len = str1.size();
        int i = 0;
        while (i < len && str1[i] == str2[i]) ++i;
        return i;
    }

};

#endif
