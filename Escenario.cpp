/**
Archivo: Escenario.cpp
Autores: Nicolas Herrera <herrera.nicolas@correounivalle.edu.co>
         Hernán Cisneros <hernan.cisneros@correounivalle.edu.co>
         Samuel Galindo <samuel.galindo@correounivalle.edu.co>
Fecha creacion: 2022-07-02
fecha ultima modificacion: 2022-08-07
Licencia: GNU-GPL
Version: 11
*/

#include "Escenario.h"

Escenario::Escenario() : _tanque(((coord[0]-coord[2])/2)+coord[2], coord[1]-5)
{
	// Inicializa los vectores como vacios.
	obstaculos.empty();
	poderes.empty();
	posicionesX.empty();
	// Genera la primera ronda de obstaculos
	generarObstaculos();
	// Pinta los limites del campo de juego
	pintarLimites();
	// Pinta el tanque dentro del campo de juego
	_tanque.pintarTanque();
}

Escenario::~Escenario()
{
	// Verifica si el vector obstaculos no es vacio.
	if(!obstaculos.empty())
	{	
		// Libera la memoria ocupada por el objeto dinamico y apunta al punto a nullptr.
		for(int cualObstaculo = 0; cualObstaculo < obstaculos.size(); cualObstaculo++)
		{
			delete obstaculos[cualObstaculo];
			obstaculos[cualObstaculo] = nullptr;
		}
	}
	// Borra los punteros.
	obstaculos.clear();

	// Verifica si el vector poderes no es vacio.
	if(!poderes.empty())
	{
		// Libera la memoria ocupada por el objeto dinamico y apunta al punto a nullptr.
		for(int cualPoder = 0; cualPoder < obstaculos.size(); cualPoder++)
		{
			delete obstaculos[cualPoder];
			obstaculos[cualPoder] = nullptr;
		}
	}
	// Borra los punteros.
	poderes.clear();
}

void Escenario::mapearConsola(int _x, int _y)
{
	HANDLE hCon;;
	hCon = GetStdHandle(STD_OUTPUT_HANDLE);
	COORD dwPos;
	dwPos.X = _x;
	dwPos.Y = _y;
	SetConsoleCursorPosition(hCon, dwPos);
}

void Escenario::pintarLimites()
{
	// Pinta borde superior.
	for(int cualCoordenadaX = coord[2]; cualCoordenadaX < coord[0]; cualCoordenadaX++)
	{
		mapearConsola(cualCoordenadaX, coord[3]-1); printf("%c", 205);
	}
	
	// Pinta borde inferior.
	for(int cualCoordenadaX = coord[2]; cualCoordenadaX < coord[0]; cualCoordenadaX++)
	{
		mapearConsola(cualCoordenadaX, coord[1]); printf("%c", 205);
	}
	
	// Pinta borde izquierdo.
	for(int cualCoordenadaY = coord[3]; cualCoordenadaY < coord[1]; cualCoordenadaY++)
	{
		mapearConsola(coord[2], cualCoordenadaY); printf("%c", 186);
	}
	
	// Pintar borde derecho.
	for(int cualCoordenadaY = coord[3]; cualCoordenadaY < coord[1]; cualCoordenadaY++)
	{
		mapearConsola(coord[0]-1, cualCoordenadaY); printf("%c", 186);
	}
	
	// Pinta esquina superior-izquierda.
	mapearConsola(coord[2],coord[3]-1); printf("%c", 201);
	// Pinta esquina inferior-izquierda.
	mapearConsola(coord[2], coord[1]); printf("%c", 200);
	// Pinta esquina superior-derecha.
	mapearConsola(coord[0]-1, coord[3]-1); printf("%c", 187);
	// Pinta esquina inferior-derecha.
	mapearConsola(coord[0]-1, coord[1]); printf("%c", 188);
}

void Escenario::pintarCorazones()
{
	mapearConsola(coord[0]-12,coord[3]-2); printf("Salud:");
	mapearConsola(coord[0]-5,coord[3]-2); printf("    ");
	for(int cualCoordenadaX = 0; cualCoordenadaX < _tanque.getCorazones() ; cualCoordenadaX++)
	{
		mapearConsola(coord[0]-4 + cualCoordenadaX, coord[3]-2); printf("%c", 3);
	}	
}

void Escenario::pintarVidas(Jugador &_jugador)
{
	mapearConsola(coord[0]-22,coord[3]-2); printf("Vidas:");
	mapearConsola(coord[0]-15,coord[3]-2); printf("%d\n", _jugador.getVidas());
}

void Escenario::pintarPuntuacion(Jugador &_jugador)
{
	mapearConsola(coord[2],coord[3]-2); printf("Puntuacion:");
	mapearConsola(coord[2]+12, coord[3]-2); printf("%d\n", _jugador.getPuntuacion());
}

void Escenario::accionesTanqueEscenario(Jugador &_jugador)
{
	// Permite el movimiento del tanque mediante las teclas.
	_tanque.controlesTanque(coord[0], coord[1],  coord[2],  coord[3]);
	// El tanque muere si pierde 3 corazones.
	_tanque.morir(_jugador);
	// Controla el movimiento de los proyectiles.
	_tanque.disparar(coord[3]);
}

void Escenario::accionesObstaculosEscenario(Jugador &_jugador)
{
	// Recorre el vector de obstaculos.
	for(int cualObstaculo = 0; cualObstaculo < obstaculos.size(); cualObstaculo++)
	{
		// Controla el movimiento del obstaculo
		obstaculos[cualObstaculo]->moverObstaculo();\
		// Valida si choco con el limite inferior del campo de juego.
		if(obstaculos[cualObstaculo]->chocarConLimite(coord[1]))
		{
			// Genera el obstaculo indicado en una posicion no repetida.
			generarObstaculos(seRepiteX(), typeid(*(obstaculos[cualObstaculo])).name());
			// Destruye el objeto dimanico de obstaculos.
			destruirObjetos(cualObstaculo, obstaculos);
		}
		// Valida si choco con el tanque.
		if(obstaculos[cualObstaculo]->chocarConTanque(_tanque))
		{
			// Genera el obstaculo indicado en una posicion no repetida.
			generarObstaculos(seRepiteX(), typeid(*(obstaculos[cualObstaculo])).name());
			// Destruye el objeto dimanico de obstaculos.
			destruirObjetos(cualObstaculo, obstaculos);
		}
		// Valida si choco con algun proyectil.
		if(obstaculos[cualObstaculo]->chocarConProyectil(_tanque.getListProyectiles(), _jugador))
		{
			// Genera el obstaculo indicado en una posicion no repetida.
			generarObstaculos(seRepiteX(), typeid(*(obstaculos[cualObstaculo])).name());
			// Destruye el objeto dimanico de obstaculos.
			destruirObjetos(cualObstaculo, obstaculos);
		}
	}
}

void Escenario::accionesPoderesEscenario()
{
	// Verifica que el vector poderes no este vacio.
	if(!poderes.empty())
	{ 	
		// Recorre el vector poderes.
		for(int cualPoder = 0;  cualPoder < poderes.size(); cualPoder++)
		{	
			// Controla el movimiento de los poderes.
			poderes[cualPoder]->moverPoder();
			// Verifica si choco con el limite inferior.
			if(poderes[cualPoder]->chocarConLimite(coord[1]))
			{
				destruirObjetos(cualPoder, poderes);
			}
			// Verifica si choco con el tanque.
			else if(poderes[cualPoder]->chocarConTanque(_tanque))
			{
				destruirObjetos(cualPoder, poderes);	
			}
		}
	}
}

void Escenario::generarObstaculos()
{
	// For de 0 hasta 9.
	for(int cualObstaculo = 0; cualObstaculo <= 9; cualObstaculo++)
	{
		if(cualObstaculo < 7)
		{
			// Crea un objeto dinamico ObsCarro y lo enlaza al puntero dentro del vector obstaculos.
			obstaculos.push_back(new ObsCarro(seRepiteX(), rand()%2 + coord[3]));
		}
		if(cualObstaculo >= 7)
		{
			// Crea un objeto dinamico ObsArbol y lo enlaza al puntero dentro del vector obstaculos.
			obstaculos.push_back(new ObsArbol(seRepiteX(), coord[3] + 2));
		}
		// Ingresa las posiciones X de los obstaculos al vector posicionesX.
		posicionesX.push_back(obstaculos[cualObstaculo]->getX());
	}
}

void Escenario::generarObstaculos(int _nuevaPosicionX, string _clase)
{
	// Valida si le objeto a crear es un ObsCarro.
	if(_clase == typeid(ObsCarro).name())
	{
		obstaculos.push_back(new ObsCarro(_nuevaPosicionX, rand()%2 + coord[3]));
	}
	// Valida si le objeto a crear es un ObsArbol.
	else if(_clase == typeid(ObsArbol).name())
	{
		obstaculos.push_back(new ObsArbol(_nuevaPosicionX, coord[3]+2));
	}
	// Agrega la nueva posicion X del obstaculo al vector posicionesX.
	posicionesX.push_back(_nuevaPosicionX);
}

void Escenario::generarPoderes(Jugador &_jugador)
{
	if(_jugador.getPuntuacion()%500 == 0 and _jugador.getPuntuacion() != 0)
	{
		poderes.push_back(new PoderCorazon((coord[2]+1)+ rand()%((coord[0]-2) - (coord[2]+1)), coord[3]+1));
	}
	if(_jugador.getPuntuacion()%1000 ==0 and _jugador.getPuntuacion() != 0)
	{
		poderes.push_back(new PoderDisTri((coord[2]+1)+ rand()%((coord[0]-2) - (coord[2]+1)), coord[3]+1));
	}
	if(_jugador.getPuntuacion()%1700 ==0 and _jugador.getPuntuacion() != 0)
	{
		poderes.push_back(new PoderInvenci((coord[2]+1)+ rand()%((coord[0]-2) - (coord[2]+1)), coord[3]+1));
	}		
}

void Escenario::destruirObjetos(int _cualObjeto, vector<Obstaculo*> &_obstaculos)
{
	posicionesX.erase(posicionesX.begin() + _cualObjeto);
	delete _obstaculos[_cualObjeto];
	_obstaculos[_cualObjeto] = nullptr;
	_obstaculos.erase(_obstaculos.begin() + _cualObjeto);	
}

void Escenario::destruirObjetos(int _cualObjeto, vector<Poder*> &_poderes)
{
	delete _poderes[_cualObjeto];
	_poderes[_cualObjeto] = nullptr;
	_poderes.erase(_poderes.begin() + _cualObjeto);	
}

int Escenario::seRepiteX()
{	
	// Genera un entero random X, entre el limite izquierdo y derecho del campo de juego.
	int x = (coord[2]+2) + rand()%((coord[0]-2) - (coord[2]+2));
	// Verifica si el vector posicionesX no esta vacio
	if(!posicionesX.empty())
	{
		//Recorre el vector posicionesX
		for(int cualCoordenadaX = 0; cualCoordenadaX < posicionesX.size(); cualCoordenadaX++)
			{
				// Validad si el x anteriormente generado es igual a alguna posicion x de algun otro obstaculo que se encuntre en pantalla.
				if(x == posicionesX[cualCoordenadaX] or x == posicionesX[cualCoordenadaX]+1 or x == posicionesX[cualCoordenadaX]+2 or x == posicionesX[cualCoordenadaX]+3 or x == posicionesX[cualCoordenadaX]-1 or x == posicionesX[cualCoordenadaX]-2 or x == posicionesX[cualCoordenadaX]-3)
				{
					// Si valida lo anterior, entonces, se genera otro entero random X, entre el limite izquierdo y derecho del campo de juego.
					x = (coord[2]+2)+ rand()%((coord[0]-2) - (coord[2]+2));
					// Establecemos la coordenada como -1, para volver a recorrer el vector posicionesX desde 0.
					cualCoordenadaX = -1;
				}
			}
	}
	// Si el vector posicionesX esta vacion, entonces retorna el x generado en un principio.
	else
	{
		return x;
	}
	// Retorna un x que no se repite.
	return x;
}

void Escenario::pintarGameOver()
{
	// Limpiar pantalla (clear screen).
	system("cls"); 
	
	Sleep(400);
	mapearConsola((((coord[0]-coord[2])/2)+coord[2]) - 40, (((coord[1]-coord[3])/2)+coord[3]) - 12);
	printf("   %c%c%c%c%c%c%c%c  ",219,219,219,223,223,223,219,219);
	printf("%c%c%c%c%c%c%c%c%c  ",219,219,219,223,223,223,219,219,219);
	printf("%c%c%c%c%c%c%c%c%c%c%c  ",219,219,219,223,219,220,219,223,219,219,219);
	printf("%c%c%c%c%c  ",219,219,223,223,223);
	printf("      %c%c               %c%c    ",219,219,219,219);

	Sleep(400);
	mapearConsola((((coord[0]-coord[2])/2)+coord[2]) - 40, (((coord[1]-coord[3])/2)+coord[3]) - 11);
	printf("   %c%c    %c%c  ",219,219,219,219);
	printf("%c%c     %c%c  ",219,219,219,219);
	printf("%c%c   %c   %c%c  ",219,219,219,219,219);
	printf("%c%c",219,219);
	printf("         %c%c%c%c%c   %c%c%c%c%c%c%C   %c%c%c%c%c  ",219,219,219,219,220,220,220,220,220,220,220,220,220,219,219,219,219);

	Sleep(400);
	mapearConsola((((coord[0]-coord[2])/2)+coord[2]) - 40, (((coord[1]-coord[3])/2)+coord[3]) - 10);
	printf("   %c%c   %c%c%c  ",219,219,220,220,220);
	printf("%c%c%c%c%c%c%c%c%c  ",219,219,220,220,220,220,220,219,219);
	printf("%c%c   %c   %c%c  ",219,219,223,219,219);
	printf("%c%c%c%c%c  ",219,219,223,223,223);
	printf("       %c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c     ",223,223,219,220,219,219,219,219,219,219,219,219,219,220,219,223,223);

	Sleep(400);
	mapearConsola((((coord[0]-coord[2])/2)+coord[2]) - 40, (((coord[1]-coord[3])/2)+coord[3]) - 9);
	printf("   %c%c    %c%c  ",219,219,219,219);
	printf("%c%c     %c%c  ",219,219,219,219);
	printf("%c%c       %c%c  ",219,219,219,219);
	printf("%c%c",219,219);
	printf("              %c%c%c%c%c%c%c%c%c%c%c%c%c       ",219,219,219,219,219,219,219,219,219,219,219,219,219);

	Sleep(400);
	mapearConsola((((coord[0]-coord[2])/2)+coord[2]) - 40, (((coord[1]-coord[3])/2)+coord[3]) - 8);
	printf("   %c%c%c%c%c%c%c%c  ",219,219,219,220,220,220,219,219);
	printf("%c%c     %c%c  ",219,219,219,219);
	printf("%c%c       %c%c  ",219,219,219,219);
	printf("%c%c%c%c%c  ",219,219,220,220,220);
	printf("         %c%c%c%c%c%c%c%c%c%c%c%c%c       ",219,219,223,223,223,219,219,219,223,223,223,219,219);

	mapearConsola((((coord[0]-coord[2])/2)+coord[2]) - 40, (((coord[1]-coord[3])/2)+coord[3]) - 7);
	printf("                                                     %c%c   %c%c%c   %c%c     \n",219,219,219,219,219,219,219);

	Sleep(400);
	mapearConsola((((coord[0]-coord[2])/2)+coord[2]) - 40, (((coord[1]-coord[3])/2)+coord[3]) - 6);
	printf("   %c%c%c%c%c%c%c%c%c  ",219,219,219,223,223,223,219,219,219); 
	printf("%c%c%c%c  %c%c%c  ",223,219,219,219,219,219,223);
	printf("%c%c%c%c%c  ",219,219,223,223,223);
	printf("%c%c%c%c%c%c%c%c%c  ",219,219,223,223,223,223,219,219,220);
	printf("          %c%c%c%c%c%c%c%c%c%c%c%c%c     ",219,219,219,219,219,223,220,223,219,219,219,219,219);

	Sleep(400);
	mapearConsola((((coord[0]-coord[2])/2)+coord[2]) - 40, (((coord[1]-coord[3])/2)+coord[3]) - 5);
	printf("   %c%c     %c%c  ",219,219,219,219);
	printf("  %c%c  %c%c   ",219,219,219,219);
	printf("%c%c     ",219,219);
	printf("%c%c     %c%c  ",219,219,219,219);
	printf("           %c%c%c%c%c%c%c%c%c%c%c       ",219,219,219,219,219,219,219,219,219,219,219);

	Sleep(400);
	mapearConsola((((coord[0]-coord[2])/2)+coord[2]) - 40, (((coord[1]-coord[3])/2)+coord[3]) - 4);
	printf("   %c%c     %c%c  ",219,219,219,219);
	printf("  %c%c  %c%c   ",219,219,219,219);
	printf("%c%c%c%c%c  ",219,219,223,223,223);
	printf("%c%c%c%c%c%c%c%c%c  ",219,219,220,220,220,220,220,223,223);
	printf("       %c%c%c%c%c  %c%c%c%c%c  %c%c%c%c%c  ",220,220,220,219,219,219,223,219,223,219,219,219,220,220,220);

	Sleep(400);
	mapearConsola((((coord[0]-coord[2])/2)+coord[2]) - 40, (((coord[1]-coord[3])/2)+coord[3]) - 3);
	printf("   %c%c     %c%c  ",219,219,219,219);
	printf("  %c%c  %c%c   ",219,219,219,223);
	printf("%c%c     ",219,219);
	printf("%c%c     %c%c  ",219,219,219,219);
	printf("       %c%c%c%c           %c%c%c%c  ",223,223,219,219,219,219,223,223);

	Sleep(400);
	mapearConsola((((coord[0]-coord[2])/2)+coord[2]) - 40, (((coord[1]-coord[3])/2)+coord[3]) - 2);
	printf("   %c%c%c%c%c%c%c%c%c  ",219,219,219,220,220,220,219,219,219);
	printf("   %c%c%c     ",223,219,223);
	printf("%c%c%c%c%c  ",219,219,220,220,220);
	printf("%c%c     %c%c%c  ",219,219,219,219,220);
	printf("        %c%c           %c%c    ",223,223,223,223);
	printf("\n\n\n");
	
}

void Escenario::pintarTablaPuntuacion(Jugador &_jugador)
{
	mapearConsola((((coord[0]-coord[2])/2)+coord[2]) - 25 , (((coord[1]-coord[3])/2)+coord[3])); printf("*******************************************");
	mapearConsola((((coord[0]-coord[2])/2)+coord[2]) - 24, (((coord[1]-coord[3])/2)+coord[3]) + 2); printf("SOLDADO");
	mapearConsola((((coord[0]-coord[2])/2)+coord[2]) + 7, (((coord[1]-coord[3])/2)+coord[3]) + 2); printf("PUNTUACION");
	mapearConsola((((coord[0]-coord[2])/2)+coord[2]) - 24, (((coord[1]-coord[3])/2)+coord[3]) + 4);printf("%s",_jugador.getNombre().c_str());
	
	//string nombre = _jugador.getNombre();
	//printf("%s",nombre.c_str());
	
	mapearConsola((((coord[0]-coord[2])/2)+coord[2]) + 7, (((coord[1]-coord[3])/2)+coord[3]) + 4); printf("%d Pts\n", _jugador.getPuntuacion());
	mapearConsola((((coord[0]-coord[2])/2)+coord[2]) - 25, (((coord[1]-coord[3])/2)+coord[3]) + 6); printf("*******************************************");
	
	mapearConsola((((coord[0]-coord[2])/2)+coord[2]) - 23, (((coord[1]-coord[3])/2)+coord[3]) + 10);
	system("pause");
	
}

void Escenario::aumDificultad(Jugador &_jugador)
{
	// Controla la velocidad de iteriacion del juego. Es decir me geneara una pausa de x milisegundos entre cada iteracion.
	Sleep(velJuego);
	if (_jugador.getPuntuacion() >= 500 and velJuego == 25)
	{
		velJuego = velJuego - 1;
		mapearConsola(coord[2] + 22, coord[3]-2); printf("Nivel 1");
	}
	else if (_jugador.getPuntuacion() >= 1000 and velJuego==24)
	{
		velJuego=velJuego - 2;
		mapearConsola(coord[2]+22, coord[3] - 2); printf("Nivel 2");
	}
	else if (_jugador.getPuntuacion() >= 1500 and velJuego==22)
	{
		velJuego=velJuego - 3;
		mapearConsola(coord[2] + 22, coord[3] - 2); printf("Nivel 3");
	}
	else if (_jugador.getPuntuacion() >= 2000 and velJuego == 19)
	{
		velJuego=velJuego - 4;
		mapearConsola(coord[2] + 22, coord[3]-2); printf("Nivel 4");
	}

}