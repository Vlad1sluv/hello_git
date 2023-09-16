#include "module1.h"
#include <algorithm>

bool reverseWordSort(const string& word1, const string& word2) {
    string reversedWord1 = word1;
    reverse(reversedWord1.begin(), reversedWord1.end());

    string reversedWord2 = word2;
    reverse(reversedWord2.begin(), reversedWord2.end());

    return reversedWord1 > reversedWord2;
}
