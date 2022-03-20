# ReorganizeMatrixElements
**Reorganize the indices of each matrix elements to diagonial the whole matrix, in other words, to distinguish each uncorrelated submatrices.**

## Input parameters:  graph, indices

graph is an adjacent matrix, which can represent both undirected graph and directed graph.

## Output parameters: indices

indices is one dimensional integers, which can reorder matrix elements to move non-zeros element close to diagonal region.

## For example:

If we define an adjacent matrix (temp), just like this:

vector<vector<float>> temp = { {0,1,0,0,0,0},
  
                               {0,0,0,0,0,1},
  
                               {0,0,0,1,0,0},
  
                               {0,1,0,0,0,1},
  
                               {0,0,0,0,1,0},
  
                               {0,0,1,0,0,1} };

the output of indices would be:

indices = {0,1,2,3,5,4};
  
Intuitively:
  
vector<vector<float>> temp = { {0,1,0,0,0,    0},
  
                               {0,0,0,0,1,    0},
  
                               {0,0,0,1,0,    0},
  
                               {0,1,0,0,1,    0},
  
                               {0,0,1,0,1,    0},
  

                               {0,0,0,0,0,    1} };
We can observed that the whole matrix can be separated by two unrelated submatrices.And Surprisingly, the final effect of this method is pretty similar to reverse Cuthill-Mckee algorithm.
