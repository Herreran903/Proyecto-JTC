/**
Archivo: Obstaculo.cpp
Autores: Nicolas Herrera <herrera.nicolas@correounivalle.edu.co>
         Hernán Cisneros <hernan.cisneros@correounivalle.edu.co>
         Samuel Galindo <samuel.galindo@correounivalle.edu.co>
Fecha creacion: 2022-07-02
fecha ultima modificacion: 2022-08-07
Licencia: GNU-GPL
Version: 11
*/

#include "Obstaculo.h"


Obstaculo::~Obstaculo()
{

}

void Obstaculo::mapearConsola(int _x ,int _y)
{
	HANDLE hCon;
	hCon = GetStdHandle(STD_OUTPUT_HANDLE);
	COORD dwPos;
	dwPos.X = _x;
	dwPos.Y = _y;
	
	SetConsoleCursorPosition(hCon, dwPos);
}

void Obstaculo::moverObstaculo()
{
	borrarObstaculo();
	y++;
	pintarObstaculo();
}

int Obstaculo::getX()
{
	return x;
}


