# Synonyms dictionary

`DictionarySynonyms` is a dictionary of synonyms stored as `HashMap<String, HashSet<String>>`. Adding a pair of words links them in both directions.

- `addWord(word1, word2)` - adds a pair of synonyms
- `countSynonyms(word)` - number of synonyms of a word, `-1` if the word is unknown
- `printListSynonyms(word)` - prints all synonyms of a word

```bash
javac -d out src/dictionarysynonyms/DictionarySynonyms.java
java -cp out dictionarysynonyms.DictionarySynonyms
```
