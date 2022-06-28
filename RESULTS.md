# **Results (ccl4-harryc3-devbp2-suyashn2)**

# **Leading Question**
### Which Pokémon is the strongest and has the greatest advantage over every other Pokémon?
We decided to tackle this problem in two ways: a general force-based visualization and a graph coloring algorithm.

# **Force Based Graph Visualization**
We decided to implement a graph visualization based on [an article from Brown University](https://cs.brown.edu/people/rtamassi/gdhandbook/chapters/force-directed.pdf). This algorithm utilizes simplified calculations of spring forces and coulombic forces in order to pull and push vertices towards and away from each other, respectively. We first randomized the coordinates of each vertex, then ran 100 simulations to bring the vertices to an equilibrium state, updating the coordinates of the vertices with each simulation.

For the edges of the graph, we decided to not draw actual arrows pointing from one vertex to another; instead, we came up with the idea that we would use colors to show the direction from one vertex to another. For example, the green end of the edge would hold the vertex representing the stronger Pokemon, while the red end of the edge would hold the vertex representing the weaker Pokemon.

After implementing the force-directed graph algorithm, we decided that we wanted to resize the vertices on the visualization based on each vertex's degree. Thus, when drawing each vertex, we considered a base radius for each node, and scaled every other vertex according to its degree based off of that base radius.

From this visualization, we were able to see which vertices were the largest; this would effectively tell us which Pokemon were the strongest out of the 151 Pokemon from Generation I. After sorting the nodes from largest degree to smallest degree and printing out the names of the Pokemon in the sorted list when testing our graph (we had to sort vertices to draw vertices in such a way so that smaller vertices do not get covered up by larger vertices), we learned that the two strongest Pokemon were Magnemite and Magneton, which makes sense due to their steel/electric type combination. In addition to this, we learned that there 8 of the vertices were smaller than the rest of the vertices, which depicted all 8 normal type Pokemon from Generation I; this makes sense because normal type Pokemon do not have an advantage over any other type.

# **Graph Coloring (Chromatic Number)**
### **What do the different colors show?**
We observed that pokemons of similar type were grouped together in the same color - color groups with less Pokemon had fairly unique type combinations. However something interesting to note is that some unique types were hidden in color groups with relatively common types.

Additionally, we initially thought graph coloring would give us a strength hierarchy with pokemon of similar strength grouped together, but it resulted in a type grouping instead. This allowed us to double check that the strongest Pokemon Magnemite and Magneton which have similar types were in the same color group.

![Graph Visualization 151 nodes](output_graph_151.png)
