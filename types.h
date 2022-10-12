#ifndef types_h
#define types_h

typedef struct
{
	int pos_x, pos_y;

} TypeFood;

typedef struct
{
	int head_x, head_y;

} TypeSnake;

typedef struct
{
	int tail_x, tail_y;
	int buftailx, buftaily;

} TypeTail;

#endif