type EdgeList = [number, number][];
type AdjMatrix = number[][];
type AdjList = number[][];

// Example graph: 0 - 1 - 2 - 3
const edgeList: EdgeList = [
  [0, 1],
  [1, 2],
  [2, 3],
];

const adjMatrix: AdjMatrix = [
  [0, 1, 0, 0],
  [1, 0, 1, 0],
  [0, 1, 0, 1],
  [0, 0, 1, 0],
];

const adjList: AdjList = [
  [1],    // Node 0 connects to 1
  [0, 2], // Node 1 connects to 0,2
  [1, 3], // Node 2 connects to 1,3
  [2],    // Node 3 connects to 2
];

// Print adjacency matrix
function printAdjMatrix(matrix: AdjMatrix) {
  matrix.forEach((row, i) => {
    console.log(`Node ${i}:`);
    row.forEach((val, j) => {
      if (val) console.log(`  Neighbour: ${j}`);
    });
  });
}

// Print adjacency list
function printAdjList(list: AdjList) {
  list.forEach((neighbours, i) => {
    console.log(`Node ${i}:`);
    neighbours.forEach(n => console.log(`  Neighbour: ${n}`));
  });
}

// Run
printAdjMatrix(adjMatrix);
printAdjList(adjList);
