#include "lexer.hpp"

#include <iostream>
#include <string>

namespace mfc {

void tokenize(std::string& source_file) {
    for (char c : source_file) {
        std::cout << c;
    }
    std::cout << std::endl;
}

}