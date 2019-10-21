#include <iostream>
#include "../includes/MyTeather.h"
using namespace std;
// :: 作用域限定运算符
int  a;
int main(){
    //TODO 面向对象
    cout <<"面向对象"<<endl;
    MyTeather t1;
    t1.setAge(33);
    float a;
    a = 3.14;
    ::a = 5;//实现在局部变量a的作用域范围内对全局变量a的访问
    cout <<"t1.age:" <<t1.getAge()<<endl;
    cout <<"local a: "<<a <<" global a:" <<::a<<endl;
    return 0;
}