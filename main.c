#include "functions.h"

void main()
{
		begin = (node*)malloc(sizeof(node));

		initSnakeAndTail(&snake);
		
		initFood();
		
		 while (game == 0) {
			setcur(0, 0);
			//system("cls");
			initmap();
			//movement();
			
			
			putSnake();
			//printsnake(10, 10);
			
			printSnakeAndFood();
			putSnake();moveSnakeAndTail();
			
			showMap();
			Sleep(80);

		 if (GetKeyState(VK_ESCAPE) < 0)
			 {
			 gameOver();
			 
			 
			 }
		  }
		return 0;
}
