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

void* findFirst(ArrayUtil arr, MatchFunc* func, void* hint){
  for (int i = 0; i < arr.length; i++) {
    void *item = arr.base + (i * arr.type_size);
    if(func(hint,item) == 1)
      return item;
  }
  return NULL;
};

void * findLast(ArrayUtil arr, MatchFunc* func, void* hint){
	for(int i=arr.length-1; i>=0; i--){
		void *item = arr.base+(i * arr.type_size);
		if (func(hint, item)==1)
			return item;
	}
	return NULL;
};

int count(ArrayUtil arr, MatchFunc* func, void* hint){
	int count=0;
	for(int i=0; i<arr.length; i++){
		void *item = arr.base+(i * arr.type_size);
		if(func(hint, item))
			count++;
	}
	return count;
};

int filter(ArrayUtil arr, MatchFunc* func, void* hint, void** destination, int maxItems){
  int length = 0;
  for (int i = 0; i < arr.length-1; i++) {
    if(length > maxItems) break;
    void *item = arr.base + (i * arr.type_size);
    if(func(hint,item) == 1){
      destination[length] = item;
      length ++;
    }
  }
  return length;
};



void map(ArrayUtil source, ArrayUtil destination, ConvertFunc* convert, void* hint){
  void *source_base = source.base;
  void *destination_base = destination.base;
  for (size_t i = 0; i < source.length; i++) {
    convert(NULL,source_base,destination_base);
    source_base+=source.type_size;
    destination_base+=source.type_size;
  }
};

void forEach(ArrayUtil arr, OperationFunc* func, void* hint){
  void *base = arr.base;
  for (size_t i = 0; i < arr.length; i++) {
    func(hint,base);
    base+=arr.type_size;
  };
};

void *reduce(ArrayUtil arr, ReducerFunc* reducer, void* hint, void* intialValue){
  void *base = arr.base;
  void *reduced = (void *)calloc(1, arr.length);
	memcpy(reduced, intialValue, arr.length);

	for (int i = 0; i < arr.length; ++i){
		reducer(hint, reduced, base);
		base += arr.type_size;
	}
	return reduced;
};
