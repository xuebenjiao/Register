#include <iostream>
using  namespace std;
void myfunc5(int a){
    cout <<"a:"<<a<<endl;

}
void myfunc5(char* a){
    cout <<"a:"<<a<<endl;

}

void myfunc5(int a,int b){
    cout <<"a:"<<a<< "b:"<<b<<endl;
}
void myfunc5(char* a,char* b){
    cout <<"a:"<<a<< "b:"<<b<<endl;
}

typedef  int SIZE_OF;//typedef ���¶���һ�����ͣ����������¶���һ������
//����ָ�� �������﷨
typedef void (myTypeFunc5)(int a,int b);//������һ����������

//����һ������ָ������
typedef void (*myPFunc5)(int a,int b);
//typedef void (*myPFunc5)(char* a,char* b);//��������������
int main41(){
    //TODO ����ָ���뺯������
    cout <<"����ָ���뺯������"<<endl;

    SIZE_OF  a;
/*    myTypeFunc5  *func = NULL;
    func = myfunc5;
    func(1,2);*/
    myPFunc5 func1 = myfunc5;
    myPFunc5  func = NULL;
    func = myfunc5;
    func(1,2);
    return 0;
}