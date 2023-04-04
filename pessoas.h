#include<iostream>
using namespace std;

class Endereco {
    private:
        string rua;
        string bairro;
        int numero_da_casa;
    
    public:
        
        Endereco() {
            rua = "";
            bairro = "";
            numero_da_casa = 0;
        }

        Endereco(string r, string b, int n) {
            rua = r;
            bairro = b;
            numero_da_casa = n;
        }
        
        // Métodos de acesso
        string getRua() {
            return rua;
        }
        
        void setRua(string r) {
            rua = r;
        }
        
        string getBairro() {
            return bairro;
        }
        
        void setBairro(string b) {
            bairro = b;
        }
        
        int getNumeroDaCasa() {
            return numero_da_casa;
        }
        
        void setNumeroDaCasa(int n) {
            numero_da_casa = n;
        }
};


//Classe animal, pets dos Clientes
class Animal
{
private:
    string nome;
    string raca;
    ListaDE<string> estados;

    void imprime_estados(){
      ElementoListaDE<string> * nav = estados.inicio;
      cout<<"Estados: ";
      while (nav != nullptr)
      {
        cout<<nav->dado;
        if(nav->proximo!= nullptr) {
          cout<<", ";
        }
        nav = nav->proximo;
      }
      cout<<endl<<endl;
    }
public:
    Animal(string n, string r): nome(n), raca(r){}
    
    void add_estado(string estado) {
        estados.insere_fim(estado);
    }

    string get_nome(){
      return nome;
    }

    string get_raca(){
      return raca;
    }

    ListaDE<string> get_estados() {
      return estados;
    }

    void imprime() {
      cout << "Nome: " << this->nome << endl;
      cout << "Raca: " << this->raca << endl;
      this->imprime_estados();
    }
};

// Classe pessoa (pai de cliente e funcionario)
class Pessoa {
protected:
  string nome;
  long long int cpf;
  string sexo;
  Endereco end;

public:
  Pessoa(string nome, long long int cpf, string sexo, int num_casa, string bairro, string rua) {
    this->nome = nome;
    this->cpf = cpf;
    this->sexo = sexo;
    end.setBairro(bairro);
    end.setNumeroDaCasa(num_casa);
    end.setRua(rua);
  }


  string get_nome() {
    return this->nome;
  }

  long long int get_cpf() {
    return this->cpf;
  }

  string get_sexo() {
    return this->sexo;
  }

  string get_bairro() {
    return end.getBairro();
  }

  string get_rua() {
    return end.getRua();
  }

  int get_num_casa() {
    return end.getNumeroDaCasa();
  }

  void imprime() {
    cout << "Nome: " << this->nome << endl;
    cout << "Sexo: " << this->sexo << endl;
    cout << "CPF: " << this->cpf << endl;
    cout << "Bairro: " << this->end.getBairro() << endl;
    cout << "Rua: " << this->end.getRua() << endl;
    cout << "Numero da casa: " << this->get_num_casa() << endl;
  }
};
// Criação da classe Cliente
class Cliente : public Pessoa {
private:
  float dinheiro;
  ListaDE<Animal> pets;

public:
  Cliente(string nome, long long int cpf, string sexo, int num_casa, string bairro, string rua, float dinheiro)
      : Pessoa(nome, cpf, sexo, num_casa, bairro, rua) {
    this->dinheiro = dinheiro;
  }

  void add_pet(string nome, string raca){
    Animal temp(nome, raca);
    pets.insere_fim(temp);
  }

  void add_pet_c_estado(Animal * pet){
    Animal temp(pet->get_nome(), pet->get_raca());
    
    ListaDE<string> est = pet->get_estados();

    ElementoListaDE<string> * nav = est.inicio;
    while (nav != nullptr)
    {
      temp.add_estado(nav->dado);
      nav = nav->proximo;
    }
    pets.insere_fim(temp);
  }

  void remove_pet(int index) {
    pets.remove_pos(index);
  }

  void tira_dinheiro(float preco) {
    dinheiro = dinheiro - preco;
  }

  void imprime() {
    Pessoa::imprime();
    cout << "Dinheiro de "<<nome<<": R$"<< this->dinheiro << endl<<endl;
    ElementoListaDE<Animal> * nav = pets.inicio;
    cout<<"Pets: "<<endl;
    while (nav!=nullptr)
    {
      nav->dado.imprime();
      nav = nav->proximo;
    }
    cout<<endl;
  }

  Animal * get_pet_index(int index) {
    Animal temp = pets.retorna_p_indice(index);
    Animal * novo = new Animal(temp.get_nome(), temp.get_raca());

    ListaDE<string> est = temp.get_estados();
    ElementoListaDE<string> * nav = est.inicio;
    while (nav != nullptr)
    {
      novo->add_estado(nav->dado);
      nav = nav->proximo;
    }

    return novo;
  }

  void enumera_pets(){
    cout<<endl;
    for(int i=0; i<pets.tamanho(); i++) {
        cout<< i <<" - "<< pets.retorna_p_indice(i).get_nome()<<endl;
    }
    cout<<endl;
  }

  int get_n_pets() {
    return pets.tamanho();
  }

  float get_dinheiro() {
    return this->dinheiro;
  }
};
// Criação da classe Funcionario
class Funcionario : public Pessoa {
private:
  string cargo;
  string turno;

public:
  Funcionario(string nome, long long int cpf, string sexo, int num_casa, string bairro, string rua, string cargo,
              string turno)
      : Pessoa(nome, cpf, sexo, num_casa, bairro, rua) {
    this->cargo = cargo;
    this->turno = turno;
  }
  void imprime() {
    Pessoa::imprime();
    cout << "Cargo: " << this->cargo << endl;
    cout << "turno: " << this->turno << endl;
    cout<<endl;
  }

  string get_cargo() {
    return this->cargo;
  }

  string get_turno() {
    return this->turno;
  }
};