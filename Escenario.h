/**
Archivo: Escenario.h
Autores: Nicolas Herrera <herrera.nicolas@correounivalle.edu.co>
         Hernán Cisneros <hernan.cisneros@correounivalle.edu.co>
         Samuel Galindo <samuel.galindo@correounivalle.edu.co>
Fecha creacion: 2022-07-02
fecha ultima modificacion: 2022-08-07
Licencia: GNU-GPL
Version: 11

  CLASE: Escenario
  INTENCION: Construir el escenario conteniendo al Tanque, Obstaculos y Poderes, para que estos se puedan relacionar entre si, ademas conoce al jugador para poder así imprimir sus atributos en pantalla (puntuación, vidas y al final del juego su nombre). 
  RELACIONES:
    - Contiene a Tanque.
    - Contiene a Obstaculo y sus clases heredadas.
    - Contiene a Poderes y sus clases heredadas.
    - Conoce a jugador.
    
*/

#ifndef _ESCENARIO_
#define _ESCENARIO_

#include "Tanque.h"
#include "Jugador.h"
#include "Obstaculo.h"
#include "ObsCarro.h"
#include "ObsArbol.h"
#include "Poder.h"
#include "PoderCorazon.h"
#include "PoderDisTri.h"
#include "PoderInvenci.h"

#include <stdlib.h>
#include <iostream>
#include <windows.h>
#include <vector>

using namespace std;

//Clase
class Escenario
{
//Atributos de la clase
    private:

        const vector <int> coord = {184, 47, 26, 7};
        // Coord[0] -> Coordenada derecha.  Coord[1] -> Coordenada abajo.  Coord[2] -> Coordenada izquierda.  Coord[3] -> Coordenada arriba.
        Tanque _tanque;
        vector <Obstaculo*> obstaculos; 
        vector <Poder*> poderes;
        vector <int> posicionesX;
        int velJuego = 25;
                    
    //Metodos
    public:

        /**
        Constructor: Incializa el escenario con sus atributos. Inicializa los vectores. Pinta los limites y al tanque en el campo de juego.
        */
        Escenario();
        /**
        Destructor: Elimina los objetos dinamicos y vacia los vectores de los mismos.
        */
        ~Escenario();
        /**
        mapearConsola(): Mapea la consola para indicar en que pocision x,y se pintará informacion.
        _x = Coordenada x;
        _y = Coordenada y;
        */
        void mapearConsola(int _x, int _y);
        /**
        pintarLimites: Pinta los limites del campo de juego.
        */
        void pintarLimites();
        /**
        pintarCorazones: Pinta los corazones actuales del tanque.
        */
        void pintarCorazones();
        /**
        pintarVidas: Pinta las vidas actuales del jugador.
        &_jugador = Acceder a la informacion y metodos de Jugador usando referencia.
        */
        void pintarVidas(Jugador &_jugador);
        /**
        pintarPuntuacion: Pinta la puntuacion actual del jugador.
        &_jugador = Acceder a la informacion y metodos de Jugador usando referencia.
        */
        void pintarPuntuacion(Jugador &_jugador);
        /**
        accionesTanqueEscenario: Usa a la funcion moverTanque para permitir su movimiento por el Escenario. Tambien llama a la funciones morir y disparar.
        &_jugador = Acceder a la informacion y metodos de Jugador usando referencia.
        */
        void accionesTanqueEscenario(Jugador &_jugador);
        /**
        accionesObstaculosEscenario: Recorre el vector de obstaculos, llamando a la funcion moverObstaculo para permitir sus movimientos por el campo de juego. Tambien llama a las funciones chocarConTanque, chocarConLimite y chocarConProyectil, para verificar si choco con el tanque, el limite inferior o algun proyectil.
        &_jugador = Acceder a la informacion y metodos de Jugador usando referencia.
        */ 
        void accionesObstaculosEscenario(Jugador &_jugador);
        /**
        accionesPoderesEscenario: Recorre el vector de poderes, llamando a la funcion moverPoder para permitir sus movimientos por el campo de juego. Tambien llama a las funciones chocarConTanque y chocarConLimite, para verificar si choco con el tanque o con el limite inferior.
        */ 
        void accionesPoderesEscenario();
        /**
        generarObstaculos: Crea los objetos dinamicos ObsCarro y ObsArbol y los enlaza a los punteros dentro del vector obstaculos. Sin parametros de entrada. (Polimorfismo Estatico)
        */ 
        void generarObstaculos();
        /**
        generarObstaculos: Crea un objeto dinamicos ObsCarro o ObsArbol de acuerdo a la clase que entra por parametro.
        _nuevaPosicionX = Nueva posicion x del obstaculo que no se repite.
        _clase = Nombre de una de las clases heredadas de obstaculo.
        */ 
        void generarObstaculos(int _nuevaPosicionX, string _clase);
        /**
        generarPoderes: Crea los objetos dinamicos poderCorazones, PoderDisTri y PoderInvenci  de acuerdo con la puntuacion del jugador.
        &_jugador = Acceder a la informacion y metodos de Jugador usando referencia.
        */ 
        void generarPoderes(Jugador &_jugador);
        /**
        destruirObjetos: Destruye el objeto dinamico ObsArbol o ObsCarro, borra el puntero enlazado a este, y borra la poscion X del obstaculo en el vetor posicionesX.
        _cualObjeto = Posicion del obstaculo en el vector.
        &_obstaculos = Vector de obstaculos por referencia.
        */ 
        void destruirObjetos(int _cualObjeto, vector<Obstaculo*> &_obstaculos);
        /**
        destruirObjetos: Destruye el objeto dinamico poderCorazones, PoderDisTri o PoderInvenci y borra el puntero enlazado a este.
        _cualObjeto = Posicion del obstaculo en el vector.
        &_obstaculos = Vector de poderes por referencia.
        */ 
        void destruirObjetos(int _cualObjeto, vector<Poder*> &_poderes);
        /**
        seRepiteX: Retorna un x, que no es igual a las posiciones de los otros obstaculos en pantallas, en un rango de 3 posiciones a la izquierda y a la derecha.
        */ 
        int seRepiteX();
        /**
        pintarGameOver: Limpia la consola y pinta el mensaje de gameOver.
        */ 
        void pintarGameOver();
        /**
        pintarTablaPuntuacion: Pinta el nombre del jugador y la puntuacion obtenida.
        */ 
        void pintarTablaPuntuacion(Jugador &_jugador);
        /**
        aumDificultad: AAumenta la velocidad del juego y el nivel de acuerdo con la puntuacion del jugador. Se basa en el atributo del escenario velJuego.
        &_jugador = Acceder a la informacion y metodos de Jugador usando referencia.
        */ 
        void aumDificultad(Jugador &_jugador);

};

#endif