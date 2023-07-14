#include <iostream>
#include <vector>
#include "Roupa.h"
using namespace std;

class Cliente {
public:
  // Getters
  string getNome();
  string getEmail();
  string getSenha();
	string getEndereco();
	string getCelular();
	string getCpf();
	int getID();
  double getSaldo();
  double getPrecoTotal();
  vector<int> getCarrinho();
  vector<int> getFavoritos();
  vector<int> getPedidos();
  vector<int> getVendas();

  // Setters
  void setNome(string nome);
  void setEmail(string email);
  void setSenha(string senha);
	void setEndereco(string endereco);
	void setCelular(string celular);
	void setCpf(string cpf);
	void setID(int id);
  void setSaldo(double saldo);
  void setPrecoTotal(double precoTotal);
  void setCarrinho(vector<int> carrinho);
  void setFavoritos(vector<int> favoritos);
  void setMeusPedidos(vector<int> meusPedidos);
  void setMinhasVendas(vector<int> minhasVendas);

  // Functions
  // atualizar para receber apenas o ID da roupa 
  void addCarrinho(int novaCompra);
  void addFavoritos(int novoFav);
  void addPedido(int novaCompra);
  void addVenda(int novaVenda);

private:
  string nome;
  string email;
  string senha;
	string endereco;
	string celular;
	string cpf;
	int id;
  double saldo;
  double precoTotal;
  vector<int> carrinho;
  vector<int> favoritos;
  vector<int> meusPedidos;
  vector<int> minhasVendas;
};