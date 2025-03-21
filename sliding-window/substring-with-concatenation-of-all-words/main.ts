function findSubstring(s: string, words: string[]): number[] {
  const result = [];

  const sLength = s.length;
  const wordCount = words.length;
  const wordLength = words[0].length;

  if (sLength < wordCount * wordLength) {
    return result;
  }

  const wordFreq = new Map<string, number>();
  for (const word of words) {
    wordFreq.set(word, (wordFreq.get(word) || 0) + 1);
  }

  // Try each possible starting point
  for (let i = 0; i < wordLength; i++) {
    let left = i;
    let right = i;
    let count = 0;
    const wordSeen = new Map<string, number>();

    // Sliding window
    while (right + wordLength <= sLength) {
      const word = s.substr(right, wordLength);
      right += wordLength;

      // not in words
      if (!wordFreq.has(word)) {
        left = right;
        count = 0;
        wordSeen.clear();
        // in words
      } else {
        wordSeen.set(word, (wordSeen.get(word) || 0) + 1);
        count++;

        // remove exceeded words
        while (wordSeen.get(word) > wordFreq.get(word)) {
          const leftWord = s.substr(left, wordLength);
          left += wordLength;
          wordSeen.set(leftWord, wordSeen.get(leftWord) - 1);
          count--;
        }

        // found a result
        if (count === wordCount) {
          result.push(left);
          const leftWord = s.substr(left, wordLength);
          wordSeen.set(leftWord, wordSeen.get(leftWord) - 1);
          count--;
          left += wordLength;
        }
      }
    }
  }
  return result;
}
