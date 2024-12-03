#!/bin/python
import random
import string
import json
def generate_shuffle_map(filename):
    letters=list(string.ascii_lowercase)
    shuffled=letters[:]
    random.shuffle(shuffled)
    shuffle_map={letters[i]:shuffled[i]for i in range(len(letters))}
    with open(filename,'w')as file:
        json.dump(shuffle_map,file)
    print(f"Shuffle map saved to {filename}")
if __name__=="__main__":
    generate_shuffle_map("input.json")
    generate_shuffle_map("output.json")
