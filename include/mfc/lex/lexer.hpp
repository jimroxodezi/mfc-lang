#ifndef MFC_LEXER_HPP
#define MFC_LEXER_HPP

#include <string>

#include "lex/tokens.hpp"

namespace mfc {



struct Lexer {
    private:
    constexpr char currentChar() const;
    void advance();
    static constexpr bool isAlpha(char c);
    static constexpr bool isDigit(char c);

    public:
    explicit Lexer(const std::string& source_code);
    Token nextToken();
};
    
void tokenize(std::string& source_file);

    
}



#endif