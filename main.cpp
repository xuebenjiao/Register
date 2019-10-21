
#include <windows.h>//用于函数SetConsoleOutputCP(65001);更改cmd编码为utf8
#include <iostream>

using namespace std;//使用命名空间std标准的命名空间
int main1(){
//todo 面向过程的求圆面积
    //在C++中cout 与C中的print()一样
    printf("你好!\n");
    cout << "Hello, World!" << endl;//endl与c中的\n类似
    //求圆的面积
    double r = 0;
    double s = 0;
    cout << "请输入圆的半径";//与c中的printf()一样  >>与<<在C++不是左移右移的操作符，而是改造增强
    //c++输入 与C中的scanf一样
    cin >> r;
    cout << "r的值是：" << r << endl;
    s = 3.14 * r * r;
    cout << "圆的面积是：" <<  s  <<endl;




    return 0;
}
class MyCicle{
public://相当于这代码块里的变量都是public的
    double m_s;//圆的面积
    double m_r;//圆的半径
public://该代码块中的都是public的方法
    void setR(double r){//类的成员函数
        m_r = r;
    }
    double  getR(){
        return m_r;
    }
    double  getArea(){
        m_s = 3.14 * m_r * m_r;
        return m_s;
    }
};
int main02(){
    //todo 面向对象的方式
    //C++的方式求圆的面积
    cout << "C++的方式求圆的面积" << endl;
    MyCicle c1,c2,c3;//用类定义变量对象

    double r = 0;
    cout << "请输入圆的半径" << endl;//与c中的printf()一样  >>与<<在C++不是左移右移的操作符，而是改造增强
    cin >> r;//c++输入 与C中的scanf一样
    c1.setR(r);
    cout << "圆的面积是：" <<  c1.getArea()  << endl;
    return 0;
}
namespace  namespaceA{
    int a = 10;
}
namespace  namespaceB{
    int a = 20;
    namespace  namespaceC{
        struct  Teacher{
            char name[20];
            int age;
        };
    }
}
int main3(){
    //todo 命名空间
    //namespace 指标识符的各种可见范围 （相当于Java的包）
    cout << "命名空间"<< endl;
    cout << "namespaceA :"<< namespaceA:: a <<endl;
    using  namespace namespaceA;
    using namespace namespaceB;
//    cout << "namespaceA:" << a <<endl;
    //如果命名空间的变量名一样，则上面的写法将不再支持，只能按照下面的下述的写法
    cout << "namespaceA :" << namespaceA::a <<endl;
    cout << "namespaceB :" << namespaceB::a <<endl;

    namespaceB::namespaceC::Teacher t1;
    t1.age = 25;
    using namespace namespaceC;
    Teacher t2 ;
    t2.age = 35;
    cout << "t1.age  is :" << t1.age  << endl;
    cout << "t2.age is :" << t2.age << endl;
}
//C++新增了bool类型 只要两个值，要么是true 要么是false
//bool 理论上只占用一个字节 = 8bit
//如果多个bool的变量定义在一起的时候，可能各自占一个bit(取决于编译器的实现)
//true 代表真值，编译器内部用1表示，false假值，编译器内部用0表示
//c++编译器会在赋值的时候将非0转换位true,0转化为false
int main4(){
//TODO bool类型 只要两个值，要么是true 要么是false
    cout << "bool类型" <<endl;
    bool  b1 = true;//c++编译器
    cout << "sizeof(bool):" << sizeof(bool) << endl;
    b1 = 10;//赋值后输出是要么是1，要么是0
    cout << "b1:" << b1 <<endl;//1
    b1 = -1;
    cout << "b1:" << b1 <<endl;//1
    b1 = 0;
    cout << "b1:" << b1 <<endl;//0

}

struct  Teacher{
    char name[20];
    int age;

};
int operatorT1(const Teacher *pt){//常量指针，表示是一种输入参数
    cout << pt->age <<endl;
    pt = NULL;

}
/**
 * 使用const的好处，
 * 1、指针函数，可以有效的提高代码的可读性，减少bug
 * 2、清楚的区分参数是输入还是输出特性
 * const 与define相同与不相同的地方
 * #define 是宏定义，是在编译预处理阶段，只是简单的文本替换
 * const 是邮编译器处理的，提供类型检查和作用域检查
 * @param pt
 * @return
 */

int operatorT2(Teacher *const pt){//指针常量 表示输出参数
    pt-> age = 2;

};
// c /c++ const
int main5(){
    //TODO const 的基本用法
    cout << "const的基本用法" << endl;
    const  int a = 10;
    int const b = 20;//一样的
    const int * c ;//常量指针 const修饰的是指针所指向的变量
    //代表指针所指向的内存空间不能被修改
    c = &a;
    c = &b;
    //*c = 30;//常量指针不允许修改指针所指向的内存空间
    int a1 = 1;
//    int  * const d  = &a;//不能赋值被定义为常量的地址
    int  * const d  = &a1;//指针常量 修饰的是指针本身，指向不能改变
    const int * const e = &a1; //常量指针常量 指针的指向与内存空间都不能改变

    return 0;

}
#define   d1 10

void fun1(){
#define  m 20
    const  int n = 20;
#undef a;//卸载，如果卸载了在其他方法中就不能使用了
}
void fun2(){
    printf("m = %d",m);
//    printf("n = %d",n);//这样不允许
}

int main(){
    //TODO const  和#define
    cout << "const 和#define" << endl;
    int a  = 10;
    int b = 10;
//    int array[a +b];//linux内核可以，gcc编译器支持
    const int c = 10;
    const int d = 20;
    int array2[c+d];
    int arrary3[c + d1];
}