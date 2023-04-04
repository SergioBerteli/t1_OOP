//#include"lista.h"
//#include"pessoas.h"
//Classe principal: PetShop

class Servico
{
private:
    string nome, estado;
    float preco;
public:
    Servico(string n, string e, float p) : nome(n), estado(e), preco(p) {}
    
    string get_nome(){
        return nome;
    }

    string get_estado(){
        return estado;
    }
    

    float get_preco(){
        return preco;
    }

    void imprime(){
        cout << "Servico: " << this->nome << endl;
        cout << "Preco: R$" << this->preco << endl;
    }
};


class PetShop {
    private:
        string nome, CNPJ;
        ListaDE<Cliente> clientes;
        ListaDE<Funcionario> funcionarios;
        ListaDE<Servico> servicos;
    public:

        PetShop(string nome, string CNPJ) { //Construtor do PetShop
            this->nome = nome;
            this->CNPJ = CNPJ;
        }

        ~PetShop(){
            cout << endl  << "Obrigado por utilizar o Petshop!" << endl;
        }

        void add_cliente(string nome, long long int cpf, string sexo, int num_casa, string bairro, string rua, float dinheiro){
            Cliente temp(nome, cpf, sexo, num_casa, bairro, rua, dinheiro);
            clientes.insere_fim(temp);
        }

        void add_funcionario(string nome, long long int cpf, string sexo, int num_casa, string bairro, string rua, string cargo,
              string turno){
            Funcionario temp(nome, cpf, sexo, num_casa, bairro, rua, cargo, turno);
            funcionarios.insere_fim(temp);
        }

        void add_servico(string nome, string estado, float preco) {
            Servico temp(nome, estado, preco);
            servicos.insere_fim(temp);
        }

        void remove_cliente(int index){
            clientes.remove_pos(index);
        }
        
        void remove_funcionario(int index){
            funcionarios.remove_pos(index);
        }

        void remove_servico(int index){
            servicos.remove_pos(index);
        }

        Cliente * get_cliente_index(int index){ //retorna um ponteiro cliente
            Cliente temp = clientes.retorna_p_indice(index);
            Cliente * novo = new Cliente(temp.get_nome(), temp.get_cpf(), temp.get_sexo(), temp.get_num_casa(), temp.get_bairro(), temp.get_rua(), temp.get_dinheiro());
            return novo;
        }

        Funcionario * get_funcionario_index(int index){ //retorna um ponteiro cliente
            Funcionario temp = funcionarios.retorna_p_indice(index);
            Funcionario * novo = new Funcionario(temp.get_nome(), temp.get_cpf(), temp.get_sexo(), temp.get_num_casa(), temp.get_bairro(), temp.get_rua(), temp.get_cargo(), temp.get_turno());
            return novo;
        }

        Servico * get_servico_index(int index) {
            Servico temp = servicos.retorna_p_indice(index);
            Servico * novo = new Servico(temp.get_nome(), temp.get_estado(), temp.get_preco());
            return novo;
        }

        void enumera_clientes(){
            cout<<endl;
            for(int i=0; i<clientes.tamanho(); i++) {
                cout<< i <<" - "<< clientes.retorna_p_indice(i).get_nome()
                <<"; cpf: "<< clientes.retorna_p_indice(i).get_cpf() <<endl;
            }
            cout<<endl;
        }

        void enumera_funcionarios(){
            cout<<endl;
            for(int i=0; i<funcionarios.tamanho(); i++) {
                cout<< i <<" - "<< funcionarios.retorna_p_indice(i).get_nome()
                <<"; cpf: "<< funcionarios.retorna_p_indice(i).get_cpf() <<endl;
            }
            cout<<endl;
        }

        void enumera_servicos(){
            cout<<endl;
            for(int i=0; i<servicos.tamanho(); i++) {
                cout<< i <<" - "<< servicos.retorna_p_indice(i).get_nome()<<endl;
            }
            cout<<endl;
        }

        void imprime_servicos(){
            ElementoListaDE<Servico> * nav = servicos.inicio;
            while (nav != nullptr)
            {
                nav->dado.imprime();
                nav = nav->proximo;
            }
        }

        void imprime_clientes(){
            ElementoListaDE<Cliente> * nav = clientes.inicio;
            while (nav != nullptr)
            {
                nav->dado.imprime();
                nav = nav->proximo;
            }
        }

        void imprime_funcionarios(){
            ElementoListaDE<Funcionario> * nav = funcionarios.inicio;
            while (nav != nullptr)
            {
                nav->dado.imprime();
                nav = nav->proximo;
            }
        }
        
        string get_nome(){
            return this->nome;
        }

        int get_n_clientes() {
            return clientes.tamanho();
        }

        int get_n_funcionarios() {
            return funcionarios.tamanho();
        }

        int get_n_servicos() {
            return servicos.tamanho();
        }
};