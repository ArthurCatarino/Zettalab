#include <iostream>
#include <unordered_map>
#include <vector>
#include <utility>
#include <fstream>
#include <string>
#include <sstream>

using namespace std;

typedef unordered_map<long long, pair<double, double>> no;
typedef unordered_map<long long, vector<long long>> g;

void exemplo_map() {
	unordered_map <int, vector<string>> map;

	map[1].push_back({ "Ola" });
	map[1].push_back({ "Mundo" });
	map[1].push_back({ "!" });

	for (const auto& par : map) {
		cout << "Chave : " << par.first;
		for (auto i : par.second) {
			cout << " " << i;
		}
	}
}

void importa_grafo(no& nos) {
	
	ifstream arquivo("C:\\Users\\arthu\\OneDrive\\Área de Trabalho\\Programaçao\\Geoloc\\Grafo\\nos.csv");

	if (!arquivo) {
		cout << "Ãrquivo dos NOS não foi aberto";
		return;
	}

	string linha, valor;
	long long id, x, y;

	getline(arquivo, linha);

	while (getline(arquivo, linha)) {
		stringstream ss(linha);

		getline(ss, valor, ',');
		id = stoll(valor);

		getline(ss, valor, ',');
		x = stoll(valor);

		getline(ss, valor, ',');
		y = stoll(valor);

		nos[id] = { x,y };
	}
	arquivo.close();
}

void importa_arestas(g& grafo) {

	ifstream arquivo("C:\\Users\\arthu\\OneDrive\\Área de Trabalho\\Programaçao\\Geoloc\\Grafo\\arestas.csv");

	if (!arquivo) {
		cout << "Ãrquivo das arestas não foi aberto";
		return;
	}

	string linha, valor;
	long long origem, destino;

	getline(arquivo, linha);

	while (getline(arquivo, linha)) {

		stringstream ss(linha);

		getline(ss, valor, ',');
		origem = stoll(valor);

		getline(ss, valor, ',');
		destino = stoll(valor);

		grafo[origem].push_back(destino);
	}

	arquivo.close();
	
}

int main() {
	
	no nos;
	g grafo;

	importa_grafo(nos);
	importa_arestas(grafo);

	return 0;
} 
