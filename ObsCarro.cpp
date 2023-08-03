/**
Archivo: ObsCarro.h
Autores: Nicolas Herrera <herrera.nicolas@correounivalle.edu.co>
         Hernán Cisneros <hernan.cisneros@correounivalle.edu.co>
         Samuel Galindo <samuel.galindo@correounivalle.edu.co>
Fecha creacion: 2022-07-02
fecha ultima modificacion: 2022-08-07
Licencia: GNU-GPL
Version: 11
*/

#include "ObsCarro.h"

ObsCarro::ObsCarro(int _iniX, int _iniY)
{
	x = _iniX;
	y = _iniY;	
}

ObsCarro::~ObsCarro()
{

}

void ObsCarro::pintarObstaculo()
{
	for (int cualCoordenadaX = 1; cualCoordenadaX > -1; cualCoordenadaX--)
		{
			for (int cualCoordenadaY = 2; cualCoordenadaY > -1; cualCoordenadaY--)
			{
				if(cualCoordenadaY==1)
				{
					mapearConsola(x + cualCoordenadaX, y + cualCoordenadaY); printf("%c", 240);
				}
				else if(cualCoordenadaY == 0)
				{
					mapearConsola(x + cualCoordenadaX, y + cualCoordenadaY); printf("%c", 219);
				}
				else if(cualCoordenadaY == 2)
				{
					mapearConsola(x + cualCoordenadaX, y + cualCoordenadaY); printf("%c", 223);
				}		
			}
		}
}

void ObsCarro::borrarObstaculo()
{	
	for (int cualCoordenadaX = 1; cualCoordenadaX > -1; cualCoordenadaX--)
	{
		for (int cualCoordenadaY = 2; cualCoordenadaY > -1; cualCoordenadaY--)
		{
			mapearConsola(x + cualCoordenadaX, y + cualCoordenadaY); printf(" ");
		}
	}
}
		
bool ObsCarro::chocarConTanque(Tanque &_tanque)
{	
	for (int cualCoordenadaXObs = 1; cualCoordenadaXObs > -1; cualCoordenadaXObs--)
	{
		for (int cualCoordenadaYObs = 2; cualCoordenadaYObs > -1; cualCoordenadaYObs--)
		{
			for(int cualCoordenadaXTan = -2; cualCoordenadaXTan < 3; cualCoordenadaXTan++)
			{
				for(int cualCoordenadaYTan  = 1; cualCoordenadaYTan < 5; cualCoordenadaYTan++)	
				{
					if((_tanque.getX() + cualCoordenadaXTan == x + cualCoordenadaXObs and _tanque.getY() + cualCoordenadaYTan == y + cualCoordenadaYObs)) 
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

bool ObsCarro::chocarConProyectil(vector <Proyectil*> &_proyectiles, Jugador &_jugador)
{
	for(int cualProyectil = 0; cualProyectil < _proyectiles.size(); cualProyectil++)
	{
		if((x == _proyectiles[cualProyectil]->getX() or x+1 == _proyectiles[cualProyectil]->getX()) and (y+2 == _proyectiles[cualProyectil]->getY() or y+1 == _proyectiles[cualProyectil]->getY()))
		{
			borrarObstaculo();
			_proyectiles[cualProyectil]->borrarProyectil();
			delete _proyectiles[cualProyectil];
			_proyectiles[cualProyectil] = nullptr;
			_proyectiles.erase(_proyectiles.begin() + cualProyectil);
			cualProyectil = -1;

			_jugador.aumentarPuntuacion(10);
			return true;
		
		}
	}
	return false;
}

bool ObsCarro::chocarConLimite(int _limiteInferior)
{
	if (_limiteInferior == y + 4)
 	{
		borrarObstaculo();
		return true;
 	}
 	else
 	{
		return false;
 	}
}