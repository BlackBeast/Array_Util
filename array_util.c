#include <stdio.h>
#include <stdlib.h>
#include "array_util.h"

ArrayUtil create(int type_size,int length){
  ArrayUtil arr_util;
  arr_util.base =(void *)calloc(length,type_size);
  arr_util.length = length;
  arr_util.type_size = type_size;
  return arr_util;
};

int areEqual(ArrayUtil arr1,ArrayUtil arr2){
  int size = arr1.length * arr1.type_size;
  char *a;
  char *b;
  if(arr1.length == arr2.length && arr1.type_size == arr2.type_size){
    while(size){
      a = arr1.base;
      b = arr2.base;
      if(*a != *b){
        return 0;
      }
      arr1.base++;
      arr2.base++;
      size--;
    }
    return 1;
  }
  return 0;
};

ArrayUtil resize(ArrayUtil arr,int length){
  realloc(arr.base,(length*arr.type_size));
  arr.length =length;
  return arr;
};

int findIndex(ArrayUtil arr,void* element){
  for (int i = 0; i < arr.length; i++) {
    if(((int *)arr.base)[i]==element)
      return i;
  };
  return -1;
};
