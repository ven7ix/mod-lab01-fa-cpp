// Copyright 2022 UNN-IASR
#include "fun.h"

unsigned int faStr1(const char *str) {
    if (str == nullptr) {
        return 0;
    }

    bool inWord = false;
    int correctWordCount = 0;
    bool hasDigit = false;

    for (int i = 0; str[i] != '\0'; i++) {
        if (str[i] == ' ') {
            if (inWord && !hasDigit) {
                correctWordCount++;
            }
            inWord = false;
        } else {
            if (!inWord) {
                inWord = true;
                hasDigit = false;
            }

            if (str[i] >= '0' && str[i] <= '9') {
                hasDigit = true;
            }
        }
    }

    if (inWord && !hasDigit) {
        correctWordCount++;
    }

    return correctWordCount;
}

unsigned int faStr2(const char *str) {
    if (str == nullptr) {
        return 0;
    }

    bool inWord = false;
    int correctWordCount = 0;

    bool correctWord = true;
    bool firstChar = true;

    for (int i = 0; str[i] != '\0'; i++) {
        if (str[i] == ' ') {
            if (inWord && correctWord) {
                correctWordCount++;
            }
            inWord = false;
        } else {
            if (!inWord) {
                inWord = true;
                firstChar = true;
                correctWord = true;
            }

            if (!correctWord) {
                continue;
            }

            if (firstChar && !(str[i] >= 'A' && str[i] <= 'Z')) {
                correctWord = false;
            }
            else if (!(str[i] >= 'a' && str[i] <= 'z')) {
                correctWord = false;
            }
            firstChar = false;
        }
    }

    if (inWord && correctWord) {
        correctWordCount++;
    }

    return correctWordCount;
}

unsigned int faStr3(const char *str) {
    if (str == nullptr) {
        return 0;
    }

    bool inWord = false;
    int correctWordCount = 0;
    int wordCounted = false;

    int currentWordLength = 0;
    int totalWordLength = 0;

    for (int i = 0; str[i] != '\0'; i++) {
        if (str[i] == ' ') {
            if (inWord) {
                inWord = false;
                correctWordCount++;

                totalWordLength += currentWordLength;
                currentWordLength = 0;
            }
        } else {
            if (!inWord) {
                inWord = true;
                currentWordLength = 0;
            }

            if ((str[i] >= 'A' && str[i] <= 'Z') ||
                (str[i] >= 'a' && str[i] <= 'z')) {
                currentWordLength++;
            }
        }
    }

    if (inWord) {
        totalWordLength += currentWordLength;
        correctWordCount++;
    }

    if (correctWordCount == 0) {
        return 0;
    }

    float mean = totalWordLength / static_cast<float>(correctWordCount);
    int rounded = static_cast<int>(mean + 0.5);
    return static_cast<int>(totalWordLength / correctWordCount);
}
