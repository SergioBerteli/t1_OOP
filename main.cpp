#include<iostream>
#include <string>
#include"lista.h"
#include"pessoas.h"
#include"petshop.h"

using namespace std;

int main(int argc, char const *argv[])
{
    int opcao, user_opcao, menu_usuario, opcao_deleta;
    long long int cpf;
    float dinheiro;
    string sexo, nome, cargo, turno;
    PetShop t1("T1", "16.925.208/0001-51");
    Cliente * user_cliente;
    Funcionario * user_funcionario;

    cout << "Bem-vindo ao Petshop " <<t1.get_nome()<<endl<< endl;
    cout << "Por favor, crie o seu primeiro funcionario antes de acessar o menu do petshop."<< endl;
    cout<<"Insira o nome do funcionario: ";
    cin>> nome;
    cout<<"Insira o sexo do funcionario: ";
    cin>>sexo;
    cout<<"Insira o cpf do funcionario (apenas numeros): ";
    cin>> cpf;
    cout<<"Insira o cargo do funcionario: ";
    cin>>cargo;
    cout<<"Insira o turno em que o funcionario trabalha: ";
    cin>>turno;
    t1.add_funcionario(nome, cpf, sexo, cargo, turno);
    do {
        cout << "Escolha uma opcao:" << endl;
        cout << "1 - Criar cliente" << endl;
        cout << "2 - Visualizar clientes" << endl;
        cout << "3 - Visualizar funcionarios" << endl;
        cout << "4 - Entrar como cliente" << endl;
        cout << "5 - Entrar como funcionario" << endl;
        cout << "0 - Sair" << endl;

        cin >> opcao;

        switch (opcao) {
            case 1: //cria cliente
                cout<<"Insira o nome do cliente: ";
                cin>> nome;
                cout<<"Insira o sexo do cliente: ";
                cin>>sexo;
                cout<<"Insira o cpf do cliente (apenas numeros): ";
                cin>> cpf;
                cout<<"Insira a quantidade de dinheiro que ele tera: ";
                cin>>dinheiro;
                t1.add_cliente(nome, cpf, sexo, dinheiro);
                break;
            case 2:// Mostra lista de clientes
                t1.imprime_clientes();
                system("pause");
                break;
            case 3:// Mostra lista de funcionarios
                t1.imprime_funcionarios();
                system("pause");
                break;
            case 4:
                cout<<"Escolha um cliente: "<<"\n\n"; //mostra as opções de funcionarios
                t1.enumera_clientes();
                cin>>user_opcao;

                if (user_opcao >= t1.get_n_clientes() or user_opcao < 0) {
                    cout<<"Numero invalido!";
                    break;
                }

                user_cliente = t1.get_cliente_index(user_opcao);
                cout << "Bem-vindo "<<user_cliente->get_nome()<<" ao menu do cliente" << "\n"<< endl;
                do
                {
                    cout << "O saldo atual de "<<user_cliente->get_nome() <<" e de R$"<<user_cliente->get_dinheiro()<<"."<< endl;
                    cout << "0 - Voltar ao menu do PetShop" << endl;
                    cin>>menu_usuario;
                    switch (menu_usuario)
                    {
                    case 0:
                        /* code */
                        break;
                    
                    default:
                        cout << "Opcao invalida!" << endl;
                        break;
                    }
                } while (menu_usuario != 0);
                delete user_cliente;
                break;
            case 5: // Menu funcionário

                cout<<"Escolha um funcionario: "<<"\n\n"; //mostra as opções de funcionarios
                t1.enumera_funcionarios();
                cin>>user_opcao;

                if (user_opcao >= t1.get_n_funcionarios() or user_opcao < 0) {
                    cout<<"Numero invalido!";
                    break;
                }

                user_funcionario = t1.get_funcionario_index(user_opcao);
                cout << "Bem-vindo "<<user_funcionario->get_nome()<<" ao menu do funcionario" << "\n"<< endl;
                do
                {
                    cout << "O seu cargo atual e "<<user_funcionario->get_cargo()<<"."<< endl;
                    cout << "1 - Criar funcionario" << endl;
                    cout << "2 - Excluir cliente" << endl;
                    cout << "3 - Excluir funcionario" << endl;
                    cout << "0 - Voltar ao menu do PetShop" << endl;
                    cin>>menu_usuario;
                    switch (menu_usuario)
                    {
                        case 1: //cria funcionario
                            cout<<"Insira o nome do funcionario: ";
                            cin>> nome;
                            cout<<"Insira o sexo do funcionario: ";
                            cin>>sexo;
                            cout<<"Insira o cpf do funcionario (apenas numeros): ";
                            cin>> cpf;
                            cout<<"Insira o cargo do funcionario: ";
                            cin>>cargo;
                            cout<<"Insira o turno em que o funcionario trabalha: ";
                            cin>>turno;
                            t1.add_funcionario(nome, cpf, sexo, cargo, turno);
                            break;
                    case 2:
                        cout<<"Escolha um cliente: "<<"\n\n"; //mostra as opções de clientes
                        t1.enumera_clientes();
                        cin>>opcao_deleta;
                        if (opcao_deleta >= t1.get_n_clientes() or opcao_deleta < 0) {
                            cout<<"Numero invalido!"<<endl;
                            break;
                        }
                        t1.remove_cliente(opcao_deleta);
                        break;
                    case 3: // excluí funcionario
                        
                        if(t1.get_n_funcionarios() == 1) {
                            cout<<"A loja deve possuir pelo menos 1 funcionario"<<endl;
                            break;
                        } else{
                            cout<<"Escolha um funcionario: "<<"\n\n"; //mostra as opções de funcionarios
                            t1.enumera_funcionarios();
                            cin>>opcao_deleta;
                            if (opcao_deleta >= t1.get_n_funcionarios() or opcao_deleta < 0) {
                                cout<<"Numero invalido!"<<endl;
                                break;
                            }
                            t1.remove_funcionario(opcao_deleta);
                            if (user_opcao == opcao_deleta) {
                                menu_usuario = 0;
                            }
                        }

                        break;
                    case 0:
                        /* code */
                        break;
                    
                    default:
                        cout << "Opcao invalida!" << endl;
                        break;
                    }
                } while (menu_usuario != 0);
                delete user_funcionario;

                break;
            case 0:
                // Sair
                break;
            default:
                cout << "Opcao invalida!" << endl;
                break;
        }
        
    } while (opcao != 0);

    if (opcao == 5) { // Menu cliente
        /* code */
        
    }else if (opcao == 6)
    {
        /* code */
    }
    
    return 0;
}
