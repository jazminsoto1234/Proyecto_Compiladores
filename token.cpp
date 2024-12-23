//
// Created by Jazmin on 4/11/2024.
//

#include <iostream>
#include "token.h"


using namespace std;

Token::Token(Type type):type(type) { text = ""; }

Token::Token(Type type, char c):type(type) { text = string(1, c); }

Token::Token(Type type, const string& source, int first, int last):type(type) {
    text = source.substr(first, last);
}

std::ostream& operator << ( std::ostream& outs, const Token & tok )
{
    switch (tok.type) {
        case Token::PLUS: outs << "TOKEN(PLUS)" << tok.text;  break;
        case Token::MINUS: outs << "TOKEN(MINUS)"; break;
        case Token::MUL: outs << "TOKEN(MUL)"; break;
        case Token::DIV: outs << "TOKEN(DIV)"; break;
        case Token::NUM: outs << "TOKEN(NUM)"; break;
        case Token::ERR: outs << "TOKEN(ERR)"; break;
        case Token::PD: outs << "TOKEN(PD)"<<" "<<tok.text; break;
        case Token::PI: outs << "TOKEN(PI)"<<" "<<tok.text; break;
        case Token::END: outs << "TOKEN(END)"; break;
        case Token::ID: outs << "TOKEN(ID)"; break;
        case Token::PRINTF: outs << "TOKEN(PRINTF)"; break;
        case Token::ASSIGN: outs << "TOKEN(ASSIGN)"; break;
        case Token::PC: outs << "TOKEN(PC)"<<" "<<tok.text; break;
        case Token::LT: outs << "TOKEN(LT)"; break;
        case Token::LE: outs << "TOKEN(LE)"; break;
        case Token::EQ: outs << "TOKEN(EQ)"; break;
        case Token::IF: outs << "TOKEN(IF)"; break;
        //case Token::THEN: outs << "TOKEN(THEN)"; break;
        case Token::ELSE: outs << "TOKEN(ELSE)"; break;
        //case Token::ENDIF: outs << "TOKEN(ENDIF)"; break;
        case Token::WHILE: outs << "TOKEN(WHILE)"; break;
        case Token::COMA: outs << "TOKEN(COMA)"; break;
        case Token::IFEXP: outs << "TOKEN(IFEXP)"; break;
        case Token::DO: outs << "TOKEN(DO)"; break;
        //case Token::ENDWHILE: outs << "TOKEN(ENDWHILE)"; break;
        //case Token::VAR: outs << "TOKEN(VAR)"; break;
        case Token::FOR : outs << "TOKEN(FOR)"; break;
        //case Token::ENDFOR : outs << "TOKEN(ENDFOR)"; break;
        case Token::TRUE : outs << "TOKEN(TRUE)"; break;
        case Token::FALSE : outs << "TOKEN(FALSE)"; break;
        case Token::RETURN : outs << "TOKEN(RETURN)"; break;
        case Token::RKEY: outs<<"TOKEN(RKEY)"<<" "<<tok.text; break;
        case Token::LKEY: outs<<"TOKEN(LKEY)"<<" "<<tok.text; break;
        case Token::LIBRARY: outs<<"TOKEN(LIBRARY)"<<" "<<tok.text; break;
        case Token::MICHI: outs<<"TOKEN(MICHI)"<<" "<<tok.text; break;
        case Token::PERCENT: outs<<"TOKEN(PERCENT)"; break;
        case Token::POINT: outs<<"TOKEN(POINT)"<<" "<<tok.text; break;
        case Token::GREATER: outs<<"TOKEN(GREATER)"; break;
        case Token::COMILLA: outs<<"TOKEN(COMILLA)"; break;
        case Token::SALTO: outs<<"TOKEN(SALTO)"; break;
        case Token::PLUSPLUS: outs<<"TOKEN(PLUSPLUS)"; break;
        case Token::COMENTARIO: outs<<"TOKEN(COMENTARIO)"; break;
        case Token::FORMAT: outs<<"TOKEN(FORMAT)"<<" "<<tok.text; break;
        case Token::TIPO: outs<<"TOKEN(TIPO)"<<" "<<tok.text; break;
        //case Token::FUN : outs << "TOKEN(FUN)"; break;
        //case Token::ENDFUN : outs << "TOKEN(ENDFUN)"; break;
        default: outs << "TOKEN(UNKNOWN)"; break;


    }
    return outs;
}

std::ostream& operator << ( std::ostream& outs, const Token* tok ) {
    return outs << *tok;
}