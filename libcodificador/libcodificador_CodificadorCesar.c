#include <jni.h>
#include <stdlib.h>
#include "libcodificador_CodificadorCesar.h"
/*
 * Class:     libcodificador_CodificadorCesar
 * Method:    codificar
 * Signature: (Ljava/lang/String;I)Ljava/lang/String;
 */
JNIEXPORT jstring JNICALL Java_libcodificador_CodificadorCesar_codificar
  (JNIEnv * env, jobject obj, jstring mensaje, jint clave){
      char* mensajeCodificado;
      const char* str = (*env)->GetStringUTFChars(env, mensaje, NULL);
      jstring responece;
      if(str == NULL){
        return NULL; //OutOfMemoryException
      }
      int strLen = (*env)->GetStringLength(env, mensaje);
      mensajeCodificado = calloc(strLen, sizeof(char));
      for(int i = 0; i < strLen; i++){
	/*
	se resta 32 y luego del cifrado se suman de nuevo para que el valor quede entre 32 a 126
	que son los caracteres imprimibles en codigo ascii
	https://elcodigoascii.com.ar
	*/
        mensajeCodificado[i] = (str[i] - 32 +(int)clave) % 95 + 32;
      }
      responece = (*env)->NewStringUTF(env, mensajeCodificado);
      free(mensajeCodificado);
      return responece;
  }

  /*
 * Class:     libcodificador_CodificadorCesar
 * Method:    decodificar
 * Signature: (Ljava/lang/String;I)Ljava/lang/String;
 */
JNIEXPORT jstring JNICALL Java_libcodificador_CodificadorCesar_decodificar
(JNIEnv * env, jobject obj, jstring mensaje, jint clave){
      char* mensajeDecodificado;
      const char* str = (*env)->GetStringUTFChars(env, mensaje, NULL);
      jstring responece;
      if(str == NULL){
        return NULL;
      }
      int strLen = (*env)->GetStringLength(env, mensaje);
      mensajeDecodificado = calloc(strLen, sizeof(char));
      for(int i = 0; i < strLen; i++){
         /*
         se resta 32 y luego del cifrado se suman de nuevo para que el valor quede entre 32 a 126
         que son los caracteres imprimibles en codigo ascii
         https://elcodigoascii.com.ar
         */
         mensajeCodificado[i] = (str[i] - 32 - (int)clave) % 95 + 32;
      }
      responece = (*env)->NewStringUTF(env, mensajeDecodificado);
      free(mensajeDecodificado);
      return responece;
}

