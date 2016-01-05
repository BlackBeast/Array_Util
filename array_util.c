#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "array_util.h"

ArrayUtil create(int type_size,int length){
  ArrayUtil arr_util;
  arr_util.base =(void *)calloc(length,type_size);
  arr_util.length = length;
  arr_util.type_size = type_size;
  return arr_util;
};

int areEqual(ArrayUtil arr1,ArrayUtil arr2){
  if(arr1.length == arr2.length && arr1.type_size == arr2.type_size)
    for (size_t i = 0; i < arr1.length; i++) {
      if(memcmp(arr1.base+(i*arr1.type_size),arr2.base+(i*arr2.type_size),arr1.type_size)!=0)
        return 0;
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
  void *base = arr.base;
  for (int i = 0; i < arr.length; i++) {
    if(memcmp(base+(i*arr.type_size),element,arr.type_size)==0)
      return i;
  };
  return -1;
};

void dispose(ArrayUtil arr){
  free(arr.base);
};

void* findFirst(ArrayUtil util, MatchFunc* match, void* hint){
  for (int i = 0; i < util.length; i++) {
    void *item = util.base + (i * util.type_size);
    if(match(hint,item) == 1)
      return item;
  }
  return NULL;
};
