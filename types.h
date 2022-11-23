#pragma once

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

} tail_t;

typedef struct element {

	struct tail tail;
	struct element* next, *prev;

} node_t;

typedef struct list {

	struct element* begin, * end;
	int counter;

} list_t;

void gameOver();
void initmap();
void setcur(int x, int y);
void showMap();
int noblock();
void initSnakeAndTail(snake_t* snake);
void moveSnakeAndTail();
list_t add_begin(list_t list, int x, int y);
list_t add_end(list_t list, int x, int y);
void makenull(list_t* list);
list_t del_end(list_t list);
void print_list(struct element* begin);
void initFood();
void printSnakeAndFood();