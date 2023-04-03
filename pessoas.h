#include<iostream>
using namespace std;

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

public:
  Cliente(string nome, long long int cpf, string sexo, float dinheiro)
      : Pessoa(nome, cpf, sexo) {
    this->dinheiro = dinheiro;
  }

  void imprime() {
    Pessoa::imprime();
    cout << "Dinheiro de "<<nome<<": R$"<< this->dinheiro << endl;
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