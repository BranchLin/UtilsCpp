#ifndef TEMPLATE_TEST_H
#define TEMPLATE_TEST_H
#include <array>
#include <iostream>
#include <sstream>
//template <class _Tp, size_t _Size>
//struct _LIBCPP_TEMPLATE_VIS array

//template <typename T>
//typename std::enable_if<std::is_trivial<T>::value>::type SFINAE_test(T value)
//{
//    std::cout<<"T is trival"<<std::endl;
//}

//typename std::enable_if<std::is_trivial<int>::value, int>::type* sd;

//template<typename EnumT , typename std::enable_if<std::is_enum<EnumT>::value>::type * = nullptr>
//void  func(EnumT e1, EnumT e2 ){}

//template<typename InterT , typename std::enable_if<std::is_Integral<InterT>::value>::type * = nullptr>
//void  func(InterT i1, InterT i2 ){}


//template<typename EnumT , typename std::enable_if_t<std::is_enum<EnumT>::value> * = nullptr>
//void  foo(EnumT e1, EnumT e2 ){}

//template<typename InterT , typename std::enable_if_t<std::is_integral<InterT>::value> * = nullptr>
//void  foo(InterT i1, InterT i2 ){}

//int main()
//{
//    func(1 , 4);
//    foo(4,1);
//     return 0;
//}
namespace template_test {
constexpr const size_t LIN = 7;
constexpr const size_t LIAN = 9;
constexpr const size_t YING = 5;

constexpr const char* name_by_id(size_t id) {
    switch (id) {
    case 7:
        return "lin";
    case 9:
        return "lian";
    default:
        return "ying";
    }
}

template <typename T, typename std::enable_if<std::is_convertible<T, const char*>::value>::type* = nullptr>
void printf(const T& str) {
    std::cout<<"str:"<<static_cast<const char*>(str)<<std::endl;
}

template <typename T, typename std::enable_if<std::is_integral<T>::value>::type* = nullptr>
void printf(const T& str) {
    std::cout<<"integral:"<<str<<std::endl;
}

template <size_t ID, class _CharT = char>
class Log {
public:
    static inline Log<ID> log;

    template <class T>
    inline Log& operator<<(const T& v) {
        std::cout<<name_by_id(ID)<<":"<<v;
        return *this;
    }

    inline Log& operator<<(std::basic_ostream<_CharT>& (*__pf)(std::basic_ostream<_CharT>&)) {
        __pf(std::cout);
        return *this;
    }

};

template <class _CharT = char>
class InvalidLog {
public:
    template <class T>
    inline InvalidLog& operator<<(const T&) {
        return *this;
    }

    inline InvalidLog& operator<<(std::basic_ostream<_CharT>& (*__pf)(std::basic_ostream<_CharT>&)) {
        return *this;
    }
};

template <>
class Log<0, char>{
public:
    static inline InvalidLog<> log;
};

void test();

}

#endif // TEMPLATE_TEST_H
