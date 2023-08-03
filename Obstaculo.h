/**
Archivo: Obstaculo.h
Autores: Nicolas Herrera <herrera.nicolas@correounivalle.edu.co>
         Hernán Cisneros <hernan.cisneros@correounivalle.edu.co>
         Samuel Galindo <samuel.galindo@correounivalle.edu.co>
Fecha creacion: 2022-07-02
fecha ultima modificacion: 2022-08-07
Licencia: GNU-GPL
Version: 11

  CLASE: Obstaculo
  INTENCION: Construir una clase abstracta, que funcionara como clase padre de Obscarro y ObsArbol, aplicando polimorfismo y herencia, teniendo sus atributos en protected para que sus clases hijas puedan hacer uso de estos, ademas se definen metodos virtuales puros, los objetos heredados de esta clase seran los obstaculos que la nave debera evitar o destruir para garantizar su supervivencia. Los objetos obstaculos son dinamicos (new).
  
  RELACIONES:
    - Es padre de ObsCarro.
    - Es padre de ObsArbol.
    - Conoce a Tanque.
    
*/

#ifndef _OBSTACULO_
#define _OBSTACULO_

#include "Tanque.h"

#include <windows.h>
#include <vector>

class Obstaculo
{
    //Atributos de la clase
    protected:

        int x;
        int y;

    //Metodos
    public:
    
        /**
        Destructor
        */
        ~Obstaculo();
        /**
        mapearConsola(): Mapea la consola para indicar en que pocision x,y se pintará informacion.
        _x = Coordenada x;
        _y = Coordenada y;
        */
        void mapearConsola(int _iniX, int _iniY);
        /**
        pintarObstaculo: Funcion virtual pura.
        */
        virtual void pintarObstaculo()=0;
        /**
        borrarObstaculo: Funcion virtual pura.
        */
        virtual void borrarObstaculo()=0;
        /**
        moverPoder: Permite desplazar cualquier obstaculo heredado por el campo de juego.
        */
        virtual void moverObstaculo();
        /**
        chocarConTanque: Funcion virtual pura.
        */
        virtual bool chocarConTanque(Tanque &_tanque) = 0;
        /**
        chocarConProyectil: Funcion virtual pura.
        */
        virtual bool chocarConProyectil(vector <Proyectil*> &_proyectiles, Jugador &_jugador)=0;
        /**
        chocarConLimite: Funcion virtual pura.
        */
        virtual bool chocarConLimite(int _limiteInferior) = 0;
        /**
        getX: Retorna la pocision "x" actual del Obstaculo en el campo de juego.
        */
        int getX();

};

#endif