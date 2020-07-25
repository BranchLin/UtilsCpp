#include "list_test.h"
#include <list>
#include <iostream>

namespace list_test {

void test() {
    const size_t TEST_SIZE = 10;
    std::list<size_t> list;
    for (size_t i = 0; i < TEST_SIZE; ++i) {
        list.emplace_back(i);
    }

    // 旋转
    for (size_t i = 0; i < TEST_SIZE; ++i) {
        list.front() = i+TEST_SIZE;
        list.splice(list.end(), list, list.begin());         // splice旋转
        //std::rotate(list.begin(), std::next(list.begin()), list.end());     // rotate旋转
        std::cout<<"rotate list:";
        std::for_each(list.begin(), list.end(), [] (size_t item) {
            std::cout<<item<<"->";
        });
        std::cout<<std::endl;
    }

    std::reverse(list.begin(), list.end());
    std::cout<<"reverse list:";
    std::for_each(list.begin(), list.end(), [] (size_t item) {
        std::cout<<item<<"->";
    });
    std::cout<<std::endl;

}

}
