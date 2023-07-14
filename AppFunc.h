#include <iostream>
#include <fstream>
#include <algorithm>
#include "Cliente.h"

using namespace std;

class AppFunc {
public:
  vector<Roupa> getListaRoupa();
  vector<Cliente> getListaClientes();
  void addListaRoupa(Roupa roupa);
  void addListaCliente(Cliente cliente);
  void selecPeca(Roupa roupa);
  string listaParaString (vector<int> listaRoupa);
  vector<int> stringParaLista (string listaString);
  bool login();
  void cadastro();
  bool passCheck(string pass);
	bool emailCheck(string email);
	bool cpfCheck(string cpf);
  void catalogo();
	bool menuLogado();
	void trocaCelular();
	void trocaEndereco();
	void trocaSenha();
	void menuDados();
	void menuFavoritos();
  void menuCarrinho();
	void pausaConsole();
	void limpaConsole();
	void removeFavorito();
	void removeCarrinho();
  void finalizarCompra();
	void adicionaCarrinho(int id_add);
	void adicionaSaldo();
																			
private:
  vector<Cliente> listaClientes;
  vector<Roupa> listaCatalogo;
	Cliente clienteLogado;
};