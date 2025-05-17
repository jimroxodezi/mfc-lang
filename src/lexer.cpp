

#include "mfc/lex/tokens.hpp"
#include "mfc/lex/lexer.hpp"
#include "mfc/basic/common.hpp"

#include <iostream>
#include <string>

MFC_NAMESPACE_BEGIN


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
    return c == ' ' || c == '\t' /* || '\v' */;
}

constexpr void Lexer::skipComment() {

}

constexpr void Lexer::skipWhitespace() {

}

constexpr Lexer::Lexer(const std::string& source_code) : source(source_code) {}

constexpr Token Lexer::nextToken() {

}

MFC_NAMESPECE_END