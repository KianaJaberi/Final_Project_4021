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
	
	return input ;
}

void NewGame (){
	
	conditions input ;
	status New ;
	
	New.heal = 3 ;
	New.point = 0 ;
	New.level = 0 ;
	
	HANDLE color ;
	color = GetStdHandle ( STD_OUTPUT_HANDLE ) ;
	
	while ( true ){ //our spaceship
		
		SetConsoleTextAttribute ( color , 13 ) ; //light purple
		cout << "your spaceship ( # or * ) : " ;
		
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
	
	vector < vector < char > > vec ( input.size , vector < char > ( input.size ) ) ;
	
	for ( int i = 0 ; i < input.size ; i ++ ){
		
		for ( int j = 0 ; j < input.size ; j ++ ){
			
			vec [i][j] = ' ' ;
		}
	}
	
	game ( input , New , vec ) ;
}

void game ( conditions input , status s , vector < vector < char > > vec ){
	
	HANDLE color ;
	color = GetStdHandle ( STD_OUTPUT_HANDLE ) ;
	
	while ( s.heal > 0 ){
		
		finding ;////////////////
		
		SetConsoleTextAttribute ( color , 13 ) ; //light purple
		cout << "heal : " << s.heal << " | " ;
		
		SetConsoleTextAttribute ( color , 11 ) ; //light blue
		cout << "enemy spaceship heal : " <<  << endl ;
		
		SetConsoleTextAttribute ( color , 14 ) ;
		cout << "point : " << point << endl ;
		
		SetConsoleTextAttribute ( color , 13 ) ;
		cout << "level : " << level << endl << endl ;
		
		SetConsoleTextAttribute ( color , 15 ) ;
		for ( int i = 0 ; i < size ; i ++ ){
			
			for ( int j = 0 ; j < size ; j ++ )
				cout << " ---" ;
			
			cout << endl ;
			
			for ( int j = 0 ; j < size ; j ++ ){
				cout << "| " ;
				
				if ( vec [i][j] == OS )
					cout << OS << " " ;
				if ( vec [i][j] == ES )
					cout << ES << " " ;
				if ( vec [i][j] == '^' )
					cout << "^ " ;
				if ( vec [i][j] == ' ' )
					cout << "  " ;
			}
			cout << "|" << endl ;
		}
		for ( int i = 0 ; i < size ; i ++ )
			cout << " ---" ;
		cout << endl ;
		
		while ( true ){
			
			SetConsoleTextAttribute ( color , 5 ) ;
			cout << "right (r) or left (l) or in its place (i) or menu (m) : " ;
			input = getche () ;
			cout << endl ;
			
			if ( input != 'r' && input != 'l' && input != 'i' && input != 'm' ){
				SetConsoleTextAttribute ( color , 4 ) ;
				cout << "error !" << endl ;
				continue ;
			}
			
			break ;
		}
		
		system ("cls") ;
	}
}
