#include "button.h"


Button::Button(std::string msg) {

    m_msg = msg;
}

void Button::print() {
    
    std::cout << m_msg << std::endl;

}

