#ifndef MFC_LEXER_HPP
#define MFC_LEXER_HPP

#include <string>
#include <unordered_map>

#include "mfc/lex/tokens.hpp"

namespace mfc {



struct Lexer {
    private:
    const std::string& source;
    size_t pos;
    static const std::unordered_map<std::string, TokenKind> keywords;

    // current chat returns the current character tracker by pos
    // if we are at the end of source, it returns EOF
    constexpr char currentChar() const;

    void advance();
    
    // helper function to determine if a character is an alphabet
    static constexpr bool isAlpha(char c);
    
    // helper function to determine if a character is a digit
    static constexpr bool isDigit(char c);

    // helper function to determine if a character is (space)
    static constexpr bool isSpace(char c);
    
    // helper function to skip whitespaces
    void skipWhitespace();

    // helper function to skip comments
    void skipComment();

    public:
    explicit Lexer(const std::string& source_code);
    Token nextToken();
};
    
void tokenize(std::string& source_file);

    
}



#endif