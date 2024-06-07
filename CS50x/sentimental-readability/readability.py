from cs50 import get_string

text = get_string("Text: ")

# Counting letters
letter = sum(c.isalpha() for c in text)

# Counting words
word = len(text.split())

# Counting sentences
sentence = text.count('.') + text.count('!') + text.count('?')

L = (letter / word) * 100
S = (sentence / word) * 100
index = (0.0588 * L) - (0.296 * S) - 15.8

if index >= 16:
    print("Grade 16+")
elif index < 1:
    print("Before Grade 1")
else:
    print(f"Grade {index:.0f}")
