#ifndef types_h
#define types_h

typedef struct
{
	int pos_x, pos_y;

} TypeFood;

typedef struct 
{
	int pos_x, pos_y;
	int buftailx, buftaily;
	
} snake_t;

typedef struct tail
{
	int tail_x, tail_y;
	//int buftailx, buftaily;

} tail_t;

typedef struct element {
	
	struct tail tail;
	struct element* next;
} node;

#endif
