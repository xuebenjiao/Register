
#include <iostream>
#include <string.h>
using namespace std;//ʹ�������ռ� std��׼�������ռ�
/**
 * ���캯��
 * 1��û�з���ֵ
 * 2���������ƺ�������ͬ ClassName(){}
 * ��������
 * 1��û�з���ֵ
 * 2���������ƺ�������ͬ ~ClassName(){}
 */
class Test{
public:
    Test(){//���캯�� ��ʼ������
        a = 10;
        p = (char*) malloc(100);//��p�����ڶ���������һ���ڴ�  ֻ��malloc ��cllloc�����ڶ��Ϸ����ڴ棬����������ջ��
        strcpy(p,"sdkfsdfgsg");
        cout <<"���캯��"<<endl;
    }
    ~Test(){//�������� �ͷ���Դ�Ĺ�������Java�е�finalize()���������ƣ�
        //���������ǵ����ǵĶ�������֮ǰ���ɱ���������ȥ���õ�
        if(p != NULL){
            free(p);//malloc���ٵ��ڴ棬����free�ͷ�
            p = NULL;
        }
        cout <<"��������"<<endl;
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
    int a ;//��ĳ�Ա����
    char *p;//
    void testa(){
    }
};
void ojbTest(){
    Test t1;//���Զ����ù��캯��
    t1.print();
}
int  main1(){
    //TODO C++�������
    cout << "C++�������"<<endl;
    ojbTest();
    return 0;
}
/**
 * ���캯������
 */
class Test2{
public:

    void init(int a,int b){
        m_a = a;
        m_b = b;
        cout <<"���÷�����ʼ������"<<m_a<<"  "<<m_b<<endl;
    }
    Test2(){//�޲ι��캯��
        m_a = 0;
        m_b= 0;
        cout <<"�޲ι��캯��"<<m_a<<"  "<<m_b<<endl;
    }
    Test2(int a){//�в����Ĺ��캯��
        m_a = a;
        m_b = 0;
        cout <<"�вι��캯��"<<m_a<<"  "<<m_b<<endl;
    }
    Test2(int a,int b){//�в����Ĺ��캯��
        m_a = a;
        m_b = b;
        cout <<"�вι��캯��"<<m_a<<"  "<<m_b<<endl;
    }
    Test2(const Test2& obj){//�������캯�� ������Java�е�clone()����
        m_a  = obj.m_a;
        m_b  = obj.m_b;
        cout <<"�������캯��"<<m_a<<"  "<<m_b<<endl;
    }
    ~Test2(){
        cout <<"��������"<<m_a <<" "<< m_b<<endl;
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
//�вι��캯������
void objTest2() {
    //1�����ŷ����ù��캯��
    Test2 t1(1);//����һ�������Ĺ��캯�� C++�������Զ��ĵ��ö�Ӧ�Ĺ��캯��
    Test2 t2(2, 3);//�������������Ĺ��캯��

    //2��=�Ⱥŷ�
    Test2 t3 = (4, 5);//=ΪC++��"="������ǿ �������˹��캯�� ���õ�һ�������Ĺ��캯����ֻ�����һ�����ź���Ĳ���������
    Test2 t4 = (4, 5, 6, 7, 8);//=ΪC++��"="������ǿ �������˹��캯�� ���õ�һ�������Ĺ��캯����ֻ�����һ�����ź���Ĳ���������
    Test2 t5 = 9;//�����ǲ��ǰ�9��ֵ��T5;���ǵģ����������Test2һ�������Ĺ��췽��

    //3��ֱ�ӵ��ù��캯�������ֶ����õĹ��캯��������1��2����C++�������Զ����õĹ��캯��
    Test2 t6 = Test2(10, 11);
    t1 = t6;//��t6 copy��t1  �Ǹ�ֵ���� ���ǵ��ù��췽��

    Test2 t7 = t6;//���õ��ǿ������캯�� ��ΪC/C++�������ʱ��Ҫ��ʼ���������Ը�=���Ƕ����ʼ�������Ǹ�ֵ

    Test2 t8(t6);
    //����ĳ�ʼ���Ͷ���ĸ�ֵ ��������ͬ�ĸ���
    // �жϳ�ʼ���븳ֵ�����ݣ�����ǰ�����Ƿ��Ѿ�����������Ѿ������ˣ���=���Ǹ�ֵ��䣬����������ǳ�ʼ��
}
void objTest3(){
    Test2 t1;
    t1.init(2,3);
    Test2 tArr[3];//֮������Ҫ��������ʼ������������Ϊ�˷�������д������������·�ʽ���в�����ʼ��
    tArr[0].init(1,2);
    tArr[0].init(1,2);
    tArr[0].init(1,2);
}

//�������캯���ĵ���ʱ��
//3����ʵ��ȥ��ʼ��һ���������βε�ʱ�����ÿ������캯��
void copyTest(Test2 t){
    cout <<t.getA()<<endl;
}
void objTest4(){
    Test2 t1(1,2);
    Test2 t2 = t1;//1�������������캯��
    Test2 t3(t2);//2() �����������캯��
    t2.print();
    cout << "t2��ʼ�����" <<endl;
    copyTest(t2);//��������t2ʵ�γ�ʼ���β�t��ʱ����Զ����ÿ������캯��
}

//4.
Test2 getTest2(){
    Test2 t(4,5);
    return t;
}

void objTest5(){
//    getTest2();//û�е��ÿ������캯��
    Test2 t1 = getTest2();//��ʼ��t1������һ���������󣨷�����������ת�����������ˣ�
    cout << "getTest2�������"<<endl;
    t1.print();

}
void objTest6(){
//    getTest2();//û�е��ÿ������캯��
    Test2 t1(1,2);//t1�Ѿ���ʼ���ˣ�
    t1 = getTest2();//��ֵ
    cout << "getTest2�������"<<endl;
    t1.print();

}
int main2(){
    //TODO �����캯������
    cout <<"���캯������"<<endl;
//    objTest1();//�����޲ι��캯��
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
    Test3(){//���캯�� ��ʼ������
        a = 10;
        p = (char*) malloc(100);//��p�����ڶ���������һ���ڴ�  ֻ��malloc ��cllloc�����ڶ��Ϸ����ڴ棬����������ջ��
        strcpy(p,"sdkfsdfgsg");
        cout <<"���캯��"<<endl;
    }
    Test3(const char *arg){
        a = 20;
        p = (char*) malloc(100);//��p�����ڶ���������һ���ڴ�  ֻ��malloc ��cllloc�����ڶ��Ϸ����ڴ棬����������ջ��
        strcpy(p,arg);
        cout <<"���캯��"<<endl;

    }
    Test3(const Test3& t){
        a = t.a;
        p = (char *)malloc(100);
        strcpy(p,t.p);

}
    ~Test3(){//�������� �ͷ���Դ�Ĺ�������Java�е�finalize()���������ƣ�
        //���������ǵ����ǵĶ�������֮ǰ���ɱ���������ȥ���õ�
        if(p != NULL){
            free(p);//malloc���ٵ��ڴ棬����free�ͷ�
//            p = NULL;
        }
        cout <<"��������"<<endl;
    }
    void print(){
        cout << "a : "<<a << " p: " << p <<endl;
    }
    int i;

protected:
    int j;

private://
    int a ;//��ĳ�Ա����
    char *p;//

};
void objTest7(){
    Test3 t1("Test3 const");
    Test3 t2 = t1;
    cout <<"objTest7����"<<endl;
}

int main(){
//TODO ǳ�������
    cout <<"ǳ�������"<<endl;

    objTest7();
    cout <<"main ����"<<endl;

    return 0;
}