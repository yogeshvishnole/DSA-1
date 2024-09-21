// restate the problem in my own words
/* 

Given two arrays, arr1 and arr2 as input, the output should be true if arr2 contains square 
of all the elements of arr1 and frequency of the number in arr1 should be equal to its square in arr2.

[1,2] and [1,4] -> true
[1,2,1] and [1,4,4] -> false
[3,4] and [9,10] ->  false
[4,5,6] and [16,25,36,49] -> true
*/

function same(arr1, arr2) {
  const arr2Freq = {};
  const arr1SqareFreq = {};

  arr1.forEach((el) => {
    // arr1Freq[el] = ++arr1Freq[el] || 1;
    arr1SqareFreq[Math.pow(el, 2)] = ++arr1SqareFreq[Math.pow(el, 2)] || 1;
  });

  arr2.forEach((el) => {
    arr2Freq[el] = ++arr2Freq[el] || 1;
  });

  for (let arr1SquareEl in arr1SqareFreq) {
    if (
      !arr2Freq[arr1SquareEl] ||
      arr2Freq[arr1SquareEl] !== arr1SqareFreq[arr1SquareEl]
    ) {
      return false;
    }
  }

  return true;
}

console.log(same([4, 5, 6], [16, 25, 36, 49]));
