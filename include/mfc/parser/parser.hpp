#ifndef MFC_PARSER_HPP
#define MFC_PARSER_HPP

#include "mfc/lex/tokens.hpp"
#include "mfc/basic/common.hpp"

#include <vector>

MFC_NAMESPACE_BEGIN

class Parser {
public:
    explicit Parser(const std::vector<Token>& tokens);
    void parse();
};

MFC_NAMESPECE_END

#endif

