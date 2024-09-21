// Problem (in shortcut) In a sorted array find the first pair of elements whose sum is zero
// if you find a pair return that pair in an array otherwise return nothing or so called undefined
// in javascript

function sumZero(inputArr) {
  let i = 0;
  let j = inputArr.length - 1;

  while (inputArr[i] <= 0 && inputArr[j] >= 0 && i < j) {
    // case 1
    if (inputArr[i] + inputArr[j] === 0) {
      return [inputArr[i], inputArr[j]];
    }
    // case 2
    else if (inputArr[i] + inputArr[j] > 0) {
      j--;
    } else {
      i++;
    }
  }
}
// example 1
console.log(sumZero([-3, -2, -1, 0, 1, 2, 3]));
// example 2
console.log(sumZero([-2, 0, 1, 3]));
// example 3
console.log(sumZero([1, 2, 3]));
