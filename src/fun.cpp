// Copyright 2022 UNN-IASR
#include "fun.h"

unsigned int faStr1(const char *str) {
    if (str == nullptr) {
        return 0;
    }

    bool inWord = false;
    int correctWordCount = 0;
    int wordCounted = false;

    for (int i = 0; str[i] != '\0'; i++) {
        inWord = str[i] == ' ';

        if (!inWord) {
            wordCounted = false;
            continue;
        }

        if (!wordCounted && !(str[i] >= '0' && str[i] <= '9')) {
            correctWordCount++;
            wordCounted = true;
        }
    }

    return correctWordCount;
}

unsigned int faStr2(const char *str) {
    if (str == nullptr) {
        return 0;
    }

    bool inWord = false;
    int correctWordCount = 0;
    int wordCounted = false;

    bool wordStartsWithCapital = false;
    bool allLettersLowercase = false;

    for (int i = 0; str[i] != '\0'; i++) {
        inWord = str[i] == ' ';

        if (!inWord) {
            if (wordStartsWithCapital && allLettersLowercase) {
                correctWordCount++;
            }
            wordStartsWithCapital = false;
            allLettersLowercase = false;
            wordCounted = false;
            continue;
        }

        if (!wordCounted && (str[i] >= 'A' && str[i] <= 'Z')) {
            wordStartsWithCapital = true;
            wordCounted = true;
        }

        if (wordStartsWithCapital && !(str[i] >= 'a' && str[i] <= 'z')) {
            allLettersLowercase = false;
        }
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

    int totalWordLength = 0;

    for (int i = 0; str[i] != '\0'; i++) {
        inWord = str[i] == ' ';

        if (!inWord) {
            wordCounted = false;
            continue;
        }

        if ((str[i] >= 'a' && str[i] <= 'z') || (str[i] >= 'A' && str[i] <= 'Z')) {
            totalWordLength++;
        }

        if (!wordCounted) {
            correctWordCount++;
            wordCounted = true;
        }
    }

    float mean = totalWordLength / (float)correctWordCount;

    if (mean - (int)mean > 0.5) {
        return (int)(totalWordLength / correctWordCount) + 1;
    }
    else {
        return (int)(totalWordLength / correctWordCount);
    }
}
