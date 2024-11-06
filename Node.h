#ifndef Node_H
#define Node_H

#include <ostream>

template <typename T> 
class Node {
            public:

                  //  El elemento almacenado, de tipo genérico T.
                  
                  T data;

                  //Puntero al siguiente nodo de la secuencia (o nullptr si es el último nodo de la secuencia).

                 Node<T>* next;

                  // Método constructor. next será nullptr en caso de que no se proporcione.



                 Node(T data, Node<T>* next = nullptr){

                        this->data = data;
                        this->next = next;

                }
                  //Sobrecarga global del operador << para imprimir una instancia de Node<T> por pantalla. 
                  //Se limitará a imprimir su atributo data. Recuerda incluir la cabecera <ostream> en el .h.




                 friend std::ostream& operator<<(std::ostream &out, const Node<T> &node){

                        out << "nodo -->" << node << std::endl;
                        
                        return out;

                 }
};

#endif
