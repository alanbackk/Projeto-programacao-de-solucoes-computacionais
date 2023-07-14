#include <iostream>
using namespace std;

class Roupa {
public:
	string getTipo();
	string getEstado();
	string getCorRoupa();
	char getTamanho();
	char getGenero();
	double getPrecoRoupa();
	int getID();

	void setTipo(string tipoDeRoupa);
	void setEstadoRoupa(string estadoDaRoupa);
	void setCorRoupa(string corRoupa);
	void setTamanhoRoupa(char TamanhoRoupa);
	void setGeneroRoupa(char generoRoupa);
	void setPrecoRoupa(double precoRoupa);
	void setID(int idRoupa);
private:
  string tipoDeRoupa;
  string estadoDaRoupa;
  string corRoupa;
  char tamanhoRoupa;
  char generoRoupa;
	double precoRoupa;
	int idRoupa;
};