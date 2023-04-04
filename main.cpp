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
    string sexo, nome, cargo, turno, pet_raca, pet_nome;
    PetShop t1("T1", "16.925.208/0001-51");
    Cliente * user_cliente;
    Funcionario * user_funcionario;
    Animal * user_pet;
    int num_casa;
    string bairro, rua;

    cout << "Bem-vindo ao Petshop " <<t1.get_nome()<<endl<< endl;

    // Criacao do primeiro funcionario
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
    cout<<"Insira o numero da casa do funcionario: ";
    cin>>num_casa;
    cout<<"Insira o bairro em que o funcionario vive: ";
    cin>>bairro;
    cout<<"Insira a rua em que o funcionario vive: ";
    cin>>rua;
    t1.add_funcionario(nome, cpf, sexo, num_casa, bairro, rua, cargo, turno);


    //Criacao do primeiro Serviço
    string serv_nome, serv_estado;
    float serv_preco;
    int serv_opcao;
    Servico * serv_escolhido;
    
    cout << "Por favor, crie o seu primeiro servico antes de acessar o menu do petshop."<< endl;
    cout<<"Insira o nome do servico: ";
    cin>> serv_nome;
    cout<<"Insira qual estado sera aplicado ao pet que utilizar esse servico: ";
    cin>>serv_estado;
    cout<<"Insira o preco desse servico: ";
    cin>> serv_preco;
    t1.add_servico(serv_nome, serv_estado, serv_preco);


    do {
        cout << "Escolha uma opcao:" << endl;
        cout << "1 - Criar cliente" << endl;
        cout << "2 - Visualizar clientes" << endl;
        cout << "3 - Visualizar funcionarios" << endl;
        cout << "4 - Visualizar servicos" << endl;
        cout << "5 - Entrar como cliente" << endl;
        cout << "6 - Entrar como funcionario" << endl;
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
                cout<<"Insira o numero da casa do cliente: ";
                cin>>num_casa;
                cout<<"Insira o bairro em que o cliente vive: ";
                cin>>bairro;
                cout<<"Insira a rua em que o cliente vive: ";
                cin>>rua;
                t1.add_cliente(nome, cpf, sexo, num_casa, bairro, rua, dinheiro);
                break;
            case 2:// Mostra lista de clientes
                t1.imprime_clientes();
                system("pause");
                break;
            case 3:// Mostra lista de funcionarios
                t1.imprime_funcionarios();
                system("pause");
                break;
            case 4:// Mostra lista de funcionarios
                t1.imprime_servicos();
                system("pause");
                break;
            case 5: // Menu cliente
                cout<<"Escolha um cliente: "<<"\n\n"; //mostra as opções de funcionarios
                t1.enumera_clientes();
                cin>>user_opcao;

                if (user_opcao >= t1.get_n_clientes() or user_opcao < 0) {
                    cout<<"Numero invalido!"<<endl;
                    break;
                }

                user_cliente = t1.get_cliente_index(user_opcao);
                t1.remove_cliente(user_opcao);
                cout << "Bem-vindo "<<user_cliente->get_nome()<<" ao menu do cliente" << "\n"<< endl;
                do
                {
                    cout << "O saldo atual de "<<user_cliente->get_nome() <<" e de R$"<<user_cliente->get_dinheiro()<<"."<< endl;
                    cout << "1 - Visualizar perfil" << endl;
                    cout << "2 - Adicionar um pet" << endl;
                    cout << "3 - Usar servico no pet" << endl;
                    cout << "0 - Encerrar a sessao." << endl;
                    cin>>menu_usuario;
                    switch (menu_usuario)
                    {
                    case 1:
                        user_cliente->imprime();
                        break;

                    case 2:
                        cout<<"Insira a raca do pet: ";
                        cin>>pet_raca;
                        cout<<"Insira o nome do pet: ";
                        cin>>pet_nome;
                        user_cliente->add_pet(pet_nome, pet_raca);
                        break;
                    
                    case 3:
                        if (user_cliente->get_n_pets() == 0) {
                            cout<<"Voce nao possui Pets!"<<endl;
                            break;
                        }
                        cout<<"Escolha um servico: "<<"\n\n"; //mostra as opções de servicos
                        t1.enumera_servicos();
                        cin>>serv_opcao; //adicionar mecanica de break caso numero invalido

                        if (serv_opcao >= t1.get_n_servicos() or serv_opcao < 0) {
                            cout<<"Numero invalido!"<<endl;
                            break;
                        }

                        serv_escolhido = t1.get_servico_index(serv_opcao);

                        if (serv_escolhido->get_preco() > user_cliente->get_dinheiro()){
                            cout<<"Você não possui dinheiro suficiente!"<<endl;
                            break;
                        }

                        cout<<"Escolha um pet: "<<"\n\n"; //mostra as opções de servicos
                        user_cliente->enumera_pets();
                        cin>>serv_opcao;

                        if (serv_opcao >= user_cliente->get_n_pets() or serv_opcao < 0) {
                            cout<<"Numero invalido!"<<endl;
                            break;
                        }

                        user_pet = user_cliente->get_pet_index(serv_opcao);


                        user_pet->add_estado(serv_escolhido->get_estado());
                        user_cliente->add_pet_c_estado(user_pet);
                        user_cliente->tira_dinheiro(serv_escolhido->get_preco());
                        user_cliente->remove_pet(serv_opcao);
                        delete user_pet;
                        delete serv_escolhido;
                        break;
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
            case 6: // Menu funcionário

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
                    cout << "2 - Criar servico" << endl;
                    cout << "3 - Excluir cliente" << endl;
                    cout << "4 - Excluir funcionario" << endl;
                    cout << "5 - Excluir servico" << endl;
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
                        cout<<"Insira o numero da casa do funcionario: ";
                        cin>>num_casa;
                        cout<<"Insira o bairro em que o funcionario vive: ";
                        cin>>bairro;
                        cout<<"Insira a rua em que o funcionario vive: ";
                        cin>>rua;
                        t1.add_funcionario(nome, cpf, sexo, num_casa, bairro, rua, cargo, turno);
                        break;
                        
                    case 2: // cria um servico
                        cout<<"Insira o nome do servico: ";
                        cin>> serv_nome;
                        cout<<"Insira qual estado sera aplicado ao pet que utilizar esse servico: ";
                        cin>>serv_estado;
                        cout<<"Insira o preco desse servico: ";
                        cin>> serv_preco;
                        t1.add_servico(serv_nome, serv_estado, serv_preco);
                        break;

                    case 3:
                        cout<<"Escolha um cliente: "<<"\n\n"; //mostra as opções de clientes
                        t1.enumera_clientes();
                        cin>>opcao_deleta;
                        if (opcao_deleta >= t1.get_n_clientes() or opcao_deleta < 0) {
                            cout<<"Numero invalido!"<<endl;
                            break;
                        }
                        t1.remove_cliente(opcao_deleta);
                        break;
                    case 4: // excluí funcionario
                        
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
                    
                    case 5:
                        if(t1.get_n_servicos() == 1) {
                            cout<<"A loja deve possuir pelo menos 1 servico"<<endl;
                            break;
                        } else{
                            cout<<"Escolha um servico: "<<"\n\n"; //mostra as opções de servicos
                            t1.enumera_servicos();
                            cin>>opcao_deleta;
                            if (opcao_deleta >= t1.get_n_servicos() or opcao_deleta < 0) {
                                cout<<"Numero invalido!"<<endl;
                                break;
                            }
                            t1.remove_servico(opcao_deleta);
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
