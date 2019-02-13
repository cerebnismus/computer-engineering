#ifndef CALCULATOR_HPP
#define CALCULATOR_HPP

#include <iostream>

namespace math {
    
enum {
  ADD,
  SUB,
  MUL,
  DIV,
  MOD
};   


class calculator 
{
public:

    calculator(){};
    
    double eval(double _val1, double _val2, int _op)
    {
        
        switch (_op) {
            case ADD:
                return _val1 + _val2;
                
            case SUB:
                return _val1 - _val2;
            
            case MUL:
                return _val1 * _val2;
                
            case DIV:
                if(_val2 != 0)
                    return _val1 / _val2;
            
            default:
                std::cout << "Unsupported opereation";
        };
        
    }
};

}

#endif