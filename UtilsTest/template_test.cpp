#include "template_test.h"

namespace template_test {

void test() {
    template_test::printf(19);
    template_test::printf("lin");

    template_test::Log<LIN>::log<<"---"<<56.8<<"--"<<"ce"<<"--"<<std::endl;
    template_test::Log<LIAN>::log<<"---"<<std::endl;
    template_test::Log<YING>::log<<"---"<<std::endl;
    template_test::Log<0>::log<<"---"<<std::endl;
    std::cout<<std::endl;
}

}
