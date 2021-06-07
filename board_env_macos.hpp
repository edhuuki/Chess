#include <iostream>
#include <string>

using namespace std;


struct node{
	string value = "";

	struct node *next;
};


class linked_list
{
private:
	node *head;
	node *tail;
public:
	linked_list(){
		head = NULL;
		tail = NULL;
	}

	void add_node(string c){

		node *temp = new node;
		temp->value = c;
		temp->next = NULL;

		if(head==NULL){
			head = temp;
			tail = temp;
		}
		else{
			tail->next = temp;
			tail = tail->next;
		}
	}
	void print_list(){

		node *c_node = head;

		while(c_node!=NULL){
			cout<<c_node->value<<" ";
			c_node = c_node->next;
		}

	}
	node *get_head(){
		return head;
	}

};



class board_env{


public:

linked_list move_list;

char board[8][8];

board_env(){
	i_board();//upon call fills the board
}

int mn = 1;//intuitive for the move to start on 1 (mn: "move number")

int* c_ind(string c){
	static int rc[2];

	rc[0] = 8-((int)c[1]-48);
	rc[1] = (int)c[0]-97;

	return &rc[0];
}

void i_board(){//stores the initial board state and fills initializes the game board
	//Initial board
	char temp[8][8] ={
	{'R', 'N','B', 'Q', 'K', 'B', 'N', 'R'},
	{'P', 'P', 'P', 'P', 'P', 'P', 'P', 'P' },
	{'.', '.', '.','.','.','.','.','.'},
	{'.', '.', '.','.','.','.','.','.'},
	{'.', '.', '.','.','.','.','.','.'},
	{'.', '.', '.','.','.','.','.','.'},
	{'p', 'p', 'p', 'p', 'p', 'p', 'p', 'p' },
	{'r', 'n', 'b', 'q', 'k', 'b', 'n', 'r'}
	};

	for (int i = 0; i < 8; ++i)
	{
		for (int j = 0; j < 8; ++j)
		{
			board[i][j] = temp[i][j];
		}
	}
}

void move(string c){
/*
#######################################
The hierarchy
-Type of move based (Actions peices could possibly take)
pawn moves
	-White or black to move
		-pieces involved
			-does the piece take?

*** Asumes all the moves inputed are valid ****
#######################################
*/



string mc;

unsigned long l = c.length();

if (l==2) mc = c;
else mc = c.substr(l-2, l-1);

int *rc = c_ind(mc);

if (c.length()==2){//pawn move no takes

	if(mn%2==1){//white to move on odd moves
	
		board[*rc][*(rc+1)]='p';

		for (int i = 1; i <= 2; ++i){//searches for the previous position of the pawn and sets it to '.'
		
			if(board[*rc+i][*(rc+1)]=='p') {
				board[*rc+i][*(rc+1)]='.';
				break;
			}
		}
	}else if(mn%2==0){//black move
	
		board[*rc][*(rc+1)]='P';

		for (int i = 1; i <= 2; ++i){//searches for the previous position of the pawn and sets it to '.'
			if(board[*rc-i][*(rc+1)]=='P') {
				board[*rc-i][*(rc+1)]='.';
				break;
			}
		}
	}

}else if(c[0]=='K'){
	if(mn%2==1){
		for (int i = 0; i < 3; ++i)
		{
			for (int j = 0; j < 3; ++j)
			{
				if(board[*rc+i-1][*(rc+1)+j-1]=='k') board[*rc+i-1][*(rc+1)+j-1] = '.';//sets any previous king square to '.'
			}
		}
		board[*rc][*(rc+1)] = 'k';

	}else{
		for (int j = 0; j < 3; ++j)
		{
			for (int i = 0; i < 3; ++i)
			{
				if(board[*rc+i-1][*(rc+1)+j-1]=='K') board[*rc+i-1][*(rc+1)+j-1] = '.';//sets any previous B king square to '.'
			}
		}
		board[*rc][*(rc+1)] = 'K';
	}
}


//System for recording the Game


mn++;//should only iterate if the move is valid

move_list.add_node(c);

	
}

void print_board(){
	int piece;

  	cout<<"\n";
	for (int i = 0; i < 8; ++i)
	{
		cout<<8-i<<"\t";

		for (int j = 0; j < 8; ++j){
			piece = (char)board[i][j];

			switch(piece){
				case 82://B Rook
					cout<<"\u265c\t";
					break;
				case 78://B Knight
					cout<<"\u265e\t";
					break;
				case 66://B Bishop
					cout<<"\u265D\t";
					break;
				case 75://B King
					cout<<"\u265A\t";
					break;
				case 81://B Queen
					cout<<"\u265B\t";
					break;
				case 80://B Pawn
					cout<<"\u265F\t";
					break;
				case 114://W Rook
					cout<<"\u2656\t";
					break;
				case 110://W Knight
					cout<<"\u2658\t";
					break;
				case 98://W Bishop
					cout<<"\u2657\t";
					break;
				case 107://W King
					cout<<"\u2654\t";
					break;
				case 113://W Queen
					cout<<"\u2655\t";
					break;
				case 112://W Pawn
					cout<<"\u2659\t";
					break;

				default:
					cout<<board[i][j]<<"\t";
			}

		}	
			
		cout<<"\n";
		
	}
	cout<<"\n\t";
	for (int i = 0; i < 8; ++i)
	{
		cout<<(char)(i+65)<<"\t";//prints the chess board file
	}
	cout<<"\n";//cuts the output//prints out a nice representation of the chess space for visual purposes
}

};



