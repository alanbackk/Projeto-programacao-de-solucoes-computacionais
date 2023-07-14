#include "Roupa.h"

  // getters
  string Roupa::getTipo() {return tipoDeRoupa;}
  string Roupa::getEstado() {return estadoDaRoupa;}
  string Roupa::getCorRoupa() {return corRoupa;}
  char Roupa::getTamanho() {return tamanhoRoupa;}
  char Roupa::getGenero() {return generoRoupa;}
  double Roupa::getPrecoRoupa() {return precoRoupa;}
  int Roupa::getID() {return idRoupa;}

  // setters
  void Roupa::setTipo(string _tipoDeRoupa) { tipoDeRoupa = _tipoDeRoupa; }
  void Roupa::setEstadoRoupa(string _estadoDaRoupa) { estadoDaRoupa = _estadoDaRoupa; }
  void Roupa::setCorRoupa(string _corRoupa) {corRoupa = _corRoupa; }
	void Roupa::setTamanhoRoupa(char _tamanhoRoupa) { tamanhoRoupa = _tamanhoRoupa; }
	void Roupa::setGeneroRoupa(char _generoRoupa) { generoRoupa = _generoRoupa; }
	void Roupa::setPrecoRoupa(double _precoRoupa) { precoRoupa = _precoRoupa; }
	void Roupa::setID(int _idRoupa) { idRoupa = _idRoupa; } 
