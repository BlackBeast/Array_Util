typedef struct array_util{
  void *base;
  int type_size;
  int length;
}ArrayUtil;

ArrayUtil create (int type_size,int length);
int areEqual(ArrayUtil ,ArrayUtil);
