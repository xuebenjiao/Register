#include <iostream>
using namespace std;
//���õ��ѵ�
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
    //�����ǰ�ջ�ϵ����� ָ�� ���س�����ʱ����������ģ���Ϊջ�ı���������������֮��ᱻϵͳ�Զ�����
    int a2 = getA2();
    cout << "a1 is " << a2  << endl;//�����ӡ����
    int* a3 = getA3();
    cout << "a3 is " << a3 << endl;//�����ӡ����
    return 0;
}
int getG1(){//���ص�����ֵ
    static int a =10;
    a++;
    return a;
}
int& getG2(){//���ص��Ǳ�������
    static int b = 20;
    b ++;
    cout <<"b" <<b <<endl;
    printf("&b:%p\n",&b);
    return b;
}
int main2(){
    //TODO static  ����static
    cout << "static"<< endl;
    int g1 = getG1();
    cout <<"g1:" <<g1 <<endl;


    //���غ���ֵ����ֵ

    int g2 = getG2();//��������ֵ

    printf("&g2:%p\n",&g2);
    cout <<"g2:" <<g2 <<endl;

    getG2() = 200;
    getG2();
    return 0;
}