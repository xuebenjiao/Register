#include "jni.h"
void func1(JNIEnv *env ,jobject jobject){
    printf("dynamicNative1 动态注册\n");
}
jstring func2(JNIEnv *env,jobject jobject){
    return (*env)->NewStringUTF(env,"hello everybody ,welcome to dynamic register");
}
jint getRandom(JNIEnv *env,jobject jobject){
    printf("return \n");
    return 100;
}
static const  char * mClassName = "com/demo/jni/DynamicRegister";
static const JNINativeMethod mMethods[] = {
        {"DynamicNative1","()V",(void*)func1},
        {"DynamicNative2","()Ljava/lang/String;",(void*)func2},
        {"getRandom","()I",(void*)getRandom}
};
JNIEXPORT jint JNICALL
JNI_OnLoad(JavaVM *vm,void * reserved){
    printf("hello dynamic native\n");
    JNIEnv * env = NULL;
    //获取JniEnv
    int r = (*vm)->GetEnv(vm,(void**) &env,JNI_VERSION_1_4);
    if(r != JNI_OK){
        return -1;
    }
    printf("hello dynamic native 1\n");
    jclass  mainActivityCls = (*env)->FindClass(env,mClassName);
    //注册，如果小于0则注册失败
    r = (*env)->RegisterNatives(env,mainActivityCls,mMethods,3);//2必须与方法个数一致，否则不会执行以下代码，也不报错
    printf("hello dynamic native 2\n");
    if(r != JNI_OK){
        return -1;
    }
    printf("hello dynamic\n");
    return  JNI_VERSION_1_4;
}

