//#include"lista.h"
//#include"pessoas.h"
//Classe principal: PetShop
class PetShop {
    private:
        string nome, CNPJ;
        ListaDE<Cliente> clientes;
        ListaDE<Funcionario> funcionarios;
    public:

        PetShop(string nome, string CNPJ) { //Construtor do PetShop
            this->nome = nome;
            this->CNPJ = CNPJ;
        }

        ~PetShop(){
            cout << endl  << "Obrigado por utilizar o Petshop!" << endl;
        }

        void add_cliente(string nome, long long int cpf, string sexo, float dinheiro){
            Cliente temp(nome, cpf, sexo, dinheiro);
            clientes.insere_fim(temp);
        }

        void add_funcionario(string nome, long long int cpf, string sexo, string cargo, string turno){
            Funcionario temp(nome, cpf, sexo, cargo, turno);
            funcionarios.insere_fim(temp);
        }

        void remove_cliente(int index){
            clientes.remove_pos(index);
        }
        
        void remove_funcionario(int index){
            funcionarios.remove_pos(index);
        }

        Cliente * get_cliente_index(int index){ //retorna um ponteiro cliente
            Cliente temp = clientes.retorna_p_indice(index);
            Cliente * novo = new Cliente(temp.get_nome(), temp.get_cpf(), temp.get_sexo(), temp.get_dinheiro());
            return novo;
        }

        Funcionario * get_funcionario_index(int index){ //retorna um ponteiro cliente
            Funcionario temp = funcionarios.retorna_p_indice(index);
            Funcionario * novo = new Funcionario(temp.get_nome(), temp.get_cpf(), temp.get_sexo(), temp.get_cargo(), temp.get_turno());
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
};