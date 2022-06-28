# **Pokémon Type Advantage Graph Visualization**

## **(ccl4-harryc3-devbp2-suyashn2)**
This project visualizes high-level strength comparisons between Pokémon based on their typing using force-based graph drawing.

## **Executables**
Creates a visualization for the strength graph of Pokémon
`./draw-graph [input_file_path] [number of pokemon] [is_colored] [is_scaling] [output_file_path]`
- NOTE: All fields are optional, just ensure that is_colored and is_scaling are passed together
- `input_file_path` - The path to the csv where the Pokemon are located. Defaults to `data/pokemon.csv`
- `number_of_pokemon` - The number of Pokémon that should be compared and visualized, max is `801`. Defaults to `151`
- `is_colored` - Whether to find the chromatic number of the graph and to color the vertices. Defaults to `true`
- `is_scaling` - Whether to scale the vertices based on its degree. Defaults to `true`
- `output_file_path` - The output file for the visualization fo the graph. Defaults to `test_graph.png`

## **Directory Structure**
- `cs225` - code provided for CS225 MPs like PNG and HSLAPixel
- `data` - location with the csv containing all of the Pokémon data
- `graphAlgorithms` - algorithms that are run on the graph (BFS, Visualizer, Coloring)
- `graphStructure` - classes that are the strucuture of the graph (Graph, Vertex, Edge)
- `graphUtil` - utility class to help create the graph (DataParser, GraphBuilder, TypeMapper) 
- `tests` - includes all the test files for each class
## **Getting Started**
### Compiled with
- clang 6.0.1

### Setting Up

1. Clone this repo navigate to its directory
   ```
   git clone https://github-dev.cs.illinois.edu/cs225-fa21/ccl4-harryc3-devbp2-suyashn2.git pokemon-graph-viz
   cd pokemon-graph-viz
   ```
   The Pokemon data is already included in csv format inside the repo.
2. Now make the executable by running `make`
3. Run the executable `./draw-graph [input_file_path] [number of pokemon] [is_colored] [is_scaling] [output_file_path]`
### Example
1. Construct a graph with 20 nodes, with coloring, but without scaling
    ```
    ./draw-graph 20 True False
    ```
2. This will construct a graph with 151 nodes, with coloring and scaling
    ```
    ./draw-graph data/pokemon.csv 151 True True test_graph2.png
    ```
    The output for this executable will look like this:
    ![Graph Visualization 151 nodes](output_graph_151.png)

## **Testing**
The project comes with a test suite that can be build and run it with the following commands:
```
make test
./test [tag]
```
The tests can be found in the [tests](tests) folder. Functionalities can be specifically tested using the following tags:
- [[parser](tests/parser_tests.cpp)]: the csv is read correctly and saved in an object
- [[builder](tests/graph_builder_tests.cpp)]: the graph can be built with the correct number of vertices and edges and the correct values
- [[mapper](tests/type_mapper_tests.cpp)]: the Pokémon types have the correct indicies
- [[graph](tests/graph_tests.cpp)]: the graph's access methods are correct
- [[bfs](tests/bfs_tests.cpp)]: BFS runs properly on the graph and visited the correct edges and vertices in the correct order
- [[coloring](tests/graph_coloring_tests.cpp)]: the chromatic number of the graph is correctly generated and colors are properly assigned to different nodes
- no-tags: all of the tests above are run