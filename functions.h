#include <stdio.h>
#include <Windows.h>
#include <conio.h>
#include <malloc.h>
#include "types.h"



#define width 25
#define height 16

TypeFood food;
snake_t snake;

tail_t tail;

//buftailx buftailxx = 0;
//buftaily buftailyy = 0;

struct element* begin;

char map[height][width + 1];

int foodCounter = 0;

char key;

int direction;

int game = 0;

void gameOver()
{
	system("cls");
	game = 1;

	printf("       GAME OVER\n\n\n\n");
}

void initmap() {

	for (int i = 0; i < width; i++)
	{
		map[0][i] = '#';
		map[0][width] = '\0';
	}
	strncpy(map[1], map[0], width + 1);

	for (int i = 1; i < width - 1; i++)
	{
		map[1][i] = ' ';
	}
	for (int i = 1; i < height - 1; i++)
	{
		strncpy(map[i], map[1], width + 1);
	}
	for (int i = 0; i < width; i++)
		map[height - 2][i] = '#';
}

void setcur(int x, int y) {

	COORD coord;
	coord.X = x;
	coord.Y = y;
	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), coord);
}

void showMap() {

	for (int i = 0; i < height - 1; i++) {

		printf("%s\n", map[i]);
	}
}

int noblock() {
	if (_kbhit())
		return _getch();
	else return -1;
}

void initSnakeAndTail(snake_t * snake) {

	snake->pos_x = width / 2;
	snake->pos_y = height / 2;
}

void moveSnakeAndTail() {

	key = noblock();

	snake.buftailx = snake.pos_x;
	snake.buftaily = snake.pos_y;

	if ((key == 'w' || key == 's' || key == 'a' || key == 'd') && (abs(direction - key) > 5))
		direction = key;

	if (direction == 'w')
		snake.pos_y--;

	if (direction == 's')
		snake.pos_y++;

	if (direction == 'a')
		snake.pos_x--;

	if (direction == 'd')
		snake.pos_x++;

	if (snake.pos_x >= 24)
		snake.pos_x = 1;

	if (snake.pos_x <= 0)
		snake.pos_x = 23;

	if (snake.pos_y >= 14)
		snake.pos_y = 1;

	if (snake.pos_y <= 0)
		snake.pos_y = 13;

	//return buftailxx, buftailyy;
}



node* add_begin(node* begin, int x, int y)
{
	struct element* temp;
	temp = (struct element*)malloc(sizeof(struct element));
	temp->tail.tail_y = y;
	temp->tail.tail_x = x;
	temp->next = begin;
	return temp;

}

void print_list(struct element* begin)
{
	if (!begin)
	{
		printf("Empty\n");
		return;
	}
	while (begin)
	{
		map[tail.tail_y][tail.tail_x] = 's';
		//print(begin->tail);
		begin = begin->next;
	}
}

void putSnake() {

	map[snake.pos_y][snake.pos_x] = 'S';
}

void initFood() {

	food.pos_x = 5;
	food.pos_y = 5;
}

void printSnakeAndFood() {

	map[food.pos_y][food.pos_x] = '*'; 

	if ((snake.pos_x == food.pos_x) && (snake.pos_y == food.pos_y))
	{
		food.pos_x = 1 + rand() % 23;
		food.pos_y = 1 + rand() % 13;
		foodCounter++;

	}
	for (int i = 0; i < foodCounter; i++)
		
	{
		begin = add_begin(begin, snake.buftailx, snake.buftaily);
		print_list(begin);
	}


	if (map[snake.pos_y][snake.pos_x] == map[tail.tail_y][tail.tail_x])
		gameOver();
}
