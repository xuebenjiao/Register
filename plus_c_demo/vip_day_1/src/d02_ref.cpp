#include <iostream>
using namespace std;
int main1(){
    //TODO ���õĻ�������
    cout << "���õĻ����÷�" << endl;

    int a = 10;
    //���õ��﷨  type & name  = var;
    int &b = a;//b����һ������,�벻Ҫ��C���﷨ȥ˼��
    //���Ǹ�a����ȡ��һ������
    printf("b:%d\n",b);
    printf("a:%d\n",a);
    b = 100;
    printf("b:%d\n",b);
    printf("a:%d\n",a);
//    int &c;//�ᱨ����ͨ�����ñ���Ҫ����ĳ�������������ʼ��
    return 0;
}

int myswap(int a ,int b){//ֵ����
    int tmp   = a;
    a = b;
    b = tmp;

}//��ɲ���ԭʼ���ݵĽ���
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
    //TODO ������������
    cout << "�������͵�����" << endl;

    int x,y;
    x = 10;
    y = 20;
    myswap(x,y);
    printf("x :%d,y:%d\n",x,y);
    myswap1(&x,&y);
    printf("x :%d,y:%d\n",x,y);
    myswap2(x,y);
    printf("x :%d,y:%d\n",x,y);//a����x�ı�����b����y�ı���
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
    //p��һ������
    p.age = 33;
}
void printT3(Teacher p){//ֵ����
    cout << p.age <<endl;
    //p��һ������
    p.age = 32;
}
int main3(){
    //TODO �����������õ�ʹ��
    cout << "�����������õ�ʹ��"<< endl;

    Teacher t1;
    t1.age = 35;
    printT1(&t1);
    printT2(t1);//p��t1�ı������޸�p���൱���޸���t1
    printT3(t1);//p���βΣ�t1 copyһ�����ݸ�p
    printf("t1.age ��%d\n",t1.age);
    return 0;
}

void modifyA(int &a){
    //����
    a = 11;

}
void modifyA1(int * const a){//ָ�볣��
    *a = 12;

}
struct Teacher1{
    char name[64];//64
    int age;//8
    int &a;//8
    int &b;//8
};

int main4(){
    //TODO ���õı���˼����
    cout << "���õı���˼��" <<endl;
    int a = 10;
    int  &b = a;//b��һ������
    modifyA(a);//�������õ�ʱ�����ǳ���Ա����Ҫȡa�ĵ�ַ
    //��˼������ͬһ�ڴ�ռ䣬����ȡ�ü���������
    //���þ���ȡ����
    //��ʹ�õĽǶȣ����û����������ֻ��һ��������û���Լ��Ĵ洢�ռ�
    printf("&a:%p,&b:%p\n",&a,&b);

    modifyA1(&a);//ָ�룬������Ҫ�ֶ�ȡ��ַ

    //������C++�ڲ�ʵ�֣�����һ������ָ��


    printf("sizeof(Teacher1):%d\n", sizeof(Teacher1));//88
    return 0;
}