function validAnagram(str1, str2) {
  if (str1.length !== str2.length) {
    return false;
  }

  let str1LetterFreq = {};
  let str2LetterFreq = {};

  for (let char of str1) {
    str1LetterFreq[char] = ++str1LetterFreq[char] || 1;
  }
  for (let char of str2) {
    str2LetterFreq[char] = ++str2LetterFreq[char] || 1;
  }

  for (let key in str1LetterFreq) {
    if (!str2LetterFreq[key] || str1LetterFreq[key] !== str2LetterFreq[key]) {
      return false;
    }
  }

  return true;
}

console.log('"", ""', validAnagram("", ""));
console.log('"aaz", "zza"', validAnagram("aaz", "zza"));
console.log('"anagram", "nagaram"', validAnagram("anagram", "nagaram"));
console.log('"rat", "car"', validAnagram("rat", "car"));
console.log('"awesome", "awesom"', validAnagram("awesome", "awesom"));
console.log('"qwerty", "qeywrt"', validAnagram("qwerty", "qeywrt"));
console.log(
  '"texttwisttime", "timetwisttext"',
  validAnagram("texttwisttime", "timetwisttext")
);
