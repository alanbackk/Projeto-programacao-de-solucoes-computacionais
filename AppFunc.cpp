#include "AppFunc.h"

vector<Cliente> AppFunc::getListaClientes() { return listaClientes; }
void AppFunc::addListaCliente(Cliente _cliente) { listaClientes.push_back(_cliente); }

vector<Roupa> AppFunc::getListaRoupa() { return listaCatalogo; }
void AppFunc::addListaRoupa(Roupa _roupa) { listaCatalogo.push_back(_roupa); }

// função para transformar uma lista em um texto para adicionar ao "BD"
string AppFunc::listaParaString (vector<int> lista) {
  string listaTxt = "(";
  for(int i=0; i<lista.size(); i++) {
    string s = to_string(lista[i]);
    listaTxt.append(s + ",");
  }
  listaTxt.append(")");
  return listaTxt;
}

// função para passar informações de uma string para uma lista
vector<int> AppFunc::stringParaLista(string str) {
  vector<int> lista;
  string palavraAchada;
  str.replace(0, 1, "");
  str.pop_back();
  for(int i=0; i<str.size(); i++) {
    if(str[i] != ',') {
      string s(1, str[i]);
      palavraAchada.append(s);
    } else {
      int valor = stoi(palavraAchada);
      lista.push_back(valor);
      palavraAchada = "";
    }
  }
  return lista;
}

// função para checar os requisitos para criação de senha
bool AppFunc::passCheck(string pass) {
  string proibidos = ";,()";
  string spChar = "!@#$%&*";
  string nums = "1234567890";
  
  bool hasSpChar = false;
  bool hasUpper = false;
  bool hasNum = false;
  bool withinRange = false;

  for (int i = 0; i < pass.size(); i++) {
      //check for special character
      for (int j = 0; j < spChar.size(); j++) {
          if (pass[i] == spChar[j])
              hasSpChar = true;
      }

      //check for upper case letter
      if (isupper(pass[i])) {
          hasUpper = true;
      }

      //check for number
      for (int n = 0; n < nums.size(); n++) {
          if (pass[i] == nums[n])
              hasNum = true;
      }

  }
  //check size of password is within range
  if (pass.size() >= 8 && pass.size() <= 16)
      withinRange = true;

  if (!hasSpChar || !hasUpper || !hasNum || !withinRange) {
      cout << "Sua senha não corresponde aos requisitos, tente novamente" << endl;
      return false;
  }
  else
      return true;
}

// função para realizar o cadastro de novos usuários
void AppFunc::cadastro() {
  Cliente cliente;
  string entrada;
	limpaConsole();
	cout << "Cadastro de novo usuario!" << endl;
  cout << "Digite seu NOME completo:  " << endl;
	cin.ignore(); // limpa a entrada anterior do teclado
 	getline(cin, entrada);
  cliente.setNome(entrada);
	
	limpaConsole();
  cout << "Digite seu E-mail: " << endl;
	cin >> entrada;
	// Verifica se o email ja foi utilizado
	while (!emailCheck(entrada)) {
  	cout << "Email existente no sistema, digite outro E-mail: " << endl;
  	cin >> entrada;
		limpaConsole();
	}
	cliente.setEmail(entrada);

	// Verifica se a senha corresponde com os requisitos de segurança
	bool senhaValida = false;
	do {
	  limpaConsole();
	  cout << "Sua senha deve conter de 8 a 16 digitos, com NO MINIMO:  " << endl;
	  cout << "* 1 Letra MAIUSCULA" << endl;
	  cout << "* 1 Caractere especial (!@#$%&*)" << endl;
	  cout << "* 1 Numero" << endl;
	  cout << "Digite sua senha:  " << endl;
	  cin >> entrada;
	  
	  senhaValida = passCheck(entrada);
	  
	  if (!senhaValida) {
	    pausaConsole();
	  }
	} while (!senhaValida);

cliente.setSenha(entrada);


	limpaConsole();
  cout << "Digite seu celular (Utilize somente numeros) " << endl;
  cin >> entrada;
  cliente.setCelular(entrada);

	limpaConsole();
  cout << "Digite seu CPF (Utilize somente numeros): " << endl;
  cin >> entrada;
	// Verifica se o Cpf ja foi utilizado
	while (!cpfCheck(entrada)) {
  	cout << "CPF já existente! Digite outro CPF: " << endl;
  	cin >> entrada;
	}
	cliente.setCpf(entrada);

  // iniciar o saldo de um novo cliente como R$0,00
  cliente.setSaldo(0);

	cout << "Cadastro realizado com sucesso!" << endl;
	cout << "Bem vindo " << cliente.getNome() << "Ao Garimpô " << endl;
	pausaConsole();
	
  addListaCliente(cliente);
}

// função para apresentar o catálogo ao usuário logado
void AppFunc::catalogo() {
  int indiceAtual = 0;
  int itensPorPagina = 4;

  while (true) {
    limpaConsole();

    if (listaCatalogo.empty()) {
      cout << "Parece que nosso catálogo está vazio :(" << endl;
      pausaConsole();
      return;
    }

    int indiceInicial = indiceAtual;
    int indiceFinal = min(indiceAtual + itensPorPagina - 1, static_cast<int>(listaCatalogo.size()) - 1);

    for (int i = indiceInicial; i <= indiceFinal; i++) {
      Roupa& itemAtual = listaCatalogo[i];
      cout << "|-----------------------------------|" << endl;
      cout << "  ID da peça: " << itemAtual.getID() << endl;
      cout << "  Tipo da peça: " << itemAtual.getTipo() << endl;
      cout << "  Estado da peça: " << itemAtual.getEstado() << endl;
      cout << "  Cor da peça: " << itemAtual.getCorRoupa() << endl;
      cout << "  Tamanho da peça: " << itemAtual.getTamanho() << endl;
      cout << "  Gênero da peça: " << itemAtual.getGenero() << endl;
      cout << "  Preço: " << itemAtual.getPrecoRoupa() << endl;
    }

    char opc;
      cout << "|-----------------------------------|" << endl;
    cout << endl << "1 - Selecionar peça" << endl;
    cout << "2 - Próxima página" << endl;
    cout << "3 - Página anterior" << endl;
    cout << "4 - Voltar" << endl << endl;
    cin >> opc;

		
    switch (opc) {
      case '1': {
        int indiceSelecionado;
        cout << "Digite o ID da peça que deseja selecionar: ";
        cin >> indiceSelecionado;
				if(indiceSelecionado > listaCatalogo.size() - 1) {
					cout << "ID não esta no catalogo, tente novamente:" << endl;
					cin >> indiceSelecionado;
				}
				selecPeca(listaCatalogo[indiceSelecionado - 1]);
      }
      case '2': {
        if (indiceFinal < listaCatalogo.size() - 1) {
          indiceAtual += itensPorPagina;
        } else {
          cout << "Você já está na última página do catálogo." << endl;
          pausaConsole();
        }
        break;
      }
      case '3': {
        if (indiceInicial > 0) {
          indiceAtual -= itensPorPagina;
        } else {
          cout << "Você já está na primeira página do catálogo." << endl;
          pausaConsole();
        }
        break;
      }
      case '4': {
        return;
      }
			default: {
				limpaConsole();
				cout << "Opção digita invalida" << endl;
				pausaConsole();
			}
    }
  }
}


void AppFunc::selecPeca(Roupa roupa) {
  char opc;
  bool continua = false;
  do {
		limpaConsole();
	  cout << "-----------------------------------" << endl;
		cout << "ID da peça: " << roupa.getID() << endl;
	  cout << "Tipo da peça: " << roupa.getTipo() << endl;
	  cout << "Estado da peça: " << roupa.getEstado() << endl;
	  cout << "Cor da peça: " << roupa.getCorRoupa() << endl;
	  cout << "Tamanho da peça: " << roupa.getTamanho() << endl;
	  cout << "Genero da peça: " << roupa.getGenero() << endl;
	  cout << "Preço: " << roupa.getPrecoRoupa() << endl;
	  cout << "-----------------------------------" << endl << endl;
    cout << "1 - Adicionar ao carrinho" << endl;
    cout << "2 - Adicionar aos favoritos" << endl;
    cout << "3 - Voltar ao catálogo" << endl << endl;
    cin >> opc;
    switch (opc) {
    case '1': {
			adicionaCarrinho(roupa.getID());
	    break;
		} // Adicionar ao carrinho
    case '2': {
      bool adicionado = false;
      vector<int> favoritos = clienteLogado.getFavoritos();
      for(int i=0; i<favoritos.size() && !adicionado; i++) {
        if (favoritos[i] != roupa.getID())
          adicionado = false;
        else
          adicionado = true;
      }
      if (!adicionado) { 
        clienteLogado.addFavoritos(roupa.getID());
				listaClientes[clienteLogado.getID()].setFavoritos(clienteLogado.getFavoritos());
				cout << endl << "Item adicionado aos favoritos" << endl;
				pausaConsole();
			}
      else {
				
        cout << endl << "Item já está nos favoritos" << endl;
				pausaConsole();
			}
			break;
    } // Adicionar aos favoritos
    case '3': {
      continua = true;
			break;
    } // Retornar
    default:
      cout << "Entrada inválida" << endl;
			pausaConsole();
    }
  } while (!continua);
}

// Realiza o login do usuario e fornece seus dados para o programa
bool AppFunc::login() {
  string email, senha;
  bool login_sucesso = false;

	limpaConsole();
  cout << "Seja bem-vindo a tela de acesso: " << endl;  
  
	cout << "Digite seu E-mail: ";
  cin >> email;

  cout << "Digite sua senha: ";
  cin >> senha;

	for(int i=0; i < listaClientes.size(); i++) { // percorre lista de clientes e verifica email e senha;
		if(email == listaClientes[i].getEmail() && senha == listaClientes[i].getSenha()){
			login_sucesso = true;	
			clienteLogado.setID(i);
			clienteLogado.setNome(listaClientes[i].getNome());
			clienteLogado.setEmail(listaClientes[i].getEmail());
			clienteLogado.setSenha(listaClientes[i].getSenha());
			clienteLogado.setCpf(listaClientes[i].getCpf());
			clienteLogado.setCelular(listaClientes[i].getCelular());
			clienteLogado.setEndereco(listaClientes[i].getEndereco());
			clienteLogado.setFavoritos(listaClientes[i].getFavoritos());
			clienteLogado.setCarrinho(listaClientes[i].getCarrinho());
			clienteLogado.setSaldo(listaClientes[i].getSaldo());
		}
	}
	if(!login_sucesso) { 
		cout << "Usuario ou senha incorretos! " << endl;
		pausaConsole();
		return false; }
	else {
		cout << "Usuario logado" << endl;
		return true;
	}
}

// menu inicial do usuario
bool AppFunc::menuLogado() {
	bool logado;
	char opcaoMenu;
	while (opcaoMenu != '6'){
			limpaConsole();
			cout << "#####################################" << endl;
			cout << "     Bem vindo ao Garimpô     " << endl;
			cout << "            " << clienteLogado.getNome() << endl;
			cout << "#####################################" << endl << endl;

			cout << "Digite a opção desejada:" << endl;
			cout << "1 - Visualizar nosso catálogo" << endl;
			cout << "2 - Visualizar sua lista de favoritos" << endl;
			cout << "3 - Visualizar seu carrinho de compras" << endl;
			cout << "4 - Visualizar seus dados pessoais" << endl;
			cout << "5 - Adicionar saldo na conta" << endl;
			cout << "6 - Para sair da sua conta" << endl;

			cin >> opcaoMenu;
			
		switch (opcaoMenu) {
			case '6': // sai da conta e do menu do usuario;
				logado = false;
				break;
			case '1': // Acessa o catalogo
				catalogo();
				break;
			case '2': // Menu de favoritos
				menuFavoritos();
				break;
			case '3': // Menu do carrinho
				menuCarrinho();
				break;
			case '4': // Menu de dados pessoais do usuario
				menuDados();
				break;
			case '5': // Adicionar saldo
				adicionaSaldo();
			default:
				cout << "Opção invalida!" << endl;
				break;
		}
	}
	
	if(logado == false)
	return false;
	else return true;
}

// menu que apresenta os dados do usuario, e a opção de edita-los
void AppFunc::menuDados() {
	limpaConsole();
	cout << "Este são seus dados :" << endl << endl
			 << "Nome: " << clienteLogado.getNome() << endl
			 << "E-mail: " << clienteLogado.getEmail() << endl
			 << "CPF: " << clienteLogado.getCpf() << endl
			 << "Celular: " << clienteLogado.getCelular() << endl
			 << "Saldo: " << clienteLogado.getSaldo() << endl
			 << "Endereco: " << clienteLogado.getEndereco() << endl << endl;
			
	cout << "Menu de dados : " << endl
	 		 << "1 - Alterar dados " << endl
			 << "2 - voltar para o menu inicial" << endl;
			
	char menudados;
	cin >> menudados;
	switch (menudados) {
	case '2':
		break;
	case '1':
		limpaConsole();
		cout << "oque você deseja alterar? " << endl;
		cout << "1 - Celular" << endl
				 << "2 - Endereço" << endl
		 		 << "3 - Alterar senha" << endl
				 << "4 - voltar menu anterior " << endl;
				
		char opcao;
		cin >> opcao;
		switch(opcao) {
		case '4':
			break;
		case '1':
			trocaCelular();
			break;
		case '2':
			trocaEndereco();
			break;
		case '3':
			trocaSenha();
			break;
		}
  }
}

// função para editar o numero de celular do usuario
void AppFunc::trocaCelular() {
	string novoCelular;
	cout << "Digite seu novo numero de contato: " << endl;
	cin >> novoCelular;
	clienteLogado.setCelular(novoCelular);
	listaClientes[clienteLogado.getID()].setCelular(clienteLogado.getCelular());
	cout << "Seu novo numero de celular é: " << clienteLogado.getCelular() << endl;
	pausaConsole();
}

// função para editar o endereço do usuario
void AppFunc::trocaEndereco() {
	string novoEndereco;
	cout << "Digite seu novo endereço: " << endl;
	cin.ignore();
	getline (cin, novoEndereco);
	clienteLogado.setEndereco(novoEndereco);
	listaClientes[clienteLogado.getID()].setEndereco(clienteLogado.getEndereco());
	cout << "Seu novo endereco é: " << clienteLogado.getEndereco() << endl;
	pausaConsole();
}

// função para editar a senha do usuario
void AppFunc::trocaSenha() {
	cout << "Digite sua senha atual: " << endl;
	string senhaAtual, novaSenha;
	cin >> senhaAtual;
	if(senhaAtual == clienteLogado.getSenha()) {
		do {
		cout << "Digite sua nova senha : " << endl;
		cin >> novaSenha;
	 		if (passCheck(novaSenha)){
				clienteLogado.setSenha(novaSenha);
				listaClientes[clienteLogado.getID()].setSenha(clienteLogado.getSenha());
			} else {
				cout << "A nova senha não atende aos requisitos" << endl;
				cin.get();
			}
		} while (!passCheck(novaSenha));					
	}	else {
		cout << "Senha incorreta." << endl;
		cin.get();
	}
}

void AppFunc::menuFavoritos() {
	char menu;
	while(menu !='3') {
		limpaConsole();
		if(clienteLogado.getFavoritos().size() > 0) {
			cout << "Aqui está a lista dos seus itens favoritados: " << endl << endl;
			vector<int>favoritos = clienteLogado.getFavoritos();
		
			// Percorre o catalogo procurando os IDS que estão na lista de favoritos
			for (auto& id : clienteLogado.getFavoritos()) {
		    auto item = find_if(listaCatalogo.begin(), listaCatalogo.end(), [id]( Roupa& roupa) {
		    	return roupa.getID() == id;
		    });
		    if (item != listaCatalogo.end()) {
		      cout << "ID: " << item->getID() << endl;
		      cout << "Tipo: " << item->getTipo() << endl;
		      cout << "Genero: " << item->getGenero() << endl;
		      cout << "Tamanho: " << item->getTamanho() << endl;
		      cout << "Cor: " << item->getCorRoupa() << endl;
		      cout << "Estado: " << item->getEstado() << endl;
		      cout << "Preço: " << item->getPrecoRoupa() << endl << endl;
		    }
			}
				
			cout << "1 - Remover item dos favoritos" << endl;
			cout << "2 - Adicionar item ao carrinho" << endl;
			cout << "3 - Voltar ao menu inicial" << endl;
		
			cin >> menu;
			switch(menu) {
				case '1': {  // Remover item dos favoritos;
					removeFavorito();
					break;
				}
				case '2': {
					int id_add;
					cout << "Digite o ID do item a ser adicionado ao carrinho: " << endl;
					cin >> id_add;
					adicionaCarrinho(id_add);
					break;
				}
				case '3': {
		
					break;
				}
			}
		} else {
				cout << "Voce não possui itens favoritodas !" << endl;
				pausaConsole();
				menu = '3';
		} 
	}
}

 void AppFunc::menuCarrinho() {
	char menu;
	while (menu !='3') {
		limpaConsole();
		cout << "Aqui está a lista dos seus itens no carrinho: " << endl << endl;
		vector<int>IdCarrinho = clienteLogado.getCarrinho();
	  double precoTotal; 
	
		for (auto& id : clienteLogado.getCarrinho()) { // percorre a lista do carrinho e imprime todos itens na tela
	    auto item = find_if(listaCatalogo.begin(), listaCatalogo.end(), [id]( Roupa& roupa) {
	       return roupa.getID() == id;
	    });
	    precoTotal += item->getPrecoRoupa();
	
	    if (item != listaCatalogo.end()) {
	    	cout << "ID: " << item->getID() << endl;
	      cout << "Tipo: " << item->getTipo() << endl;
	      cout << "Genero: " << item->getGenero() << endl;
	      cout << "Tamanho: " << item->getTamanho() << endl;
	      cout << "Cor: " << item->getCorRoupa() << endl;
	      cout << "Estado: " << item->getEstado() << endl;
	      cout << "Preço: " << item->getPrecoRoupa() << endl << endl;
	    }
	    
		}
		
	  if(clienteLogado.getCarrinho().size() > 0) {
		  cout << "Valor total dos itens: " << precoTotal << endl;
			clienteLogado.setPrecoTotal(precoTotal);  
		  cout << "1 - Remover item do carrinho" << endl;
			cout << "2 - Finalizar compra" << endl;
			cout << "3 - Voltar ao menu inicial" << endl;
		  cin >> menu; 
		  switch(menu){
		  	case '1':{
		    	removeCarrinho();
		  		break; 
		  		}
				case '2': {
		  		finalizarCompra();
		  		}
		  	}
		} else {
			cout << "Voce nao possui itens no carrinho!" << endl;
			menu = '3';
			pausaConsole();
		}
	}
}

void AppFunc::pausaConsole() {
	cout << endl << "Aperte Enter para continuar" << endl;
	cin.get();
	cin.get();
}

void AppFunc::limpaConsole() {
	system("clear");
}

void AppFunc::removeFavorito() {
	vector<int>favoritos = clienteLogado.getFavoritos();
	cout << "Qual item Deseja remover dos seus favoritos? " << endl;
	cout << "Digite o ID do item: " ;
	int id_Remover;
	cin >> id_Remover;
	auto remove = find_if(favoritos.begin(), favoritos.end(), [id_Remover](int favoritos) {
		return favoritos == id_Remover;
	});
	
	if (remove != favoritos.end()) {
		favoritos.erase(remove);
		clienteLogado.setFavoritos(favoritos);
		listaClientes[clienteLogado.getID()].setFavoritos(clienteLogado.getFavoritos());

		
		cout << "Item ID " << id_Remover << " removido com sucesso" << endl;
		pausaConsole();
		} else {
		cout << "ID não esta na lista de favoritos";
		pausaConsole();
		}
} // Remove item da lista de favoritos

void AppFunc::finalizarCompra(){
	limpaConsole();
  cout << "Seu saldo atual é: " << clienteLogado.getSaldo() << endl;
  cout << "O valor total da sua compra é: " << clienteLogado.getPrecoTotal() << endl;
  cout << "Deseja finalizar sua compra? " << endl;
  cout << "1- Sim" << endl;
  cout << "2- Não" << endl;
  char op;
  cin >> op;

  switch(op){
    case '1' : { 
			limpaConsole();
      if(clienteLogado.getSaldo() < clienteLogado.getPrecoTotal()){
        cout << "Saldo insuficiente!";
        pausaConsole();
        
      } else{
        double saldoCliente = clienteLogado.getSaldo();
        double saldoCompra = clienteLogado.getPrecoTotal();

        saldoCliente -= saldoCompra;
        clienteLogado.setSaldo(saldoCliente);

        clienteLogado.setPrecoTotal(0);
        vector<int>zeraCarrinho;
        clienteLogado.setCarrinho(zeraCarrinho);
        listaClientes[clienteLogado.getID()].setSaldo(clienteLogado.getSaldo());
        listaClientes[clienteLogado.getID()].setCarrinho(clienteLogado.getCarrinho());
        listaClientes[clienteLogado.getID()].setPrecoTotal(clienteLogado.getPrecoTotal());
        

        cout << "Compra finalizada com sucesso!" << endl;
        cout << clienteLogado.getSaldo() << endl;
        cout << clienteLogado.getPrecoTotal() << endl;
        for(auto & item:clienteLogado.getCarrinho()){
          cout << item << endl;
          
        pausaConsole();
        
        }
        
      
      }
      
    }
  }
  

}

void AppFunc::adicionaCarrinho(int id_add) {
    // Verifica se o item já está no carrinho
    if (find(clienteLogado.getCarrinho().begin(), clienteLogado.getCarrinho().end(), id_add) != clienteLogado.getCarrinho().end()) {
      cout << "Item já está no carrinho" << endl;
      pausaConsole();
    } else {
      vector<int> carrinho_atual = clienteLogado.getCarrinho();
      carrinho_atual.push_back(id_add);
      clienteLogado.setCarrinho(carrinho_atual); // Atualiza carrinho do cliente
      listaClientes[clienteLogado.getID()].setCarrinho(clienteLogado.getCarrinho());
        cout << "Item adicionado ao carrinho" << endl;
        pausaConsole();
    }
}  // adicionar item dos favoritos ao carrinho

void AppFunc:: removeCarrinho() {
	
	vector<int> carrinho = clienteLogado.getCarrinho();
	cout << "Qual item deseja remover do carrinho? " << endl;
	cout << "Digite o ID do item: ";
	int idRemover;
	cin >> idRemover;

	auto remove = find_if(carrinho.begin(), carrinho.end(), [idRemover](int id) {
    return id == idRemover;
	});

	if (remove != carrinho.end()) {
    carrinho.erase(remove);
    clienteLogado.setCarrinho(carrinho);
    listaClientes[clienteLogado.getID()].setCarrinho(clienteLogado.getCarrinho());

    cout << "Item ID " << idRemover << " removido do carrinho com sucesso" << endl;
    pausaConsole();
	} else {
    cout << "ID não está no carrinho" << endl;
    pausaConsole();
	}

} // remover item do carrinho

bool AppFunc::emailCheck(string email) {
  for (auto& item : listaClientes) {
    if (item.getEmail() == email) {
      return false; // E-mail já existe na lista de clientes
    }
  }
  return true; // E-mail novo
} // Verifica se o email ja existe na lista de clientes

bool AppFunc::cpfCheck(string cpf) {
	  for (auto& item : listaClientes) {
    if (item.getCpf() == cpf) {
      return false; // Cpf existente na lista de usuarios
    }
  }
  return true; // Novo CPF
} // Verifica se o Cpf ja existe na lista de clientes

void AppFunc::adicionaSaldo() {
	limpaConsole();
	cout << "Digite o valor a adicionar a sua conta: ";
	double saldo;
	cin >> saldo;
	clienteLogado.setSaldo(clienteLogado.getSaldo() + saldo);
	listaClientes[clienteLogado.getID()].setSaldo(clienteLogado.getSaldo());

	limpaConsole();
	cout << "Adicionado a sua conta: " << saldo << endl;
	cout << "Seu saldo atualizado é: " << clienteLogado.getSaldo() << endl;
	pausaConsole();
} // Apenas adiciona saldo, sem verificaçoes