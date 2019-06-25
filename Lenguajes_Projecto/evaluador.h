#ifndef _EVALUADOR_H
#define _EVALUADOR_H
#include <iostream>
#include <cctype>
#include <stdlib.h>

class Eval {
public:
    Eval() = default;
    Eval(std::string &in): in(in) {}
    ~Eval() = default;
    auto prioridad(char op);
    std::string convertir();
    void evaluar(std::string p);
    std::string getText() { return posf; }
    //std::string getResult() { return std::to_string(res);} 
    auto getExpected(int op){return op == 1 ? posf : std::to_string(res);}

private:
    std::string &in;
    std::string posf;
    double res;
};
#endif

//C++ 11 Features
// tostringru
// default const

//C++ 14 Features
/*auto */

//C++ 17 Features
/**/