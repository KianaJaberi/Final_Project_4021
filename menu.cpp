#include <iostream>
#include <windows.h>

using namespace std ;

main (){
	
	HANDLE color ;
	color = GetStdHandle ( STD_OUTPUT_HANDLE ) ;
	char input ;
	
	while ( true ){
	
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
	return 0 ;
}