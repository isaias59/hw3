#include "string.h"
#include <cstring>
#include <iostream>
using namespace std;

static int stringLength(const char* s) {
    int length = 0;
    while (s[length] != '\0') ++length;
    return length;
}

static void stringCopy(char* dest, const char* src) {
    while (*src) {
        *dest++ = *src++;
    }
    *dest = '\0';
}

String::String(const char* s) {
    stringCopy(buf, s);
}

String::String(const String& s) {
    stringCopy(buf, s.buf);
}

String::~String() {
    buf[0] = '\0';
}

int String::size() {
    return stringLength(buf);
}

String& String::operator=(const String& s) {
    if (this != &s) {
        stringCopy(buf, s.buf);
    }
    return *this;
}

char& String::operator[](int index) {
    if (!in_bounds(index)) {
        static char nullChar = '\0';
        return nullChar;
    }
    return buf[index];
}

std::ostream& operator<<(std::ostream& out, const String& s) {
    s.print(out);
    return out;
}

std::istream& operator>>(std::istream& in, String& s) {
    s.read(in);
    return in;
}


bool String::operator==(const String& s) const {
    return std::strcmp(buf, s.buf) == 0;
}

bool String::operator!=(const String& s) const {
    return !(*this == s);
}

bool String::operator<(const String& s) const {
    return std::strcmp(buf, s.buf) < 0;
}

bool String::operator<=(const String& s) const {
    return std::strcmp(buf, s.buf) <= 0;
}

bool String::operator>(const String& s) const {
    return std::strcmp(buf, s.buf) > 0;
}

bool String::operator>=(const String& s) const {
    return std::strcmp(buf, s.buf) >= 0;
}

String String::operator+(const String& s) const {
    String newString;
    std::strcpy(newString.buf, buf);
    std::strcat(newString.buf, s.buf);
    return newString;
}

String& String::operator+=(const String& s) {
    std::strcat(buf, s.buf);
    return *this;
}

String String::reverse() {
    String reversed;
    int end = size() - 1;
    for (int i = 0; i <= end; ++i) {
        reversed.buf[i] = buf[end - i];
    }
    reversed.buf[end + 1] = '\0';
    return reversed;
}

int String::indexOf(char c) {
    for (int i = 0; buf[i] != '\0'; ++i) {
        if (buf[i] == c) {
            return i;
        }
    }
    return -1; 
}

int String::indexOf(const String& s) {
    const char* found = std::strstr(buf, s.buf);
    if (found) {
        return found - buf;
    }
    return -1; 
}

bool String::in_bounds(int i) {
    return i >= 0 && i < stringLength(buf);
}

void String::print(std::ostream& out) const {
    out << buf;
}

void String::read(std::istream& in) {
    in >> buf;
}

