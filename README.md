O projeto e composto por 3 arquivos 
 - Main.py que busca os dados e monta o grafo da região escolhida (a cidade buscada pode ser alterada na linha 6 do arquivo).
 - Exporta_grafo.py essa função e chamada pela Main.py e exporta o grafo ja extraido para 2 arquivos csv, um contendo os nos e outro as arestas
 - Projeto_geotecnologia.cpp Nesse arquivo e onde o algoritmo de fato existe, ele le os arquivos csv gerados posteriosmente, processa o grafo em memoria e roda o algoritmo que devolve um arquivo csv onde cada linha possui dois nos (lat1,long1) e a conexao entre eles e um ponto critico do grafo.
 -   Verifique se o arquivo  Projeto_geotecnologia.cpp esta lendo o arquivo que contem o grafo correto (pode ser alterado na linha 31 e 62).  
