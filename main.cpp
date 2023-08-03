/**
Archivo: main.cpp
Autores: Nicolas Herrera <herrera.nicolas@correounivalle.edu.co>
         Hernán Cisneros <hernan.cisneros@correounivalle.edu.co>
         Samuel Galindo <samuel.galindo@correounivalle.edu.co>
Fecha creacion: 2022-07-02
fecha ultima modificacion: 2022-08-07
Licencia: GNU-GPL
Version: 11

Historia:
Haciendo uso de la programación orientada a objetos se propone el desarrollo de un videojuego de tipo de disparos arcade, en el cual un jugador podrá controlar por teclado, el movimiento y disparo de un tanque de guerra a través de un escenario dentro de unos límites definidos, intentando esquivar y/o destruir un conjunto de obstáculos que aparecerán aleatoriamente durante todo el tiempo de juego (árboles y vehículos enemigos) y que disminuirán sus vidas al colapsar con él.  

El jugador podrá desplazar el tanque de guerra de izquierda a derecha y de arriba a abajo, dentro de los límites del campo de juego, además, el tanque podrá disparar proyectiles hacia arriba, los cuales podrán destruir únicamente a los vehículos enemigos, ya que los árboles serán indestructibles. 

Al iniciar el juego, se le pedirá al jugador ingresar su nombre para registro de la partida. Inicialmente, El jugador contará con 3 vidas y el taque con tres corazones. Los corazones del tanque se irán disminuyendo uno a uno, cada vez que el mismo choque con un obstáculo. Así mismo, cada vez que el tanque pierda sus 3 corazones, el jugador perderá una de sus 3 vidas, y se reiniciaran los corazones del tanque a sus 3 iniciales, de esta manera, el juego terminará cuando el jugador pierda sus 3 vidas totales.

Durante el tiempo de juego, el tanque podrá atrapar una serie de ítems (poderes) que podrá obtener y usar durante un tiempo limitado (poder “Triple disparo”, poder “Intangibilidad”). Además, también podrá atrapar ítems de corazón extra, ayudándolo en su tarea de sobrevivir el mayor tiempo posible dentro del campo de juego.

El objetivo del jugador será sobrevivir en el campo de juego, usando sus 3 vidas totales, el mayor tiempo posible. 

Su puntuación final será determinada en la cantidad de tiempo en juego y la cantidad de vehículos enemigos destruidos, la cual se mostrará, junto al nombre registrado, al perder sus 3 vidas, generando una pantalla de “GAME OVER
*/

#include <iostream>
#include "Escenario.h"

void pantallaCompleta()
{
    keybd_event(VK_MENU,
                0x38,
                0,
                0);
    keybd_event(VK_RETURN,
                0x1c,
                0,
                0);
    keybd_event(VK_RETURN,
                0x1c,
                KEYEVENTF_KEYUP,
                0);
    keybd_event(VK_MENU,
                0x38,
                KEYEVENTF_KEYUP,
                0);
    return;
} 

void ocultarCursor()
{
	HANDLE hCon;;
	hCon = GetStdHandle(STD_OUTPUT_HANDLE);
	CONSOLE_CURSOR_INFO cci;
	cci.dwSize = 2;
	cci.bVisible = FALSE;
	
	SetConsoleCursorInfo(hCon, &cci);
}

int main() 
{
	pantallaCompleta();
    Jugador jugador;
	jugador.setNombre();
	Escenario juego;

	bool gameOver = false;
	while(!gameOver)
	{
		ocultarCursor();
		juego.pintarPuntuacion(jugador);
		juego.pintarVidas(jugador);
		juego.pintarCorazones();
		juego.accionesTanqueEscenario(jugador);
		juego.accionesObstaculosEscenario(jugador);
		juego.generarPoderes(jugador);
		juego.accionesPoderesEscenario();
		jugador.aumentarPuntuacion();          
		juego.aumDificultad(jugador);
		if(jugador.getVidas()==0)
		{
			gameOver = true;
		}	
 	}
	juego.pintarGameOver();
	juego.pintarTablaPuntuacion(jugador);
	Sleep(1000); 

  return 0;
}