#include <iostream>
#include <ctime>

using namespace std ;

int main (){
	
	//input : size
	//output : enemy spaceship type , enemy spaceship heal , enemy spaceship location
	
	int size ;
	
	char type ;
	int heal ;
	int loc ;
		
	srand ( time (0) ) ;
	
	int random = rand () % 4 ;
		
	switch ( random ){
		case 0 : type = 'd' , heal = 1 ; //type : dart
			break ;
		case 1 : type = 's' , heal = 2 ; //type : Striker
			break ;
		case 2 : type = 'w' , heal = 4 ; //type : Wraith
			break ;
		case 3 : type = 'b' , heal = 6 ; //type : Banshee
			break ;
	}
	
	while ( true ){
	
		switch ( type ){
			case 'd' : loc = rand () % size ;
				break ;
			case 's' : loc = rand () % ( size - 1 ) ;
				break ;
			case 'w' : loc = rand () % ( size - 2 ) ;
				break ;
			case 'b' : loc = rand () % ( size - 3 ) ;
				break ;
		}
		
		if ( loc >= size )
			continue ;
		
		break ;
	}
	
	return 0 ;
}