#include "middle_str.h"

char shift(char that, int offset, char baseChar) {
    char charPos = that - baseChar;
    char newCharPos = (charPos + offset) % ALPHABET_SIZE;
    int absNewCharPos = newCharPos < 0
                        ? newCharPos + ALPHABET_SIZE
                        : newCharPos;
    return baseChar + absNewCharPos;
}

string itc_Cezar(string source, int k) {
    string result;
    for (char e: source)
        if ('a' <= e && e <= 'z')
            result += shift(e, k, 'a');
        else if ('A' <= e && e <= 'Z')
            result += shift(e, k, 'A');
        else
            result += e;
    return result;
}

string itc_rmFreeSpace(string str) {
    bool isLastSpace = false;
    string result;
    for (auto item: str) {
        if (item == ' ') {
            if (!isLastSpace)
                result += item;
            isLastSpace = true;
        } else {
            isLastSpace = false;
            result += item;
        }
    }
    return result;
}

//bool itc_isIp(string str) {
//    for (const auto &item: str) {
//
//    }
//}