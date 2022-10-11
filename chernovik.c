#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include <Windows.h>

#define width 25
#define height 15


int i = 1;

int x, y;

char map[height][width+1];

int foodCounter = 0;

char key;

int direction;

int tailpos;

int game = 0;

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

TypeFood food;
TypeSnake snake;
TypeTail tail[100];

void gameOver()
{		
	system("cls");
	game = 1;
	
	printf("GAME OVER\n\n\n\n");
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
		map[height - 1][i] = '#';
}

void showMap() {

	for (int i = 0; i < height; i++) {

		printf("%s\n", map[i]);
	}
}

int noblock() {
	if (_kbhit())
		return _getch();
	else return -1;
}

void moveSnakeAndTail() {
	

		key = noblock();
		
		tail[0].buftailx = snake.head_x;
		tail[0].buftaily = snake.head_y;

		for (int i = 1; i < foodCounter; i++) {
		
			tail[i + 1].buftailx = tail[i].tail_x;
			tail[i + 1].buftaily = tail[i].tail_y;
		}

		if ((key == 'w' || key == 's' || key == 'a' || key == 'd') && (abs(direction - key) > 5))
			direction = key;

		if (direction == 'w')
			snake.head_y--;

		if (direction == 's')
			snake.head_y++;

		if (direction == 'a')
			snake.head_x--;

		if (direction == 'd')
			snake.head_x++;

		if (snake.head_x >= 24)
			snake.head_x = 1;

		if (snake.head_x <= 0)
			snake.head_x = 23;

		if (snake.head_y >= 14)
			snake.head_y = 1;

		if (snake.head_y <= 0)
			snake.head_y = 13;
}

void initSnakeAndTail() {

		snake.head_x = width / 2;
		snake.head_y = height / 2;
}

void putSnake() {

	map[snake.head_y][snake.head_x] = 'S';
}

void initFood() {

	food.pos_x = 5;
	food.pos_y = 5;
}

void putFood() {

	map[food.pos_y][food.pos_x] = '*';

		if ((snake.head_x == food.pos_x) && (snake.head_y == food.pos_y))
		{
			food.pos_x = 1 + rand() % 23;
			food.pos_y = 1 + rand() % 13;
			foodCounter++;
			
		}
		for (int i = 0; i < foodCounter; i++) {

				tail[i + 1].buftailx = tail[i].tail_x;
				tail[i + 1].buftaily = tail[i].tail_y;

				tail[i].tail_x = tail[i].buftailx;
				tail[i].tail_y = tail[i].buftaily;

				map[tail[i].tail_y][tail[i].tail_x] = 's';
		}
		if (map[snake.head_y][snake.head_x] == map[tail[i].tail_y][tail[i].tail_x])
			gameOver();
}

void main()
{
		initSnakeAndTail();
		initFood();
		
		 while (game == 0) {
			system("cls");
			initmap();
			moveSnakeAndTail();
			putFood();
			putSnake();
			showMap();
			Sleep(75);

		 if (GetKeyState(VK_ESCAPE) < 0)
		 {
			 gameOver();
		 }
							}
		return 0;
	}
