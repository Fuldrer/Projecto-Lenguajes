#include <iostream>
#include <cstdlib>
#include <cmath>
#include <stack>
#include <string>
#include <exception>
#include <evaluador.h>
using namespace std;

auto Eval::prioridad(char op) {
 switch (op) {
  case '^': return 3;
  case '*':
  case '%':
  case '/': return 2;
  case '+': 
  case '-': return 1;
  case ']':
  case ')': return -1;
  default: return 0;
 }
} 
string Eval::convertir() {
 stack<char> pila;
 posf = "";
 for (int i=0; i < in.size(); i++) {
    switch (in[i]) {
    case '[':
    case '(':
      pila.push('(');
      break;
    case ']':
    case ')':
      while (!pila.empty() && pila.top() != '(' && pila.top() != '[') {
      posf += string(1,pila.top()) + " ";
      pila.pop();
      }
      pila.pop();
      break;
    case '+':
    case '-':
    case '*':
    case '/':
    case '^':
    case '%':
      while (!pila.empty() && prioridad(in[i]) <= prioridad(pila.top())) {
      posf += string(1,pila.top()) + " ";
      pila.pop();
      }
      pila.push(in[i]);
      break;
    default:
      if(isdigit(in[i]))
      {
          posf += string(1, in[i++]);
          while(isdigit(in[i]) || in[i] == '.') 
          posf += string(1, in[i++]);
          posf += " ";
          i--; 
      }
      if(isalpha(in[i]))
      {
        throw "\n Se encontro un caracter no aceptado -> " + std::string(1,in[i]);
      }
    }
  }
  while (!pila.empty()) {
    posf += string(1, pila.top()) + " ";
    pila.pop();
  }
  return posf;
}
void Eval::evaluar(string p) {
 stack<double> pila;
 double op1, op2;
 for (int i=0; i < p.size(); i+=2) {
  switch (p[i]) {
   case '^':
    op2 = pila.top(); pila.pop();
    op1 = pila.top(); pila.pop();
    pila.push(pow(op1, op2));
    break;
   case '*':
    op2 = pila.top(); pila.pop();
    op1 = pila.top(); pila.pop();
    pila.push(op1*op2);
    break;
   case '/':
    op2 = pila.top(); pila.pop();
    op1 = pila.top(); pila.pop();
    pila.push(op1 / op2);
    break;
   case '+':
    op2 = pila.top(); pila.pop();
    op1 = pila.top(); pila.pop();
    pila.push(op1 + op2);
    break;
   case '%':
    op2 = pila.top(); pila.pop();
    op1 = pila.top(); pila.pop();
    pila.push(int(op1) % int(op2));
    break;
   case '-':
    op2 = pila.top(); pila.pop();
    op1 = pila.top(); pila.pop();
    pila.push(op1 - op2);
    break;
   default:
    string aux = "";
    while (p[i] != ' ')
     aux += string(1, p[i++]);
    pila.push(atof(aux.c_str()));
    i--;
  }
 }
 res = pila.top();
}