#include "demo_Register.h"
JNIEXPORT jstring JNICALL Java_demo_Register_HelloWorld(JNIEnv * env,jobject jobject){
    return  (*env)->NewStringUTF(env,"hello everybody");
//    return (*env) -> NewStringUTF(env,"hello world");
}