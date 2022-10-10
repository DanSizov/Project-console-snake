#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include <Windows.h>

#define width 25
#define height 15


char map[height][width+1];
int bufx, bufy;
int buftailx, buftaily;
int foodCounter = 0;
int foodCounterBuf = 0;
char key;
int direction;

typedef struct
{
	int pos_x, pos_y;

} TypeFood;

typedef struct
{
	int head_x, head_y, head_w;
	
} TypeSnake;

TypeSnake snake;

typedef struct
{
	int tail_x, tail_y, tail_w;
	

} TypeTail;


TypeFood food;
TypeTail tail;

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
	bufx = snake.head_x;
	bufy = snake.head_y;

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

	tail.tail_x = bufx;
	tail.tail_y = bufy;

	buftailx = tail.tail_x;
	buftaily = tail.tail_y;

}

void initSnakeAndTail() {

		snake.head_x = width / 2;
		snake.head_y = height / 2;
		snake.head_w = 1;
		tail.tail_x = snake.head_x;
		tail.tail_y = snake.head_y;
		tail.tail_w = 1;
	
}

void putSnake() {

	map[snake.head_y][snake.head_x] = 'S';

}

void growTail() {

	if (foodCounter == 1) {
		map[tail.tail_y][tail.tail_x] = 's';

		tail.tail_x = snake.head_x;
		tail.tail_y = snake.head_y;
		tail.tail_w = 1;
	};
	if (foodCounter >= 2) {
		TypeTail tailg;

		map[buftaily][buftailx] = 's';
		tailg.tail_x = buftailx;
		tailg.tail_y = buftaily;
		tailg.tail_w = 1;
		

		

	}
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
		};	
		growTail();
}


void main()
{
		initSnakeAndTail();
		initFood();
		
		do {
		system("cls");
		initmap();
		moveSnakeAndTail();
		putFood();

		putSnake();;
		showMap();
		
		Sleep(75);
			}
		while (GetKeyState(VK_ESCAPE) >= 0);

		return 0;
		
	}
