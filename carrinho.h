#include<iostream>
using namespace std;
#include"lista.h"

class Animal
{
protected:
    string nome;
    ListaDE<string> estados;
public:
    Animal(string n): nome(n){}
    void add_estado(string estado) {
        estados.insere_fim(estado);
    }
};

class Cachorro : public Animal
{
private:
    string raca;
public:
    Cachorro(string raca) : Animal(nome){
        this->raca = raca;
    }
};

class Gato : public Animal
{
private:
    string pelagem;
public:
    Gato(string pelagem) : Animal(nome){
        this->pelagem = pelagem;
    }
};

class Servico
{
private:
    float preco;
    string estado, nome;
public:
    Servico(string n, float p, string e): nome(n), preco(p), estado(e) {};
    void add_estado(Animal pet) {
        
    }
};
