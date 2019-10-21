
#include <iostream>
#include <string.h>
using namespace std;//使用命名空间 std标准的命名空间
/**
 * 构造函数
 * 1、没有返回值
 * 2、函数名称和类名相同 ClassName(){}
 * 析构函数
 * 1、没有返回值
 * 2、函数名称和类名相同 ~ClassName(){}
 */
class Test{
public:
    Test(){//构造函数 初始化工作
        a = 10;
        p = (char*) malloc(100);//给p变量在堆区分配了一块内存  只有malloc 与cllloc可以在堆上分配内存，其他都是在栈上
        strcpy(p,"sdkfsdfgsg");
        cout <<"构造函数"<<endl;
    }
    ~Test(){//析构函数 释放资源的工作（与Java中的finalize()方法的类似）
        //析构函数是当我们的对象被销毁之前，由编译器主动去调用的
        if(p != NULL){
            free(p);//malloc开辟的内存，就用free释放
            p = NULL;
        }
        cout <<"析构函数"<<endl;
    }
    void print(){
        cout << "a : "<<a << " p: " << p <<endl;
    }
    int i;
    void testc(){
    }
protected:
    int j;
    void testb(){
    }
private://
    int a ;//类的成员变量
    char *p;//
    void testa(){
    }
};
void ojbTest(){
    Test t1;//会自动调用构造函数
    t1.print();
}
int  main1(){
    //TODO C++类与对象
    cout << "C++类与对象"<<endl;
    ojbTest();
    return 0;
}
/**
 * 构造函数分类
 */
class Test2{
public:

    void init(int a,int b){
        m_a = a;
        m_b = b;
        cout <<"调用方法初始化参数"<<m_a<<"  "<<m_b<<endl;
    }
    Test2(){//无参构造函数
        m_a = 0;
        m_b= 0;
        cout <<"无参构造函数"<<m_a<<"  "<<m_b<<endl;
    }
    Test2(int a){//有参数的构造函数
        m_a = a;
        m_b = 0;
        cout <<"有参构造函数"<<m_a<<"  "<<m_b<<endl;
    }
    Test2(int a,int b){//有参数的构造函数
        m_a = a;
        m_b = b;
        cout <<"有参构造函数"<<m_a<<"  "<<m_b<<endl;
    }
    Test2(const Test2& obj){//拷贝构造函数 类似于Java中的clone()方法
        m_a  = obj.m_a;
        m_b  = obj.m_b;
        cout <<"拷贝构造函数"<<m_a<<"  "<<m_b<<endl;
    }
    ~Test2(){
        cout <<"析构函数"<<m_a <<" "<< m_b<<endl;
    }
    void print(){
        cout <<"print "<<m_a<<"  "<<m_b<<endl;
    }
    int getA(){
        return m_a;
    }
private:
    int m_a;
    int m_b;
};
void objTest1(){
    Test2 t1;
}
//有参构造函数调用
void objTest2() {
    //1、括号法调用构造函数
    Test2 t1(1);//调用一个参数的构造函数 C++编译器自动的调用对应的构造函数
    Test2 t2(2, 3);//调用两个参数的构造函数

    //2、=等号法
    Test2 t3 = (4, 5);//=为C++对"="功能增强 ，调用了构造函数 调用的一个参数的构造函数，只有最后一个逗号后面的参数有作用
    Test2 t4 = (4, 5, 6, 7, 8);//=为C++对"="功能增强 ，调用了构造函数 调用的一个参数的构造函数，只有最后一个逗号后面的参数有作用
    Test2 t5 = 9;//这里是不是把9赋值给T5;不是的，这里调用了Test2一个参数的构造方法

    //3、直接调用构造函数，是手动调用的构造函数，上述1、2都是C++编译器自动调用的构造函数
    Test2 t6 = Test2(10, 11);
    t1 = t6;//把t6 copy给t1  是赋值操作 不是调用构造方法

    Test2 t7 = t6;//调用的是拷贝构造函数 因为C/C++定义变量时需要初始化话，所以该=号是对象初始化，不是赋值

    Test2 t8(t6);
    //对象的初始化和对象的赋值 是两个不同的概念
    // 判断初始化与赋值的依据：看当前变量是否已经声明，如果已经声明了，则=号是赋值语句，如果声明则是初始化
}
void objTest3(){
    Test2 t1;
    t1.init(2,3);
    Test2 tArr[3];//之所以需要构造器初始化操作，就是为了方便代码编写，避免出现如下方式进行参数初始化
    tArr[0].init(1,2);
    tArr[0].init(1,2);
    tArr[0].init(1,2);
}

//拷贝构造函数的调用时机
//3、用实参去初始化一个函数的形参的时候会调用拷贝构造函数
void copyTest(Test2 t){
    cout <<t.getA()<<endl;
}
void objTest4(){
    Test2 t1(1,2);
    Test2 t2 = t1;//1、调动拷贝构造函数
    Test2 t3(t2);//2() 调动拷贝构造函数
    t2.print();
    cout << "t2初始化完毕" <<endl;
    copyTest(t2);//当我们用t2实参初始化形参t的时候会自动调用拷贝构造函数
}

//4.
Test2 getTest2(){
    Test2 t(4,5);
    return t;
}

void objTest5(){
//    getTest2();//没有调用拷贝构造函数
    Test2 t1 = getTest2();//初始化t1，创建一个匿名对象（扶正）从匿名转成了有名字了，
    cout << "getTest2调用完毕"<<endl;
    t1.print();

}
void objTest6(){
//    getTest2();//没有调用拷贝构造函数
    Test2 t1(1,2);//t1已经初始化了，
    t1 = getTest2();//赋值
    cout << "getTest2调用完毕"<<endl;
    t1.print();

}
int main2(){
    //TODO ：构造函数分类
    cout <<"构造函数分类"<<endl;
//    objTest1();//调用无参构造函数
//    objTest2();
//    objTest3();
//    objTest4();
    objTest5();
    cout <<"======================"<<endl;
    objTest6();
    return 0;
}


class Test3{
public:
    Test3(){//构造函数 初始化工作
        a = 10;
        p = (char*) malloc(100);//给p变量在堆区分配了一块内存  只有malloc 与cllloc可以在堆上分配内存，其他都是在栈上
        strcpy(p,"sdkfsdfgsg");
        cout <<"构造函数"<<endl;
    }
    Test3(const char *arg){
        a = 20;
        p = (char*) malloc(100);//给p变量在堆区分配了一块内存  只有malloc 与cllloc可以在堆上分配内存，其他都是在栈上
        strcpy(p,arg);
        cout <<"构造函数"<<endl;

    }
    Test3(const Test3& t){
        a = t.a;
        p = (char *)malloc(100);
        strcpy(p,t.p);

}
    ~Test3(){//析构函数 释放资源的工作（与Java中的finalize()方法的类似）
        //析构函数是当我们的对象被销毁之前，由编译器主动去调用的
        if(p != NULL){
            free(p);//malloc开辟的内存，就用free释放
//            p = NULL;
        }
        cout <<"析构函数"<<endl;
    }
    void print(){
        cout << "a : "<<a << " p: " << p <<endl;
    }
    int i;

protected:
    int j;

private://
    int a ;//类的成员变量
    char *p;//

};
void objTest7(){
    Test3 t1("Test3 const");
    Test3 t2 = t1;
    cout <<"objTest7调动"<<endl;
}

int main(){
//TODO 浅拷贝深拷贝
    cout <<"浅拷贝深拷贝"<<endl;

    objTest7();
    cout <<"main 调动"<<endl;

    return 0;
}