/**
Archivo: Poder.h
Autores: Nicolas Herrera <herrera.nicolas@correounivalle.edu.co>
         Hernán Cisneros <hernan.cisneros@correounivalle.edu.co>
         Samuel Galindo <samuel.galindo@correounivalle.edu.co>
Fecha creacion: 2022-07-02
fecha ultima modificacion: 2022-08-07
Licencia: GNU-GPL
Version: 11

  CLASE: Poder
  INTENCION: Construir una clase abstracta, que funcionara como clase padre de PoderCorazon, PoderDistri y PoderInvenci, aplicando polimorfismo y herencia, teniendo sus atributos en protected para que sus clases hijas puedan hacer uso de estos, ademas se definen metodos virtuales puros, estos poderes seran beneficos para el Tanque. Los objetos Poder son dinamicos (new).
  RELACIONES:
    - Es padre de PoderCorazon.
    - Es padre de PoderDistri.
    - Es padre de PoderInvenci.
    - Conoce a Tanque.
    
*/

#ifndef _PODER_
#define _PODER_

#include "Tanque.h"

#include <windows.h>

class Poder
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
        virtual ~Poder();
        /**
        mapearConsola(): Mapea la consola para indicar en que pocision x,y se pintará informacion.
        _x = Coordenada x;
        _y = Coordenada y;
        */
        void mapearConsola(int x, int y);
        /**
        pintarPoder: Funcion virtual pura.
        */
        virtual void pintarPoder()=0;
        /**
        borrarPoder: Borra cualquier poder heredado.
        */
        void borrarPoder();
        /**
        moverPoder: Permite desplazar cualquier poder heredado por el campo de juego.
        */
        void moverPoder();
        /**
        chocarConTanque: Retorna True si la pocision del poder concide con la pocision de el Tanque (chocan) activando el poder respectivo. En caso contrario, retorna false.
        &_tanque = Acceder a la informacion y metodos de Tanque usando referencia.
        */
        bool chocarConTanque(Tanque &_tanque);
        /**
        chocarConLimite: Retorna True si la pocision del poder concide con el limite inferior del campo de juego.
        _limiteInferior: Coordenada limite inferior del campo de juego.
        */
        bool chocarConLimite(int _limiteInferior);
        /**
        efectoPoder: Funcion virtual pura.
        */
        virtual void efectoPoder(Tanque &_tanque) = 0;

};

#endif