# LSE detection d'anomalie sur des graphes de donnée

> # *LIBS TO INSTALL*

- graphviz
- graphviz-dev

> # *METRIQUES*
- Average Degree
- Average Weighted Degree
- Network Diameter
- Graph density
- HITS (Hyperlink-Induced Topic Search)
- Modularity
- PageRank
- Connected Components
- Average Clustering Components
- Average Clustering Coefficient
- Eigenvector Centrality
- Average Path Length
- Weak Paths

https://barabasi.com/f/625.pdf




> manipulation des formats:

transform_matrix_to_adjacency_list()
transform_adjacency_list_to_matrix()

> caracterisation des graphes

get_node_number(G)
get_edge_number(G)

---

> Cas 2: Anomalies entre noeuds dans le même graphe

* méthodes de calcul de distances dans les graphes
* méthodes de calcul d'anomalies
---

> Cas 2: Anomalies entre graphes

* méthodes de calcul de distances dans les graphes

get_node_number(G)
get_node_distance(G1, G2)
get_edge_number()
get_edge_distance(G1, G2)

---

* métriques de graphes: nb de noeuds, nb d'arrêtes, graphes complexes (diamètre, etc.) ...

-> lib c/c++

-> tests (fonctionnel et performance selon taille des graphes)

-> data (matrices; listes d'adjacence)

***********************************
# *Manipulation des graphes*

Bibliothèque de manipulation de graphes en C

https://www.fil.univ-lille1.fr/~lemairef/ARO/doclibgraphe/index.html

Représentation interne et adjacent_matrix

https://cpp.developpez.com/redaction/data/pages/users/gbdivers/boost-graph/


****************************************************************
# *Calcul de distances dans les graphes*
https://www.labri.fr/perso/fkardos/cours7.pdf

http://www.lsv.fr/~jezequel/talk_stage2007.pdf


****************************************************************
# *Métriques de graphes*

http://www-sop.inria.fr/members/Guillaume.Ducoffe/slides/slides-algotel-2015-2.pdf

****************************************************************
# *DataSets*

https://dataverse.harvard.edu/dataset.xhtml?persistentId=doi:10.7910/DVN/OPQMVF

https://www.kaggle.com/ymirsky/network-attack-dataset-kitsune

https://www.kaggle.com/pparrend/pdssc-lab-session-predicting-attacks/data?select=UNSW-NB15_1.csv

****************************************************************
# *Anomalie Detection*

https://www.vs.inf.ethz.ch/edu/HS2011/CPS/papers/chandola09_anomaly-detection-survey.pdf

https://github.com/yzhao062/anomaly-detection-resources

https://arxiv.org/abs/2106.07178

https://hal.archives-ouvertes.fr/hal-02993787/document\

Unsupervised learning

http://snap.stanford.edu/class/cs224w-2015/projects_2015/Anomaly_Detection_in_Graphs.pdf

https://orbilu.uni.lu/bitstream/10993/38853/1/1002472.pdf

****************************************************************

Approche visée:

*Decomposition de graphes en sous structures pondérées*

*Calculer la similarité entre les branches*

*Evaluer la compléxité spacial et temporel pour une approche plus efficace*

