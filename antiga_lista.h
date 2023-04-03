

template <typename TIPO>
struct ElementoListaNum
{
    TIPO dado;
    int num;
    ElementoListaNum * anterior;
    ElementoListaNum * proximo;
    ElementoListaNum(TIPO d): dado(d), proximo(nullptr), anterior(nullptr), num(1){}
};

template <typename TIPO> 
ElementoListaNum<TIPO> *novoelementoLN(TIPO dado) {
  ElementoListaNum<TIPO> *novo = new ElementoListaNum<TIPO>(dado);
  return novo;
}

template <typename TIPO>
struct ListaNum
{
    ElementoListaNum<TIPO> * inicio = nullptr;
    ElementoListaNum<TIPO> * fim = nullptr;

    ElementoListaNum<TIPO> * procura(int prod_id){
        ElementoListaNum<TIPO> * nav = inicio;
        while (inicio != nullptr)
        {
            if (inicio->dado)
        }
        
    }
    
    void push(TIPO dado) {
    ElementoListaNum<TIPO> *novo = novoelementoLN(dado);
    novo->anterior = fim;
    fim = novo;
    if (novo->anterior != nullptr) {
      ElementoListaDE<TIPO> *anterior = novo->anterior;
      anterior->proximo = novo;
    } else {
      inicio = novo;
    }



    TIPO pop() {
    if (inicio == nullptr) {
      return false;
    } else {
      ElementoListaNum<TIPO> *apagado = inicio;
      inicio = apagado->proximo;
      if (inicio != nullptr) {
        inicio->anterior = nullptr;
        if (inicio->proximo == nullptr) {
          fim = inicio;
        }
      }
      delete apagado;
      return true;
    }
  }

  int tamanho() {
    ElementoListaDE<TIPO> *nav = inicio;
    int cont = 0;
    while (nav != nullptr) {
      cont++;
      nav = nav->proximo;
    }
    return cont;
  }
}
};