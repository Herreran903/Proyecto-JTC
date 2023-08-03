/**
Archivo: Proyectiles.cpp
Autores: Nicolas Herrera <herrera.nicolas@correounivalle.edu.co>
         Hernán Cisneros <hernan.cisneros@correounivalle.edu.co>
         Samuel Galindo <samuel.galindo@correounivalle.edu.co>
Fecha creacion: 2022-07-02
fecha ultima modificacion: 2022-08-07
Licencia: GNU-GPL
Version: 11
*/

#include "Proyectiles.h"

Proyectil::Proyectil(int _iniX, int _iniY)
{
	x = _iniX;
	y = _iniY;
}

Proyectil::~Proyectil()
{
	
}

void Proyectil::mapearConsola()
{
	HANDLE hCon;;
	hCon = GetStdHandle(STD_OUTPUT_HANDLE);
	COORD dwPos;
	dwPos.X = x;
	dwPos.Y = y;
	
	SetConsoleCursorPosition(hCon, dwPos);
}

void Proyectil::pintarProyectil()
{
	mapearConsola(); printf(".");
}

void Proyectil::borrarProyectil()
{
	mapearConsola(); printf(" ");
}

void Proyectil::moverProyectil()
{
	borrarProyectil();
	y--;
	pintarProyectil();
}

bool Proyectil::chocoConLimite(int _limiteSuperior)
{
	if(y == _limiteSuperior)
	{
		borrarProyectil();
		return true;
	}
	else
	{
		return false;
	}

}

int Proyectil::getX()
{
	return x;
}

int Proyectil::getY()
{
	return y;
}


