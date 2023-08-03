/**
Archivo: PoderInvenci.cpp
Autores: Nicolas Herrera <herrera.nicolas@correounivalle.edu.co>
         Hernán Cisneros <hernan.cisneros@correounivalle.edu.co>
         Samuel Galindo <samuel.galindo@correounivalle.edu.co>
Fecha creacion: 2022-07-02
fecha ultima modificacion: 2022-08-07
Licencia: GNU-GPL
Version: 11
*/

#include "PoderInvenci.h"

PoderInvenci::PoderInvenci(int _iniX, int _iniY)
{
	x = _iniX;
	y = _iniY;
}

PoderInvenci::~PoderInvenci()
{
		
}

void PoderInvenci::pintarPoder()
{
	mapearConsola(x, y); printf("%c", 157);
}

void PoderInvenci::efectoPoder(Tanque &_tanque)
{
	_tanque.activarPoderInvenci();
}