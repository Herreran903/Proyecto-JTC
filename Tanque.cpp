/**
Archivo: Tanque.cpp
Autores: Nicolas Herrera <herrera.nicolas@correounivalle.edu.co>
         Hernán Cisneros <hernan.cisneros@correounivalle.edu.co>
         Samuel Galindo <samuel.galindo@correounivalle.edu.co>
Fecha creacion: 2022-07-02
fecha ultima modificacion: 2022-08-07
Licencia: GNU-GPL
Version: 11
*/

#include "Tanque.h"

Tanque::Tanque(int _iniX, int _iniY)
{
	x = _iniX;
	y = _iniY;
}

Tanque::~Tanque()
{
	if(!proyectiles.empty())
	{
		for(int cualProyectil = 0; cualProyectil < proyectiles.size(); cualProyectil++)
		{
			delete proyectiles[cualProyectil];
			proyectiles[cualProyectil] = nullptr;
		}
	}
	proyectiles.clear();
}

void Tanque::mapearConsola(int _x, int _y)
{
	HANDLE hCon;;
	hCon = GetStdHandle(STD_OUTPUT_HANDLE);
	COORD dwPos;
	dwPos.X = _x;
	dwPos.Y = _y;
	
	SetConsoleCursorPosition(hCon, dwPos);
}

void Tanque::pintarTanque()
{
	mapearConsola(x, y); printf("|", 219);
	for(int cualCoordenadaX = -2; cualCoordenadaX < 3; cualCoordenadaX++)
	{
		for(int cualCoordenadaY = 1; cualCoordenadaY < 5; cualCoordenadaY++)
		{
			if(cualCoordenadaX == 0 and cualCoordenadaY == 1 )
			{
				mapearConsola(x + cualCoordenadaX, y + cualCoordenadaY); printf("%c", 186);
			}
			else if(cualCoordenadaX == 0 and cualCoordenadaY == 2)
			{
				mapearConsola(x + cualCoordenadaX, y + cualCoordenadaY); printf("%c", 254);
			}
			else if(cualCoordenadaX == -2 and cualCoordenadaY == 1)
			{
				mapearConsola(x + cualCoordenadaX, y + cualCoordenadaY); printf("%c", 220);
			}
			else if(cualCoordenadaX == 2 and cualCoordenadaY == 1)
			{
				mapearConsola(x + cualCoordenadaX, y + cualCoordenadaY); printf("%c", 220);
			}
			else if(cualCoordenadaX == -2 and cualCoordenadaY == 4)
			{
				mapearConsola(x + cualCoordenadaX, y + cualCoordenadaY); printf("%c", 223);
			}
			else if(cualCoordenadaX == 2 and cualCoordenadaY == 4)
			{
				mapearConsola(x + cualCoordenadaX, y + cualCoordenadaY); printf("%c", 223);
			}
			else
			{
				mapearConsola(x + cualCoordenadaX, y + cualCoordenadaY); printf("%c",219);
			}
		}		
	}	
}

void Tanque::borrarTanque()
{
	mapearConsola(x, y); printf(" ");
	for(int cualCoordenadaX = -2; cualCoordenadaX < 3; cualCoordenadaX++)
	{
		for(int cualCoordenadaY = 1; cualCoordenadaY < 5; cualCoordenadaY++)	 
		{
			mapearConsola(x + cualCoordenadaX ,y + cualCoordenadaY); printf(" ");	
		}
	}
}

void Tanque::controlesTanque(int _limiteDerecho, int _limiteInferior, int _limiteIzquerido, int _limiteSuperior)
{
	// khbhit valida constantemnte la entrada del teclado.
	if(kbhit())
	{
		// Guarda en la variable tecla, la entrada del teclado presionada.
		char tecla = getch();
		borrarTanque();
		if(tecla == 'w' and y > _limiteSuperior)
		{
			y--;
		}
		if(tecla == 's' and y < _limiteInferior-5)
		{
			y++;
		}
		if(tecla == 'a' and x > _limiteIzquerido+3)   
		{
			x--;
		}
		if(tecla == 'd' and x < _limiteDerecho-4)
		{
			x++;
		}
		if(tecla == 'r')
		{
			generarProyectiles();
		}
		pintarTanque();
	}
}

void Tanque::quitarCorazones()
{
	if(poderInvenci == 0)
	{
		corazones--;
	}
	else
	{
		poderInvenci--;
	}
}

void Tanque::morir(Jugador &_jugador)
{
	if(corazones == 0)
	{
		borrarTanque();
		mapearConsola(x - 2, y);     printf("  *  ");
		mapearConsola(x - 2, y + 1); printf(" *** ");
		mapearConsola(x - 2, y + 2); printf("*****");
		mapearConsola(x - 2, y + 3); printf("*****");
		mapearConsola(x - 2, y + 4); printf(" *** ");
		Sleep(200);

		borrarTanque();
		mapearConsola(x - 2, y);     printf("  *  ");
		mapearConsola(x - 2, y + 1); printf("* * *");
		mapearConsola(x - 2, y + 2); printf("** **");
		mapearConsola(x - 2, y + 3); printf("** **");
		mapearConsola(x - 2, y + 4); printf("* * *");
		Sleep(400);

		borrarTanque();
		mapearConsola(x - 2, y);     printf("  *  ");
		mapearConsola(x - 2, y + 1); printf(" *** ");
		mapearConsola(x - 2, y + 2); printf("*****");
		mapearConsola(x - 2, y + 3); printf("*****");
		mapearConsola(x - 2, y + 4); printf(" *** ");
		Sleep(200);

		borrarTanque();
		pintarTanque();

		_jugador.quitarVidas();
		corazones = 3;
	}
}

void Tanque::generarProyectiles()
{
	if(poderDisTri == 0)
	{	
		proyectiles.push_back(new Proyectil(x, y - 1));
	}
	else
	{
		proyectiles.push_back(new Proyectil(x, y - 1));
		proyectiles.push_back(new Proyectil(x + 1, y - 1));
		proyectiles.push_back(new Proyectil(x - 1, y - 1));
		poderDisTri--;
	}	
}

void Tanque::disparar(int _limiteSuperior)
{
	if(!proyectiles.empty())
	{
		for(int cualProyectil = 0; cualProyectil < proyectiles.size(); cualProyectil++)
		{
			proyectiles[cualProyectil]->moverProyectil();
			if(proyectiles[cualProyectil]->chocoConLimite(_limiteSuperior))
			{
				delete proyectiles[cualProyectil];
				proyectiles[cualProyectil] = nullptr;
				proyectiles.erase(proyectiles.begin() + cualProyectil);
				cualProyectil = -1;		  
			}
		}
	}
	
} 

void Tanque::ActivarPoderCorazon()
{
	if(corazones < 3)
	{
		corazones++;
	}	
}

void Tanque::activarPoderDisTri()
{
	if(poderDisTri == 0)
	{
		poderDisTri = 20;
	}
}

void Tanque::activarPoderInvenci()
{
	if(poderInvenci == 0)
	{
		poderInvenci = 5;
	}
}

int Tanque::getCorazones()
{
	return corazones;
}

int Tanque::getX()
{
	return x;
}

int Tanque::getY()
{
	return y;
}

vector <Proyectil*> &Tanque::getListProyectiles()
{
	return proyectiles;
}
