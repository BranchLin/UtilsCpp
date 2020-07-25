#include <QCoreApplication>
#include <raw_string.h>
#include <list_test.h>
#include <template_test.h>
int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);

    //raw_string::test(); // 原生字符串测试
    //list_test::test(); // list测试
    template_test::test();
    return a.exec();
}
