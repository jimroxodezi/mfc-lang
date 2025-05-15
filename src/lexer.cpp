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

}