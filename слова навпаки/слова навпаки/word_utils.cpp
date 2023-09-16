#include "word_utils.h"
#include <algorithm>

using namespace std;

namespace WordUtils {
    // Реалізація функції для обертання слова
    string reverseWord(const string& word) {
        string reversed = word;
        reverse(reversed.begin(), reversed.end());
        return reversed;
    }

    // Реалізація функції для сортування слів в зворотньому порядку
    void sortWordsByReverse(vector<string>& words) {
        sort(words.begin(), words.end(), [](const string& a, const string& b) {
            return reverseWord(a) > reverseWord(b);
            });
    }
}
