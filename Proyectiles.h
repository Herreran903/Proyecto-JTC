/**
Archivo: Proyectiles.h
Autores: Nicolas Herrera <herrera.nicolas@correounivalle.edu.co>
         Hernán Cisneros <hernan.cisneros@correounivalle.edu.co>
         Samuel Galindo <samuel.galindo@correounivalle.edu.co>
Fecha creacion: 2022-07-02
fecha ultima modificacion: 2022-08-07
Licencia: GNU-GPL
Version: 11

  CLASE: Proyectiles
  INTENCION: Construir la clase proyectiles que funcionara como una acción de el tanque, esta podra destruir ObsCarro, colisionar con los limites del escenario y colisionar con ObsArbol destruyendose a si mismo. Los objetos proyectiles son dinamicos (new).
  RELACIONES:
    - Es contenido por Tanque.
*/

#ifndef _PROYECTILES_
#define _PROYECTILES_

#include <windows.h>
#include <cstdio>

//Clase
class Proyectil
{
    //Atributos de la clase
    private:

        int x;
        int y;

    //Metodos de la clase
    public:
        /**
        Constructor: Crea el objeto Proyectil con sus atributos iniciales. 
        _iniX: Coordenada inicial x. 
        _iniY: Coordenada inicial y.
        */
        Proyectil(int _iniX, int _iniY);
        /**
        Destructor
        */
        ~Proyectil();
        /**
        mapearConsola: Mapea la conosola para indicar en que pocision x,y se pintará informacion.
        */
        void mapearConsola();
        /**
        pintarProyectil: Imprime el Proyectil en la pocision x,y que se indique usando la funcion mapearConsola.
        */
        void pintarProyectil();
        /**
        borrarProyectil: Borra el Proyectil en la pocision x,y que se indique usando la funcion mapearConsola.
        */
        void borrarProyectil();
        /**
        moverProyectil: Permite desplazar el Proyectil en una pocision sobre el eje "y" del campo de juego. 
        */
        void moverProyectil();
        /**
        moverProyectil: Retorna True si el Proyectil choca con el limite superior del campo de juego en su reccorrido. En caso contrario, retorna False.
        _limiteSuperior: Coordenada limite superior del campo de juego.
        */
        bool chocoConLimite(int _limiteSuperior);
        /**
        getX: Retorna la pocision "x" actual del Proyectil en el campo de juego.
        */
        int getX();
        /**
        getY(): Retorna la pocision "y" actual del Proyectil en el campo de juego.
        */
        int getY();

};

#endif