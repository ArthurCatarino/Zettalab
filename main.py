import osmnx as ox
import geopandas as gpd
from exporta_grafo_csv import exporta_grafo_csv

# Baixar a rede de ruas de Lavras
cidade = "Lavras, Brazil"
grafo = ox.graph_from_place(cidade, network_type='all')

#exporta_grafo_json(grafo)
exporta_grafo_csv(grafo)