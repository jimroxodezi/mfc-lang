#ifndef MFC_PARSER_HPP
#define MFC_PARSER_HPP

#include <vector>
#include "lex/tokens.hpp"

namespace mfc {

class Parser {
public:
    explicit Parser(const std::vector<Token>& tokens);
    void parse();
};

    
}

#endif

