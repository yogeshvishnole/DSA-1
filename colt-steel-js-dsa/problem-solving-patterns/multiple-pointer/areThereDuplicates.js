/* 

Frequency Counter / Multiple Pointers - areThereDuplicates
Implement a function called, areThereDuplicates which accepts a variable number of arguments, and checks whether there are any duplicates among the arguments passed in.  You can solve this using the frequency counter pattern OR the multiple pointers pattern.

Examples:

areThereDuplicates(1, 2, 3) // false
areThereDuplicates(1, 2, 2) // true 
areThereDuplicates('a', 'b', 'c', 'a') // true 
Restrictions:

Time - O(n)

Space - O(n)

Bonus:

Time - O(n log n)

Space - O(1)


*/

function areThereDuplicatesFreqCounter(...args) {
  const freqCounter = {};
  for (let el of args) {
    freqCounter[el] = ++freqCounter[el] || 1;
    if (freqCounter[el] > 1) {
      return true;
    }
  }
  return false;
}
function areThereDuplicatesMultiPointer(...args) {
  args.sort();
  let i = 0;
  let j = i + 1;
  while (j < args.length) {
    if (args[i] === args[j]) return true;
    i++;
    j++;
  }
  return false;
}

console.log(
  "areThereDuplicatesFreqCounter(1, 2, 3)",
  areThereDuplicatesFreqCounter(1, 2, 3)
); // false
console.log(
  "areThereDuplicatesFreqCounter(1, 2, 2)",
  areThereDuplicatesFreqCounter(1, 2, 2)
); // true
console.log(
  'areThereDuplicatesFreqCounter("a", "b", "c", "a")',
  areThereDuplicatesFreqCounter("a", "b", "c", "a")
); // true
console.log(
  "areThereDuplicatesMultiPointer(1, 2, 3)",
  areThereDuplicatesMultiPointer(1, 2, 3)
); // false
console.log(
  "areThereDuplicatesMultiPointer(1, 2, 2)",
  areThereDuplicatesMultiPointer(1, 2, 2)
); // true
console.log(
  'areThereDuplicatesMultiPointer("a", "b", "c", "a")',
  areThereDuplicatesMultiPointer("a", "b", "c", "a")
); // true
