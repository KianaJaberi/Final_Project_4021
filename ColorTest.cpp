#include <iostream>
#include <windows.h>

using namespace std ;

int main (){
	
	HANDLE color ;
	
	color = GetStdHandle ( STD_OUTPUT_HANDLE ) ;
	
	for ( int k = 0 ; k < 20 ; k ++ ){
		SetConsoleTextAttribute ( color , k ) ;
		cout << k << endl ;
	}
	
	return 0 ;
}
	