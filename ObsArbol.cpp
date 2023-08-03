/**
Archivo: ObsArbol.cpp
Autores: Nicolas Herrera <herrera.nicolas@correounivalle.edu.co>
         Hernán Cisneros <hernan.cisneros@correounivalle.edu.co>
         Samuel Galindo <samuel.galindo@correounivalle.edu.co>
Fecha creacion: 2022-07-02
fecha ultima modificacion: 2022-08-07
Licencia: GNU-GPL
Version: 11
*/

#include "ObsArbol.h"


ObsArbol::ObsArbol(int _iniX, int _iniY)
{
	x = _iniX;
	y = _iniY;
}

ObsArbol::~ObsArbol()
{

}

void ObsArbol::pintarObstaculo()
{  
	for(int cualCoordenadaX = -1; cualCoordenadaX < 2; cualCoordenadaX++)
	{
		for(int cualCoordenadaY = 1; cualCoordenadaY < 3; cualCoordenadaY++)	
		{
			mapearConsola(x + cualCoordenadaX, y - cualCoordenadaY); printf("%c", 177);	
		}
	}
	mapearConsola(x, y); printf("l");
}

void ObsArbol::borrarObstaculo()
{	
	for(int cualCoordenadaX = -1; cualCoordenadaX < 2; cualCoordenadaX++)
	{
		for(int cualCoordenadaY = 1; cualCoordenadaY < 3; cualCoordenadaY++)
		{
			mapearConsola(x + cualCoordenadaX, y - cualCoordenadaY); printf(" ");
		}
	}
    mapearConsola(x, y); printf(" ");
}
		
bool ObsArbol::chocarConTanque(Tanque &_tanque)
{	
	for(int cualCoordenadaXObs = -1; cualCoordenadaXObs < 2; cualCoordenadaXObs++)
	{
		for (int cualCoordenadaYObs = 1; cualCoordenadaYObs < 3; cualCoordenadaYObs++)
		{
			for(int cualCoordenadaXTan = -2; cualCoordenadaXTan < 3; cualCoordenadaXTan++)
			{
				for(int cualCoordenadaYTan = 1; cualCoordenadaYTan < 5; cualCoordenadaYTan++)	
				{
					if((_tanque.getX() + cualCoordenadaXTan == x + cualCoordenadaXObs and _tanque.getY() + cualCoordenadaYTan ==  y + cualCoordenadaYObs)) 
					{
						_tanque.quitarCorazones();
						borrarObstaculo();
						_tanque.pintarTanque();
						return true;
					}	
				}
			}
		}
	}
	return false;
}

bool ObsArbol::chocarConProyectil(vector <Proyectil*> &_proyectiles, Jugador &_jugador)
{
	for(int cualProyectil = 0; cualProyectil < _proyectiles.size(); cualProyectil++)
	{
		if((x == _proyectiles[cualProyectil]->getX() or x+1 == _proyectiles[cualProyectil]->getX() or x-1 == _proyectiles[cualProyectil]->getX()) and (y+2 == _proyectiles[cualProyectil]->getY() or y+1 == _proyectiles[cualProyectil]->getY()))
		{
			_proyectiles[cualProyectil]->borrarProyectil();
			delete _proyectiles[cualProyectil];
			_proyectiles[cualProyectil] = nullptr;
			_proyectiles.erase(_proyectiles.begin() + cualProyectil);
			cualProyectil = -1;
			return false;
		}
	}
	return false;
}

bool ObsArbol::chocarConLimite(int _limiteInferior)
{
	if (_limiteInferior == y + 1)
 	{
		borrarObstaculo();
		return true;
 	}
 	else
 	{
		return false;
 	}
}