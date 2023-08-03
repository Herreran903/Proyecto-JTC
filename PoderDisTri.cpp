/**
Archivo: PoderDistri.cpp
Autores: Nicolas Herrera <herrera.nicolas@correounivalle.edu.co>
         Hernán Cisneros <hernan.cisneros@correounivalle.edu.co>
         Samuel Galindo <samuel.galindo@correounivalle.edu.co>
Fecha creacion: 2022-07-02
fecha ultima modificacion: 2022-08-07
Licencia: GNU-GPL
Version: 11
*/

#include "PoderDisTri.h"

PoderDisTri::PoderDisTri(int _iniX, int _iniY)
{
	x = _iniX;
	y = _iniY;
}

PoderDisTri::~PoderDisTri()
{
 
}

void PoderDisTri::pintarPoder()
{
	mapearConsola(x, y); printf("%c", "x");
}
		
void PoderDisTri::efectoPoder(Tanque &_tanque)
{
	_tanque.activarPoderDisTri();
}