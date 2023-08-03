/**
Archivo: Jugador.cpp
Autores: Nicolas Herrera <herrera.nicolas@correounivalle.edu.co>
         Hernán Cisneros <hernan.cisneros@correounivalle.edu.co>
         Samuel Galindo <samuel.galindo@correounivalle.edu.co>
Fecha creacion: 2022-07-02
fecha ultima modificacion: 2022-08-07
Licencia: GNU-GPL
Version: 11
*/
#include "Jugador.h"

Jugador::Jugador()
{
	
}

Jugador::~Jugador()
{
	
}

void Jugador::setNombre()
{
	cout<<"\n\n\t********************************************";
	cout<<"\n\n\t**** !!! Bienvenido a WAR ADVENTURE !!! ****" ;
	cout<<"\n\n\t********************************************";
	cout<<"\n\n\tIngrese su nombre soldado \n\t---> ";
	cin>> nombre;
	system("pause");	
	cout<<"\n\n\tSOLDADO *** "<<nombre<<" ***\n\n\tUsted ha sido elegido para dirigir conducir y proteger el vehiculo de guerra en el campo de batalla\n\tEsta listo para la mision???"<<endl;
	cout<<"\n\n\tPresione ENTER para acceptar e iniciar la mision"<<endl;
	system("\tpause");		
	system("cls");	
}

string Jugador::getNombre()
{
	return nombre;
}

int Jugador::getPuntuacion()
{
	return puntuacion;
}

int Jugador::getVidas()
{
	return vidas;
}

void Jugador::quitarVidas()
{
	vidas--;
}
void Jugador::aumentarPuntuacion()
{
	puntuacion++;
}
void Jugador::aumentarPuntuacion(int _x)
{
	puntuacion = puntuacion + _x;
}



