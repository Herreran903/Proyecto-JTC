/**
Archivo: PoderCorazon.h
Autores: Nicolas Herrera <herrera.nicolas@correounivalle.edu.co>
         Hernán Cisneros <hernan.cisneros@correounivalle.edu.co>
         Samuel Galindo <samuel.galindo@correounivalle.edu.co>
Fecha creacion: 2022-07-02
fecha ultima modificacion: 2022-08-07
Licencia: GNU-GPL
Version: 11

  CLASE: PoderCorazon
  INTENCION: Construir una clase hija de Poder, que usara sus atributos protected, utilizando funciones virtuales puras y polimorfismo, cuando este poder colisione con el Tanque, le sumara una vida. Estos objetos son dinamicos (new).
    - Es hijo de Poder.
    - Conoce a Tanque.
    
*/

#ifndef _PODER_CORAZON_
#define _PODER_CORAZON_

#include "Poder.h"

class PoderCorazon : public Poder
{
	private:
		
	public:

		/**
    	Constructor: Crea el objeto PoderCorazon con sus atributos iniciales. 
   		_iniX: Coordenada inicial x. 
    	_iniY: Coordenada inicial y.
		*/
		PoderCorazon(int _iniX, int _iniY);
		/**
    	Destructor.
		*/
		~PoderCorazon();
		/**
    	pintarPoder: Pinta el poderCorazon en el campo de juego. 
		*/
		virtual void pintarPoder();
		/**
    	efectoPoder: Llama a la funcion ActivarPoderCorazon, que aumenta un corazon al tanque en caso de tener menos de 3 corazones. 
		&_tanque = Acceder a la informacion y metodos de Tanque usando referencia.
		*/
		virtual void efectoPoder(Tanque &_tanque);

};

#endif