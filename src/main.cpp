#include "mfc/lex/lexer.hpp"

#include <iostream>
#include <fstream>
#include <string>
#include <iterator>

int main(int argc, char* argv[]) {
    if (argc < 2) {
        std::cerr << "Incorrect Usage! Please provide the source file" << "\n";
        std::cerr << "mfc <input-file.mfc>" << std::endl;
        return EXIT_FAILURE;
    }

    std::string filename = argv[1];
    std::ifstream in(filename);
    if (!in.is_open()) {
        std::cerr << "Error: could not open file " << filename << std::endl;
        return EXIT_FAILURE;
    }

    std::string source_code((std::istreambuf_iterator<char>(in)), std::istreambuf_iterator<char>());
    std::cout << "File read successfully. Size: " << source_code.size() << " bytes." << std::endl;

    // std::cout << "\n\n\n" << source_code << std::endl;

    // mfc::tokenize(source_code);

    return EXIT_SUCCESS;
}