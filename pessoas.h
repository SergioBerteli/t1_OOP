#include<iostream>
using namespace std;

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
      cout<<endl;
    }
public:
    Animal(string n, string r): nome(n), raca(r){}
    
    void add_estado(string estado) {
        estados.insere_fim(estado);
    }

    void imprime() {
      cout << "Nome: " << this->nome << endl;
      cout << "Raça: " << this->raca << endl;
      this->imprime_estados();
    }
};

// Classe pessoa (pai de cliente e funcionario)
class Pessoa {
protected:
  string nome;
  long long int cpf;
  string sexo;

public:
  Pessoa(string nome, long long int cpf, string sexo) {
    this->nome = nome;
    this->cpf = cpf;
    this->sexo = sexo;
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

  void imprime() {
    cout << "Nome: " << this->nome << endl;
    cout << "Sexo: " << this->sexo << endl;
    cout << "CPF: " << this->cpf << endl;
  }
};
// Criação da classe Cliente
class Cliente : public Pessoa {
private:
  float dinheiro;
  ListaDE<Animal> pets;

public:
  Cliente(string nome, long long int cpf, string sexo, float dinheiro)
      : Pessoa(nome, cpf, sexo) {
    this->dinheiro = dinheiro;
  }

  void add_pet(string nome, string raca){
    Animal temp(nome, raca);
    pets.insere_fim(temp);
  }

  void imprime() {
    Pessoa::imprime();
    cout << "Dinheiro de "<<nome<<": R$"<< this->dinheiro << endl;
    ElementoListaDE<Animal> * nav = pets.inicio;
    cout<<"Pets: "<<endl;
    while (nav!=nullptr)
    {
      nav->dado.imprime();
    }
    
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
  Funcionario(string nome, long long int cpf, string sexo, string cargo,
              string turno)
      : Pessoa(nome, cpf, sexo) {
    this->cargo = cargo;
    this->turno = turno;
  }
  void imprime() {
    Pessoa::imprime();
    cout << "Cargo: " << this->cargo << endl;
    cout << "turno: " << this->turno << endl;
  }

  string get_cargo() {
    return this->cargo;
  }

  string get_turno() {
    return this->turno;
  }
};