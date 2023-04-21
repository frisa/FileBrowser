/*
    this is the main application of the file browser
*/
#include <iostream>
#include <memory>

#include "Cpp11_AutoDecltype.hpp"

int main()
{
    std::unique_ptr<Cpp11_AutoDecltype> autoDecltype = std::make_unique<Cpp11_AutoDecltype>();

    autoDecltype->auto_TemplateArgumentDeduction();
    //autoDecltype->auto_SimpleTypeDeduction();
    //autoDecltype->auto_ConstTypeDeduction();
    return 0;
}
