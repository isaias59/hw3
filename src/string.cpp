#include "string.hpp"
#include <fstream>

using namespace std;

/*
String::String(const char* s) {
    strncpy(buf, s, MAXLEN - 1);
    buf[MAXLEN - 1] = '\0';
}

String::String(const String& s) {
    strcpy(buf, s.buf);
}

String& String::operator=(const String& s) {
    if (this != &s) {
        strcpy(buf, s.buf);
    }
    return *this;
}

char& String::operator[](int index) {
    return buf[index];
}

int String::size() {
    return strlen(buf);
}

String String::reverse() {
    String reversed;
    int len = size();
    for (int i = 0; i < len; ++i) {
        reversed.buf[i] = buf[len - i - 1];
    }
    reversed.buf[len] = '\0';
    return reversed;
}

int String::indexOf(char c) {
    const char* ptr = strchr(buf, c);
    if (ptr) {
        return ptr - buf;
    }
    return -1;
}

int String::indexOf(const String& s) {
    const char* ptr = strstr(buf, s.buf);
    if (ptr) {
        return ptr - buf;
    }
    return -1;
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

String String::operator+(const String& s) {
    String result;
    strcpy(result.buf, buf);
    strcat(result.buf, s.buf);
    return result;
}

String& String::operator+=(const String& s) {
    strcat(buf, s.buf);
    return *this;
}

void String::print(std::ostream& out) const {
    out << buf;
}

void String::read(std::istream& in) {
  //  in.getline(buf, MAXLEN);
  buf[0] = '\0';
    
    // Read one word from the input stream
    in >> std::setw(MAXLEN) >> buf;

    // Ignore any remaining characters in the input stream
    in.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
}

String::~String() {}

int String::strlen(const char* s) {
    return strlen(s);
}

char* String::strcpy(char* dest, const char* src) {
    return strcpy(dest, src);
}

char* String::strncpy(char* dest, const char* src, int n) {
    return strncpy(dest, src, n);
}


char* String::strncat(char* dest, const char* src, int n) {
    return strncat(dest, src, n);
}

int String::strcmp(const char* left, const char* right) {
    return strcmp(left, right);
}

int String::strncmp(const char* left, const char* right, int n) {
    return strncmp(left, right, n);
}

void String::reverse_cpy(char* dest, const char* src) {
    int len = strlen(src);
    for (int i = 0; i < len; ++i) {
        dest[i] = src[len - i - 1];
    }
    dest[len] = '\0';
}

const char* String::strchr(const char* str, char c) {
    return strchr(str, c);
}

const char* String::strstr(const char* haystack, const char* needle) {
    return strstr(haystack, needle);
}

std::ostream& operator<<(std::ostream& out, const String& s) {
    s.print(out);
    return out;
}

std::istream& operator>>(std::istream& in, String& s) {
    s.read(in);
    return in;
}


/*
std::istream& operator>>(std::istream& in, String& s) {
    s.read(in);
    return in;
}
*/


String::String(const char* s) {
    //strncpy(buf, s, MAXLEN - 1);
    //buf[MAXLEN - 1] = '\0';
    if (strlen(s) >= MAXLEN) {
        std::cout << "ERROR" << std::endl;
        buf[0] = '\0'; // Recover by setting an empty string
    }
    else {
        strncpy(buf, s, MAXLEN - 1);
        buf[MAXLEN - 1] = '\0';
    }
}

String::String(const String& s) {
    strcpy(buf, s.buf);
}

String& String::operator=(const String& s) {
    if (this != &s) {
        strcpy(buf, s.buf);
    }
    return *this;
}

char& String::operator[](int index) {
  //  if (index < 0 || index >= size()) {
    //    return buf[size() - 1]; 
    //}
    //return buf[index];

    if (!in_bounds(index)) {
        std::cout << "ERROR" << std::endl;
        return buf[0];
    }
    return buf[index];

}


int String::size()const {  //change 1.1
    return strlen(buf);
}

String String::reverse() const{  //change 2.2
    String reversed;
    int len = size();
    for (int i = 0; i < len; ++i) {
        reversed.buf[i] = buf[len - i - 1];
    }
    reversed.buf[len] = '\0';
    return reversed;
}

int String::indexOf(char c)const {
    const char* ptr = strchr(buf, c);
    if (ptr) {
        return ptr - buf;
    }
    return -1;
}

int String::indexOf(const String& s) const{
    const char* ptr = strstr(buf, s.buf);
    if (ptr) {
        return ptr - buf;
    }
    return -1;
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
   // String result;
    //strcpy(result.buf, buf);
    //strcat(result.buf, s.buf);
    //return result;

    String result;
    if (strlen(buf) + strlen(s.buf) >= MAXLEN) {
        std::cout << "ERROR" << std::endl;
        // Recover by copying only the available space
        strncpy(result.buf, buf, MAXLEN - strlen(s.buf) - 1);
        result.buf[MAXLEN - strlen(s.buf) - 1] = '\0';
    }
    else {
        strcpy(result.buf, buf);
        strcat(result.buf, s.buf);
    }
    return result;

}

String& String::operator+=(const String& s) {
   // strcat(buf, s.buf); fix 1
    //return *this; fix1
   
    //size_t currentLength = strlen(buf); fix2
    //size_t concatLength = strlen(s.buf);
    //if (currentLength + concatLength >= MAXLEN) {
      //  size_t availableSpace = MAXLEN - currentLength - 1;
        //strncat(buf + currentLength, s.buf, availableSpace);
    //}
    //else {
      //  strcat(buf, s.buf);
    //}
    //return *this;fix2

   /* size_t currentLength = strlen(buf);
    size_t concatLength = strlen(s.buf);

    if (currentLength + concatLength >= MAXLEN) {
        size_t availableSpace = MAXLEN - currentLength - 1;
        strncat(buf + currentLength, s.buf, availableSpace);
    }
    else {
        strcat(buf, s.buf);
    }

    return *this;
    */

    if (strlen(buf) + strlen(s.buf) >= MAXLEN) {
        std::cout << "ERROR" << std::endl;
        // Recover by appending only the available space
        strncat(buf, s.buf, MAXLEN - strlen(buf) - 1);
        buf[MAXLEN - 1] = '\0';
    }
    else {
        strcat(buf, s.buf);
    }
    return *this;
}

void String::print(std::ostream& out) const {
    out << buf;
}

void String::read(std::istream& in) {
  //  in.getline(buf, MAXLEN);
    in.getline(buf, MAXLEN);

    // Trim any trailing whitespace characters
    size_t len = strlen(buf);
    while (len > 0 && isspace(buf[len - 1])) {
        buf[--len] = '\0';
    }
}

String::~String() {}

int String::strlen(const char* s) {
    return std::strlen(s);
}

char* String::strcpy(char* dest, const char* src) {
    return std::strcpy(dest, src);
}

char* String::strncpy(char* dest, const char* src, int n) {
    return std::strncpy(dest, src, n);
}

char* String::strncat(char* dest, const char* src, int n) {
    return std::strncat(dest, src, n);
}

int String::strcmp(const char* left, const char* right) {
    return std::strcmp(left, right);
}

int String::strncmp(const char* left, const char* right, int n) {
    return std::strncmp(left, right, n);
}

void String::reverse_cpy(char* dest, const char* src) {
    int len = strlen(src);
    for (int i = 0; i < len; ++i) {
        dest[i] = src[len - i - 1];
    }
    dest[len] = '\0';
}

const char* String::strchr(const char* str, char c) {
    return std::strchr(str, c);
}

const char* String::strstr(const char* haystack, const char* needle) {
    return std::strstr(haystack, needle);
}

std::ostream& operator<<(std::ostream& out, const String& s) {
    s.print(out);
    return out;
}

std::istream& operator>>(std::istream& in, String& s) {
    s.read(in);
    return in;
}
