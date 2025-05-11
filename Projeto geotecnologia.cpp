#include <iostream>
#include <stack>
#include <utility>
#include <vector>
#include <unordered_map>
#include <fstream>
#include <iomanip>
#include<sstream>

using namespace std;

typedef unordered_map<long long, pair<double,double>> no; // pair de coordenadas lat e long
typedef unordered_map<long long, vector<pair<int,long long>>> g; // sendo o pair do vector {id da aresta , destino}
typedef unordered_map<long long,int> visitado;

bool busca_visita(long long origem,g &grafo, pair<long long, long long> destino, visitado &info) {
	
	info[origem] = 2;

	for (auto i : grafo[origem]) {
		if (info[i.second] == 1 and i.first != destino.first) {
			if (i.second == destino.second) {
				return true;
			}
			if (busca_visita(i.second, grafo, destino, info)) {
				return true;
			}
		}
	}
	info[origem] = 3;
	return false;

}

bool busca_em_profundidade(no &nos, g &grafo, long long origem, pair<long long,long long> destino) {

	visitado info;

	for (auto &i : nos) {
		info[i.first] = 1;
	}

	info[origem] = 2;

	for (auto& i: grafo[origem]) {
		if (i.first != destino.first) {
			if (busca_visita(i.second, grafo, destino, info)) {
				return true;
			}
		}
	}
	return false;
}

vector<pair<long long, long long>> verifica_arestas_criticas(no& nos, g& grafo) {

	vector<pair<long long, long long>> arestas_criticas;

	int p = 0;
	int tamanho = grafo.size();
	int intervalos = tamanho / 20;

	for (auto origem : grafo) {
		p++;
		if (p % intervalos  == 0) {
			cout << "(" << p << "/" << tamanho << ")" << endl;
		}
		for (auto destino : origem.second) {
			if (!busca_em_profundidade(nos,grafo, origem.first, destino)) {
				arestas_criticas.push_back({ origem.first,destino.second });
			}
		}
	}
	return arestas_criticas;
}

void importa_grafo(no& nos) {

	ifstream arquivo("C:\\Users\\arthu\\OneDrive\\Área de Trabalho\\Programaçao\\Geoloc\\Grafo\\nos.csv");

	if (!arquivo) {
		cout << "Ãrquivo dos NOS não foi aberto";
		return;
	}

	string linha, valor;
	long long id;
	double x, y;

	getline(arquivo, linha);

	while (getline(arquivo, linha)) {
		stringstream ss(linha);

		getline(ss, valor, ',');
		id = stoll(valor);

		getline(ss, valor, ',');
		x = stold(valor);


		getline(ss, valor, ',');
		y = stold(valor);

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
	int id;

	getline(arquivo, linha);

	while (getline(arquivo, linha)) {

		stringstream ss(linha);

		getline(ss, valor, ',');
		id = stoi(valor);

		getline(ss, valor, ',');
		origem = stoll(valor);

		getline(ss, valor, ',');
		destino = stoll(valor);

		grafo[origem].push_back({ id,destino });
	}

	arquivo.close();

}

int main() {
	
	no nos;
	g grafo;
	 	
	importa_grafo(nos);
	importa_arestas(grafo);

	vector<pair<long long, long long>> arestas_criticas = verifica_arestas_criticas(nos, grafo);
	
	ofstream arquivo("Pontos_criticos.csv");

	arquivo << "lat1,long1,lat2,long2" << endl;


	for (auto& i : arestas_criticas) { //Salva em um arquivo as coordenadas dos pontos que possuem um ponto critico entre eles no sentindo p1 --> p2
		arquivo << fixed << setprecision(8) << nos[i.first].second << "," << nos[i.first].first << "," << nos[i.second].second <<"," << nos[i.second].first << endl;
	}
}
