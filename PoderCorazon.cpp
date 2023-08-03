/**
Archivo: PoderCorazon.cpp
Autores: Nicolas Herrera <herrera.nicolas@correounivalle.edu.co>
         Hernán Cisneros <hernan.cisneros@correounivalle.edu.co>
         Samuel Galindo <samuel.galindo@correounivalle.edu.co>
Fecha creacion: 2022-07-02
fecha ultima modificacion: 2022-08-07
Licencia: GNU-GPL
Version: 11
*/

#include "PoderCorazon.h"

PoderCorazon::PoderCorazon(int _iniX, int _iniY)
{
	x = _iniX;
	y = _iniY;	
}

PoderCorazon::~PoderCorazon()
{
		
}

void PoderCorazon::pintarPoder()
{
	mapearConsola(x,y); printf("%c", 3);
}

void PoderCorazon::efectoPoder(Tanque &_tanque)
{
	_tanque.ActivarPoderCorazon();
}