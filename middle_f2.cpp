#include "middle_str.h"

bool isLetter(char item) {
    return 'a' <= item && item <= 'z' || 'A' <= item && item <= 'Z';
}

string itc_maxCharWord(string str) {
    string result;
    string last;
    int spaces = 0;
    for (const auto item: str) {
        if (isLetter(item))
            last += item;
        else if (item == ' ') {
            spaces++;
            result = itc_len(last) > itc_len(result) ? last : result;
            last = "";
        }
    }
    result = itc_len(last) > itc_len(result) ? last : result;
    return spaces == 0 ? "error" : result;
}

bool test(char i, string str) {
    int count = 0;
    for (const auto &item: str)
        if (item == i)
            count++;
    return count == 2;
}

char itc_sameChar(string str) {
    for (char i: str)
        if (test(i, str))
            return i;
    return '-';
}

bool itc_isFirstInSecond(string s1, string s2) {
    long long s1len = itc_len(s1);
    long long s2len = itc_len(s2);
    int s = 0;
    for (int x = 0; x < s2len; ++x) {
        for (int y = 0; y < s1len; ++y) {
            if (s1[y]==s2[x]) {
                
            }
        }
    }
}