typedef struct array_util{
  void *base;
  int type_size;
  int length;
}ArrayUtil;

typedef int (MatchFunc)(void* hint, void* item);
typedef void (ConvertFunc)(void* hint, void* sourceItem, void* destinationItem);
typedef void (OperationFunc)(void* hint, void* item);
typedef void* (ReducerFunc)(void* hint, void* previousItem, void* item);

ArrayUtil create (int,int);

int areEqual(ArrayUtil ,ArrayUtil);

ArrayUtil resize(ArrayUtil,int);

int findIndex (ArrayUtil,void*);

void dispose(ArrayUtil);

void* findFirst(ArrayUtil , MatchFunc* , void* );

void* findLast(ArrayUtil , MatchFunc* , void* );

int count(ArrayUtil , MatchFunc* , void* );

int filter(ArrayUtil , MatchFunc* , void* , void** , int);

void map(ArrayUtil , ArrayUtil , ConvertFunc* , void* );

void forEach(ArrayUtil , OperationFunc* , void* );

void *reduce(ArrayUtil , ReducerFunc* , void* , void* );
