/**
Archivo: Tanque.h
Autores: Nicolas Herrera <herrera.nicolas@correounivalle.edu.co>
         Hernán Cisneros <hernan.cisneros@correounivalle.edu.co>
         Samuel Galindo <samuel.galindo@correounivalle.edu.co>
Fecha creacion: 2022-07-02
fecha ultima modificacion: 2022-08-07
Licencia: GNU-GPL
Version: 11

  CLASE: Tanque
  INTENCION: Construir un tanque con sus controles, dimensiones, corazones, y otros atributos relacionados con los poderes, ademas de colisionar y modificar sus atributos al colisionar con un obstaculo y/o poder.
  RELACIONES:
    - Es conocido por obstaculos.
    - Es conocido por Poderes
    - Contiene a Proyectiles.
    - Conoce a Jugador
    
*/
#ifndef _TANQUE_H_
#define _TANQUE_H_

#include "Jugador.h"
#include "Proyectiles.h"

#include <windows.h>
#include <conio.h>
#include <vector>

//Clase
using namespace std;

class Tanque
{
    //Atributos de la clase
    private:

        int x;
        int y;
        int corazones = 3;
        int poderDisTri = 0;
        int poderInvenci = 0;
        vector <Proyectil*> proyectiles;
        
    //Metodos de la clase
    public:
        /**
        Constructor(): Crea el objeto Tanque con sus atributos iniciales. 
        _iniX: Coordenada inicial x. 
        _iniY: Coordenada inicial y.
        */
        Tanque(int _iniX, int _iniY);
        /**
        Destructor: Elimina los objetos dinamicos y vacia el vector de proyectiles.
        */
        ~Tanque();
        /**
        mapearConsola: Mapea la consola para indicar en que pocision x,y se pintará informacion.
        _x = Coordenada x;
        _y = Coordenada y;
        */
        void mapearConsola(int _x,int _y);
        /**
        pintarTanque: Imprime el Tanque en la pocision x,y que se indique usando la funcion mapearConsola.
        */
        void pintarTanque();
        /**
        borrarTanque: Borra el tanque en la pocision x,y que se indique usando la funcion mapearConsola.
        */
        void borrarTanque();
        /**
        controlesTanque: Controla las acciones del tanque (Movimientos y disparo) de acuerdo a la entrada del teclado y limita su campo de movimiento.
        */
        void controlesTanque(int _limiteDerecho, int _limiteInferior, int _limiteIzquerido, int _limiteSuperior);
        /**
        quitarCorazones: Quita corazones si la nave no tiene poder de invencibilidad. Si lo tiene dismunye su poder por colision con un obstaculo.
        */
        void quitarCorazones();
        /**
        morir: Si la nave pierde 3 corazones, se quita una vida al jugador y se imprime la animacion de explotar.
        _jugador: Acceder a la informacion y metodos de Jugador usando referencia.
        */
        void morir(Jugador &_jugador);
        /**
        generarProyectiles: Si la nave no tiene PoderDisTri, crea un objeto dinamico proyectil y su respectivo puntero en el vector proyectiles. Si lo tiene, realiza lo anterior 3 veces al mismo tiempo.
        */
        void generarProyectiles();
        /**
        Disparar: Verifica si el vector proyectil no es vacio. Usa la funcion moverProyectil parar permitir su moviemiento por el escenario. Tambien llama la funcion chocarConLimite para verificar si choco con el limite superior.
        */
        void disparar(int _limiteSuperior);
        /**
        ActivarPoderCorazon: Si la nave tiene menos de 3 corazones, aumenta un corazon.
        */
        void ActivarPoderCorazon();
        /**
        activarPoderDisTri: Si la nave tiene el poderDisTri igual a 0, aumenta su valor a 20.
        */
        void activarPoderDisTri();
        /**
        activarPoderInvenci: Si la nave tiene el PoderInvenci igual a 0, aumenta su valor a 5.
        */
        void activarPoderInvenci();
        /**
        getCorazones: Retorna los corazones actuales de el Tanque en el escenario.
        */
        int getCorazones();
        /**
        getX: Retorna la pocision "x" actual de el Tanque en el escenario.
        */
        int getX();
        /**
        getY: Retorna la pocision "y" actual de el Tanque en el escenario.
        */
        int getY();
        /**
        &getListProyectiles: Retorna la referencia al vector de proyectiles.
        */
        vector <Proyectil*> &getListProyectiles();

};

#endif