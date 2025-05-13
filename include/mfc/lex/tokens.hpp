#ifndef MFC_TOKENS_H
#define MFC_TOKENS_H

#include <string>

namespace mfc {

    enum class TokenKind {
        // keywords
        MFC_TOKENKIND_CLASS,        // 'class'
        MFC_TOKENKIND_IF,           // 'if'
        MFC_TOKENKIND_ELSE,         // 'else'
        MFC_TOKENKIND_WHILE,        // 'while'
        MFC_TOKENKIND_RETURN,       // 'return'
        MFC_TOKENKIND_INT,          // 'int'
        MFC_TOKENKIND_FLOAT,        // 'float'
        MFC_TOKENKIND_BOOL,         // 'bool'
        MFC_TOKENKIND_CHAR,         // 'char'
        MFC_TOKENKIND_VOID,         // 'void'
        MFC_TOKENKIND_TRUE,         // 'true'
        MFC_TOKENKIND_FALSE,        // 'false'
    
        // operators
        MFC_TOKENKIND_PLUS,         // '+'
        MFC_TOKENKIND_MINUS,        // '-' (unary and binary)
        MFC_TOKENKIND_MULTIPLY,     // '*'
        MFC_TOKENKIND_DIVIDE,       // '/'
        MFC_TOKENKIND_EQUAL,        // '==' (comparison)
        MFC_TOKENKIND_NOT_EQUAL,    // '!='
        MFC_TOKENKIND_LESS,         // '<' (will also be used in templates)
        MFC_TOKENKIND_GREATER,      // '>' (will also be used in templates)
        MFC_TOKENKIND_LESS_EQUAL,   // '<='
        MFC_TOKENKIND_GREATER_EQUAL,// '>='
        MFC_TOKENKIND_LOGICAL_AND,  // '&&'
        MFC_TOKENKIND_LOGICAL_OR,   // '||'
        MFC_TOKENKIND_LOGICAL_NOT,  // '!'
        MFC_TOKENKIND_ASSIGN,       // '=' (assignment)
    
      
        MFC_TOKENKIND_LPAREN,       // '('
        MFC_TOKENKIND_RPAREN,       // ')'
        MFC_TOKENKIND_LBRACE,       // '{'
        MFC_TOKENKIND_RBRACE,       // '}'
        MFC_TOKENKIND_SEMICOLON,    // ';'
        MFC_TOKENKIND_COMMA,        // ','
        MFC_TOKENKIND_DOT,          // '.'
        MFC_TOKENKIND_SINGLE_QUOTE, // '\'' (for character literals)
        MFC_TOKENKIND_DOUBLE_QUOTE, // '"' (for string literals)
    
        // literals and identifiers
        MFC_TOKENKIND_IDENTIFIER,   // e.g., variable names, class names
        MFC_TOKENKIND_INT_LITERAL,  // e.g., 123
        MFC_TOKENKIND_FLOAT_LITERAL,// e.g., 12.34
        MFC_TOKENKIND_CHAR_LITERAL,  // e.g., 'a'
        MFC_TOKENKIND_STRING_LITERAL
    };

struct Token {
    TokenKind kind;
    std::string name;
    int line;
    int column;
};

struct Lexer {

};

void tokenize(std::string& source_file);

}

#endif