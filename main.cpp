
#include <windows.h>//���ں���SetConsoleOutputCP(65001);����cmd����Ϊutf8
#include <iostream>

using namespace std;//ʹ�������ռ�std��׼�������ռ�
int main1(){
//todo ������̵���Բ���
    //��C++��cout ��C�е�print()һ��
    printf("���!\n");
    cout << "Hello, World!" << endl;//endl��c�е�\n����
    //��Բ�����
    double r = 0;
    double s = 0;
    cout << "������Բ�İ뾶";//��c�е�printf()һ��  >>��<<��C++�����������ƵĲ����������Ǹ�����ǿ
    //c++���� ��C�е�scanfһ��
    cin >> r;
    cout << "r��ֵ�ǣ�" << r << endl;
    s = 3.14 * r * r;
    cout << "Բ������ǣ�" <<  s  <<endl;




    return 0;
}
class MyCicle{
public://�൱����������ı�������public��
    double m_s;//Բ�����
    double m_r;//Բ�İ뾶
public://�ô�����еĶ���public�ķ���
    void setR(double r){//��ĳ�Ա����
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
    //todo �������ķ�ʽ
    //C++�ķ�ʽ��Բ�����
    cout << "C++�ķ�ʽ��Բ�����" << endl;
    MyCicle c1,c2,c3;//���ඨ���������

    double r = 0;
    cout << "������Բ�İ뾶" << endl;//��c�е�printf()һ��  >>��<<��C++�����������ƵĲ����������Ǹ�����ǿ
    cin >> r;//c++���� ��C�е�scanfһ��
    c1.setR(r);
    cout << "Բ������ǣ�" <<  c1.getArea()  << endl;
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
    //todo �����ռ�
    //namespace ָ��ʶ���ĸ��ֿɼ���Χ ���൱��Java�İ���
    cout << "�����ռ�"<< endl;
    cout << "namespaceA :"<< namespaceA:: a <<endl;
    using  namespace namespaceA;
    using namespace namespaceB;
//    cout << "namespaceA:" << a <<endl;
    //��������ռ�ı�����һ�����������д��������֧�֣�ֻ�ܰ��������������д��
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
//C++������bool���� ֻҪ����ֵ��Ҫô��true Ҫô��false
//bool ������ֻռ��һ���ֽ� = 8bit
//������bool�ı���������һ���ʱ�򣬿��ܸ���ռһ��bit(ȡ���ڱ�������ʵ��)
//true ������ֵ���������ڲ���1��ʾ��false��ֵ���������ڲ���0��ʾ
//c++���������ڸ�ֵ��ʱ�򽫷�0ת��λtrue,0ת��Ϊfalse
int main4(){
//TODO bool���� ֻҪ����ֵ��Ҫô��true Ҫô��false
    cout << "bool����" <<endl;
    bool  b1 = true;//c++������
    cout << "sizeof(bool):" << sizeof(bool) << endl;
    b1 = 10;//��ֵ�������Ҫô��1��Ҫô��0
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
int operatorT1(const Teacher *pt){//����ָ�룬��ʾ��һ���������
    cout << pt->age <<endl;
    pt = NULL;

}
/**
 * ʹ��const�ĺô���
 * 1��ָ�뺯����������Ч����ߴ���Ŀɶ��ԣ�����bug
 * 2����������ֲ��������뻹���������
 * const ��define��ͬ�벻��ͬ�ĵط�
 * #define �Ǻ궨�壬���ڱ���Ԥ����׶Σ�ֻ�Ǽ򵥵��ı��滻
 * const ���ʱ���������ģ��ṩ���ͼ�����������
 * @param pt
 * @return
 */

int operatorT2(Teacher *const pt){//ָ�볣�� ��ʾ�������
    pt-> age = 2;

};
// c /c++ const
int main5(){
    //TODO const �Ļ����÷�
    cout << "const�Ļ����÷�" << endl;
    const  int a = 10;
    int const b = 20;//һ����
    const int * c ;//����ָ�� const���ε���ָ����ָ��ı���
    //����ָ����ָ����ڴ�ռ䲻�ܱ��޸�
    c = &a;
    c = &b;
    //*c = 30;//����ָ�벻�����޸�ָ����ָ����ڴ�ռ�
    int a1 = 1;
//    int  * const d  = &a;//���ܸ�ֵ������Ϊ�����ĵ�ַ
    int  * const d  = &a1;//ָ�볣�� ���ε���ָ�뱾��ָ���ܸı�
    const int * const e = &a1; //����ָ�볣�� ָ���ָ�����ڴ�ռ䶼���ܸı�

    return 0;

}
#define   d1 10

void fun1(){
#define  m 20
    const  int n = 20;
#undef a;//ж�أ����ж���������������оͲ���ʹ����
}
void fun2(){
    printf("m = %d",m);
//    printf("n = %d",n);//����������
}

int main(){
    //TODO const  ��#define
    cout << "const ��#define" << endl;
    int a  = 10;
    int b = 10;
//    int array[a +b];//linux�ں˿��ԣ�gcc������֧��
    const int c = 10;
    const int d = 20;
    int array2[c+d];
    int arrary3[c + d1];
}