#include "string.h"
#include <fstream>
#include <iostream>
#include <iomanip>
using namespace std;


String::String(const char* s) {
    if (strlen(s)) {
        cout << "ERROR: String Capacity Exceeded." << endl;
    }
    strncpy(buf, s, MAXLEN);
}

String::String(const String& s) {
    strcpy(buf, s.buf);
}

String& String::operator=(const String& s) {
    strcpy(buf, s.buf);
    return *this;
}

int String::size()const {
    return strlen(buf);
}

String String::reverse()const {
    String reversed;
    reversed.reverse_cpy(reversed.buf, buf);
    return reversed;
}

int String::indexOf(char c)const {
    return strchr(buf, c) - buf;
}

int String::indexOf(const String& s) const{
    return strstr(buf, s.buf) - buf;
}

bool String::operator==(const String& s) const {
    return strcmp(buf, s.buf) == 0;
}

bool String::operator!=(const String& s) const {
    return strcmp(buf, s.buf) != 0;
}

bool String::operator>(const String& s) const {
    return strcmp(buf, s.buf) > 0;
}

bool String::operator<(const String& s) const {
    return strcmp(buf, s.buf) < 0;
}

bool String::operator<=(const String& s) const {
    return strcmp(buf, s.buf) <= 0;
}

bool String::operator>=(const String& s) const {
    return strcmp(buf, s.buf) >= 0;
}

String String::operator+(const String& s) const{
    String result;
    strcpy(result.buf, buf);
    strncat(result.buf, s.buf, MAXLEN);
    return result;
}

String& String::operator+=(const String& s) {
    strncat(buf, s.buf, MAXLEN);
    return *this;
}

void String::print(std::ostream& out) const {
    out << buf;
}

void String::read(std::istream& in)
{
    in >> buf;
}

String::~String() {}

int String::strlen(const char* s) {
    int i = 0;
    for (; s[i] != '\0'; i++) {}
    return i;
}

char* String::strcpy(char* dest, const char* src) {
    int i = 0;
    for (; src[i] != '\0' && i < MAXLEN; i++) {
        dest[i] = src[i];
    }
    dest[i] = '\0';
    return dest;
}

char* String::strncpy(char* dest, const char* src, int n) {
    int i = 0;
    for (; src[i] != '\0' && i < MAXLEN && i < n; i++) {
        dest[i] = src[i];
    }
    dest[i] = '\0';
    return dest;
}

int String::strcmp(const char* left, const char* right) {
    int i = 0;
    for (; left[i] != '\0' && right[i] != '\0'; i++) {
        if (left[i] != right[i]) {
            break;
        }
    }
    return left[i] - right[i];
}

int String::strncmp(const char* left, const char* right, int n) {
    int i = 0;
    for (; left[i] != '\0' && right[i] != '\0' && i < n; i++) {
        if (left[i] != right[i]) {
            break;
        }
    }
    return left[i] - right[i];
}

void String::reverse_cpy(char* dest, const char* src) {
    int len = strlen(src);
    for (int i = 0; i < len; ++i) {
        dest[i] = src[len - i - 1];
    }
    dest[len] = '\0';
}

std::ostream& operator<<(std::ostream& out, const String& s) {
    s.print(out);
    return out;
}

std::istream& operator>>(std::istream& in, String& s) {
    s.read(in);
    return in;
}

char& String::operator[](int index) {
    if (!in_bounds(index)) {
        cout << "ERROR: String Capacity Exceeded" << endl;
        return buf[0];
    }
    return buf[index];
}

char* String::strncat(char* dest, const char* src, int n) {
    char* ptr = dest;
    int i = 0;
    while (*ptr != '\0') {
        i++;
        ptr++;  
    }

    while (*src != '\0' && i < n) {
        i++;
        *ptr++ = *src++;  
    }
    *ptr = '\0';  

    return dest;  
}

const char* String::strchr(const char* str, char c) {
    for (int i = 0; str[i] != '\0' && i < MAXLEN; i++) {
        if (str[i] == c) {
            return str + i;
        }
    }
    return nullptr;
}

const char* String::strstr(const char* haystack, const char* needle) {
    return std::strstr(haystack, needle);
}

char* strcat(char* dest, const char* src) {
    char* ptr = dest;
    while (*ptr != '\0') {
        ptr++;  
    }

    while (*src != '\0') {
        *ptr++ = *src++;  
    }
    *ptr = '\0';  

    return dest;  
}
