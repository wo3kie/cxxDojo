/*
 * Website:
 *      https://github.com/wo3kie/dojo
 *
 * Inspired by & followed:
 *      http://www.codeproject.com/Articles/993067/Calling-Java-from-Cplusplus-with-JNI
 *
 * Author:
 *      Lukasz Czerwinski
 *
 * Compilation:
 *      g++ --std=c++20 main.cpp -o main                        \
 *          -I .../java-7-openjdk-amd64/include                 \
 *          -L .../java-7-openjdk-amd64/jre/lib/amd64/server    \
 *          -ljvm
 *
 * Usage:
 *      $ ./main
 */

#include <cassert>
#include <iostream>

#include <jni.h>

int main() {
  JavaVM* jvm;
  JNIEnv* env;

  JavaVMOption* options = new JavaVMOption[1];
  options[0].optionString = const_cast<char*>("-Djava.class.path=.");

  JavaVMInitArgs vmArgs;
  vmArgs.version = JNI_VERSION_1_6;
  vmArgs.nOptions = 1;
  vmArgs.options = options;
  vmArgs.ignoreUnrecognized = false;

  jint rc = JNI_CreateJavaVM(&jvm, (void**)(&env), &vmArgs);

  if(rc != JNI_OK) {
    std::cerr << "errorCode: " << rc << std::endl;
    return 1;
  }

  {
    jclass cls = env->FindClass("Main");

    if(cls == nullptr) {
      std::cerr << "Could not find class 'Main'" << std::endl;
      return 2;
    }

    {
      /*
             * static void
             */

      jmethodID methodId = env->GetStaticMethodID(cls, "function", "()V");

      if(methodId == nullptr) {
        std::cerr << "Could not find method 'void function()'" << std::endl;
        return 3;
      }

      env->CallStaticVoidMethod(cls, methodId);
    }

    {
      /*
             * static with parameters and return value
             */

      jmethodID methodId = env->GetStaticMethodID(cls, "function2", "(I)I");

      if(methodId == nullptr) {
        std::cerr << "Could not find method 'int function2(int)'" << std::endl;
        return 4;
      }

      jint result = env->CallStaticIntMethod(cls, methodId, (jint)(5));
      assert((int)(result) == 10);
    }

    {
      /*
             * method
             */

      jmethodID methodId = env->GetMethodID(cls, "<init>", "()V");

      if(methodId == nullptr) {
        std::cerr << "Could not find method '<init>'" << std::endl;
        return 5;
      }

      jobject object = env->NewObject(cls, methodId);

      if(object == nullptr) {
        std::cerr << "Could not construct an object" << std::endl;
        return 6;
      }

      methodId = env->GetMethodID(cls, "getId", "()I");

      if(methodId == nullptr) {
        std::cerr << "Could not find method 'getId'" << std::endl;
        return 7;
      }

      jint result = env->CallIntMethod(object, methodId);
      assert((int)(result) == 14);
    }
  }

  jvm->DestroyJavaVM();
  delete options;
}
