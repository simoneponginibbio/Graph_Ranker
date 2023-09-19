<h1>Graph Ranker</h1>

[![License: MIT][license-image]][license]

Final project of "**Algoritmi e Principi dell'Informatica**" 2020-2021 held by Professor <a href="https://martinenghi.faculty.polimi.it/" target="_blank">**Davide Martinenghi**</a> at Politecnico di Milano.

More detailed specifications and informations (in italian) can be found in the [documents][spec] folder.<br>
The public tests with inputs, outputs and a testcase generator given by the professor can be found in the [tests][tests] folder.

<h2>Project specification</h2>

- The goal of this project is to manage a ranking between weighted directed graphs;
- the ranking keeps track of the k "best" graphs;
- the program to be implemented receives as input:
    - two parameters, once (on the first line of the file, separated by space)
        - d: the number of nodes of the graphs;
        - k: the length of the ranking;
    - a sequence of commands between
        - AggiungiGrafo (AddGraph) [adjacency matrix];
        - TopK.

<h2>AggiungiGrafo (AddGraph)</h2>

Requires adding a graph to those considered for ranking. 

Is followed by the adjacency matrix of the graph itself, printed one row for each row, with the elements separated by commas.

The nodes of the graph are to be considered logically labeled with an integer index between 0 and d-1; the node in position 0 is the one whose outgoing star is described by the first row of the matrix.

<h2>TopK</h2>

- Consider each graph from the beginning of the program to the TopK command labeled with an integer index corresponding to the number of graphs read before it (starting from 0);
- TopK prompts the program to print the integer indexes of the k graphs having the k smallest values of the following metric:
    - sum of the shortest paths between node 0 and all other nodes in the graph;
- if there are multiple graphs with the same value of the metric, it gives precedence to the first ones;
- the k integer indexes are printed, on a single line, separated by a space, in any order.

<h2>Copyright and license</h2>

This project is copyright 2023.

Licensed under the **[MIT License][license]**; you may not use this software except in compliance with the License.

[spec]: https://github.com/simoneponginibbio/Graph_Ranker/tree/main/documents
[tests]: https://github.com/simoneponginibbio/Graph_Ranker/tree/main/tests
[license]: https://github.com/simoneponginibbio/Graph_Ranker/blob/main/LICENSE
[license-image]: https://img.shields.io/badge/License-MIT-blue.svg
