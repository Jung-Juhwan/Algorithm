typedef enum
{
	false, true
}bool;

typedef struct
{
	char** value;
	int size;
}charArray2D;

typedef struct
{
	char* value;
	int size;
}Slice;

Slice* algorithm(char[], int);
charArray2D* split(char*, int, int);