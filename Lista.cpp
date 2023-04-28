#include "Lista.h"
#include <cassert>

Lista::Lista() : tam_(0), prim(NULL), ult(NULL){}

Lista::Lista(const Lista& l) : Lista() {
    //Inicializa una lista vacía y luego utiliza operator= para no duplicar el código de la copia de una lista.
    *this = l;
}

Lista::~Lista() {
    destruirNodos();
}

Lista& Lista::operator=(const Lista& aCopiar) {
    destruirNodos();
    copiarNodos(aCopiar);
    return *this;
}

void Lista::agregarAdelante(const int& elem) {
    Nodo* nuevo = new Nodo(nullptr,elem,prim);
    if(prim == nullptr) {
        prim = nuevo;
        ult = nuevo;
        return;
    }
    Nodo* actual = ult;
    while(actual->ant != nullptr) {
        actual = actual -> ant;
    }
    actual->ant = nuevo;
    prim=nuevo;
}

void Lista::agregarAtras(const int& elem) {
    Nodo* nuevo = new Nodo(ult,elem, nullptr);
    if (prim == nullptr) {
        prim = nuevo;
        ult = nuevo;
        return;
    }
    Nodo* actual = prim;
    while(actual->sig != nullptr) {
        actual = actual -> sig;
    }
    actual->sig = nuevo;
    ult=nuevo;
}




void Lista::eliminar(Nat i) {
    Nodo* actual = prim;
    for (int j = 0; j < i; ++j) {
        actual = actual->sig;
    }

  if(0!=i && i!=longitud()-1){
      (actual->ant)->sig=actual->sig;
      (actual->sig)->ant=actual->ant;
  } else {
      if(i==0){
          if(prim->sig== nullptr){
              prim=actual->sig;
          } else {
              prim=actual->sig;
              prim->ant= nullptr;
          }
      } else {
          if (i==longitud()-1){
              (actual->ant)->sig= nullptr;
              ult=actual->ant;
              //ult->sig= nullptr;
          }
      }
  }
  delete actual;
 tam_--;
}


int Lista::longitud() const {
    Nodo* actual = prim;
    int contador = 0;
    while (actual != nullptr) {
        contador++;
        actual = actual->sig;
    }
    return contador;
}

const int& Lista::iesimo(Nat i) const {
    Nodo* actual = prim;
    for (int j = 0; j < i; ++j) {
        actual = actual->sig;
    }
    return actual->valor;
    assert(false);
}

int& Lista::iesimo(Nat i) {
    Nodo* actual = prim;
    for (int j = 0; j < i; ++j) {
        actual = actual->sig;
    }
    return actual->valor;
    assert(false);
}

void Lista::mostrar(ostream& o) {
    }


//Aux
void Lista::copiarNodos(const Lista &aCopiar) {
    Nodo* actual = aCopiar.prim;
    while (actual != nullptr) {
        agregarAtras(actual->valor);
        actual = actual->sig;
    }
}
void Lista::destruirNodos() {
    Nodo* actual = prim;
    while (actual != nullptr) {
        Nodo* siguiente = actual->sig;
        delete actual;
        actual = siguiente;
    }
    prim = nullptr;
    ult = nullptr;
    tam_ = 0;
}