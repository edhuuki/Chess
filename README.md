# Chess

This is a barebones chess enviormeent for the purposes of my understanding of AI systems and algorithms

chess_envmacos.cpp

## Using the enviorment to play a game

```cpp
#include <iostream>
#include "board_env_macos.hpp"
#include <string>


using namespace std;

//moving the peices back and forth
using namespace std;
int main() {
board_env b;

b.print_board();

b.move("e4");

b.move("d5");

b.print_board();

b.move_list.print_list();

}
```

## Output

```shell

8	♜	♞	♝	♛	♚	♝	♞	♜	
7	♟	♟	♟	♟	♟	♟	♟	♟	
6	.	.	.	.	.	.	.	.	
5	.	.	.	.	.	.	.	.	
4	.	.	.	.	.	.	.	.	
3	.	.	.	.	.	.	.	.	
2	♙	♙	♙	♙	♙	♙	♙	♙	
1	♖	♘	♗	♕	♔	♗	♘	♖	

	A	B	C	D	E	F	G	H	

8	♜	♞	♝	♛	♚	♝	♞	♜	
7	♟	♟	♟	.	♟	♟	♟	♟	
6	.	.	.	.	.	.	.	.	
5	.	.	.	♟	.	.	.	.	
4	.	.	.	.	♙	.	.	.	
3	.	.	.	.	.	.	.	.	
2	♙	♙	♙	♙	.	♙	♙	♙	
1	♖	♘	♗	♕	♔	♗	♘	♖	

	A	B	C	D	E	F	G	H	

e4 d5
```
