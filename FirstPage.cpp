#include <iostream>
#include <windows.h> //for color

using namespace std ;

int main (){
	
	char OS ;      //our spaceship
	char ES ;      //enemi spaceship
	HANDLE color ; //for color function
	int size ;     //table size
	
	color = GetStdHandle ( STD_OUTPUT_HANDLE ) ;
	
	SetConsoleTextAttribute ( color , 13 ) ;
	cout << "| ***** The last war ***** |" << endl << endl ;
	
	SetConsoleTextAttribute ( color , 8 ) ;
	cout << "for exit enter (E)" << endl << endl ;
	
	while ( true ){
	
		while ( true ){ //our spaceship
			SetConsoleTextAttribute ( color , 3 ) ;
			cout << "select your spaceship ( @ , # , $ , & or * ) : " ;
			cin >> OS ;
			
			if ( OS == 'E' )
				exit (0) ;
			else if ( OS != '@' && OS != '#' && OS != '$' && OS != '&' && OS != '*' ){
				SetConsoleTextAttribute ( color , 4 ) ;
				cout << "wrong choise !" << endl ;
				continue ;
			}
			break ;
		}
		
		while ( true ){ //enemi spaceship
			SetConsoleTextAttribute ( color , 3 ) ;
			cout << "select enemi spaceship ( @ , # , $ , & or * ) : " ;
			cin >> ES ;
			
			if ( ES == 'E' )
				exit (0) ;
			else if ( ES != '@' && ES != '#' && ES != '$' && ES != '&' && ES != '*' ){
				SetConsoleTextAttribute ( color , 4 ) ;
				cout << "wrong choise !" << endl ;
				continue ;
			}
			break ;
		}
		
		if ( OS == ES ){ //for similar spaceships
			SetConsoleTextAttribute ( color , 4 ) ;
			cout << "your spaceship and enemi spaceship can't be same !" << endl << endl ;
			continue ;
		} 
		break ;
	}
	
	while ( true ){ //table size
		
		SetConsoleTextAttribute ( color , 3 ) ;
		cout << "enter size of table ( size must biger than 15 ) : " ;
		cin >> size ;
		
		if ( size < 15 ){
			SetConsoleTextAttribute ( color , 4 ) ;
			cout << "wrong choice !" << endl ;
			continue ;
		}
		if ( ( size % 2 ) == 0 ) //for even size
			size ++ ;

		break ;
	}
	
	return 0 ;
}