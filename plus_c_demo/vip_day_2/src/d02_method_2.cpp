#include <iostream>
using  namespace std;
void myPrint(int x = 1){
    cout << "x is "<< x <<endl;
}
//void myPrint2(int a,int b,int c = 1,int d = 2 ,int e){//��������ôд
void myPrint2(int a,int b,int c = 1,int d = 2){
    cout <<"a:" <<a << "b: "<<b <<" c: "<<c <<" d: "<<d <<endl;
}
//1���������д�˲�����ʹ������д�ģ�����Ĭ��ֵ
//2�� ��Ĭ�ϵĲ��������У����Ĭ�ϲ������֣���ô�ұ߶�������Ĭ�ϲ���
int main21(){
    //TODO ������Ĭ�ϲ���
    cout <<"������Ĭ�ϲ���"<<endl;
    myPrint(4);
    myPrint();
    myPrint2(1,2,3,4);
    myPrint2(5,6);
    myPrint2(7,8,9);

    return 0;
}
//����ռλ����
void myPrint3(int a,int b,int){//ռλ���� ֻ�в������ͣ�û�в�����
    cout <<"a:"<<a <<"b:"<<b<<endl;
}
int main22(){
    //TODO :����ռλ����
    cout<<"����ռλ����"<<endl;
//    myPrint3(1,2)//�����������������ò�����
    myPrint3(1,2,3);
    return 0;
}
//����Ĭ�ϲ�����ռλ�������
void myPrint4(int a,int b ,int =0){
    cout <<"a:" <<a << "b: "<<b <<endl;
}
/**
 * ռλ��������
 * 1��Ϊ�Ժ�ĳ�����������
 * 2������C�����п��ܳ��ֵĲ��淶д��
 * @return
 */
int main23(){
    //TODO ����Ĭ�ϲ�����ռλ�������
    cout <<"����Ĭ�ϲ�����ռλ�������"<<endl;
    myPrint4(1,2);//���Ե���
    myPrint4(1,2,3);
    return 0;
}
