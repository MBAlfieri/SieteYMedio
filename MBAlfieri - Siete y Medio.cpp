#include <iostream>
#include <cstdlib>
#include <ctime>
using namespace std;

int main(int argc, char *argv[]) {
	
	int mazo[4][10] =  {{1,2,3,4,5,6,7,10,11,12}, 
	{1,2,3,4,5,6,7,10,11,12},  //Basicamente, �ste es el mazo.
	{1,2,3,4,5,6,7,10,11,12},
	{1,2,3,4,5,6,7,10,11,12}};
	string palo[4] = {"Basto","Espada","Copa","Oro"}; //Decid� almacenar los palos aparte.
	int posicioncartaalazar = 0; // Me va a permitir elegir una fila al azar.
	int posicioncartaalazar2 = 0; // Me va a permitir elegir una columna al azar.
	int selecciondepalo = 0; // Me va a permitir elegir un palo.
	int cartaalazar = 0; // Me va a permitir guardar el valor de la carta al azar, para luego hacer la sumatoria
	float sumatoria = 0; // Guarda los valores de cada carta que sale, para luego ir sum�ndolos.
	float sumatoriapc = 0; //Guarda los valores de las cartas que la Computadora va sacando, para luego ir sum�ndolos.
	int seleccionmenu = 0; // Selecciona las opciones del men�
	int selecciondurantejuego = 0; //Selecciona las opciones una vez que se inici� el juego.	
	srand (time(NULL));
	
	//introducci�n
	cout << "**************************************************************" << endl;
	cout << "*                    ���Bienvenido!!!                        *" << endl;
	cout << "*      �Usted ha iniciado una partida de Siete y Medio!      *" << endl;
	cout << "*                    �Que desea hacer?                       *" << endl;
	cout << "**************************************************************" << endl << endl << endl;
	
	//Menu
	while((seleccionmenu>0)||(seleccionmenu<6)){
		
		cout << "**************************************************************" << endl;
		cout << "*     !Presione la tecla -1- para jugar!                     *" << endl;
		cout << "*     !Presione la tecla -2- para leer las instrucciones!    *" << endl;
		cout << "*     !Presione la tecla -3- para ver un DEMO del juego!     *" << endl;
		cout << "*     !Presione la tecla -4- para ver los cr�ditos!          *" << endl;
		cout << "*     !Presione la tecla -5- para salir!                     *" << endl;
		cout << "**************************************************************" << endl << endl << endl;
		
		cin >> seleccionmenu;	
		
		if((seleccionmenu>0)&&(seleccionmenu<6)){
			
			switch(seleccionmenu){
				//-----------------------------------------------------------------------------------------------Inicia el c�digo para la partida			
			case 1: //inicio de la partida.
				cout << "**************************************************************" << endl;
				cout << "*                   �Listo para jugar?                       *" << endl;
				cout << "*     Presione la tecla -1- para recibir tu primera carta!   *" << endl;
				cout << "*                   ���Buena suerte!!!                       *" << endl;
				cout << "**************************************************************" << endl << endl << endl;
				
				while((selecciondurantejuego>0)||(selecciondurantejuego<3)){
					
					cin >> selecciondurantejuego;		
					if(selecciondurantejuego==1){
						
						posicioncartaalazar = rand()%4; // Elige una fila al azar
						posicioncartaalazar2 = rand()%10; // Elige una columna al azar
						selecciondepalo = rand()%4; // Elige un palo al azar
						cartaalazar = mazo[posicioncartaalazar][posicioncartaalazar2];
						
						cout <<"      Tu carta al azar es: " << cartaalazar << " de " << palo[selecciondepalo] << endl;
						
						if(cartaalazar<8&&cartaalazar>0){ //Si la carta va del 1 al 7
							sumatoria += cartaalazar;
							cout << "      Suma total: " << sumatoria << endl << endl;
						}
						
						else{ //Si la carta va de 10 a 12.
							sumatoria += 0.5;
							cout << "      Suma total: " << sumatoria << endl << endl;
						}
						
						
						if(sumatoria>7.50){ //Si el jugador se pasa.
							cout <<"**************************************************************" << endl;
							cout <<"*               �Te pasaste! �Has perdido!                   *" << endl;
							cout <<"*              �M�s suerte para la pr�xima!                  *" << endl;
							cout <<"*              �Volvamos al men� principal!                  *" << endl;
							cout <<"**************************************************************" << endl << endl << endl;
							sumatoria = 0; //Como el jugador perdi�, dejo la sumatoria en cero de nuevo.
							break;							
						} 
						
						cout <<"**************************************************************" << endl;	
						cout <<"*     �Que desea hacer?                                      *" << endl;
						cout <<"*     Presiona la tecla -1- para recibir otra carta.         *" << endl;
						cout <<"*     Presione la tecla -2- para plantarse.                  *" << endl;
						cout <<"**************************************************************" << endl << endl << endl;
					}						
					if(selecciondurantejuego==2){
						cout <<"**************************************************************" << endl;
						cout <<"*     �Te has plantado!                                      *" << endl;
						cout <<"*     �Es el turno de la Computadora!                        *" << endl;
						cout <<"**************************************************************" << endl << endl << endl;
						
						
						while(sumatoriapc<6){ //Permit� que la Computadora siga pidiendo cartas hasta que llegue a 6, para que no sea tan dificil.
							posicioncartaalazar = rand()%4; // Elige una fila al azar
							posicioncartaalazar2 = rand()%10; // Elige una columna al azar
							selecciondepalo = rand()%4; // Elige un palo al azar
							cartaalazar = mazo[posicioncartaalazar][posicioncartaalazar2];
							cout <<"     La carta de la Computadora es: " << cartaalazar << " de " << palo[selecciondepalo] << endl << endl;
							
							if(cartaalazar<8&&cartaalazar>0){ //Si la carta va del 1 al 7
								sumatoriapc += cartaalazar;
								cout << "     Suma total de la Computadora: " << sumatoriapc << endl << endl;
							}
							
							else{ //Si la carta va de 10 a 12.
								sumatoriapc += 0.5;
								cout << "     Suma total de la Computadora: " << sumatoriapc << endl << endl;
							}
						}	
						cout <<"**************************************************************" << endl;
						cout <<"*     �La Computadora ha decidido detenerse!                 *" << endl;
						cout <<"**************************************************************" << endl << endl << endl;						
						
						if((sumatoriapc>7.50)||(sumatoria>sumatoriapc)){
							cout <<"**************************************************************" << endl;
							cout <<"*                 �����Has ganado!!!!!                       *" << endl;
							cout <<"*            �Te atreves a jugarle una revancha? ;)          *" << endl;
							cout <<"*                �Volvamos al men� principal!                *" << endl;
							cout <<"**************************************************************" << endl << endl << endl;
							break;
						}
						
						if((sumatoriapc>sumatoria)||(sumatoriapc==sumatoria)){
							cout <<"**************************************************************" << endl;
							cout <<"*                �La Computadora ha ganado!                  *" << endl;
							cout <<"*               �M�s suerte para la pr�xima!                 *" << endl;
							cout <<"*             �Te atreves a jugarle una revancha?            *" << endl;
							cout <<"*                �Volvamos al men� principal!                *" << endl;
							cout <<"**************************************************************" << endl << endl << endl;
							break;
						}
						
					}
				}	
				sumatoria = 0; //Como termin� la ronda, dejo las sumatorias en cero de nuevo.
				sumatoriapc = 0;
				break;
				//-----------------------------------------------------------------------------------------------Termina el c�digo para la partida.			
			case 2: //instrucciones
				cout << "**************************************************************" << endl;
				cout << "*                   Instrucciones:                           *" << endl;
				cout << "* El objetivo principal del programa es acercarse a 7 y medio*" << endl;
				cout << "* sin pasarse. Al inicio del juego usted recibir� una carta. *" << endl;
				cout << "* A partir de ese momento, puede decidir si quiere pedir     *" << endl;	
				cout << "* otra carta, o plantarse.                                   *" << endl;	
				cout << "* Una vez que termine su turno, la computadora comenzar� a   *" << endl;
				cout << "* jugar. Si usted se pasa de 7 y medio, o si empata, la      *" << endl;
				cout << "* Computadora ganar�. Si la sumatoria de sus cartas supera   *" << endl;
				cout << "* las de la Computadora, habr� ganado.                       *" << endl;
				cout << "* Los valores de las cartas son:                             *" << endl;
				cout << "* 1,2,3,4,5,6 y 7 ---- > Mantienen su valor normal.          *" << endl;
				cout << "* 10, 11 y 12 -------- > Valen medio.                        *" << endl;
				cout <<	"* Por ejemplo, si usted obtiene las cartas: 2, 4, 10 y 11,   *" << endl;
				cout <<	"* la suma total es 7, ya que 2+4 = 6, mientras que 10 y 11   *" << endl;
				cout << "* valen medio, por lo tanto, medio+medio = 1.                *" << endl;
				cout << "* Recuerde que puede ver un DEMO del juego presionando la    *" << endl;
				cout << "* tecla -3-. �Muy �til si a�n no queda en claro c�mo funciona*" << endl;
				cout << "* el programa!                                               *" << endl;
				cout << "* �Ha entendido las reglas? Entonces, �an�mese a jugar!      *" << endl;
				cout << "*             �Volvamos al menu principal!                   *" << endl;
				cout << "**************************************************************" << endl << endl;
				break;
				
			case 3: // Demo. M�s que nada es puro texto, para que el usuario se de una idea de como funciona el juego.
				cout << "**************************************************************" << endl;
				cout << "*                ��Ha iniciado el DEMO!!                     *" << endl;
				cout << "**************************************************************" << endl << endl << endl;
				cout << "      Tu carta al azar es: 2 de Oro                           " << endl;
				cout << "      Suma total: 2                                           " << endl << endl;
				cout << "**************************************************************" << endl;	
				cout << "*     �Que desea hacer?                                      *" << endl;
				cout << "*     Presiona la tecla -1- para recibir otra carta.         *" << endl;
				cout << "*     Presione la tecla -2- para plantarse.                  *" << endl;
				cout << "**************************************************************" << endl << endl << endl;
				cout << "1"<< endl;
				cout << "      Tu carta al azar es: 4 de Espada                         " << endl;
				cout << "      Suma total: 6                                            " << endl << endl;
				cout << "**************************************************************" << endl;	
				cout << "*     �Que desea hacer?                                      *" << endl;
				cout << "*     Presiona la tecla -1- para recibir otra carta.         *" << endl;
				cout << "*     Presione la tecla -2- para plantarse.                  *" << endl;
				cout << "**************************************************************" << endl << endl << endl;
				cout << "1" << endl;
				cout << "      Tu carta al azar es: 11 de Basto                        " << endl;
				cout << "      Suma total: 6.50                                        " << endl << endl;
				cout << "**************************************************************" << endl;	
				cout << "*     �Que desea hacer?                                      *" << endl;
				cout << "*     Presiona la tecla -1- para recibir otra carta.         *" << endl;
				cout << "*     Presione la tecla -2- para plantarse.                  *" << endl;
				cout << "**************************************************************" << endl << endl << endl;
				cout << "2" << endl;
				cout <<"**************************************************************" << endl;
				cout <<"*     �Te has plantado!                                      *" << endl;
				cout <<"*     �Es el turno de la Computadora!                        *" << endl;
				cout <<"**************************************************************" << endl << endl << endl;
				cout <<"     La carta de la Computadora es: 2 de Copa                 " << endl;
				cout <<"     Suma total de la Computadora:  2                         " << endl;
				cout <<"     La carta de la Computadora es: 3 de Oro                  " << endl;
				cout <<"     Suma total de la Computadora:  5                         " << endl;
				cout <<"     La carta de la Computadora es: 12 de Copa                " << endl;
				cout <<"     Suma total de la Computadora:  5.50                      " << endl;
				cout <<"     La carta de la Computadora es: 11 de Basto               " << endl;
				cout <<"     Suma total de la Computadora:  6                         " << endl << endl ;
				cout <<"**************************************************************" << endl;
				cout <<"*     �La Computadora ha decidido detenerse!                 *" << endl;
				cout <<"**************************************************************" << endl << endl << endl;
				cout <<"**************************************************************" << endl;
				cout <<"*                 �����Has ganado!!!!!                       *" << endl;
				cout <<"**************************************************************" << endl << endl << endl;
				cout <<"**************************************************************" << endl;
				cout <<"*               ��Ha terminado el DEMO!!                     *" << endl;
				cout <<"*            �Ha quedado un poco m�s claro?                  *" << endl;
				cout <<"*                 ��Atr�vase a jugar!!                       *" << endl;
				cout << "*             �Volvamos al menu principal!                  *" << endl;
				cout <<"**************************************************************" << endl << endl << endl;
				
				break;
				
			case 4: // Creditos
				cout << "**************************************************************" << endl;
				cout << "*                    ��Cr�ditos!!                            *" << endl;
				cout << "**************************************************************" << endl;
				cout << "* Alumna: Micaela B. Alfieri                                 *" << endl;
				cout << "* Carrera: TEC en Dise�o y Programaci�n de Videojuegos.      *" << endl;
				cout << "* Materia: Introducci�n a la Programaci�n.                   *" << endl;
				cout << "* Instituci�n: Universidad Nacional del Litoral.             *" << endl;
				cout << "* A�o: 2019                                                  *" << endl;
				cout << "* Agradecimientos especiales: al Caf�, por ayudarme a estar  *" << endl;
				cout << "* despiert-- zzzZZZZZZZZ.....                                *" << endl;
				cout << "*             �Volvamos al menu principal!                   *" << endl;
				cout << "**************************************************************" << endl << endl;
				break;
				
			case 5: // Finalizar el juego
				cout << "**************************************************************" << endl;
				cout << "*                   �Es hora de irse? :(                     *" << endl;
				cout << "*         �Muchas gracias por jugar a Siete y Medio!         *" << endl;
				cout << "*                �Esperamos verlo pronto!                    *" << endl;
				cout << "*                Finalizando el programa......               *" << endl;
				cout << "**************************************************************" << endl;
				return 0;
			}
		}
	}
	return 0;
}
