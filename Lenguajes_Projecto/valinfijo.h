#ifndef _VALINFIJO_
#define _VALINFIJO_
#include <iostream>
#include <cctype>
#include <stdlib.h>

class Validar{
    public:
        Validar(std::istream &in): in(in) {}
        ~Validar(){}
        void init();
        void expr();
        void expr_p();
        void term();
        void term_p();
        void factor();
        std::string getType();

    private:
        std::istream &in;
        std::string curr_type;
        std::string Type;
};

#endif