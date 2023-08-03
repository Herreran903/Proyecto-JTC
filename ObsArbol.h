/**
Archivo: ObsArbol.h
Autores: Nicolas Herrera <herrera.nicolas@correounivalle.edu.co>
         Hernán Cisneros <hernan.cisneros@correounivalle.edu.co>
         Samuel Galindo <samuel.galindo@correounivalle.edu.co>
Fecha creacion: 2022-07-02
fecha ultima modificacion: 2022-08-07
Licencia: GNU-GPL
Version: 11

  CLASE: ObsArbol
  INTENCION: Construir una clase hija de Obstaculo, utilizando herencia y polimorfismo, esta clase imprime objetos con una dimensión establecida, usa el prefijo public Obstaculo, usa funciones virtuales de Obstaculo. Estos objetos seran indestructibles contra los proyectiles destruyendo a los proyectiles al chocar, ademas si choca con el Tanque se destruira y restara un corazon al Tanque.
  
  RELACIONES:
    - Es hijo de Obstaculo. 
	- Conoce a Tanque.
	- Conoce a Jugador.
    
*/

#ifndef _OBSTACULO_ARBOL_
#define _OBSTACULO_ARBOL_

#include "Obstaculo.h"

class ObsArbol : public Obstaculo
{
	private:
		
	public:

		/**
    	Constructor: Crea el objeto ObsArbol con sus atributos iniciales. 
   		_iniX: Coordenada inicial x. 
    	_iniY: Coordenada inicial y.
		*/
		ObsArbol(int _iniX, int _iniY);
		/**
        Destructor
        */
		~ObsArbol();
		/**
        pintarObstaculo: Pinta el ObsArbol en el campo de juego.
        */
		virtual void pintarObstaculo();
		/**
        pintarObstaculo: Borra el ObsArbol.
        */
		virtual void borrarObstaculo();
		/**
        chocarConTanque: Retorna True si la pocision del ObsArbol concide con la pocision de el Tanque (chocan) dismuyendo un corazon del tanque. En caso contrario, retorna false.
		&_tanque = Acceder a la informacion y metodos de Tanque usando referencia.
        */
		bool chocarConTanque(Tanque &_tanque);
		/**
        chocarConProyectil: Siempre Retorna False si la pocision del ObsArbol concide con la pocision de un proyectil (chocan).
		&_proyectiles = Acceder al vector de proyectiles por referencia.
		&_tanque = Acceder a la informacion y metodos de Tanque usando referencia.
        */
		virtual bool chocarConProyectil(vector <Proyectil*> &_proyectiles, Jugador &_jugador);
		/**
        chocarConLimite: Retorna True si la pocision del ObsArbol concide con el limite inferior del campo de juego.
		_limiteInferior: Coordenada limite inferior del campo de juego.
        */
        virtual bool chocarConLimite(int _limiteInferior);
		
};

#endif