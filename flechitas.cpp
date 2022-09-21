//LIBRERIAS IMPORTADAS

#include <iostream>
#include <stdlib.h>
#include <conio.h>
#include <string.h>
#include <math.h>
#include <unistd.h>

using namespace std;




//DECLARACION DE ASCCI TECLAS "FLECHITAS"

#define KEY_UP 72
#define KEY_DOWN 80
#define KEY_RIGHT 77 
#define KEY_LEFT 75




//DECLARACION DE CONFIG JUEGO LARGO Y CORTO

#define LARGO 50
#define CORTO 10




//DATOS DE SCORES (PUNTAJES)

char scores[20]={10,7,9,5};
char names[20][20]={"Matias","Naiara","Pablo","Mauro"};

char contS=4;
char contN=4;






//FUNCION PARA IMPRIMIR EN PANTALLA DIRECION DE LA TECLA A PRESIONAR

void imprimirFlecha(int flecha){
	
	system("cls");
	printf("\n\n");
	switch(flecha){
		case KEY_UP: // Número del teclado 72
			printf("\t ----------- \n");
			printf("\t|     ^     | \n");
			printf("\t|     |     | \n");
			printf("\t ----------- \n");
			break;
		case KEY_DOWN: // Número del teclado 80
			printf("\t ----------- \n");
			printf("\t|     |     | \n");
			printf("\t|     v     | \n");
			printf("\t ----------- \n");
			break;
		case KEY_LEFT: // Número del teclado 75
			printf("\t ------------ \n");
			printf("\t|     <--    | \n");
			printf("\t ------------ \n");
			break;
		case KEY_RIGHT: // Número del teclado 77
			printf("\t ------------ \n");
			printf("\t|     -->    | \n");
			printf("\t ------------ \n");
			break;
	}
}








//FUNCION CUENTA REGRESIVA 

void cuentaRegresiva(){
	
	system("cls");
	
	for(int i=3;i>0;i--){
		printf("\nEmpieza en ...\a ");
		printf("%i",i);
		sleep(1);
		system("cls");
	}
	
	printf("\nYaaaaaa!\a");
	sleep(1);
}






//BASE CENTRAL DEL JUEGO, GENERA POSICION RANDOM, ESPERA EL INPUT - FLECHA CORRECTA Y GUARDA UN SCORE FINAL

int random(int opc){
	
	int tecla=0;
	int num=0;
	int movimientos,random_number,  opciones[4] = {72, 80, 77, 75}, score=0, fail=0;
	bool LOGGER = true;
	char respuesta;
	
	
	if(opc==1){
		movimientos=CORTO;
	}
	else{
		movimientos=LARGO;
	}
	
	
	system("cls");
	printf("\n ---------------------------------------------------------------------");
	printf("\n|   Empieza el juego, intenta acertar la direccion de las flechas...  |");
	printf("\n|                                                                     |");
	printf("\n|   Movimientos: %i                                                   |",movimientos);
	printf("\n ---------------------------------------------------------------------\n\n\n\n");
	system("pause");
	
	
	
	cuentaRegresiva();
	
	
	
	for (int i=0; i< movimientos ;i++) {
		
		
		random_number = rand()%4;
		
		
		if (LOGGER){
			
			
			imprimirFlecha(opciones[random_number]);
			
			
			getch();
			switch(tecla=getch()){
				
				
				case KEY_UP: // Número del teclado 72
					num=72;
					break;
				case KEY_DOWN: // Número del teclado 80
					num=80;
					break;
				case KEY_LEFT: // Número del teclado 75
					num=75;
					break;
				case KEY_RIGHT: // Número del teclado 77
					num=77;
					break;
			}
			
			
			
			if(opciones[random_number]==num){
				score=score+1;
			}
			else{
				fail=fail+1;
			}
		}
	}

	
	
	system("cls");
	printf("\t\n -------------------------------");
	printf("\t\n|   PUNTUACION: %i, ERRORES: %i  |", score,fail);
	printf("\t\n -------------------------------\n\n");
	
	
	
	printf("|| REGISTRAR PUNTAJE..\n\n \tNombre (sin espacios): ");
	scanf("%s", &names[contN]);
	scores[contS]=score;
	contS+=1;
	contN+=1;
	printf("\n\n\tGUARDADO!! \n\n", names[contN-1],scores[contS-1]);
	
	

	system("pause");
	
}






//MENU DE CREDITOS

void creditos(){
	system("cls");
	printf("\t\n\n ---------------------------------------------------------------");
	printf("\t\n|                                                               |");
	printf("\t\n| Juego creado por Pablo Candela en la materia 'Laboratorio'... |");
	printf("\t\n|                                                               |");
	printf("\t\n| Tiempo estimado de creacion: 5 horas aproximadamente...       |");
	printf("\t\n|                                                               |");
	printf("\t\n| Contacto: pabloccandela@gmail.com                             |");
	printf("\t\n|                                                               |");
	printf("\t\n ---------------------------------------------------------------\n\n");
	system("pause");
}








// FUNCION QUE LISTA LOS SCORE DE CADA JUGADOR, CON SCORE DE MUESTRA PRE DEFINIDOS

void scoreList(){
	
	system("cls");
	printf("=====  Lista de Puntajes =====\n\n");
	
	for(int i=0; i<strlen(scores);i++){
		printf("||  %s ==> %i\n",names[i],scores[i]);
	}
	
	printf("\n==============================\n\n");
	
	system("pause");
}








//SUBMENU

void menu2(){
	int pos=1,c, opc=0;
	char arrow[]="-->";
	
	char opc1[]="   ";
	strcpy(opc1, arrow);
	char opc2[]="   ";
	char opc3[]="   ";

	
	
	
	while(opc!=3){
		system("cls");
		printf("\n\n	----------- BINARY ARROWS -----------");
		printf("\n	||                                     ||");
		printf("\n	|| %s   1) Corto (10 movimientos)     ||",opc1);
		printf("\n	|| %s   2) Largo (50 Movimientos)     ||",opc2);
		printf("\n	|| %s   3) Atras                      ||",opc3);
		printf("\n	||                                     ||");
		printf("\n	-----------------------------------------\n\n");
		
		//printf("\n\n	Opcion: ");
		//scanf("%i", &opc);
		
		switch((c=getch())) {
			
	        case KEY_UP:
	        	if(pos==1){
	        		pos=3;
				}else{
					pos = pos - 1;	
				}
				
	            break;
	            
	        case KEY_DOWN:
	            if(pos==3){
	        		pos=1;
				}else{
					pos = pos + 1;	
				}
	            break; 
				
			case KEY_RIGHT:
				if (pos==3){
					opc=3;
				}else{
					random(pos);
				}
	    }
		
    
		switch(pos){
			case 1:
				strcpy(opc1,arrow);
				strcpy(opc2,"   ");
				strcpy(opc3,"   ");

				
				break;
			
			case 2:
				strcpy(opc1,"   ");
				strcpy(opc2,arrow);
				strcpy(opc3,"   ");

				
				break;
			
			case 3:
				strcpy(opc1,"   ");
				strcpy(opc2,"   ");
				strcpy(opc3,arrow);
				
				break;
		}
    }
}








//MENU PRINCIPAL - MAIN 

int main(){

	int pos=1,c, opc=0;
	char arrow[]="-->";
	
	char opc1[]="   ";
	strcpy(opc1, arrow);
	char opc2[]="   ";
	char opc3[]="   ";
	char opc4[]="   ";
	char opc5[]="   ";
	char opc6[]="   ";
	char opc7[]="   ";
	
	
	
	while(opc!=4){
		system("cls");
		printf("\n\n	------------- BINARY ARROWS -------------");
		printf("\n	||                                     ||");
		printf("\n	|| %s   1) Jugar                      ||",opc1);
		printf("\n	|| %s   2) Score                      ||",opc2);
		printf("\n	|| %s   3) Creditos                   ||",opc3);
		printf("\n	|| %s   4) Salir                      ||",opc4);
		printf("\n	||                                     ||");
		printf("\n	-----------------------------------------\n\n");
		
		//printf("\n\n	Opcion: ");
		//scanf("%i", &opc);
		
		switch((c=getch())) {
			
	        case KEY_UP:
	        	if(pos==1){
	        		pos=4;
				}else{
					pos = pos - 1;	
				}
				
	            break;
	            
	        case KEY_DOWN:
	            if(pos==4){
	        		pos=1;
				}else{
					pos = pos + 1;	
				}
	            break; 
				
			case KEY_RIGHT:
				if (pos==4){
					opc=4;
				}
				if(pos==1){
					menu2();
				}
				if(pos==2){
					scoreList();
				}
				if(pos==3){
					creditos();
				}
	    }
		
    
		switch(pos){
			case 1:
				strcpy(opc1,arrow);
				strcpy(opc2,"   ");
				strcpy(opc3,"   ");
				strcpy(opc4,"   ");
				strcpy(opc5,"   ");
				strcpy(opc6,"   ");
				strcpy(opc7,"   ");
				
				break;
			
			case 2:
				strcpy(opc1,"   ");
				strcpy(opc2,arrow);
				strcpy(opc3,"   ");
				strcpy(opc4,"   ");
				strcpy(opc5,"   ");
				strcpy(opc6,"   ");
				strcpy(opc7,"   ");
				
				break;
			
			case 3:
				strcpy(opc1,"   ");
				strcpy(opc2,"   ");
				strcpy(opc3,arrow);
				strcpy(opc4,"   ");
				strcpy(opc5,"   ");
				strcpy(opc6,"   ");
				strcpy(opc7,"   ");
				
				break;
			
			case 4:
				strcpy(opc1,"   ");
				strcpy(opc2,"   ");
				strcpy(opc3,"   ");
				strcpy(opc4,arrow);
				strcpy(opc5,"   ");
				strcpy(opc6,"   ");
				strcpy(opc7,"   ");
				
				break;
				
			default:
				break;
		}
    }
}
