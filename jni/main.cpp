/*
 * Website:
 *      https://github.com/wo3kie/dojo
 *
 * Inspired & followed by:
 *      http://www.codeproject.com/Articles/993067/Calling-Java-from-Cplusplus-with-JNI
 *
 * Author:
 *      Lukasz Czerwinski
 *
 * Compilation:
 *      g++ --std=c++11 main.cpp -o main                        \
 *          -I .../java-7-openjdk-amd64/include                 \
 *          -L .../java-7-openjdk-amd64/jre/lib/amd64/server    \
 *          -ljvm
 *
 * Usage:
 *      $ ./main
 */

#include <iostream>

#include <jni.h>

int main(){
    JavaVM * jvm;
    JNIEnv * env;

    JavaVMOption * options = new JavaVMOption[1];
    options[0].optionString = const_cast< char* >( "-Djava.class.path=." );

    JavaVMInitArgs vmArgs;
    vmArgs.version = JNI_VERSION_1_6;
    vmArgs.nOptions = 1;
    vmArgs.options = options;
    vmArgs.ignoreUnrecognized = false;

    jint rc = JNI_CreateJavaVM( & jvm, (void**)( & env ), & vmArgs );

    if( rc != JNI_OK ){
        std::cerr << "errorCode: " << rc << std::endl;
        return 1;
    }

    {
        jclass cls = env->FindClass( "Main" );

        if( cls == nullptr ){
            std::cerr << "Could not find class 'Main'" << std::endl;
            return 2;
        }

        {
            /*
             * static void
             */

            jmethodID methodId = env->GetStaticMethodID( cls, "function", "()V" );

            if( methodId == nullptr ){
                std::cerr << "Could not find method 'void function()'" << std::endl;
                return 3;
            }

            env->CallStaticVoidMethod( cls, methodId );
        }

        {
            /*
             * static with parameters
            */

            jmethodID methodId = env->GetStaticMethodID( cls, "function2", "(I)I" );

            if( methodId == nullptr ){
                std::cerr << "Could not find method 'int function2(int)'" << std::endl;
                return 4;
            }

            jint result = env->CallStaticIntMethod( cls, methodId, (jint)(5) );

            std::cout << (int)(result) << std::endl;
        }
    }

    jvm->DestroyJavaVM();
    delete options;
}

