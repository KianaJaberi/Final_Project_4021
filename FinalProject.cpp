#include <iostream>
#include <windows.h> //for color and system clear

using namespace std ;

struct F_P {
	char OS ;  //our spaceship
	char ES ;  //enemy spaceship
	int size ; //table size
};

F_P FirstPage () ; //first page
char menu () ; //menu

int main (){
	
	F_P fp = FirstPage () ; //first page
	system ("cls") ; //for clear first page
	
	char me = menu () ; //menu entry
	system ("cls") ; //for clear menu
			
	if ( me == 'n' ){
	}
	
	if ( me == 'c' ){
	}
	
	if ( me == 's' ){
	}
	
	if ( me == 'e' ){
	}
	
	return 0 ;
}

F_P FirstPage (){
	
	F_P f ;
	HANDLE color ; //for color function
	
	color = GetStdHandle ( STD_OUTPUT_HANDLE ) ;
	
	SetConsoleTextAttribute ( color , 13 ) ;
	cout << "| ***** The last war ***** |" << endl << endl ;
	
	while ( true ){
	
		while ( true ){ //our spaceship
			SetConsoleTextAttribute ( color , 3 ) ;
			cout << "select your spaceship ( @ , # , $ , & or * ) : " ;
			cin >> f.OS ;
			
			if ( f.OS != '@' && f.OS != '#' && f.OS != '$' && f.OS != '&' && f.OS != '*' ){
				SetConsoleTextAttribute ( color , 4 ) ;
				cout << "wrong choise !" << endl ;
				continue ;
			}
			break ;
		}
		
		while ( true ){ //enemy spaceship
			SetConsoleTextAttribute ( color , 3 ) ;
			cout << "select enemy spaceship ( @ , # , $ , & or * ) : " ;
			cin >> f.ES ;
			
			if ( f.ES != '@' && f.ES != '#' && f.ES != '$' && f.ES != '&' && f.ES != '*' ){
				SetConsoleTextAttribute ( color , 4 ) ;
				cout << "wrong choise !" << endl ;
				continue ;
			}
			break ;
		}
		
		if ( f.OS == f.ES ){ //for similar spaceships
			SetConsoleTextAttribute ( color , 4 ) ;
			cout << "your spaceship and enemy spaceship can't be same !" << endl << endl ;
			continue ;
		} 
		break ;
	}
	
	while ( true ){ //table size
		
		SetConsoleTextAttribute ( color , 3 ) ;
		cout << "enter the table size ( the size must be greater than 15 ) : " ;
		cin >> f.size ;
		
		if ( f.size < 15 ){
			SetConsoleTextAttribute ( color , 4 ) ;
			cout << "wrong choice !" << endl ;
			continue ;
		}
		if ( ( f.size % 2 ) == 0 ) //for even size
			f.size ++ ;

		break ;
	}
	return f ;
}

char menu (){
	
	char input ;
	HANDLE color ; //for color function
	
	color = GetStdHandle ( STD_OUTPUT_HANDLE ) ;
	
	while ( true ){ //menu entry
	
		SetConsoleTextAttribute ( color , 3 ) ;
		cout << "___ menu ____" << endl << endl ;
		
		SetConsoleTextAttribute ( color , 13 ) ;
		cout << "new game (n)" << endl ;
		
		SetConsoleTextAttribute ( color , 14 ) ;
		cout << "continue game (c)" << endl ;
		
		SetConsoleTextAttribute ( color , 12 ) ;
		cout << "enemies status (s)" << endl ;
		
		SetConsoleTextAttribute ( color , 15 ) ;
		cout << "exit (e)" << endl << endl ;
		
		cin >> input ;
		
		if ( input != 'n' && input != 'c' && input != 's' && input != 'e' ){
			SetConsoleTextAttribute ( color , 4 ) ;
			cout << "wrong choice !" << endl << endl ;
			continue ;
		}
		break ;
	}
	return input ;
}