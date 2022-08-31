'''
Q804. Description: International Morse Code defines a standard encoding where each letter is mapped to a series of dots and dashes.
Given an array of strings words where each word can be written as a concatenation of the Morse code of each letter. For example, "cab" can be written as "-.-..--...", which is the concatenation of "-.-.", ".-", and "-...". We will call such a concatenation the transformation of a word.

Return the number of different transformations among all words we have.
'''
class Solution:
    def uniqueMorseRepresentations(self, words: List[str]) -> int:
        morsecode = {'a': '.-', 'b': '-...', 'c': '-.-.', 'd': '-..', 'e': '.', 
                     'f': '..-.', 'g': '--.', 'h': '....', 'i': '..', 'j': '.---', 
                     'k': '-.-', 'l': '.-..', 'm': '--', 'n': '-.', 'o': '---', 
                     'p': '.--.', 'q': '--.-', 'r': '.-.', 's': '...', 't': '-', 
                     'u': '..-', 'v': '...-', 'w': '.--', 'x': '-..-', 
                     'y': '-.--', 'z': '--..'}
        
        result = {}
        for word in words:
            code = ''
            for letter in word:
                code += morsecode[letter]
            if code not in result.keys():
                result[code] = 1
            else:
                result[code] += 1
        return len(result.keys())
                