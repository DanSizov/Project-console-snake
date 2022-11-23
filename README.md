A console game built on C using 2 structures each consists of 1 symbol: TypeSnake as a head of a snake and TypeTail as a tail.

Each and every time head eats food it gains 1 tail structure in the end as a symbol.

Every tail symbol has got the previous position of the tail symbol in front of it as a buffer.

Movement explanataion.

Every time the snake moves, each and every tail symbol moves to the previous coordinates of the tail symbol in front of it. The first tail symbol has got the position of head.

The snake moves constantly using WASD as movement keys. 

btw if a snake head goes into the wall it continues moving starting from the opposite wall.

----------------------------------------------------------------------------
A huge refactoring is added in the "snake-refactor" branch. A README file was also added there so you can check the chenges in a new version right now! Enjoy :)
