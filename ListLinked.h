#include <ostream>
#include <exception>
#include <ostream>

#include "List.h"
#include "Node.h"

template <typename T>
class ListLinked : public List<T> {

            private:
                    //Puntero al primer nodo de la secuencia enlazada que almacena los datos de la lista (de tipo T genérico)

                    Node<T>* first;

                    //Número de elementos que contiene la lista

                    int n;
          

            public:

                    //Método constructor sin argumentos. Inicializará los dos atributos de instancia (first será nullptr).

                    ListLinked(){

                        first = nullptr;
                        n = 0;


                    }

                    //Método destructor. Se encargará de liberar la memoria dinámica reservada por los nodos Node<T> que componen la secuencia. Ver la nota de abajo para más detalles.

                    ~ListLinked(){

                        Node<T>* aux = first;
                        
                        while(n != 0){

                                aux = first;
                                first = first->next;
                                delete aux;
                                

                        }

                        delete first;

                    }

                    //Sobrecarga del operador []. Devuelve el elemento situado en la posición pos. Lanza una excepción std::out_of_range si la posición no es válida (fuera del intervalo [0, size()-1]).

                    T operator[](int pos){

                        if(pos < 0 || pos > size()-1){

                                throw std::out_of_range("posición no válida");

                        }
                        
                        Node<T>* aux = first;

                        while(aux->next != pos){

                                aux = aux->next;

                        }

                        aux->data = aux[pos];
                        


                    }

                    //Sobrecarga global del operador << para imprimir una instancia de ListLinked<T> por pantalla. Recuerda incluir la cabecera <ostream> en el .h.

                    friend std::ostream& operator<<(std::ostream &out, const ListLinked<T> &list){

                        Node<T>* aux = first;

                        while(aux->next != nullptr){

                                out<<aux->data<<std::endl;
                                aux = aux->next;

                        }


                        return out;

                    }
                    
                    
  //añade un metodo sobrecarga de la operacion suma(+), tendrá como parámetros las dos listas a sumar L1 y L2, y devolverá una nueva lista con la suma de ambas
  
   T operator[](const Listlinked<T>& list) const {
   		
   	
  }
  
  friend std::ostream& operator+(std::ostream &out,const ListArray<T> &list){
 		  
return out;}
        //Inserta el elemento e en la posición pos. Lanza una excepción std::out_of_range si la posición pos no es válida (fuera del intervalo [0, size()]).
        
        void insert(int pos, T e){

                if(pos < 0 || pos > size()){

                        throw std::out_of_range("Posición no válida");

                }else{

                        Node<T>* aux_d = first; //nodo auxiliar que se situará a la derecha para guardar la dirección de memoria y que el que se inserte se "enganche a él"
                        Node<T>* aux_i = first; //nodo auxiliar que se situará a la izquierda para que el nodo anterior al que se añada pueda recibir la dirección de memoria del siguente
                        int i = 0; // contador de posición
                        
                        while(i <= pos ){

                                aux_i = aux_d;
                                aux_d = aux_d->next;
                                i++;

                        }
                        // Ya estamos posicionados

                        aux_i->next = new Node<T>(e, aux_d);
                        


                }

        }

        //Inserta el elemento e al final de la lista.

        void append(T e){

                Node<T>* aux = first;
                
                while(aux != nullptr){

                        aux = aux->next;

                }
                aux->next = new Node<T>(e,nullptr);
                

        }

        //Inserta el elemento e al principio de la lista.

        void prepend(T e){

                first = new Node<T>(e,first->next);


        }
        
        //Elimina y devuelve el elemento situado en la posición pos. Lanza una excepción std::out_of_range si la posición no es válida (fuera del intervalo [0, size()-1]).


        T remove(int pos){

                if(pos < 0 || pos > size()-1){

                        throw std::out_of_range("posición no válida");

                }else{

                        Node<T>* aux_d = first;
                        Node<T>* aux_i = first;
                        int i = 0;

                        while(i <= pos){

                                aux_i = aux_d;
                                aux_d = aux_d->next;

                                i++;
                        }
               
                        int ret = aux_d->data;
                        aux_i = aux_d->next;
                        delete aux_d;

                }

                return ret;

        }

        //Devuelve el elemento situado en la posición pos. Lanza una excepción std::out_of_range si la posición no es válida (fuera del intervalo [0, size()-1]).

        get(int pos){

                Node<T>* aux = first;

                int i = 0;

                while(i <= pos){

                        aux = aux->next;

                }

                return aux->data;

        }

        //Indica si la lista está vacía.

        bool empty(){


        }

        //Devuelve el número de elementos de la lista.

        int size(){


        }
        void invert_list() override{

		Node<T> *prevAux = nullptr;
		Node<T> *aux = nullptr;
		Node<T> *pivote = first;

        	while (pivote != nullptr) {
            		aux = pivote->next;
            		pivote->next = prevAux;
          		prevAux = pivote;
            		pivote = aux;
        	}

        	first = prevAux; 
    	}
};
