////////////////////////////////////////////////////////////////////////////////
// Module Name:  stack_machine.h/cpp
// Authors:      Sergey Shershakov
// Version:      0.2.0
// Date:         23.01.2017
//
// This is a part of the course "Algorithms and Data Structures" 
// provided by  the School of Software Engineering of the Faculty 
// of Computer Science at the Higher School of Economics.
////////////////////////////////////////////////////////////////////////////////

#include "stack_machine.h"
#include <stdlib.h>
#include <string>
#include <vector>
#include <sstream>
#include <iostream>
#include <stdlib.h>
#include <cstring>
#include <cctype>

namespace xi {

    void StackMachine::registerOperation(char symb, xi::IOperation *oper) {
        SymbolToOperMapConstIter obj = _opers.find(symb);
        if(obj!=_opers.end())
            throw std::logic_error("ERROR");
        _opers[symb]=oper;
    }
    IOperation* StackMachine::getOperation(char symb) {
        SymbolToOperMapConstIter obj = _opers.find(symb);
        if(obj==_opers.end())
            return nullptr;
        return obj->second;
    }

//==============================================================================
// Free functions -- helpers
//==============================================================================

bool StackMachine:: _isCorrect(const std::string& str)
{
        bool q= false;
        std::string line="";
        for(int i=0; i<str.length(); i++)
        {
            q=false;
            if(str[i]!=' ')
            {
                line += str[i];
            }
            else {

                if(_isNumb(line)) {
                    q= true;
                    _s.push(std::stoi(line));
                }

                else
                    if(_isSymb(line)) {
                        vect.push_back((line[0]));
                        q= true;
                    }
                line="";
            }
            if(i==str.length()-1)
            {
                q=true;
                if(_isNumb(line))
                    _s.push(std::stoi(line));
                if(_isSymb(line))
                    vect.push_back((line[0]));
                else{
                    throw std::logic_error("ERROR");
                }
            }
            }

        if(!vect.empty() && !_s.isEmpty())
            return true;
        return false;
}

    bool StackMachine::_isNumb(std::string &str) {
        for(int i=0; i<str.length(); i++)
        {
         if(!isdigit(str[i]))
             return false;
        }
        return true;
    }
    bool StackMachine::_isSymb(std::string &str)
    {
      if(getOperation(str[0])!= nullptr)
          return true;
      return false;
    }
// TODO: if you need any free functions, add their definitions here.

//==============================================================================
// class PlusOp
//==============================================================================


int PlusOp::operation(char op, int a, int b, int /*c*/) // < just commented unused argument. This does not affect the code anyhow.
{
    if(op != '+')
        throw std::logic_error("Operation other than Plus (+) are not supported");

    // here we just ignore unused operands
    return a + b;
}

IOperation::Arity PlusOp::getArity() const
{
    return arDue;
}
int MinusOp::operation(char op, int a, int b, int /*c*/)
{
        if(op!='-')
            throw std::logic_error("ERROR");
        return b-a;
}
IOperation:: Arity MinusOp::getArity() const {
        return arDue;
    }
IOperation:: Arity AssignOp::getArity() const {
        return arUno;
    }
    int AssignOp::operation(char op, int a, int /*b*/, int /*c*/) {
        if(op!='=')
            throw std::logic_error("ERROR");
        return a;
    }
    int AndOp::operation(char op, int a, int b, int /*c*/) {
        if(op!='&')
            throw std::logic_error("ERROR");
        return a&b;
    }
    IOperation:: Arity AndOp::getArity() const {
        return arDue;
    }
//==============================================================================
// class StackMachine
//==============================================================================
int StackMachine::calculate(const std::string &expr, bool clearStack) {
        if (clearStack)
            _s.clear();

            if (_isCorrect(expr)) {
                for (int i = 0; i < vect.size(); i++) {
                    int arr = getOperation(vect[i])->getArity();
                    if (arr == 0) {
                        int a = _s.pop();
                        int result = getOperation(vect[i])->operation(vect[i], a, 0, 0);
                        _s.push(result);
                    }
                    if (arr == 1) {
                        int a = _s.pop();
                        int b = _s.pop();
                        int result = getOperation(vect[i])->operation(vect[i], a, b, 0);
                        _s.push(result);
                    }
                    if (arr == 2) {
                        int a = _s.pop();
                        int b = _s.pop();
                        int c = _s.pop();
                        int result = getOperation(vect[i])->operation(vect[i], a, b, c);
                        _s.push(result);
                    }
                }
                int r = _s.pop();
                if (!_s.isEmpty())
                    throw std::logic_error("ERROR");
                else {
                    _s.push(r);
                    return r;

                }

            }
        }

// TODO: put StackMachine methods implementation here


} // namespace xi
