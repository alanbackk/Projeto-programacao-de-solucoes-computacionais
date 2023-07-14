#include "Cliente.h"

// Getters
  string Cliente::getNome() { return nome; }
  string Cliente::getEmail() { return email; }
  string Cliente::getSenha() { return senha; }
  string Cliente::getEndereco() { return endereco; }
  vector<int> Cliente::getCarrinho() { return carrinho; }
  vector<int> Cliente::getFavoritos() { return favoritos; }
  vector<int> Cliente::getPedidos() { return meusPedidos; }
  vector<int> Cliente::getVendas() { return minhasVendas; }
	int Cliente::getID() { return id; }
  double Cliente::getSaldo() { return saldo; }
  double Cliente::getPrecoTotal() { return precoTotal; }
	string Cliente::getCelular() { return celular; }
	string Cliente::getCpf() { return cpf; }
	
	// Setters
  void Cliente::setNome(string _nome) { nome = _nome;}
  void Cliente::setEmail(string _email) { email = _email; }
  void Cliente::setSenha(string _senha) { senha = _senha; }
  void Cliente::setEndereco(string _endereco) { endereco = _endereco; }
  void Cliente::setSaldo(double _saldo) { saldo = _saldo; }
  void Cliente::setPrecoTotal(double _precoTotal) { precoTotal = _precoTotal; }
	void Cliente::setCelular(string _celular) {celular = _celular; }
	void Cliente::setCpf(string _cpf) { cpf = _cpf; }
	void Cliente::setID(int _id) { id = _id;}
  void Cliente::setCarrinho(vector<int> _carrinho) { carrinho = _carrinho; };
  void Cliente::setFavoritos(vector<int> _favoritos) { favoritos = _favoritos; };
  void Cliente::setMeusPedidos(vector<int> _meusPedidos) { meusPedidos = _meusPedidos; };
  void Cliente::setMinhasVendas(vector<int> _minhasVendas) { minhasVendas = _minhasVendas; };

  // Functions
  void Cliente::addCarrinho(int _novaCompra) { carrinho.push_back(_novaCompra); }
  void Cliente::addFavoritos(int _novoFav) { favoritos.push_back(_novoFav); }
  void Cliente::addPedido(int _novaCompra) { meusPedidos.push_back(_novaCompra); }
  void Cliente::addVenda(int _novaVenda) { minhasVendas.push_back(_novaVenda); }