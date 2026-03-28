// Copyright 2022 UNN-IASR
#include <iostream>
#include "fun.h"

int main() {
    std::cout << "Тесты для faStr1\n";
    const char* t1[] = {
        "Hello 123 world!",
        "abc def 789",
        "   one two three   ",
        "",
        "   ",
        "a1 b2 c3 d4",
        "test"
    };
    for (const char* s : t1) {
        std::cout << "\"" << s << "\" -> " << faStr1(s) << std::endl;
    }

    std::cout << "\nТесты для faStr2\n";
    const char* t2[] = {
        "Hello world! 123 abc",
        "Apple Banana Cat",
        "Hello World!",
        "A a B b",
        "A1b2 C3d4",
        "lowercase",
        "   First   Second   ",
        "",
        "   "
    };
    for (const char* s : t2) {
        std::cout << "\"" << s << "\" -> " << faStr2(s) << std::endl;
    }

    std::cout << "\nТесты для faStr3\n";
    const char* t3[] = {
        "   Hello   world   ",
        "short longg",
        "a",
        "abc def",
        "   ",
        "",
        "a bb ccc",
        "abcde fghij"
    };
    for (const char* s : t3) {
        std::cout << "\"" << s << "\" -> " << faStr3(s) << std::endl;
    }

    return 0;
}
