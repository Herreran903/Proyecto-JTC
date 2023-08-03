/**
Archivo: ObsCarro.h
Autores: Nicolas Herrera <herrera.nicolas@correounivalle.edu.co>
         Hernán Cisneros <hernan.cisneros@correounivalle.edu.co>
         Samuel Galindo <samuel.galindo@correounivalle.edu.co>
Fecha creacion: 2022-07-02
fecha ultima modificacion: 2022-08-07
Licencia: GNU-GPL
Version: 11

  CLASE: ObsCarro
  INTENCION: Construir una clase hija de Obstaculo, utilizando herencia y polimorfismo, esta clase imprime objetos con una dimensión establecida, usa el prefijo public Obstaculo, usa funciones virtuales de Obstaculo. Ademas podra ser destruida por los proyectiles y en caso de colisionar con la Tanque se destruira y le quitara un corazon al Tanque.
  RELACIONES:
    - Es hijo de Obstaculo. 
	- Conoce a Tanque.
	- Conoce a Jugador.
    
*/

#ifndef _OBSTACULO_CARRO_
#define _OBSTACULO_CARRO_

#include "Obstaculo.h"

class ObsCarro : public Obstaculo
{
	private:
		
	public:
	
		/**
    	Constructor: Crea el objeto ObsCarro con sus atributos iniciales. 
   		_iniX: Coordenada inicial x. 
    	_iniY: Coordenada inicial y.
		*/
		ObsCarro(int _iniX, int _iniY);
		/**
        Destructor
        */
		~ObsCarro();
		/**
        pintarObstaculo: Pinta el ObsCarro en el campo de juego.
        */
		virtual void pintarObstaculo();
		/**
        pintarObstaculo: Borra el ObsCarro.
        */
		virtual void borrarObstaculo();
		/**
        chocarConTanque: Retorna True si la pocision del ObsCarro concide con la pocision de el Tanque (chocan) dismuyendo un corazon del tanque. En caso contrario, retorna false.
		&_tanque = Acceder a la informacion y metodos de Tanque usando referencia.
        */
		bool chocarConTanque(Tanque &_tanque);
		/**
        chocarConProyectil: Retorna True si la pocision del ObsCarro concide con la pocision de un proyectil (chocan) aumentando la puntuacion del jugador. En caso contrario, retorna False.
		&_proyectiles = Acceder al vector de proyectiles por referencia.
		&_tanque = Acceder a la informacion y metodos de Tanque usando referencia.
        */
		bool chocarConProyectil(vector <Proyectil*> &_proyectiles, Jugador &_jugador);
		/**
        chocarConLimite: Retorna True si la pocision del ObsCarro concide con el limite inferior del campo de juego.
		_limiteInferior: Coordenada limite inferior del campo de juego.
        */
		virtual bool chocarConLimite(int _limiteInferior);

};

#endif