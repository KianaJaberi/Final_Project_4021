#include <iostream>
#include <windows.h> //for color and system clear
#include <ctime>
#include <vector>

using namespace std ;

struct F_P {
	char OS ;  //our spaceship
	char ES ;  //enemy spaceship
	int size ; //table size
};
struct E_S{
	char type ;
	char heal ;
	int loc ;
};

F_P FirstPage () ; //first page
char menu () ; //menu
E_S EnemySpaceship ( int ) ;
void NewGame ( int , vector < vector < char > > , char , char ) ;

int main (){
	
	F_P fp = FirstPage () ; //first page
	system ("cls") ; //for clear first page
	
	char me = menu () ; //menu entry
	system ("cls") ; //for clear menu
	
	vector < vector < char > > vec ( fp.size , vector < char > ( fp.size ) ) ;
	
	for ( int i = 0 ; i < fp.size ; i ++ )
		for ( int j = 0 ; j < fp.size ; j ++ )
			vec [i][j] = ' ' ;
			
	if ( me == 'n' ){
		NewGame ( fp.size , vec , fp.OS , fp.ES ) ;
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
			cout << "select your spaceship ( # or * ) : " ;
			cin >> f.OS ;
			
			if ( f.OS != '#' && f.OS != '*' ){
				SetConsoleTextAttribute ( color , 4 ) ;
				cout << "wrong choise !" << endl ;
				continue ;
			}
			break ;
		}
		
		while ( true ){ //enemy spaceship
			SetConsoleTextAttribute ( color , 3 ) ;
			cout << "select enemy spaceship ( # or * ) : " ;
			cin >> f.ES ;
			
			if ( f.ES != '#' && f.ES != '*' ){
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

E_S EnemySpaceship ( int size ){
		
	E_S ES ;
		
	srand ( time (0) ) ;
	
	int random = rand () % 4 ;
		
	switch ( random ){
		case 0 : ES.type = 'd' , ES.heal = 1 ; //type : dart
			break ;
		case 1 : ES.type = 's' , ES.heal = 2 ; //type : Striker
			break ;
		case 2 : ES.type = 'w' , ES.heal = 4 ; //type : Wraith
			break ;
		case 3 : ES.type = 'b' , ES.heal = 6 ; //type : Banshee
			break ;
	}
	
	while ( true ){
	
		switch ( ES.type ){
			case 'd' : ES.loc = rand () % size ;
				break ;
			case 's' : ES.loc = rand () % size + 1 ;
				break ;
			case 'w' : ES.loc = rand () % size + 2 ;
				break ;
			case 'b' : ES.loc = rand () % size + 3 ;
				break ;
		}
		
		if ( ES.loc >= size )
			continue ;
		
		break ;
	}
	
	return ES ;
}

void NewGame ( int size , vector < vector < char > > vec , char OS , char ES ){
	
	E_S es = EnemySpaceship ( size ) ;
	
	HANDLE color ;
	color = GetStdHandle ( STD_OUTPUT_HANDLE ) ;
	
	vec [ size - 1 ][ size / 2 ] = OS ;
	
	int row = 0 ;
	int col = es.loc ;
	
	if ( es.type == 'd' ){
		vec [row][col] = ES ;
	}
	
	if ( es.type == 's' ){
		for ( int i = 0 ; i < 2 ; i ++ ){
			for ( int j = 0 ; j < 2 ; j ++ ){
				vec [row][col] = ES ;
				col ++ ;
			}
			row ++ ;
			col -= 2 ;
		}
	}
	
	if ( es.type == 'w' ){
		for ( int i = 0 ; i < 3 ; i ++ ){
			for ( int j = 0 ; j < 3 ; j ++ ){
				vec [row][col] = ES ;
				col ++ ;
			}
			row ++ ;
			col -= 3 ;
		}
	}
	
	if ( es.type == 'b' ){
		for ( int i = 0 ; i < 4 ; i ++ ){
			for ( int j = 0 ; j < 4 ; j ++ ){
				vec [row][col] = ES ;
				col ++ ;
			}
			row ++ ;
			col -= 4 ;
		}
	}
	
}