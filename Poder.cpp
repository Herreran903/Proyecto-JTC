/**
Archivo: Poder.cpp
Autores: Nicolas Herrera <herrera.nicolas@correounivalle.edu.co>
         Hernán Cisneros <hernan.cisneros@correounivalle.edu.co>
         Samuel Galindo <samuel.galindo@correounivalle.edu.co>
Fecha creacion: 2022-07-02
fecha ultima modificacion: 2022-08-07
Licencia: GNU-GPL
Version: 11
*/

#include "Poder.h"

Poder::~Poder()
{

}

void Poder::mapearConsola(int x, int y)
{
	HANDLE hCon;
	hCon = GetStdHandle(STD_OUTPUT_HANDLE);
	COORD dwPos;
	dwPos.X = x;
	dwPos.Y = y;
	
	SetConsoleCursorPosition(hCon, dwPos);
}

void Poder::borrarPoder()
{
	mapearConsola(x , y); printf(" ");
}

void Poder::moverPoder()
{
	borrarPoder();
	y++;	
	pintarPoder();
}

bool Poder::chocarConTanque(Tanque &_tanque)
{
	for(int cualCoordenadaXTan = -2; cualCoordenadaXTan < 3; cualCoordenadaXTan++)
	{
		for(int cualCoordenadaYTan = 1; cualCoordenadaYTan < 5; cualCoordenadaYTan++)	
		{
			if((_tanque.getX() + cualCoordenadaXTan == x and _tanque.getY() + cualCoordenadaYTan == y)) 
			{
				efectoPoder(_tanque);
				borrarPoder();
				_tanque.pintarTanque();
				return true;
			}		
		}
	}
	return false;
}

bool Poder::chocarConLimite(int _limiteInferior)
{
	if (_limiteInferior == y + 1)
	{
		borrarPoder();
		return true;
	}
	else
	{
		return false;
	}
}

