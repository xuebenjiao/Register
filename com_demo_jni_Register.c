#include "com_demo_jni_Register.h"
#include <string.h>
#include <stdlib.h>
#include <Windows.h>
#include "jni.h"

JNIEXPORT jstring JNICALL Java_com_demo_jni_Register_HelloWorld(JNIEnv * env, jobject jobject){
    return (*env)->NewStringUTF(env,"hello mybaby ,welcom to the world");
}
JNIEXPORT jstring JNICALL Java_com_demo_jni_Register_sayHello(JNIEnv * env, jclass jclaz,jstring jstr){
    const  char * c_str = NULL;
    //在C语言中数组是不能扩容的
    char buf[128] = {0};
    jboolean  iscopy;
    //需要将java的String 转换成C语言的char类型的指针
    c_str = (*env)->GetStringUTFChars(env,jstr,&iscopy);
    //GetStringUTFChars函数从JVM内部获取一个字符串之后，JVM内部会分配一块新的内存，
    //用于存储原字符串的拷贝，以便本地代码访问与修改。既然有内存分配，用完只有马上释放是一个编程
    //好的习惯。通过调用ReleaseStringUTFChars函数通知JVM这块内存已经不使用了，你可以清除了
    //注意 这两个函数是配对使用的，用两个GetXXX就必须调用ReleaseXXX,而且这两个函数的命名也有规律
    //除了前面的Get和Release之外，后面的都一样
    printf("iscopy:%d\n",iscopy);
    if( c_str == NULL){
        return NULL;
    }
    printf("c_str:%s \n",c_str);
    //格式化输出  C语言的拼接
    sprintf(buf,"hello 你好 %s",c_str);
    printf("c_str:%s \n",buf);
    //释放刚创建String的内存空间
    (*env)->ReleaseStringUTFChars(env,jstr,c_str);
    //
    return (*env)->NewStringUTF(env,buf);
    return (*env)->NewStringUTF(env,"hello mybaby ,welcom to the world");
}
JNIEXPORT jstring JNICALL Java_com_demo_jni_Register_sayChineseHello(JNIEnv * env, jclass jclaz,jstring jstr){
    jboolean  iscp ;
    const char * c_str =(*env)->GetStringUTFChars(env,jstr,&iscp);
    if(iscp == JNI_OK){
        printf("is copy :JNI_TRUE\n");
    }
    else {
        printf("is copy :JNI_FALSE\n");
    }
    int length = (*env)->GetStringLength(env,jstr);
    const  jchar *jchar = (*env)->GetStringChars(env,jstr,NULL);

    //jchar --> char
    char * rtn = (char*)malloc(sizeof(char) * 2 * length + 3);
//memset() 的作用是在一段内存块中填充某个给定的值。因为它只能填充一个值，所以该函数的初始化为原始初始化，无法将变量初始化为程序中需要的数据。用memset初始化完后，后面程序中再向该内存空间中存放需要的数据。
    memset(rtn,0, sizeof(char) * 2 * length +3);
    int size = 0;
    //WideCharToMultiByte 该函数映射一个unicode字符串到一个多字节字符串
    size = WideCharToMultiByte(CP_ACP,0,(LPCWSTR)jchar,length,rtn, sizeof(char) * 2 * length +3,NULL,NULL);
    (*env)->ReleaseStringUTFChars(env,jstr,c_str);// JVM 使用。通知JVM c_str 所指的空间可以释放了
    printf("string:%s\n",rtn);
    return (*env)->NewStringUTF(env,rtn);

}
//调用java定义的native方法，修改java对象中的全局变量
JNIEXPORT jstring JNICALL Java_com_demo_jni_Register_testFeild(JNIEnv * env, jobject jobj){

    //FindClass是通过传java中完整的类名来查找java的class，
    //而GetObjectClass是通过传入jni中的一个java的引用来获取该引用的类型。
    //前者要求你必须知道完整的类名，后者要求在Jni有一个类的引用。
    printf("Java_com_demo_jni_Register_testFeild\n");
    jclass  claz = (*env)->GetObjectClass(env,jobj);
    jfieldID  jfieldId = (*env)->GetFieldID(env,claz,"property","I");
    jint  a = (*env)->GetIntField(env,jobj,jfieldId);
    printf("the java object global varible is %d\n",a);
    (*env)->SetIntField(env,jobj,jfieldId,100);//该方法第二个参数是传 jobject 不是jclass
    printf("Java_com_demo_jni_Register_testFeild2\n");

}
//调用java类中定义的native方法，修改java类中的静态变量
JNIEXPORT jstring JNICALL Java_com_demo_jni_Register_testStaticField(JNIEnv * env, jclass jclaz){
//    jclass  jclass1 = jclaz;//这种写法不可行，在java端会报错
    jclass  jclass1 = (*env)->GetObjectClass(env,jclaz);
    jfieldID  field_id = (*env)->GetStaticFieldID(env,jclass1,"stPropery","I");
    jint  a = (*env)->GetStaticIntField(env,jclaz,field_id);
    printf("the java object global varible is %d\n",a);
    (*env)->SetStaticIntField(env,jclaz,field_id,200);////该方法第二个参数是传 jclaz与jclass1都可以

}

//JNI 反射调用java
JNIEXPORT void JNICALL Java_com_demo_jni_Register_callJavaConstructMethod(JNIEnv * env, jobject obj){
    jclass  jcalz = (*env)->FindClass(env,"com/demo/jni/User");
    if(jcalz == NULL){
        printf("jcalz is null\n");
        return ;
    }
    jmethodID  method_id = (*env)->GetMethodID(env,jcalz,"<init>","()V");//调用构造器时，函数名称传递<init>。只有构造器才是如此
    if(method_id == NULL){
        printf("method_id GetMothodId is NULL\n");
        return ;
    }
    jobject  user = (*env)->NewObject(env,jcalz,method_id);//相当于java中的实例化一个对象
}
JNIEXPORT void JNICALL Java_com_demo_jni_Register_callJavaMethod(JNIEnv * env, jobject obj){
    jclass  jclaz = (*env)->FindClass(env,"com/demo/jni/User");
    if(jclaz == NULL){
        printf("jclaz is null\n");
        return ;
    }
    jmethodID  method_id = (*env)->GetMethodID(env,jclaz,"<init>","()V");//调用构造器时，函数名称传递<init>。只有构造器才是如此
    if(method_id == NULL){
        printf("method_id GetMothodId is NULL\n");
        return ;
    }
    jobject  user = (*env)->NewObject(env,jclaz,method_id);//相当于java中的实例化一个对象
    //初始化三个参数
    jstring  name = (*env)->NewStringUTF(env,"jni");
    jstring  phoneNum= (*env)->NewStringUTF(env,"18092425120");
    jmethodID  method_id1 = (*env)->GetMethodID(env,jclaz,"setUser","(Ljava/lang/String;ILjava/lang/String;)V");
    (*env)->CallVoidMethod(env,user,method_id1,name,25,phoneNum);//调用java方法


    (*env)->DeleteLocalRef(env,jclaz);
    (*env)->DeleteLocalRef(env,user);
    (*env)->DeleteLocalRef(env,name);
    (*env)->DeleteLocalRef(env,phoneNum);
/*    (*env)->DeleteLocalRef(env,method_id);
    (*env)->DeleteLocalRef(env,method_id1);*/
}
JNIEXPORT jobject JNICALL Java_com_demo_jni_Register_callJavaObjectMethod(JNIEnv * env, jobject obj){
    jclass claz = (*env)->FindClass(env,"Lcom/demo/jni/User;");
    if(claz  == NULL){
        printf("claz is null\n");
        return NULL;
    }
//    jmethodID  construct_method_id = (*env)->GetMethodID(env,claz,"<init>","()V");//构造方法
    jmethodID  construct_method_id = (*env)->GetMethodID(env,claz,"<init>","(Ljava/lang/String;ILjava/lang/String;)V");//构造方法
    if(construct_method_id == NULL){
        printf("construct_method_id is null\n");
        return NULL;
    }
    jstring name = (*env)->NewStringUTF(env,"中国");
    jstring  phoneNum = (*env)->NewStringUTF(env,"15091456865");
    jobject   user = (*env)->NewObject(env,claz,construct_method_id,name,70,phoneNum);//实例化Java User对象(有参数构造器)
    if(user == NULL){
        printf("initialization user failed \n");
        return NULL;
    }

    jfieldID  name_id = (*env)->GetFieldID(env,claz,"name","Ljava/lang/String;");
    jstring  name_value = (*env)->GetObjectField(env,user,name_id);

    printf("jstring name_value is %s\n",name_value);
    const char * c_str =(*env)->GetStringUTFChars(env,name_value,NULL);
    printf("name_value is %s\n",c_str);

    //java中的字符串编码与JNI中字符串编码不一致，所以需要转换才能显示，否在java调用时，显示的是乱码
  /*  int length = (*env)->GetStringLength(env,name_value);
    const  jchar *jchar = (*env)->GetStringChars(env,name_value,NULL);
    //jchar --> char
    char * rtn = (char*)malloc(sizeof(char) * 2 * length + 3);
     //memset() 的作用是在一段内存块中填充某个给定的值。因为它只能填充一个值，所以该函数的初始化为原始初始化，无法将变量初始化为程序中需要的数据。用memset初始化完后，后面程序中再向该内存空间中存放需要的数据。
    memset(rtn,0, sizeof(char) * 2 * length +3);
    int size = 0;
    //WideCharToMultiByte 该函数映射一个unicode字符串到一个多字节字符串
    size = WideCharToMultiByte(CP_ACP,0,(LPCWSTR)jchar,length,rtn, sizeof(char) * 2 * length +3,NULL,NULL);
    (*env)->ReleaseStringUTFChars(env,name_value,c_str);// JVM 使用。通知JVM c_str 所指的空间可以释放了

    printf("the value of name is %s\n",rtn);
*/







//    jmethodID  method_id = (*env)->GetMethodID(env,claz,"getUser","(Ljava/lang/String;ILjava/lang/String;)Lcom/demo/jni/User;");

//   (*env)->CallObjectMethod(env,user,method_id,name,70,phoneNum);

    (*env)->DeleteLocalRef(env,claz);
//    (*env)->DeleteLocalRef(env,user);//需要返回的对象不能释放，否则java端收到的是地址，不是具体对象
    /*  (*env)->DeleteLocalRef(env,name);
      (*env)->DeleteLocalRef(env,phoneNum);*/
/*    (*env)->DeleteLocalRef(env,method_id);
    (*env)->DeleteLocalRef(env,construct_method_id);*/
    return user;
}
