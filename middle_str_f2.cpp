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

bool itc_isFirstInSecond(string what, string str) {
    long long whatLen = itc_len(what);
    long long strLen = itc_len(str);
    int last = -1;
    for (int startLen = 0; startLen < strLen; ++startLen) {
        for (int index = 0; index < whatLen; ++index) {
            if (what[index] == str[startLen + index]) {
                if (index == 0)
                    last = startLen;
            } else {
                last = -1;
                break;
            }
        }
        if (last != -1)
            return true;
    }
    return false;
}