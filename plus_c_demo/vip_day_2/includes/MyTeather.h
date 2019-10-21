//
// Created by benjiao on 2019/10/15.
#pragma once//只包含一次 与下面的宏作用一样
//这里宏的作用，防止重复导入
//#ifndef REGISTER_MYTEATHER_H //REGISTER_MYTEATHER_H 可以随便改
//#define REGISTER_MYTEATHER_H

//类的声明 、字段、方法的声明 实现在在.cpp文件中
class MyTeather {
private:
    int m_age;
    char m_name[32];
protected:
public:
    void setAge(int age);
    int getAge();
};

//#endif //REGISTER_MYTEATHER_H
