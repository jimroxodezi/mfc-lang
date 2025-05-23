#ifndef MFC_TOKENS_H
#define MFC_TOKENS_H

#include <string>
#include <optional>

// #include "lex/lexer.hpp"
#include "mfc/basic/common.hpp"
#include "mfc/basic/sourcelocation.hpp"

MFC_NAMESPACE_BEGIN

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
    MFC_TOKENKIND_SINGLE_QUOTE, // ''' (for character literals)
    MFC_TOKENKIND_DOUBLE_QUOTE, // '"' (for string literals)
    
    // literals and identifiers
    MFC_TOKENKIND_IDENTIFIER,   // e.g., variable names, class names
    MFC_TOKENKIND_INT_LITERAL,  // e.g., 123
    MFC_TOKENKIND_FLOAT_LITERAL,// e.g., 12.34
    MFC_TOKENKIND_CHAR_LITERAL,  // e.g., 'a'
    MFC_TOKENKIND_STRING_LITERAL,

    // others
    MFC_TOKENKIND_EOF,
    MFC_TOKENKIND_INVALID_TOKEN
};



struct Token {
    // actual flavour or type of the token. see TokenKind enum for possible tokens
    TokenKind kind;
    // std::optional<std::string> name;
    std::string name;
    SourceLocation loc;

    /// is checks if this token is a specific kind, as in
    bool is(TokenKind K) const { return kind == K; }

    // isNot checks if a token is not of a specific kind
    bool isNot(TokenKind K) const { return kind != K; }
    
    // isOneOf checks if a token is 
    bool isOneOf(TokenKind K1, TokenKind K2) const {
        return is(K1) || is(K2);
    }
    
    //specialization for multiple token kinds
    template <typename... Ts> bool isOneOf(TokenKind K1, Ts... Ks) const {
        return is(K1) || isOneOf(Ks...);
    }

    std::string toString() const {
        std::string typeStr;
        switch (kind)
        {
        // keywords
        case TokenKind::MFC_TOKENKIND_CLASS:        typeStr = "MFC_TOKENKIND_CLASS"; break;
        case TokenKind::MFC_TOKENKIND_IF:           typeStr = "MFC_TOKENKIND_IF"; break;
        case TokenKind::MFC_TOKENKIND_ELSE:         typeStr = "MFC_TOKENKIND_ELSE"; break;
        case TokenKind::MFC_TOKENKIND_WHILE:        typeStr = "MFC_TOKENKIND_WHILE"; break;
        case TokenKind::MFC_TOKENKIND_RETURN:       typeStr = "MFC_TOKENKIND_RETURN"; break;
        case TokenKind::MFC_TOKENKIND_INT:          typeStr = "MFC_TOKENKIND_INT"; break;
        case TokenKind::MFC_TOKENKIND_FLOAT:        typeStr = "MFC_TOKENKIND_FLOAT"; break;
        case TokenKind::MFC_TOKENKIND_BOOL:         typeStr = "MFC_TOKENKIND_BOOL"; break;
        case TokenKind::MFC_TOKENKIND_CHAR:         typeStr = "MFC_TOKENKIND_CHAR"; break;
        case TokenKind::MFC_TOKENKIND_VOID:         typeStr = "MFC_TOKENKIND_VOID"; break;
        case TokenKind::MFC_TOKENKIND_TRUE:         typeStr = "MFC_TOKENKIND_TRUE"; break;
        case TokenKind::MFC_TOKENKIND_FALSE:        typeStr = "MFC_TOKENKIND_FALSE"; break;
        
        // operators
        case TokenKind::MFC_TOKENKIND_PLUS:         typeStr = "MFC_TOKENKIND_PLUS"; break;
        case TokenKind::MFC_TOKENKIND_MINUS:        typeStr = "MFC_TOKENKIND_MINUS"; break;
        case TokenKind::MFC_TOKENKIND_MULTIPLY:     typeStr = "MFC_TOKENKIND_MULTIPLY"; break;
        case TokenKind::MFC_TOKENKIND_DIVIDE:       typeStr = "MFC_TOKENKIND_DIVIDE"; break;
        case TokenKind::MFC_TOKENKIND_EQUAL:        typeStr = "MFC_TOKENKIND_EQUAL"; break;
        case TokenKind::MFC_TOKENKIND_NOT_EQUAL:    typeStr = "MFC_TOKENKIND_NOT_EQUAL"; break;
        case TokenKind::MFC_TOKENKIND_LESS:         typeStr = "MFC_TOKENKIND_LESS"; break;
        case TokenKind::MFC_TOKENKIND_GREATER:      typeStr = "MFC_TOKENKIND_GREATER"; break;
        case TokenKind::MFC_TOKENKIND_LESS_EQUAL:   typeStr = "MFC_TOKENKIND_LESS_EQUAL"; break;
        case TokenKind::MFC_TOKENKIND_GREATER_EQUAL:typeStr = "MFC_TOKENKIND_GREATER_EQUAL"; break;
        case TokenKind::MFC_TOKENKIND_LOGICAL_AND:  typeStr = "MFC_TOKENKIND_LOGICAL_AND"; break;
        case TokenKind::MFC_TOKENKIND_LOGICAL_OR:   typeStr = "MFC_TOKENKIND_LOGICAL_OR"; break;
        case TokenKind::MFC_TOKENKIND_LOGICAL_NOT:  typeStr = "MFC_TOKENKIND_LOGICAL_NOT"; break;
        case TokenKind::MFC_TOKENKIND_ASSIGN:       typeStr = "MFC_TOKENKIND_ASSIGN"; break;
        
        // punctuations
        case TokenKind::MFC_TOKENKIND_LPAREN:       typeStr = "MFC_TOKENKIND_LPAREN"; break;
        case TokenKind::MFC_TOKENKIND_RPAREN:       typeStr = "MFC_TOKENKIND_RPAREN"; break;
        case TokenKind::MFC_TOKENKIND_LBRACE:       typeStr = "MFC_TOKENKIND_LBRACE"; break;
        case TokenKind::MFC_TOKENKIND_RBRACE:       typeStr = "MFC_TOKENKIND_RBRACE"; break;
        case TokenKind::MFC_TOKENKIND_SEMICOLON:    typeStr = "MFC_TOKENKIND_SEMICOLON"; break;
        case TokenKind::MFC_TOKENKIND_COMMA:        typeStr = "MFC_TOKENKIND_COMMA"; break;
        case TokenKind::MFC_TOKENKIND_DOT:          typeStr = "MFC_TOKENKIND_DOT"; break;
        case TokenKind::MFC_TOKENKIND_SINGLE_QUOTE: typeStr = "MFC_TOKENKIND_SINGLE_QUOTE"; break;
        case TokenKind::MFC_TOKENKIND_DOUBLE_QUOTE: typeStr = "MFC_TOKENKIND_DOUBLE_QUOTE"; break;


        case TokenKind::MFC_TOKENKIND_INT_LITERAL:  typeStr = "MFC_TOKENKIND_INT_LITERAL"; break;
        case TokenKind::MFC_TOKENKIND_IDENTIFIER:   typeStr = "MFC_TOKENKIND_IDENTIFIER"; break;
        case TokenKind::MFC_TOKENKIND_FLOAT_LITERAL:typeStr = "MFC_TOKENKIND_FLOAT_LITERAL"; break;
        case TokenKind::MFC_TOKENKIND_CHAR_LITERAL: typeStr = "MFC_TOKENKIND_CHAR_LITERAL"; break;
        case TokenKind::MFC_TOKENKIND_STRING_LITERAL:typeStr = "MFC_TOKENKIND_STRING_LITERAL"; break;
        default: 
            break;
        }

        return "Token(" + typeStr + ", \"" + name + "\")";
    }
};

MFC_NAMESPECE_END

#endif