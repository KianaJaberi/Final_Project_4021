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
struct status {
	int heal ;
	int point ;
	int level ;
};

F_P FirstPage () ; //first page
char menu () ; //menu
E_S EnemySpaceship ( int ) ;
void NewGame ( int , char , char ) ;
void game ( int , vector < vector < char > > , char , char , int , char , status ) ;
bool finding ( vector < vector < char > > , int , char ) ;

int main (){
	
	F_P fp = FirstPage () ; //first page
	system ("cls") ; //for clear first page
	
	char me = menu () ; //menu entry
	system ("cls") ; //for clear menu
			
	if ( me == 'n' ){
		NewGame ( fp.size , fp.OS , fp.ES ) ;
	}
	
	if ( me == 'c' ){
	}
	
	if ( me == 's' ){
	}
	
	if ( me == 'e' ){
		exit (0) ;
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
		cout << "exit (e)" << endl ;

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
			case 's' : ES.loc = rand () % ( size - 1 ) ;
				break ;
			case 'w' : ES.loc = rand () % ( size - 2 ) ;
				break ;
			case 'b' : ES.loc = rand () % ( size - 3 ) ;
				break ;
		}
		
		if ( ES.loc >= size )
			continue ;
		
		break ;
	}
	
	return ES ;
}

void NewGame ( int size , char OS , char ES ){
	
	vector < vector < char > > vec ( size , vector < char > ( size ) ) ;
	
	for ( int i = 0 ; i < size ; i ++ )
		for ( int j = 0 ; j < size ; j ++ )
			vec [i][j] = ' ' ;
	
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
	
	status s ;
	s.heal = 3 ;
	s.point = 0 ;
	s.level = 0 ;
	
	game ( size , vec , OS , ES , es.heal , es.type , s ) ;
}

void game ( int size , vector < vector < char > > vec , char OS , char ES , int es_h , char es_t , status s ){
	
	int heal = s.heal ;
	int point = s.point ;
	int level = s.level ;
	char input ;
	bool flag ;
	bool flag2 = true ;
	
	HANDLE color ;
	color = GetStdHandle ( STD_OUTPUT_HANDLE ) ;
	
	while ( heal > 0 ){
		
		SetConsoleTextAttribute ( color , 10 ) ;
		cout << "our heal : " << heal << endl ;
		
		SetConsoleTextAttribute ( color , 11 ) ;
		cout << "enemy spaceship heal : " << es_h << endl ;
		
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
			cin >> input ;
			
			if ( input != 'r' && input != 'l' && input != 'i' && input != 'm' ){
				SetConsoleTextAttribute ( color , 4 ) ;
				cout << "error !" << endl ;
				continue ;
			}
				
			break ;
		}
		
		system ("cls") ;
		
		if ( input == 'r' ){
			
			for ( int i = 0 ; i < size ; i ++ ){ //for bullet
				for ( int j = 0 ; j < size ; j ++ ){
					if ( vec [i][j] == '^' ){
						if ( ( i - 1 ) == -1 ){
							vec [i][j] = ' ' ;
						}
						else {
							if ( vec [i - 1][j] == ES ){
								vec [i][j] = ' ' ;
								es_h -- ;
								if ( es_h == 0 ){
									
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
									for ( int i = 0 ; i < size ; i ++ ){
										for ( int j = 0 ; j < size ; j ++ ){
											if ( vec [i][j] == ES ){
												vec [i][j] = ' ' ;
											}
										}
									}
									E_S es = EnemySpaceship ( size ) ;
									es_t = es.type ;
									int row = 0 ;
									int col = es.loc ;
									
									if ( es_t == 'd' ){
										vec [row][col] = ES ;
										es_h = 1 ;
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
									}
								}
							}
							else {
								vec [i][j] = ' ' ;
								vec [i - 1][j] = '^' ;
							}
						}
					}
				}
			}
			
			for ( int j = ( size - 1 ) ; j >= 0 ; j -- ){ //for our spaceship
				if ( vec [ size - 1 ][j] == OS ){
					if ( vec [ size - 1 ][ j + 1 ] == ES ){
						heal -- ;
						for ( int i = 0 ; i < size ; i ++ ){
							for ( int j = 0 ; j < size ; j ++ ){
								if ( vec [i][j] == ES ){
									vec [i][j] = ' ' ;
								}
							}
						}
						E_S es = EnemySpaceship ( size ) ;
						es_t = es.type ;
									
						int row = 0 ;
						int col = es.loc ;
									
						if ( es_t == 'd' ){
							vec [row][col] = ES ;
							es_h = 1 ;
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
						}
					}
					if ( ( j + 1 ) == size ){
						vec [ size - 2 ][j] = '^' ;
					}
					else {
						vec [ size - 1 ][j] = ' ' ;
						vec [ size - 1 ][j + 1] = OS ;
						vec [ size - 2 ][j + 1] = '^' ;
					}
				}
			}
			
			for ( int i = ( size - 1 ) ; i >= 0 ; i -- ){ // for enemy spaceship
				for ( int j = ( size - 1 ) ; j >= 0 ; j -- ){
					if ( vec [i][j] == ES ){	
						if ( ( i + 1 ) == size ){
							vec [i][j] = ' ' ;
						}
						else {
							if ( vec [i + 1][j] == '^' ){
								vec [i][j] = ' ' ;
								vec [i + 1][j] = ES ;
								es_h -- ;
								if ( es_h == 0 ){
									
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
									for ( int i = 0 ; i < size ; i ++ ){
										for ( int j = 0 ; j < size ; j ++ ){
											if ( vec [i][j] == ES ){
												vec [i][j] = ' ' ;
											}
										}
									}
									E_S es = EnemySpaceship ( size ) ;
									es_t = es.type ;
									
									int row = 0 ;
									int col = es.loc ;
									
									if ( es_t == 'd' ){
										vec [row][col] = ES ;
										es_h = 1 ;
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
									}
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
		}
		
		if ( input == 'l' ){
			
			for ( int i = 0 ; i < size ; i ++ ){ //for bullet
				for ( int j = 0 ; j < size ; j ++ ){
					if ( vec [i][j] == '^' ){
						if ( ( i - 1 ) == -1 ){
							vec [i][j] = ' ' ;
						}
						else {
							if ( vec [i - 1][j] == ES ){
								vec [i][j] = ' ' ;
								es_h -- ;
								if ( es_h == 0 ){
									
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
									for ( int i = 0 ; i < size ; i ++ ){
										for ( int j = 0 ; j < size ; j ++ ){
											if ( vec [i][j] == ES ){
												vec [i][j] = ' ' ;
											}
										}
									}
									E_S es = EnemySpaceship ( size ) ;
									es_t = es.type ;
									
									int row = 0 ;
									int col = es.loc ;
									
									if ( es_t == 'd' ){
										vec [row][col] = ES ;
										es_h = 1 ;
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
									}
								}
							}
							else {
								vec [i][j] = ' ' ;
								vec [i - 1][j] = '^' ;
							}
						}
					}
				}
			}
			
			for ( int j = 0 ; j < size ; j ++ ){ //for our spaceship
				if ( vec [ size - 1 ][j] == OS ){
					if ( vec [ size - 1 ][ j - 1 ] == ES ){
						heal -- ;
						for ( int i = 0 ; i < size ; i ++ ){
							for ( int j = 0 ; j < size ; j ++ ){
								if ( vec [i][j] == ES ){
									vec [i][j] = ' ' ;
								}
							}
						}
						E_S es = EnemySpaceship ( size ) ;
						es_t = es.type ;
									
						int row = 0 ;
						int col = es.loc ;
									
						if ( es_t == 'd' ){
							vec [row][col] = ES ;
							es_h = 1 ;
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
						}
					}
					if ( ( j - 1 ) == -1 ){
						vec [ size - 2 ][j] = '^' ;
					}
					else {
						vec [ size - 1 ][j] = ' ' ;
						vec [ size - 1 ][j - 1] = OS ;
						vec [ size - 2 ][j - 1] = '^' ;
					}
				}
			}
			
			for ( int i = ( size - 1 ) ; i >= 0 ; i -- ){ // for enemy spaceship
				for ( int j = ( size - 1 ) ; j >= 0 ; j -- ){
					if ( vec [i][j] == ES ){
						if ( ( i + 1 ) == size ){
							vec [i][j] = ' ' ;
						}
						else {
							if ( vec [i + 1][j] == '^' ){
								vec [i][j] = ' ' ;
								vec [i + 1][j] = ES ;
								es_h -- ;
								if ( es_h == 0 ){
									
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
									for ( int i = 0 ; i < size ; i ++ ){
										for ( int j = 0 ; j < size ; j ++ ){
											if ( vec [i][j] == ES ){
												vec [i][j] = ' ' ;
											}
										}
									}
									E_S es = EnemySpaceship ( size ) ;
									es_t = es.type ;
									
									int row = 0 ;
									int col = es.loc ;
									
									if ( es_t == 'd' ){
										vec [row][col] = ES ;
										es_h = 1 ;
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
									}
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
		}
		
		if ( input == 'i' ){
			
			for ( int i = 0 ; i < size ; i ++ ){ //for bullet
				for ( int j = 0 ; j < size ; j ++ ){
					if ( vec [i][j] == '^' ){
						if ( ( i - 1 ) == -1 ){
							vec [i][j] = ' ' ;
						}
						else {
							if ( vec [i - 1][j] == ES ){
								vec [i][j] = ' ' ;
								es_h -- ;
								if ( es_h == 0 ){
									
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
									for ( int i = 0 ; i < size ; i ++ ){
										for ( int j = 0 ; j < size ; j ++ ){
											if ( vec [i][j] == ES ){
												vec [i][j] = ' ' ;
											}
										}
									}
									E_S es = EnemySpaceship ( size ) ;
									es_t = es.type ;
									
									int row = 0 ;
									int col = es.loc ;
									
									if ( es_t == 'd' ){
										vec [row][col] = ES ;
										es_h = 1 ;
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
									}
								}
							}
							else {
								vec [i][j] = ' ' ;
								vec [i - 1][j] = '^' ;
							}
						}
					}
				}
			}
			
			for ( int j = 0 ; j < size ; j ++ ){ //for our spaceship
				if ( vec [ size - 1 ][j] == OS ){
					vec [ size - 2 ][j] = '^' ;
				}
			}
			
			for ( int i = ( size - 1 ) ; i >= 0 ; i -- ){ // for enemy spaceship
				for ( int j = ( size - 1 ) ; j >= 0 ; j -- ){
					if ( vec [i][j] == ES ){						
						if ( ( i + 1 ) == size ){
							vec [i][j] = ' ' ;
						}
						else {
							if ( vec [i + 1][j] == '^' ){
								vec [i][j] = ' ' ;
								vec [i + 1][j] = ES ;
								es_h -- ;
								if ( es_h == 0 ){
									
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
									for ( int i = 0 ; i < size ; i ++ ){
										for ( int j = 0 ; j < size ; j ++ ){
											if ( vec [i][j] == ES ){
												vec [i][j] = ' ' ;
											}
										}
									}
									E_S es = EnemySpaceship ( size ) ;
									es_t = es.type ;
									
									int row = 0 ;
									int col = es.loc ;
									
									if ( es_t == 'd' ){
										vec [row][col] = ES ;
										es_h = 1 ;
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
									}
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
		}
		flag = finding ( vec , size , ES ) ;
		if ( flag == true ){
			heal -- ;
			E_S es = EnemySpaceship ( size ) ;
			es_t = es.type ;
				
			int row = 0 ;
			int col = es.loc ;
					
			if ( es_t == 'd' ){
				vec [row][col] = ES ;
				es_h = 1 ;
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
			}
		}
		
		if ( input == 'm' ){
			
			input = menu () ;
			
			if ( input == 'n' ){
				NewGame ( size , OS , ES ) ;
			}
			
			if ( input == 'c' ){
			}
			
			if ( input == 's' ){
			}
			
			if ( input == 'e' ){
				exit (0) ;
			}
		}
	}
	
}

bool finding ( vector < vector < char > > vec , int size , char ES ){
	
	bool flag = true ;
	
	for ( int i = 0 ; i < size ; i ++ )
		for ( int j = 0 ; j < size ; j ++ )
			if ( vec [i][j] == ES )
				flag = false ;
				
	return flag ;
}
