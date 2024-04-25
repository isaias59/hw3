/*#include "string.hpp"
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
    const char* ptr = strchr(buf, c);
    if (ptr == nullptr) {
        return -1; 
    }
    return ptr - buf;
}

int String::indexOf(const String& s) const {
    const char* ptr = strstr(buf, s.buf);
    if (ptr == nullptr) {
        return -1; 
    }
    return ptr - buf;
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
/////////////////////////////////////////////////////////
const char* String::strstr(const char* haystack, const char* needle) {
    int len = strlen(needle);
    for (const char* p = haystack; (p = strchr(p, needle[0])); ++p)
        if (strncmp(p, needle, len) == 0)
            return p;
    return nullptr;
}

////////////////////////////////////

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
*/

#include "string.hpp"

String::String(const char* s) {
    if (s) {
        int i;
        for (i = 0; s[i] && i < MAXLEN - 1; ++i) {
            buf[i] = s[i];
        }
        buf[i] = '\0';  
    }
    else {
        buf[0] = '\0';
    }
}

String::String(const String& s) {
    int i;
    for (i = 0; s.buf[i] && i < MAXLEN - 1; ++i) {
        buf[i] = s.buf[i];
    }
    buf[i] = '\0';  
}

String& String::operator=(const String& s) {
    if (this != &s) { 
        int i;
        for (i = 0; s.buf[i] && i < MAXLEN - 1; ++i) {
            buf[i] = s.buf[i];
        }
        buf[i] = '\0';  
    }
    return *this;
}

String::~String() {
}

void String::print(std::ostream& out) const {
    out << buf;
}

std::ostream& operator<<(std::ostream& out, const String& s) {
    s.print(out);
    return out;
}

int String::size() const {
    int length = 0;
    while (buf[length] != '\0') {
        ++length;
    }
    return length;
}

char& String::operator[](int index) {
    if (!in_bounds(index)) {
        static char nullchar = '\0';
        std::cerr << "ERROR out of bounds" << std::endl;
        return nullchar;  
    }
    return buf[index];
}

int String::strlen(const char* s) {
    int length = 0;
    while (s[length] != '\0') {
        ++length;
    }
    return length;
}

bool String::in_bounds(int i) const {
    return i >= 0 && i < this->size();
}

bool String::operator==(const String& s) const {
    if (this->size() != s.size()) {
        return false;
    }
    for (int i = 0; i < this->size(); i++) {
        if (buf[i] != s.buf[i]) {
            return false;
        }
    }
    return true;
}

bool String::operator!=(const String& s) const {
    return !(*this == s);
}

bool String::operator>(const String& s) const {
    int minSize = this->size() < s.size() ? this->size() : s.size();
    for (int i = 0; i < minSize; ++i) {
        if (buf[i] > s.buf[i]) return true;
        if (buf[i] < s.buf[i]) return false;
    }
    return this->size() > s.size();
}

bool String::operator<(const String& s) const {
    return !(*this == s) && !(*this > s);
}
bool String::operator>=(const String& s) const {
    return *this > s || *this == s;
}

bool String::operator<=(const String& s) const {
    return *this < s || *this == s;
}

String String::reverse() const {
    String rev;
    int len = this->size();
    for (int i = 0; i < len; ++i) {
        rev.buf[i] = buf[len - 1 - i];
    }
    rev.buf[len] = '\0'; 
    return rev;
}

int String::indexOf(char c) const {
    for (int i = 0; i < this->size(); ++i) {
        if (buf[i] == c) {
            return i;
        }
    }
    return -1;
}

int String::indexOf(const String& s) const {
    if (s.size() == 0) {
        return -1;
    }
    for (int i = 0; i < this->size(); ++i) {
        int j = 0;
        while (i + j < this->size() && j < s.size() && buf[i + j] == s.buf[j]) {
            ++j;
        }
        if (j == s.size()) {
            return i;
        }
    }
    return -1; 
}

String String::operator+(const String& s) const {
    String result;
    int thisLen = this->size();
    int otherLen = s.size();
    int i;
    for (i = 0; i < thisLen && i < MAXLEN - 1; ++i) {
        result.buf[i] = buf[i];
    }
    for (int j = 0; j < otherLen && i < MAXLEN - 1; ++j, ++i) {
        result.buf[i] = s.buf[j];
    }
    result.buf[i] = '\0'; 
    return result;
}

String& String::operator+=(const String& s) {
    *this = *this + s;
    return *this;
}
