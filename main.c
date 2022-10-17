#include "types.h"
#include "functions.h"

void main()
{
		initSnakeAndTail();
		initFood();
		
		 while (game == 0) {
			system("cls");
			initmap();
			moveSnakeAndTail();
			putFoodAndTail();
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
