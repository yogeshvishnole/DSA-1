function countUniqueValues(inputArr) {
  let counter = inputArr.length ? 1 : 0;
  let p1 = 0;
  let p2 = 1;

  while (p2 < inputArr.length) {
    if (inputArr[p1] !== inputArr[p2]) {
      counter++;
      p1 = p2;
    }
    p2++;
  }
  return counter;
}

//Example1
console.log("[1,1,1,1,1,2]", " ", countUniqueValues([1, 1, 1, 1, 1, 2]));
//Example2
console.log(
  "[1,2,3,4,4,4,7,7,12,12,13]",
  " ",
  countUniqueValues([1, 2, 3, 4, 4, 4, 7, 7, 12, 12, 13])
);
//Example3
console.log("[]", " ", countUniqueValues([]));
//Example4
console.log("[-2,-1,-1,0,1]", " ", countUniqueValues([-2, -1, -1, 0, 1]));

/* 
Time complexity = O(n)
Space complexoty = O(1)
*/
