#include <iostream>
using namespace std;
//引用的难点
int getA1(){
    int a ;
     a = 10;
     return a;

}
int* getA3(){
    int a ;
    a = 30;
    return &a;
}
int& getA2(){
    int a ;
    a = 20;
    return  a;

}
int main1(){
    int a1 = getA1();
    cout << "a1 is " << a1  << endl;//a1 is 10
    //当我们把栈上的引用 指针 返回出来的时候是有问题的，因为栈的变量，方法调用完之后会被系统自动回收
    int a2 = getA2();
    cout << "a1 is " << a2  << endl;//不会打印出来
    int* a3 = getA3();
    cout << "a3 is " << a3 << endl;//不会打印出来
    return 0;
}
int getG1(){//返回的是数值
    static int a =10;
    a++;
    return a;
}
int& getG2(){//返回的是变量本身
    static int b = 20;
    b ++;
    cout <<"b" <<b <<endl;
    printf("&b:%p\n",&b);
    return b;
}
int main2(){
    //TODO static  返回static
    cout << "static"<< endl;
    int g1 = getG1();
    cout <<"g1:" <<g1 <<endl;


    //返回函数值当左值

    int g2 = getG2();//函数当右值

    printf("&g2:%p\n",&g2);
    cout <<"g2:" <<g2 <<endl;

    getG2() = 200;
    getG2();
    return 0;
}