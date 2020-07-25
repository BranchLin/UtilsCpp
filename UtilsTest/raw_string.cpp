#include "raw_string.h"
#include <string>
#include <iostream>

namespace raw_string {

void test() {
    //
    std::string utf8 = u8"编码——UTF8";
    std::u16string utf16 = u"编码——UTF16";
    std::u32string utf32 = U"编码——UTF32";

    std::string raw = R"(原生字\n符串)";
    //std::string raw_brackets = R"(原生字符串)")";   error
    std::string raw_brackets = R"b(原生字\n符串)")b";

    std::string raw_utf8 = u8R"(原生字)"
                           u8R"(符串——UTF8)";

    std::string raw_complex = u8R"c(复杂原生
                        字)c"
                        u8R"c(符串)")c";

    std::cout<<"raw:"<<raw<<std::endl;
    std::cout<<"raw_brackets:"<<raw_brackets<<std::endl;
    std::cout<<"raw_utf8:"<<raw_utf8<<std::endl;
    std::cout<<"raw_complex:"<<raw_complex<<std::endl;

}

}
