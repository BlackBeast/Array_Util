#include <stdlib.h>
#include "array_util.h"

ArrayUtil create(int type_size,int length){
  ArrayUtil arr_util;
  arr_util.base =(void *)malloc(type_size);
  arr_util.length = length;
  arr_util.type_size = type_size;
  return arr_util;
};
