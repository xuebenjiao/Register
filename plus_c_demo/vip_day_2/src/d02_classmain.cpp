#include <iostream>
#include "../includes/MyTeather.h"
using namespace std;
// :: �������޶������
int  a;
int main(){
    //TODO �������
    cout <<"�������"<<endl;
    MyTeather t1;
    t1.setAge(33);
    float a;
    a = 3.14;
    ::a = 5;//ʵ���ھֲ�����a��������Χ�ڶ�ȫ�ֱ���a�ķ���
    cout <<"t1.age:" <<t1.getAge()<<endl;
    cout <<"local a: "<<a <<" global a:" <<::a<<endl;
    return 0;
}