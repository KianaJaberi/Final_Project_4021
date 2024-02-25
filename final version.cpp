#include <iostream>
#include <fstream>
#include <vector>
#include <windows.h> //clear function
#include <ctime>     //srand function
#include <conio.h>   //getche function

using namespace std ;

char menu () ;

int main (){
	
	char input ;
	
	input = menu () ;
	
	return 0 ;
}

char menu (){
	
	HANDLE color ;
	color = GetStdHandle ( STD_OUTPUT_HANDLE ) ;
	
	char input ;
	
	while ( true ){
		
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
		
		input = getche () ;
		
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