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
struct EnemySpaceship{
	char type ; //enemy spaceship type
	int loc ;   //enemy spaceship location
};
struct cont { //for continue game
	int heal ;
	char type ;
};

char menu () ;
void NewGame () ;
void ContinueGame () ;
void game ( conditions , status , cont , vector < vector < char > > ) ;
bool finding ( vector < vector < char > > , int , char ) ;
EnemySpaceship enemy ( int ) ;

int main (){
	
	char input ;
	
	input = menu () ;
	
	if ( input == 'n' ){
		
		NewGame () ;
	}
	
	if ( input == 'c' ){
		
		ContinueGame () ;
	}
	
	if ( input == 'e' ){
		
		exit (0) ;
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
	
	if ( ( input.size % 2 ) == 0 ){
		
		input.size ++ ;
	}
	
	system ( " cls " ) ;
	
	vector < vector < char > > vec ( input.size , vector < char > ( input.size ) ) ;
	
	for ( int i = 0 ; i < input.size ; i ++ ){
		
		for ( int j = 0 ; j < input.size ; j ++ ){
			
			vec [i][j] = ' ' ;
		}
	}
	
	vec [ input.size - 1 ][ input.size / 2 ] = input.OS ;
	
	cont c ;
	c.heal = 0 ;   //null
	c.type = 'a' ; //null
	
	game ( input , New , c , vec ) ;
}

void ContinueGame (){
	
	conditions input ;
	status New ;
	cont c ;
	
	ifstream file ;
	
	file.open ( "game.txt" ) ;
	
	file >> input.OS ;
	file >> input.ES ;
	file >> input.size ;
	
	file >> New.heal ;
	file >> New.point ;
	file >> New.level ;
	
	file >> c.heal ;
	file >> c.type ;
	
	vector < vector < char > > vec ( input.size , vector < char > ( input.size ) ) ;
	
	for ( int i = 0 ; i < input.size ; i ++ ){
		
		for ( int j = 0 ; j < input.size ; j ++ ){
			
			file >> vec [i][j] ;
			
			if ( vec [i][j] == 'n' ){ //n = null
				
				vec [i][j] = ' ' ;
			}
		}
	}
	
	file.close() ;
	
	game ( input , New , c , vec ) ;
}

void game ( conditions input , status s , cont c , vector < vector < char > > vec ){
	
	char OS = input.OS ; //our spaceship
	char ES = input.ES ; //enemy spaceship
	int size = input.size ;
	
	int heal = s.heal ;
	int point = s.point ;
	int level = s.level ;
	
	int es_h = c.heal ;  //enemy spaceship heal
	char es_t = c.type ; //enemy spaceship type
	char move ;
	bool flag ; //for finding function
	
	//file
	ofstream file ;
	char f_OS = OS ;
	char f_ES = ES ;
	int f_size = size ;
	int f_heal = heal ;
	int f_point = point ;
	int f_level = level ;
	int f_es_h = es_h ;
	char f_es_t = es_t ;
	
	HANDLE color ;
	color = GetStdHandle ( STD_OUTPUT_HANDLE ) ;
	
	while ( heal > 0 ){
		
		file.open ( "game.txt" ) ;
		
		flag = finding ( vec , size , ES ) ;
		
		if ( flag == true ){
			
			EnemySpaceship es = enemy ( size ) ;
			
			es_t = es.type ;
			f_es_t = es_t ;
			
			int row = 0 ;
			int col = es.loc ;
			
			if ( es_t == 'd' ){
				
				vec [row][col] = ES ;
				
				es_h = 1 ;
				f_es_h = es_h ;
			}
			
			if ( es_t == 's' ){
				
				for ( int i = 0 ; i < 2 ; i ++ ){
					
					for ( int j = 0 ; j < 2 ; j ++ ){
						
						vec [row][col] = ES ;
						
						col ++ ;
					}
					
					row ++ ;
					col -= 2 ;
				}
				
				es_h = 2 ;
				f_es_h = es_h ;
			}
			
			if ( es_t == 'w' ){
				
				for ( int i = 0 ; i < 3 ; i ++ ){
					
					for ( int j = 0 ; j < 3 ; j ++ ){
						
						vec [row][col] = ES ;
						
						col ++ ;
					}
					
					row ++ ;
					col -= 3 ;
				}
				
				es_h = 4 ;
				f_es_h = es_h ;
			}
			
			if ( es_t == 'b' ){
				
				for ( int i = 0 ; i < 4 ; i ++ ){
					
					for ( int j = 0 ; j < 4 ; j ++ ){
						
						vec [row][col] = ES ;
						
						col ++ ;
					}
					
					row ++ ;
					col -= 4 ;
				}
				
				es_h = 6 ;
				f_es_h = es_h ;
			}
		}

		SetConsoleTextAttribute ( color , 13 ) ; //light purple
		cout << "heal : " << heal << " |" ;
		
		SetConsoleTextAttribute ( color , 14 ) ; //light yellow
		cout << "| enemy spaceship heal : " << es_h << endl ;
		
		SetConsoleTextAttribute ( color , 11 ) ; //light blue
		cout << "point : " << point << " |" ;
		
		SetConsoleTextAttribute ( color , 10 ) ; //light green
		cout << "| level : " << level << endl << endl ;
		
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
			
			//bullet
			for ( int i = 0 ; i < size ; i ++ ){
				
				for ( int j = 0 ; j < size ; j ++ ){
					
					if ( vec [i][j] == '^' ){
						
						if ( i == 0 ){
							
							vec [i][j] = ' ' ;
						}
						
						else if ( vec [i - 1][j] == ES ){
							
							es_h -- ;
							f_es_h = es_h ;
							
							vec [i][j] = ' ' ;
							
							if ( es_h == 0 ){
								
								for ( int a = 0 ; a < size ; a ++ ){
									
									for ( int b = 0 ; b < size ; b ++ ){
										
										if ( vec [a][b] == ES ){
											
											vec [a][b] = ' ' ;
										}
									}
								}
								
								switch ( es_t ){
									
									case 'd' : point += 2 ;
										break ;
										
									case 's' : point += 8 ;
										break ;
										
									case 'w' : point += 18 ;
										break ;
										
									case 'b' : point += 32 ;
										break ;
								}
									
								if ( point >= 200 ){
									
									level ++ ;
									point -= 200 ;
								}
								
								f_point = point ;
								f_level = level ;
							}
						}
						
						else {
							
							vec [i][j] = ' ' ;
							vec [i - 1][j] = '^' ;
						}
					}
				}
			}
			
			//our spaceship
			for ( int i = 0 ; i < size ; i ++ ){
				
				if ( vec [size - 1][i] == OS ){
					
					if ( ( i - 1 ) == -1 ){
						
						if ( vec [size - 2][i] == ES ){
							
							heal -- ;
							f_heal = heal ;
							
							for ( int a = 0 ; a < size ; a ++ ){
								
								for ( int b = 0 ; b < size ; b ++ ){
									
									if ( vec [a][b] == ES ){
										
										vec [a][b] = ' ' ;
									}
								}
							}
						}
						
						else {
							
							vec [size - 2][i] = '^' ;
						}
					}
					
					else if ( vec [size - 1][i - 1] == ES ){
						
						heal -- ;
						f_heal = heal ;
						
						vec [size - 1][i] = ' ' ;
						vec [size - 1][i - 1] = OS ;
						
						for ( int a = 0 ; a < size ; a ++ ){
							
							for ( int b = 0 ; b < size ; b ++ ){
								
								if ( vec [a][b] == ES ){
									
									vec [a][b] = ' ' ;
								}
							}
						}
					}
					
					else if ( vec [size - 2][i - 1] == ES ){
						
						heal -- ;
						f_heal = heal ;
						
						vec [size - 1][i] = ' ' ;
						vec [size - 1][i - 1] = OS ;
						
						for ( int a = 0 ; a < size ; a ++ ){
							
							for ( int b = 0 ; b < size ; b ++ ){
								
								if ( vec [a][b] == ES ){
									
									vec [a][b] = ' ' ;
								}
							}
						}
					}
					
					else {
						
						vec [size - 1][i] = ' ' ;
						vec [size - 1][i - 1] = OS ;
						
						vec [size - 2][i - 1] = '^' ;
					}
				}
			}
			
			//enemy spaceship
			for ( int i = ( size - 1 ) ; i >= 0 ; i -- ){
				
				for ( int j = ( size - 1 ) ; j >= 0 ; j -- ){
					
					if ( vec [i][j] == ES ){
						
						if ( i == ( size - 1 ) ){
							
							if ( vec [i - 1][j] != ES ){
								
								heal -- ;
								f_heal = heal ;
								
								for ( int a = 0 ; a < size ; a ++ ){
								
									for ( int b = 0 ; b < size ; b ++ ){
										
										if ( vec [a][b] == ES ){
											
											vec [a][b] = ' ' ;
										}
									}
								}
							}
							
							else {
								
								vec [i][j] = ' ' ;
							}
						}
						
						else if ( vec [i + 1][j] == '^' ){
							
							es_h -- ;
							f_es_h = es_h ;
							
							vec [i + 1][j] == ' ' ;
							
							if ( es_h == 0 ){
								
								for ( int a = 0 ; a < size ; a ++ ){
									
									for ( int b = 0 ; b < size ; b ++ ){
										
										if ( vec [a][b] == ES ){
											
											vec [a][b] = ' ' ;
										}
									}
								}
								
								switch ( es_t ){
									
									case 'd' : point += 2 ;
										break ;
										
									case 's' : point += 8 ;
										break ;
										
									case 'w' : point += 18 ;
										break ;
										
									case 'b' : point += 32 ;
										break ;
								}
									
								if ( point >= 200 ){
									
									level ++ ;
									point -= 200 ;
								}
								
								f_point = point ;
								f_level = level ;
							}
							
							else {
								
								vec [i][j] = ' ' ;
								vec [i + 1][j] = ES ;
							}
						}
						
						else {
							
							vec [i][j] = ' ' ;
							vec [i + 1][j] = ES ;
						}
					}
				}
			}
		}
		
		else if ( move == 's' ){
			
			//bullet
			for ( int i = 0 ; i < size ; i ++ ){
				
				for ( int j = 0 ; j < size ; j ++ ){
					
					if ( vec [i][j] == '^' ){
						
						if ( i == 0 ){
							
							vec [i][j] = ' ' ;
						}
						
						else if ( vec [i - 1][j] == ES ){
							
							es_h -- ;
							f_es_h = es_h ;
							
							vec [i][j] = ' ' ;
							
							if ( es_h == 0 ){
								
								for ( int a = 0 ; a < size ; a ++ ){
									
									for ( int b = 0 ; b < size ; b ++ ){
										
										if ( vec [a][b] == ES ){
											
											vec [a][b] = ' ' ;
										}
									}
								}
								
								switch ( es_t ){
									
									case 'd' : point += 2 ;
										break ;
										
									case 's' : point += 8 ;
										break ;
										
									case 'w' : point += 18 ;
										break ;
										
									case 'b' : point += 32 ;
										break ;
								}
									
								if ( point >= 200 ){
									
									level ++ ;
									point -= 200 ;
								}
								
								f_point = point ;
								f_level = level ;
							}
						}
						
						else {
							
							vec [i][j] = ' ' ;
							vec [i - 1][j] = '^' ;
						}
					}
				}
			}
			
			//our spaceship
			for ( int i = 0 ; i < size ; i ++ ){
				
				if ( vec [size - 1][i] == OS ){
					
					if ( vec [size - 2][i] == ES ){
						
						heal -- ;
						f_heal = heal ;
						
						for ( int a = 0 ; a < size ; a ++ ){
							
							for ( int b = 0 ; b < size ; b ++ ){
								
								if ( vec [a][b] == ES ){
									
									vec [a][b] = ' ' ;
								}
							}
						}
					}
					
					else {
						
						vec [size - 2][i] = '^' ;
					}
				}
			}
			
			//enemy spaceship
			for ( int i = ( size - 1 ) ; i >= 0 ; i -- ){
				
				for ( int j = ( size - 1 ) ; j >= 0 ; j -- ){
					
					if ( vec [i][j] == ES ){
						
						if ( i == ( size - 1 ) ){
							
							if ( vec [i - 1][j] != ES ){
								
								heal -- ;
								f_heal = heal ;
								
								for ( int a = 0 ; a < size ; a ++ ){
								
									for ( int b = 0 ; b < size ; b ++ ){
										
										if ( vec [a][b] == ES ){
											
											vec [a][b] = ' ' ;
										}
									}
								}
							}
							
							else {
								
								vec [i][j] = ' ' ;
							}
						}
						
						else if ( vec [i + 1][j] == '^' ){
							
							es_h -- ;
							f_es_h = es_h ;
							
							vec [i + 1][j] == ' ' ;
							
							if ( es_h == 0 ){
								
								for ( int a = 0 ; a < size ; a ++ ){
									
									for ( int b = 0 ; b < size ; b ++ ){
										
										if ( vec [a][b] == ES ){
											
											vec [a][b] = ' ' ;
										}
									}
								}
								
								switch ( es_t ){
									
									case 'd' : point += 2 ;
										break ;
										
									case 's' : point += 8 ;
										break ;
										
									case 'w' : point += 18 ;
										break ;
										
									case 'b' : point += 32 ;
										break ;
								}
									
								if ( point >= 200 ){
									
									level ++ ;
									point -= 200 ;
								}
								
								f_point = point ;
								f_level = level ;
							}
							
							else {
								
								vec [i][j] = ' ' ;
								vec [i + 1][j] = ES ;
							}
						}
						
						else {
							
							vec [i][j] = ' ' ;
							vec [i + 1][j] = ES ;
						}
					}
				}
			}
		}
		
		else if ( move == 'd' ){
			
			//bullet
			for ( int i = 0 ; i < size ; i ++ ){
				
				for ( int j = 0 ; j < size ; j ++ ){
					
					if ( vec [i][j] == '^' ){
						
						if ( i == 0 ){
							
							vec [i][j] = ' ' ;
						}
						
						else if ( vec [i - 1][j] == ES ){
							
							es_h -- ;
							f_es_h = es_h ;
							
							vec [i][j] = ' ' ;
							
							if ( es_h == 0 ){
								
								for ( int a = 0 ; a < size ; a ++ ){
									
									for ( int b = 0 ; b < size ; b ++ ){
										
										if ( vec [a][b] == ES ){
											
											vec [a][b] = ' ' ;
										}
									}
								}
								
								switch ( es_t ){
									
									case 'd' : point += 2 ;
										break ;
										
									case 's' : point += 8 ;
										break ;
										
									case 'w' : point += 18 ;
										break ;
										
									case 'b' : point += 32 ;
										break ;
								}
									
								if ( point >= 200 ){
									
									level ++ ;
									point -= 200 ;
								}
								
								f_point = point ;
								f_level = level ;
							}
						}
						
						else {
							
							vec [i][j] = ' ' ;
							vec [i - 1][j] = '^' ;
						}
					}
				}
			}
			
			//our spaceship
			for ( int i = ( size - 1 ) ; i >= 0 ; i -- ){
				
				if ( vec [size - 1][i] == OS ){
					
					if ( ( i + 1 ) == size ){
						
						if ( vec [size - 2][i] == ES ){
							
							heal -- ;
							f_heal = heal ;
							
							for ( int a = 0 ; a < size ; a ++ ){
								
								for ( int b = 0 ; b < size ; b ++ ){
									
									if ( vec [a][b] == ES ){
										
										vec [a][b] = ' ' ;
									}
								}
							}
						}
						
						else {
							
							vec [size - 2][i] = '^' ;
						}
					}
					
					else if ( vec [size - 1][i + 1] == ES ){
						
						heal -- ;
						f_heal = heal ;
						
						vec [size - 1][i] = ' ' ;
						vec [size - 1][i + 1] = OS ;
						
						for ( int a = 0 ; a < size ; a ++ ){
							
							for ( int b = 0 ; b < size ; b ++ ){
								
								if ( vec [a][b] == ES ){
									
									vec [a][b] = ' ' ;
								}
							}
						}
					}
					
					else if ( vec [size - 2][i + 1] == ES ){
						
						heal -- ;
						f_heal = heal ;
						
						vec [size - 1][i] = ' ' ;
						vec [size - 1][i + 1] = OS ;
						
						for ( int a = 0 ; a < size ; a ++ ){
							
							for ( int b = 0 ; b < size ; b ++ ){
								
								if ( vec [a][b] == ES ){
									
									vec [a][b] = ' ' ;
								}
							}
						}
					}
					
					else {
						
						vec [size - 1][i] = ' ' ;
						vec [size - 1][i + 1] = OS ;
						
						vec [size - 2][i + 1] = '^' ;
					}
				}
			}
			
			//enemy spaceship
			for ( int i = ( size - 1 ) ; i >= 0 ; i -- ){
				
				for ( int j = ( size - 1 ) ; j >= 0 ; j -- ){
					
					if ( vec [i][j] == ES ){
						
						if ( i == ( size - 1 ) ){
							
							if ( vec [i - 1][j] != ES ){
								
								heal -- ;
								f_heal = heal ;
								
								for ( int a = 0 ; a < size ; a ++ ){
								
									for ( int b = 0 ; b < size ; b ++ ){
										
										if ( vec [a][b] == ES ){
											
											vec [a][b] = ' ' ;
										}
									}
								}
							}
							
							else {
								
								vec [i][j] = ' ' ;
							}
						}
						
						else if ( vec [i + 1][j] == '^' ){
							
							es_h -- ;
							f_es_h = es_h ;
							
							vec [i + 1][j] == ' ' ;
							
							if ( es_h == 0 ){
								
								for ( int a = 0 ; a < size ; a ++ ){
									
									for ( int b = 0 ; b < size ; b ++ ){
										
										if ( vec [a][b] == ES ){
											
											vec [a][b] = ' ' ;
										}
									}
								}
								
								switch ( es_t ){
									
									case 'd' : point += 2 ;
										break ;
										
									case 's' : point += 8 ;
										break ;
										
									case 'w' : point += 18 ;
										break ;
										
									case 'b' : point += 32 ;
										break ;
								}
									
								if ( point >= 200 ){
									
									level ++ ;
									point -= 200 ;
								}
								
								f_point = point ;
								f_level = level ;
							}
							
							else {
								
								vec [i][j] = ' ' ;
								vec [i + 1][j] = ES ;
							}
						}
						
						else {
							
							vec [i][j] = ' ' ;
							vec [i + 1][j] = ES ;
						}
					}
				}
			}
		}
		
		//insert into file
		file << f_OS << endl ;
		file << f_ES << endl ;
		file << f_size << endl ;
		file << f_heal << endl ;
		file << f_point << endl ;
		file << f_level << endl ;
		file << f_es_h << endl ;
		file << f_es_t << endl ;
		
		for ( int i = 0 ; i < size ; i ++ ){
			
			for ( int j = 0 ; j < size ; j ++ ){
				
				if ( vec [i][j] == OS ){
					
					file << OS << endl ;
				}
				
				else if ( vec [i][j] == ES ){
					
					file << ES << endl ;
				}
				
				else if ( vec [i][j] == '^' ){
					
					file << "^" << endl ;
				}
				
				else if ( vec [i][j] == ' ' ){
					
					file << "n" << endl ;
				}
			}
		}
		
		file.close () ;
		
		if ( move == 'w' ){
			
			char input ;
	
			input = menu () ;
			
			if ( input == 'n' ){
				
				NewGame () ;
			}
			
			if ( input == 'c' ){
			}
			
			if ( input == 'e' ){
				
				exit (0) ;
			}
		}
	}
	
	if ( heal <= 0 ){
		
		SetConsoleTextAttribute ( color , 4 ) ; //red
		cout << "game over ! " << endl ;
		
		remove ( "game.txt" ) ;
	}
}

bool finding ( vector < vector < char > > vec , int size , char ES ){
	
	bool flag = true ;
	
	for ( int i = 0 ; i < size ; i ++ ){
		
		for ( int j = 0 ; j < size ; j ++ ){
			
			if ( vec [i][j] == ES ){
				
				flag = false ;
			}
		}
	}
	
	return flag ;
}

EnemySpaceship enemy ( int size ){
	
	EnemySpaceship es ;
	
	srand ( time (0) ) ;
	
	int random = rand () % 4 ;
	
	switch ( random ){
		
		case 0 : es.type = 'd' ; //dart
			break ;
		
		case 1 : es.type = 's' ; //striker
			break ;
		
		case 2 : es.type = 'w' ; //wraith
			break ;
		
		case 3 : es.type = 'b' ; //banshee
			break ;
	}
	
	switch ( es.type ){
		
		case 'd' : es.loc = rand () % size ; //1*1
			break ;
		
		case 's' : es.loc = rand () % ( size - 1 ) ; //2*2
			break ;
		
		case 'w' : es.loc = rand () % ( size - 2 ) ; //3*3
			break ;
		
		case 'b' : es.loc = rand () % ( size - 3 ) ; //4*4
			break ;
	}
	
	return es ;
}