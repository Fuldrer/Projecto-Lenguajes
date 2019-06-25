#define DOCTEST_CONFIG_IMPLEMENT_WITH_MAIN

#include "doctest.h"
#include "valinfijo.h"
#include "evaluador.h"

const char *test1 = "(1*2)+(3^3)-(5%5)";

TEST_CASE("Validar Expresion Infija")
{
    std::istringstream ins;
    ins.str(test1);
    Validar f(ins);
    bool parseSuccess = false;
    try{
        f.init();
        parseSuccess = true;
    }
    catch(std::string msg)
    {
        parseSuccess = false;
        std::cout << "Error: " << msg << std::endl;
    }
    REQUIRE(parseSuccess);
}
TEST_CASE("Evaluador de Expresiones")
{
    std::string ins;
    ins = test1;
    Eval l(ins);
    try{
        l.convertir();
        l.evaluar(l.getText());
        //REQUIRE(l.getExpected(1) == "15 2 3 + - ");
        REQUIRE(stoi(l.getExpected(2)) == 29);
        std::string p = l.convertir();
        std::cout << "Posfija: " << p << std::endl;
        //std::cout << "Evaluada: " << l.evaluar(p) << std::endl;
    }
    catch(std::string msg)
    {
       std::cout << "Error: " << msg << std::endl;
    }
}