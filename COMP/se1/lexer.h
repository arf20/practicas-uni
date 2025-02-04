#ifndef _LEXER_H
#define _LEXER_H

enum {
    MAIN = 1,
    PRINT,
    LITINT,
    ID,

    PARENL,
    PARENR,
    BRACKETL,
    BRACKETR,
    SEMICOLON,
    COMMA,

    OPEQUAL,
    OPPLUS,
    OPMINUS
};

#endif /* _LEXER_H */

