#include "valinfijo.h"

void Validar::init()
{
    Type = getType();
    expr();
    if(Type == "Eof")
        std::cout << "\n-----------------\nExpresion infija correcta\n-----------------\n" << std::endl;
    else
        throw "Expresion infija incorrecta";
}

void Validar::expr()
{
    term();
    expr_p();
}
void Validar::expr_p()
{
    if(Type == "Add" || Type == "Sub")
    {
        Type = getType();
        term();
        expr_p();
    }   
}
void Validar::term()
{
    factor();
    term_p();
}
void Validar::term_p()
{
    if(Type == "Mult" || Type == "Div" || Type == "Mod" || Type == "Pow")
    {
        Type = getType();
        factor();
        term_p();
    }
}
void Validar::factor()
{
    if(Type == "Number")
    {
        Type = getType();
    }   
    else if (Type == "OpPar" || Type == "OpBr")
    {
        Type = getType();
        expr();
        if(Type == "ClPar" || Type == "ClBr")
            Type = getType();
        else 
            throw "Se esperaba ) o ] -> " + curr_type;
    }
    else 
    {
        throw "Error: Se esperaba numero o ( -> " + curr_type;
    }
}

std::string Validar::getType()
{
    char symbol = in.get();
    curr_type = "";
    while(true)
    {
        switch (symbol)
        {
            case '+': curr_type += symbol; return "Add";
            case '-': curr_type += symbol; return "Sub";
            case '*': curr_type += symbol; return "Mult";
            case '%': curr_type += symbol; return "Mod";
            case '/': curr_type += symbol; return "Div";
            case '^': curr_type += symbol; return "Pow";
            case '(': curr_type += symbol; return "OpPar";
            case ')': curr_type += symbol; return "ClPar";
            case '[': curr_type += symbol; return "OpBr";
            case ']': curr_type += symbol; return "ClBr";
            case EOF: return "Eof";
            default:
                if(symbol == ' ' || symbol == '\t' || symbol == '\n' || symbol == '\r')
                    symbol = in.get();
                else if(isdigit(symbol))
                {
                    curr_type += symbol;
                    symbol = in.get();
                    while(isdigit(symbol) || symbol == '.')
                    {
                        curr_type += symbol;
                        symbol = in.get();
                    }
                    in.unget();
                    return "Number";
                }
                else
                {
                    curr_type += symbol;
                    throw "\n Character no valido en la gramatica -> " + curr_type;
                }
        }
    }
}