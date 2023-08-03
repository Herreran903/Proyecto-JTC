/**
Archivo: Jugador.h
Autores: Nicolas Herrera <herrera.nicolas@correounivalle.edu.co>
         Hernán Cisneros <hernan.cisneros@correounivalle.edu.co>
         Samuel Galindo <samuel.galindo@correounivalle.edu.co>
Fecha creacion: 2022-07-02
fecha ultima modificacion: 2022-08-07
Licencia: GNU-GPL
Version: 11

  CLASE: Jugador
  INTENCION: Construir un jugador, con su nombre, una puntuación y un numero de vidas. 
  RELACIONES:
    - Es conocido por Escenario.
    - Es concido por Tanque.
    - Es conocido por Obstaculo.
    
*/

#ifndef _JUGADOR_
#define _JUGADOR_

#include <string>
#include <iostream>

using namespace std;

//Clase
class Jugador
{
    //Atributos de la clase
    private:

        string nombre;
        int puntuacion = 0;
        int vidas = 3;

    //Metodos de la clase
    public:

        /**
        Constructor: Crea el objeto Jugador. 
        */
        Jugador();
        /**
        Destructor
        */
        ~Jugador();
        /**
        setNombre: Pide el nombre al jugador. 
        */
        void setNombre();
        /**
        getNombre: Retorna el nombre del jugador. 
        */
        string getNombre();
        /**
        getPuntuacion: Retorna retorna la puntuacion del jugador. 
        */
        int getPuntuacion();
        /**
        getVidas: Retorna retorna las vidas del jugador. 
        */
        int getVidas();
        /**
        quitarVidas: Disminuye una vida al jugador. 
        */
        void quitarVidas();
        /**
        aumentarPuntuacion: Aumenta la puntuacion en 1 por cada iteracion del juego. (Polimorfismo estatico)
        */
        void aumentarPuntuacion();
        /**
        aumentarPuntuacion: Aumenta la puntuacion en 10 por destuir un osbtaculo carro.
        _x = Numero entero que aumenta la puntuacion. (Polimorfismo estatico)
        */
        void aumentarPuntuacion(int _x);
};

#endif