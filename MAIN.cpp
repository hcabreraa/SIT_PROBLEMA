#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include <windows.h>
#include <iostream>
#define N 50
#define P 3
#define T 3
using namespace std;

void dibujarCuadro(int x1,int y1,int x2,int y2);
void gotoxy(int x,int y);
void limpia();
void menu();
int verpyme();

string search;
int search_break;
#include "PYME.cpp"
PYME pyme_arr[P];
#include "Trabajador.cpp"
Trabajador trabajador_arr[T];
int contarPYME = -1;
int contarTrabajadores = -1;

int main(){
	system("mode con: cols=80 lines=25");
	dibujarCuadro(0,0,78,24);
	dibujarCuadro(1,1,77,3);
	gotoxy(16,2); cout << "           I N V E N T A R I O";
	menu();
	getch();
	return 0;
}

void menu(){
	char op;
	do{
		limpia();
		gotoxy(3,6); cout << "  MENU PRINCIPAL";
		gotoxy(3,9); cout << "  (1) Agregar una PYME";
		gotoxy(3,11); cout << "  (2) Agregar un Trabajador";
		gotoxy(3,13); cout << "  (3) Consultar PYME";
		gotoxy(3,15); cout << "  (4) Consultar Trabajador";
		gotoxy(3,17); cout << "  (5) Cerrar";
		gotoxy(3,19); cout << "  Ingrese opcion: ";
		cin >> op;
		
		if(op!='1' && op!='2' && op!='3' && op!='4' && op!='5'){
			gotoxy(3,21); cout << "  Error al ingresar valores. Presione una tecla para volver a ingresar.";
			getch();
			gotoxy(3,22); cout << "                                                                       ";
			gotoxy(3,17); cout << "                                                                       ";
		}
			
	}while(op!='1' && op!='2' && op!='3' && op!='4' && op!='5');
	
	
	if (op=='1'){
		limpia(); 
		gotoxy(3,6);
		if (contarPYME < P-1){
			contarPYME += 1;
			pyme_arr[contarPYME].buildPYME();

		}
		else {
			cout << "  No quedan mas espacios.";
			gotoxy(3,8); cout << "  Presione una tecla para continuar.";
		}
		getch();
		menu();
	}
	

	if (op=='2'){
		limpia();
		gotoxy(3,6);
		if (contarPYME >= 0 && contarTrabajadores < W-1){
	    contarTrabajadores += 1;
 		trabajador_arr[contarTrabajadores].buildTrabajador();
		}
		else if (contarPYME <= 0){
			cout << "  No se pueden anadir trabajadores. Crea una PYME para empezar. << endl";
			gotoxy(3,8); cout << "  Presiona una tecla para continuar.";
		}
		else if (contarTrabajadores >= W-1){
			cout << "  No quedan mas espacios.";
			gotoxy(3,8); cout << "  Presiona una tecla para continuar.";
		}
		else {
			cout << "Error." << endl;
		}
		getch();  
		menu(); 
	}
	
	if (op=='3'){
		limpia();
		gotoxy(3,6); cout << "Introduzca el nombre de la PYME que desea consultar: " << endl;
		cin >> search;
		int i = verpyme();
		if (i >= 0){
			limpia();
			gotoxy(3,6);
			pyme_arr[i].printPYME();
			cout << "Presiona una tecla para continuar." << endl;
			getch(); 
		}
		else {
			limpia();
			gotoxy(3,6); 
			cout << "PYME no encontrada en los registros." << endl;
			cout << "Presiona una tecla para continuar." << endl;
			getch();  
		}
		menu();
	}

	if (op=='4'){
		search_break = 0;
		limpia();
		gotoxy(3,6); cout << "Introduzca el nombre del trabajador que desea buscar: " << endl;
    	cin >> search;
    	for (int i = 0; i < P; i++) {
			if (trabajador_arr[i].nombreTrabajador == search){
				search_break = 1;
				limpia();
				gotoxy(3,6);
				trabajador_arr[i].printTrabajador();
				cout << "Presiona una tecla para continuar." << endl;
				getch();  
			}
    	}
		if (search_break == 0){
				limpia();
				gotoxy(3,6); cout << "Trabajador no encontrado." << endl;
				cout << "Presiona una tecla para continuar." << endl;
				getch();  
		}
		menu(); 
	}
	
	if (op=='5')
		exit(0);
	
}

int verpyme(){
	int i;
    for (i = 0; i < P; i++) {
		if (pyme_arr[i].nombrePYME == search){
			return i;
		}
    }
	return -1;
}

void limpia(){
	int i,j;
	for(i=5;i<=23;i++){
		for(j=3;j<=76;j++){
			gotoxy(j,i); printf(" ");}}
}
void gotoxy(int x,int y){  
      HANDLE hcon;  
      hcon = GetStdHandle(STD_OUTPUT_HANDLE);  
      COORD dwPos;  
      dwPos.X = x;  
      dwPos.Y= y;  
      SetConsoleCursorPosition(hcon,dwPos);  
}
void dibujarCuadro(int x1,int y1,int x2,int y2){
    int i;
    for (i=x1;i<x2;i++){
		gotoxy(i,y1); cout << "-";
		gotoxy(i,y2); cout << "-";
    }

    for (i=y1;i<y2;i++){
		gotoxy(x1,i); cout << "-";
		gotoxy(x2,i); cout << "-";
    }
    
    gotoxy(x1,y1); cout << "-";
    gotoxy(x1,y2); cout << "-";
    gotoxy(x2,y1); cout << "-";
    gotoxy(x2,y2); cout << "-";
}
