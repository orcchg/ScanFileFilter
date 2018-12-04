#include "log_reader.h"

JNIEXPORT jboolean JNICALL Java_com_orcchg_scanfilefilter_LogReader_setFilter
        (JNIEnv* jenv, jobject obj, jstring Filter) {

    return true;
}

JNIEXPORT jboolean JNICALL Java_com_orcchg_scanfilefilter_LogReader_addSourceBlock
        (JNIEnv* jenv, jobject obj, jstring Block) {

    return true;
}
