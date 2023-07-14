#include "App.h"

void App::start() {
  // carregar do arquivos "arquivoClientes.txt" e "arquivoCatalogo.txt" para as listas 
  fstream arquivoClientes;
  string linha;
  arquivoClientes.open("arquivoClientes.txt", ios::in);
  // carrega as informações do arquivoClientes.txt para a lista de clientes
  if (arquivoClientes.is_open()) {
    while(getline(arquivoClientes, linha)) {
      Cliente cliente;
      string palavraAchada;
      int contador = 0;
      for(int i = 0; i < linha.size(); i++) {
        if(linha[i]!=';') {
          string s(1, linha[i]);
          palavraAchada.append(s);
        }
        else {
          contador++;
          switch (contador) {
            case 1:{
              cliente.setNome(palavraAchada);
              palavraAchada.clear();
            }
            break;
            case 2:{
              cliente.setEmail(palavraAchada);
              palavraAchada.clear();
            }
            break;
            case 3:{
              cliente.setSenha(palavraAchada);
              palavraAchada.clear();
            }
            break;
            case 4:{
              cliente.setEndereco(palavraAchada);
              palavraAchada.clear();
            }
            break;
            case 5:{
              cliente.setCelular(palavraAchada);
              palavraAchada.clear();
            }
            break;
            case 6:{
              cliente.setCpf(palavraAchada);
              palavraAchada.clear();
            }
            break;
            case 7: {
              float saldo = stod(palavraAchada);
              cliente.setSaldo(saldo);
              palavraAchada.clear();
            }
            break;
            case 8:{
              vector<int> carrinho = stringParaLista(palavraAchada); 
              cliente.setCarrinho(carrinho);
              palavraAchada.clear();
            }
            break;
            case 9:{
              vector<int> favoritos = stringParaLista(palavraAchada); 
              cliente.setFavoritos(favoritos);
              palavraAchada.clear();
            }
            break;
            case 10:{
              vector<int> meusPedidos = stringParaLista(palavraAchada); 
              cliente.setMeusPedidos(meusPedidos);
              palavraAchada.clear();
            }
            break;
            case 11:{
              vector<int> minhasVendas = stringParaLista(palavraAchada); 
              cliente.setMinhasVendas(minhasVendas);
              palavraAchada.clear();
            }
            break; 
          }
        }
      }
      addListaCliente(cliente);
    }
  }
  arquivoClientes.close();

  // carrega as informações do arquivoCatalogo.txt para a lista de roupas
  fstream arquivoRoupas;
  arquivoRoupas.open("arquivoRoupas.txt", ios::in);
  if(arquivoRoupas.is_open()) {
     while(getline(arquivoRoupas, linha)) {
      Roupa roupa;
      string palavraAchada;
      int contador = 0;
      for(int i = 0; i < linha.size(); i++) {
        if(linha[i]!=';') {
          string s(1, linha[i]);
          palavraAchada.append(s);
        }
        else{
          contador++;
          switch(contador){
            case 1:{
              roupa.setTipo(palavraAchada);
              palavraAchada.clear();
            }
            break;
             case 2:{
              roupa.setEstadoRoupa(palavraAchada);
              palavraAchada.clear();
            }
            break;
             case 3:{
              roupa.setCorRoupa(palavraAchada);
              palavraAchada.clear();
            }
            break;
             case 4:{
              char saida = palavraAchada[0];
              roupa.setGeneroRoupa(saida);
              palavraAchada.clear();
            }
            break;
             case 5:{
              char saida = palavraAchada[0];
              roupa.setTamanhoRoupa(saida);
              palavraAchada.clear();
            }
            break;
             case 6:{
              double valor = stod(palavraAchada);
              roupa.setPrecoRoupa(valor);
              palavraAchada.clear();
            }
            break;
             case 7:{
               int valor = stoi(palavraAchada);
              roupa.setID(valor);
              palavraAchada.clear();
            }
            break;
          }
        }
      }
      addListaRoupa(roupa);
     }
  arquivoRoupas.close(); 
	}
}

void App::run() {
  char opcao;
	bool logado = false;
  do{
		limpaConsole();
    cout << ">>>> Garimpô <<<<" << endl;
    cout << "Escolha uma opcao:" << endl;
    cout << "1 - Login" << endl;
    cout << "2 - Cadastro" << endl;
    cout << "3 - Sair" << endl;
    cin >> opcao;
        
    switch(opcao) {
      case '1':
      logado = login(); // função login retorna true ou false;
				while(logado){
					logado = menuLogado(); // ao sair do menu, cancela o loop;
				}
      break;
      case'2':
        cadastro();
      break;
      case'3':
        cout << "Obrigado por utilizar nosso app! Volte sempre!" << endl;
      break;
      default:
        cout << "Entrada inválida!" << endl;
      break;
 	 }
  }while(opcao!='3');
  
}

void App::finish() {
  // carregar para arquivos "arquivoClientes.txt" e "arquivoCatalogo.txt" para as listas
  // exemplo de linha do arquivo: 
	// nome;email;senha;endereço;cpf;telefone;saldo;(carrinho);(favoritos);(meuspedidos);(minhasvendas);
  // nome;email@gmail.com;senha123;endereço4500;30451608;05376623084;0;(carrinho);(favoritos);(meuspedidos);(minhasvendas);
	fstream arquivoClientes;
  arquivoClientes.open("arquivoClientes.txt",ios::out);
  if(arquivoClientes.is_open()) {
    vector<Cliente> clientes = getListaClientes();
    for(int i=0; i<clientes.size(); i++) {
      vector<int> carrinho = clientes[i].getCarrinho();
      vector<int> favoritos = clientes[i].getFavoritos();
      vector<int> meuspedidos = clientes[i].getPedidos();
      vector<int> minhasvendas = clientes[i].getVendas();
      arquivoClientes << clientes[i].getNome() << ";" 
              << clientes[i].getEmail() << ";"
              << clientes[i].getSenha() << ";"
              << clientes[i].getEndereco() << ";"
              << clientes[i].getCelular() << ";"
              << clientes[i].getCpf() << ";"
              << clientes[i].getSaldo() << ";"
              << listaParaString(carrinho) << ";"
              << listaParaString(favoritos) << ";"
              << listaParaString(meuspedidos) << ";"
              << listaParaString(minhasvendas) << ";" << endl;
    }
  }
  arquivoClientes.close();

  // exemplo de linha do arquivo:
  // tipo;estado;cor;genero;tamanho;preco;ID;
  // calca;nova;azul;m;p;55;0001;
  
  fstream arquivoRoupas;
  arquivoRoupas.open("arquivoRoupas.txt", ios::out);
  if(arquivoRoupas.is_open()) {
    vector<Roupa> roupas = getListaRoupa();
    for(int i=0; i<roupas.size(); i++) {
      arquivoRoupas << roupas[i].getTipo() << ";"
                    << roupas[i].getEstado() << ";"
                    << roupas[i].getCorRoupa() << ";"
                    << roupas[i].getGenero() << ";"
                    << roupas[i].getTamanho() << ";"
                    << roupas[i].getPrecoRoupa() << ";"
                    << roupas[i].getID() << ";" << endl;
    }
  }
  arquivoRoupas.close();
  
}