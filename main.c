#include "functions.ñ"

void main()
{
	makenull(&list);
	initSnakeAndTail(&snake);
	initFood();
	while (game == 0) {
		setcur(0, 0);
		initmap();
		printSnakeAndFood();
		moveSnakeAndTail();
		showMap();
		Sleep(95);
		if (GetKeyState(VK_ESCAPE) < 0)
		{
			gameOver();
		}
	}
	return 0;
}
