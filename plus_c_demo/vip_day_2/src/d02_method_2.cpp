#include <iostream>
using  namespace std;
void myPrint(int x = 1){
    cout << "x is "<< x <<endl;
}
//void myPrint2(int a,int b,int c = 1,int d = 2 ,int e){//不可以这么写
void myPrint2(int a,int b,int c = 1,int d = 2){
    cout <<"a:" <<a << "b: "<<b <<" c: "<<c <<" d: "<<d <<endl;
}
//1、如果你填写了参数，使用你填写的，不用默认值
//2、 在默认的参数规则中，如果默认参数出现，那么右边都必须有默认参数
int main21(){
    //TODO 函数的默认参数
    cout <<"函数的默认参数"<<endl;
    myPrint(4);
    myPrint();
    myPrint2(1,2,3,4);
    myPrint2(5,6);
    myPrint2(7,8,9);

    return 0;
}
//函数占位参数
void myPrint3(int a,int b,int){//占位参数 只有参数类型，没有参数名
    cout <<"a:"<<a <<"b:"<<b<<endl;
}
int main22(){
    //TODO :函数占位参数
    cout<<"函数占位参数"<<endl;
//    myPrint3(1,2)//报错，传两个参数调用不起来
    myPrint3(1,2,3);
    return 0;
}
//函数默认参数和占位参数结合
void myPrint4(int a,int b ,int =0){
    cout <<"a:" <<a << "b: "<<b <<endl;
}
/**
 * 占位参数意义
 * 1、为以后的程序留下线索
 * 2、兼容C语言中可能出现的不规范写法
 * @return
 */
int main23(){
    //TODO 函数默认参数和占位参数结合
    cout <<"函数默认参数和占位参数结合"<<endl;
    myPrint4(1,2);//可以调用
    myPrint4(1,2,3);
    return 0;
}
