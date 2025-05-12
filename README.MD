# MFC

mfc stands for my first compiler. It is a compiler for a statically typed, compiled language with Java-like class syntax, C-like function syntax, and support for generic programming via templates. It emphasizes composition over inheritance. 

## Overview
- **Typing**: Static, with type names before identifiers.
- **Classes**: Java-style, supporting fields and methods, no inheritance, only composition.
- **Functions**: C-style syntax.
- **Templates**: Generic classes with `<T>` syntax.
- **Types**: Basic types (`int`, `float`, `bool`, `char`, `void`, `string`), class types, and template types.
- **Literals**: Integer, float, boolean, character, and string literals.

## BNF Grammar

### Program Structure
```bnf
<program> ::= <declaration-list>
<declaration-list> ::= <declaration> | <declaration> <declaration-list> | ε
<declaration> ::= <function-decl> | <class-decl> | <global-var-decl>
```

### Supported types
```bnf
<type> ::= <basic-type> | <class-type> | <template-type>
<basic-type> ::= "int" | "float" | "bool" | "char" | "void" | "string"
<class-type> ::= <identifier>
<template-type> ::= <identifier> "<" <type-list> ">"
```

### Identifiers
```bnf
<identifier> ::= <letter> <letter-or-digit>*
<letter> ::= [a-zA-Z_]
<letter-or-digit> ::= [a-zA-Z_0-9]
```

### function declaration
```bnf
<function-decl> ::= <type> <identifier> "(" <param-list> ")" "{" <stmt-list> "}"
<param-list> ::= ε | <param> | <param> "," <param-list>
<param> ::= <type> <identifier>
<stmt-list> ::= <stmt> | <stmt> <stmt-list> | ε
```

### class declaration
```bnf
<class-decl> ::= "class" <identifier> <template-params>? "{" <class-member-list> "}"
<template-params> ::= "<" <identifier-list> ">"
<identifier-list> ::= <identifier> | <identifier> "," <identifier-list>
<class-member-list> ::= <class-member> | <class-member> <class-member-list> | ε
<class-member> ::= <field-decl> | <method-decl>
<field-decl> ::= <type> <identifier> ";"
<method-decl> ::= <type> <identifier> "(" <param-list> ")" "{" <stmt-list> "}"
```

### global variable decl
```bnf
<global-var-decl> ::= <type> <identifier> ";"
```

### statements
```bnf
<stmt> ::= <var-decl-stmt> | <assign-stmt> | <if-stmt> | <while-stmt> | <return-stmt> | <expr-stmt> | <block-stmt>
<var-decl-stmt> ::= <type> <identifier> "=" <expr> ";"
<assign-stmt> ::= <lvalue> "=" <expr> ";"
<if-stmt> ::= "if" "(" <expr> ")" <stmt> | "if" "(" <expr> ")" <stmt> "else" <stmt>
<while-stmt> ::= "while" "(" <expr> ")" <stmt>
<return-stmt> ::= "return" <expr>? ";"
<expr-stmt> ::= <expr> ";"
<block-stmt> ::= "{" <stmt-list> "}"
<lvalue> ::= <identifier> | <lvalue> "." <identifier>
```

### expressions
```bnf
<expr> ::= <literal> | <identifier> | <binary-expr> | <unary-expr> | <call-expr> | <field-access-expr> | <paren-expr>
<literal> ::= <int-literal> | <float-literal> | <bool-literal> | <char-literal> | <string-literal>
<int-literal> ::= [0-9]+
<float-literal> ::= [0-9]+ "." [0-9]+
<bool-literal> ::= "true" | "false"
<char-literal> ::= "'" <char> "'"
<string-literal> ::= "\"" <char-sequence> "\""
<char-sequence> ::= ε | <char> <char-sequence>
<char> ::= <any-character-except-quote> | <escape-sequence>
<escape-sequence> ::= "\\" ("n" | "t" | "\"" | "\\")
<any-character-except-quote> ::= [^\"\\]
<binary-expr> ::= <expr> <bin-op> <expr>
<bin-op> ::= "+" | "-" | "*" | "/" | "==" | "!=" | "<" | ">" | "<=" | ">=" | "&&" | "||"
<unary-expr> ::= <unary-op> <expr>
<unary-op> ::= "-" | "!"
<call-expr> ::= <identifier> "(" <expr-list> ")" | <expr> "." <identifier> "(" <expr-list> ")"
<field-access-expr> ::= <expr> "." <identifier>
<paren-expr> ::= "(" <expr> ")"
<expr-list> ::= ε | <expr> | <expr> "," <expr-list>
```