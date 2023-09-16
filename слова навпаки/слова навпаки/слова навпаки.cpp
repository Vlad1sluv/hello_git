#include <iostream>
#include <fstream>
#include <vector>
#include <algorithm>
#include <Windows.h>
#include "module1.h" // Включення модулів
#include "module2.h"

using namespace std;

int main() {
    // Встановимо кодування 1251 для кирилиці
    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);

    vector<string> words;

    cout << "Введіть 1, щоб завантажити дані з файлу, або будь-який інший текст, щоб ввести дані вручну: ";
    string choice;
    cin >> choice;

    if (choice == "1") {
        // Запитуємо користувача про ім'я файлу для завантаження даних
        string filename;
        cout << "Введіть ім'я файлу: ";
        cin >> filename;

        // Відкриваємо файл і зчитуємо слова з нього
        ifstream file(filename);
        if (file.is_open()) {
            string word;
            while (file >> word) {
                words.push_back(word);
            }
            file.close();
        }
        else {
            cerr << "Помилка відкриття файлу!" << endl;
            return 1;
        }
    }
    else {
        // Введення тексту вручну
        cout << "Введіть послідовність слів тексту (завершіть введення, натиснувши Enter та ввівши 'done'): ";
        string word;
        while (cin >> word && word != "done") {
            words.push_back(word);
        }
    }

    // Сортування за зворотнім порядком слів
    sort(words.begin(), words.end(), reverseWordSort);

    // Обчислення довжин слів
    vector<int> wordLengths;
    for (const string& word : words) {
        wordLengths.push_back(word.length());
    }

    // Виведення результатів у текстовий файл
    string outputFilename;
    cout << "Введіть ім'я файлу для результатів: ";
    cin >> outputFilename;

    ofstream outputFile(outputFilename);
    if (outputFile.is_open()) {
        for (int i = 0; i < words.size(); ++i) {
            string reversedWord = words[i];
            reverse(reversedWord.begin(), reversedWord.end());

            outputFile << "Слово: " << words[i] << " (" << reversedWord << "), Довжина: " << wordLengths[i] << endl;
        }
        outputFile.close();
        cout << "Результати збережено у файлі \"" << outputFilename << "\"" << endl;
    }
    else {
        cerr << "Помилка відкриття файлу для результатів!" << endl;
        return 1;
    }

    return 0;
}
