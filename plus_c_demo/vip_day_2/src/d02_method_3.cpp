#include <iostream>
using namespace std;


void test(int a){
    cout <<"a:"<<a<<endl;

}
void test(char* a){
    cout <<"a:"<<a<<endl;

}
void test(int a,int b){
    cout <<"a:"<<a<< "b:"<<b<<endl;
}
/**
 * ����
 * 1��������
 * 2��������ͬ��1��������2�����ͣ�
 * @return
 */
int main31(){
    //TODO ��������
    cout <<"��������"<<endl;
    test(1);
    test("aaaaaa");
    test(1,2);
    return 0;
}
//�������� ����Ĭ�ϲ��� ��һ��

void test1(int a,int b){
    cout <<"a:"<<a<< "b:"<<b<<endl;
}
void test1(int a,int b,int c = 3){
    cout <<"a:"<<a<< "b:"<<b<< "c:"<<c<<endl;
}
void test1(int a){
    cout <<"a:"<< a <<endl;
}
int main32(){
    //TODO
    cout <<""<<endl;
//    test1(1,2);//��������ʱ������������ԣ�C++����
return 0;
}