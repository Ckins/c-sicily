#include "md5.h"
#include <string>
#include <iostream>
using namespace std;
 
int main(int argc, char *argv[])
{
    cout << "MD5(\"\") = " << md5("")  << endl;
    cout << "MD5(\"admin\") = " << md5("admin") << endl;
    cout << "MD5(\"123456\") = " << md5("123456") << endl;
    return 0;
    /* 函数输出为：
    MD5("") = d41d8cd98f00b204e9800998ecf8427e
    MD5("admin") = 21232f297a57a5a743894a0e4a801fc3
    MD5("123456") = e10adc3949ba59abbe56e057f20f883e */
}
