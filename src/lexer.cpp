#include "mfc/lex/tokens.hpp"
#include "mfc/lex/lexer.hpp"

#include <iostream>
#include <string>

namespace mfc {

// void tokenize(std::string& source_file) {
//     for (char c : source_file) {
//         std::cout << c;
//     }
//     std::cout << std::endl;
// }

constexpr char Lexer::currentChar() const {

    return pos < source.length() ? source[pos] : '\0';
}

void Lexer::advance() {
    if (pos < source.length()) {
        
    }
}

constexpr bool Lexer::isAlpha(char c) {
    return (c >= 'a' && c <= 'z') || (c >= 'A' && c <= 'Z');
}

constexpr bool Lexer::isDigit(char c) {
    return c >= '0' && c <= '9';
}

constexpr bool Lexer::isSpace(char c) {
    return c == ' ';
}

}