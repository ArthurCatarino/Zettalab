import networkx as nx
import csv
import os
from shapely.geometry import LineString

def exporta_grafo_csv(G, caminho_pasta="Grafo"):
    # Garante que a pasta existe
    os.makedirs(caminho_pasta, exist_ok=True)

    caminho_nos = os.path.join(caminho_pasta, "nos.csv")
    caminho_arestas = os.path.join(caminho_pasta, "arestas.csv")

    # Exporta nós (id, x, y)
    with open(caminho_nos, 'w', newline='', encoding='utf-8') as f_nos:
        writer = csv.writer(f_nos)
        writer.writerow(["id", "x", "y"])  # cabeçalho
        for node_id, data in G.nodes(data=True):
            writer.writerow([node_id, data.get("x", ""), data.get("y", "")])

    # Exporta arestas (source, target)
    id = 1
    with open(caminho_arestas, 'w', newline='', encoding='utf-8') as f_arestas:
        writer = csv.writer(f_arestas)
        writer.writerow(["id","source", "target"])  # cabeçalho
        for u, v, data in G.edges(data=True):
            writer.writerow([id,u, v])
            id = id+1

    print(f"Grafo exportado com sucesso para:\n  - {caminho_nos}\n  - {caminho_arestas}")
