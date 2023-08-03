/**
Archivo: PoderInvenci.h
Autores: Nicolas Herrera <herrera.nicolas@correounivalle.edu.co>
         Hernán Cisneros <hernan.cisneros@correounivalle.edu.co>
         Samuel Galindo <samuel.galindo@correounivalle.edu.co>
Fecha creacion: 2022-07-02
fecha ultima modificacion: 2022-08-07
Licencia: GNU-GPL
Version: 11

  CLASE: PoderInvenci
  INTENCION: Construir una clase hija de Poder, que usara sus atributos protected, utilizando funciones virtuales puras y polimorfismo, cuando este poder colisione con el Tanque este podra absorber 5 colisiones sin perder corazones. Estos objetos son dinamicos (new).
    - Es hijo de Poder.
    - Conoce a Tanque.
    
*/

#ifndef _PODER_INVENCIBILIDAD_
#define _PODER_INVENCIBILIDAD_

#include "Poder.h"

class PoderInvenci : public Poder
{
	private:
		
	public:
		
		/**
    	Constructor: Crea el objeto PoderInvenci con sus atributos iniciales. 
   		_iniX: Coordenada inicial x. 
    	_iniY: Coordenada inicial y.
		*/
		PoderInvenci(int _iniX, int _iniY);
		/**
    	Destructor.
		*/
		~PoderInvenci();
		/**
    	pintarPoder: Pinta el PoderInvenci en el campo de juego. 
		*/
		virtual void pintarPoder();
		/**
    	efectoPoder: Llama a la funcion ActivarPoderInvenci, que aumenta en 5 el poderDisInvenci en caso de tenerlo anteriormente en 0. 
		&_tanque = Acceder a la informacion y metodos de Tanque usando referencia.
		*/
		virtual void efectoPoder(Tanque &_tanque);

};

#endif