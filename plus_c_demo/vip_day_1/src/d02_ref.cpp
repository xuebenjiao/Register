#include <iostream>
using namespace std;
int main1(){
    //TODO 引用的基本类型
    cout << "引用的基本用法" << endl;

    int a = 10;
    //引用的语法  type & name  = var;
    int &b = a;//b就是一个引用,请不要用C的语法去思考
    //就是给a变量取了一个别名
    printf("b:%d\n",b);
    printf("a:%d\n",a);
    b = 100;
    printf("b:%d\n",b);
    printf("a:%d\n",a);
//    int &c;//会报错，普通的引用必须要依附某个变量，必须初始化
    return 0;
}

int myswap(int a ,int b){//值传递
    int tmp   = a;
    a = b;
    b = tmp;

}//完成不了原始数据的交换
int myswap1(int *a,int *b){
    int temp = *a;
    *a = *b;
    *b = temp;
}
int myswap2(int &a ,int &b){
    int tmp   = a;
    a = b;
    b = tmp;

}

int main2(){
    //TODO 基本类型引用
    cout << "基本类型的引用" << endl;

    int x,y;
    x = 10;
    y = 20;
    myswap(x,y);
    printf("x :%d,y:%d\n",x,y);
    myswap1(&x,&y);
    printf("x :%d,y:%d\n",x,y);
    myswap2(x,y);
    printf("x :%d,y:%d\n",x,y);//a就是x的别名，b就是y的别名
    return 0;
}
struct Teacher{
    int age;
    char name[20]  ;
};
void printT1(const Teacher *pt){
    cout << pt->age <<endl;
}
void printT2(Teacher &p){
    cout << p.age <<endl;
    //p是一个别名
    p.age = 33;
}
void printT3(Teacher p){//值传递
    cout << p.age <<endl;
    //p是一个别名
    p.age = 32;
}
int main3(){
    //TODO 复杂类型引用的使用
    cout << "复杂类型引用的使用"<< endl;

    Teacher t1;
    t1.age = 35;
    printT1(&t1);
    printT2(t1);//p是t1的别名，修改p就相当于修改了t1
    printT3(t1);//p是形参，t1 copy一份数据给p
    printf("t1.age ：%d\n",t1.age);
    return 0;
}

void modifyA(int &a){
    //引用
    a = 11;

}
void modifyA1(int * const a){//指针常量
    *a = 12;

}
struct Teacher1{
    char name[64];//64
    int age;//8
    int &a;//8
    int &b;//8
};

int main4(){
    //TODO 引用的本质思考？
    cout << "引用的本质思考" <<endl;
    int a = 10;
    int  &b = a;//b是一个常量
    modifyA(a);//函数调用的时候，我们程序员不需要取a的地址
    //请思考：对同一内存空间，可以取好几个名字吗？
    //引用就是取别名
    //从使用的角度，引用会让人误会其只是一个别名，没有自己的存储空间
    printf("&a:%p,&b:%p\n",&a,&b);

    modifyA1(&a);//指针，我们需要手动取地址

    //引用在C++内部实现，就是一个常量指针


    printf("sizeof(Teacher1):%d\n", sizeof(Teacher1));//88
    return 0;
}