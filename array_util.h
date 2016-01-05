typedef struct array_util{
  void *base;
  int type_size;
  int length;
}ArrayUtil;

typedef int (MatchFunc)(void* hint, void* item);

ArrayUtil create (int,int);

int areEqual(ArrayUtil ,ArrayUtil);

ArrayUtil resize(ArrayUtil,int);

int findIndex (ArrayUtil,void*);

void dispose(ArrayUtil);

void* findFirst(ArrayUtil , MatchFunc* , void* );
