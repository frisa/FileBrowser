#include <iostream>
#include <type_traits>
#include "TestCls.hpp"

namespace {
    const int getTypeFromExpression(){
        return 0;
    }
    template<typename T>
    void someTemplateFunction(T parameter){
        return;
    }
/*     void someTemplateFunction2(auto parameter){
        // this is the aloved construct only in the C++ 20
        return;
    } */
    class TstCls{
        public:
        TstCls() = default;
        TstCls(const TstCls& other)
        {
            std::cout << "Copy constructor has been called" << std::endl;
        }
    };

    const TstCls getObj(){
        TstCls* ret = new TstCls();
        return *ret;
    };

    const TstCls& getRef(){
        TstCls* ret = new TstCls();
        return *ret;
    };
}

/*
    Inspects the declared type of the variable of the type and value category of an expression
    - auto has the same rules like the template parameter deduction so it is not going to deduce reference
    - auto never deduce the reference
    - const-ness is deduced by auto
*/

void TestCls::auto_decltype()
{
    int variable1 {1};
    auto avar1 = variable1;

    // simple example of the decltype
    int typed_variable{0};
    static_assert(std::is_same<decltype(typed_variable), int32_t>::value, "typed variable is not the 32 bit integer");

    // simple example of the decltype and auto variable deduced form the constant
    auto auto_variable0{0};
    static_assert(std::is_same<decltype(auto_variable0), int32_t>::value, "auto variable has not been deduced from the initialized value to 32 bit integer");

    // deduction of the int from the function
    const auto& auto_variable1{getTypeFromExpression()};
    static_assert(std::is_same<decltype(auto_variable1), const int&>::value, "auto variable has not been deduced propery from the function");

    // deduction of the const and int from the function
    decltype(auto) auto_variable2 = getObj();
    static_assert(std::is_same<decltype(auto_variable2), const TstCls>::value, "auto variable has not been deduced propery from the function");
}
