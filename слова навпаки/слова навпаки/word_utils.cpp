#include "word_utils.h"
#include <algorithm>

using namespace std;

namespace WordUtils {
    // ��������� ������� ��� ��������� �����
    string reverseWord(const string& word) {
        string reversed = word;
        reverse(reversed.begin(), reversed.end());
        return reversed;
    }

    // ��������� ������� ��� ���������� ��� � ����������� �������
    void sortWordsByReverse(vector<string>& words) {
        sort(words.begin(), words.end(), [](const string& a, const string& b) {
            return reverseWord(a) > reverseWord(b);
            });
    }
}
