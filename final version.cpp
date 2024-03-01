#include <iostream>
#include <fstream>
#include <vector>
#include <windows.h> //clear function
#include <ctime>     //srand function
#include <conio.h>   //getche function

using namespace std ;

struct conditions {
	char OS ;  //our spaceship
	char ES ;  //enemy spaceship
	int size ; //table size
};
struct status {
	int heal ;
	int point ;
	int level ;
};

char menu () ;
void NewGame () ;
void game ( conditions , status , vector < vector < char > > ) ;

int main (){
	
	char input ;
	
	input = menu () ;
	
	if ( input == 'n' ){
		
		NewGame () ;
	}
	
	if ( input == 'c' ){
	}
	
	if ( input == 'e' ){
	}
	
	return 0 ;
}

char menu (){
	
	HANDLE color ;
	color = GetStdHandle ( STD_OUTPUT_HANDLE ) ;
	
	char input ;
	
	while ( true ){ //input
		
		SetConsoleTextAttribute ( color , 15 ) ; //white
		cout << " /|_/| " << endl ;
		cout << "( *.* )" << endl ;
		cout << "/| " ;
		
		SetConsoleTextAttribute ( color , 5 ) ; //dark purple
		cout << "menu" << endl << endl ;
		
		SetConsoleTextAttribute ( color , 13 ) ; //light purple
		cout << "new game (n)" << endl ;
		
		SetConsoleTextAttribute ( color , 11 ) ; //light blue
		cout << "continue game (c)" << endl ;
		
		SetConsoleTextAttribute ( color , 14 ) ; //light yellow
		cout << "exit (e)" << endl ;
		
		SetConsoleTextAttribute ( color , 15 ) ; //white
		input = getche () ;
		cout << endl ;
		
		if ( input != 'n' && input != 'c' && input != 'e' ){
			
			SetConsoleTextAttribute ( color , 4 ) ; //red
			cout << "error !" << endl << endl ;
			
			continue ;
		}
		
		else{
			
			break ;
		}
	}
	
	system ( " cls " ) ;
	
	return input ;
}

void NewGame (){
	
	conditions input ;
	status New ;
	
	HANDLE color ;
	color = GetStdHandle ( STD_OUTPUT_HANDLE ) ;
	
	New.heal = 3 ;
	New.point = 0 ;
	New.level = 0 ;
	
	while ( true ){ //our spaceship
		
		SetConsoleTextAttribute ( color , 13 ) ; //light purple
		cout << "your spaceship ( # or * ) : " ;
		
		SetConsoleTextAttribute ( color , 15 ) ; //white
		input.OS = getche () ;
		cout << endl ;
		
		if ( input.OS != '#' && input.OS != '*' ){
			
			SetConsoleTextAttribute ( color , 4 ) ; //red
			cout << "error !" << endl ;
			
			continue ;
		}
		
		else {
			
			break ;
		}
	}
	
	switch ( input.OS ){ //enemy spaceship
		
		case '#' : input.ES = '*' ;
			break ;
		
		case '*' : input.ES = '#' ;
			break ;
	}
	
	while ( true ){ //table size
		
		SetConsoleTextAttribute ( color , 11 ) ; //light blue
		cout << "table size ( the size must be greater than 15 ) : " ;
		
		SetConsoleTextAttribute ( color , 15 ) ; //white
		cin >> input.size ;
		cout << endl ;
		
		if ( input.size < 15 ){
			
			SetConsoleTextAttribute ( color , 4 ) ; //red
			cout << "error !" << endl ;
			
			continue ;
		}
		
		else {
			
			break ;
		}
	}
	
	system ( " cls " ) ;
	
	vector < vector < char > > vec ( input.size , vector < char > ( input.size ) ) ;
	
	for ( int i = 0 ; i < input.size ; i ++ ){
		
		for ( int j = 0 ; j < input.size ; j ++ ){
			
			vec [i][j] = ' ' ;
		}
	}
	
	game ( input , New , vec ) ;
}

void game ( conditions input , status s , vector < vector < char > > vec ){
	
	char OS = input.OS ;
	char ES = input.ES ;
	int size = input.size ;
	
	int heal = s.heal ;
	int point = s.point ;
	int level = s.level ;
	
	int es_h ;
	char move ;
	
	HANDLE color ;
	color = GetStdHandle ( STD_OUTPUT_HANDLE ) ;
	
	while ( heal > 0 ){
		
		SetConsoleTextAttribute ( color , 13 ) ; //light purple
		cout << "heal : " << heal << " | " ;
		
		SetConsoleTextAttribute ( color , 14 ) ; //light yellow
		cout << "enemy spaceship heal : " << es_h << endl ;
		
		SetConsoleTextAttribute ( color , 11 ) ; //light blue
		cout << "point : " << point << " | " ;
		
		SetConsoleTextAttribute ( color , 10 ) ; //light green
		cout << "level : " << level << endl << endl ;
		
		SetConsoleTextAttribute ( color , 15 ) ; //white
		for ( int i = 0 ; i < size ; i ++ ){
			
			for ( int j = 0 ; j < size ; j ++ ){
				
				cout << " ---" ;
			}
			
			cout << endl ;
			
			for ( int j = 0 ; j < size ; j ++ ){
				
				cout << "| " ;
				
				if ( vec [i][j] == OS ){
					
					cout << OS << " " ;
				}
				
				if ( vec [i][j] == ES ){
					
					cout << ES << " " ;
				}
				
				if ( vec [i][j] == '^' ){
					
					cout << "^ " ;
				}
				
				if ( vec [i][j] == ' ' ){
					
					cout << "  " ;
				}
			}
			
			cout << "|" << endl ;
		}
		
		for ( int i = 0 ; i < size ; i ++ ){
			
			cout << " ---" ;
		}
		
		cout << endl << endl ;
		
		while ( true ){
			
			SetConsoleTextAttribute ( color , 5 ) ; //dark purple
			cout << "left (a) or here (s) or right (d) or menu (w) : " ;
			
			SetConsoleTextAttribute ( color , 15 ) ; //white
			move = getche () ;
			cout << endl ;
			
			if ( move != 'a' && move != 's' && move != 'd' && move != 'w' ){
				
				SetConsoleTextAttribute ( color , 4 ) ; //red
				cout << "error !" << endl ;
				
				continue ;
			}
			
			else {
				
				break ;
			}
		}
		
		system ( " cls " ) ;
		
		if ( move == 'a' ){
		}
		
		if ( move == 's' ){
		}
		
		if ( move == 'd' ){
		}
		
		if ( move == 'w' ){
		}
	}
}
