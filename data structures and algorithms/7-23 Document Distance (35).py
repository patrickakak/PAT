import math, string, sys

translation_table = string.maketrans(string.punctuation+string.uppercase, " "*len(string.punctuation)+string.lowercase)

def get_words_from_line_list(text):
    text = text.translate(translation_table)
    word_list = text.split()
    return word_list

def count_frequency(word_list):
    D = {}
    for new_word in word_list:
        if new_word in D:
            D[new_word] = D[new_word]+1
        else:
            D[new_word] = 1
    return D

def word_frequencies_for_file(text):
    word_list = get_words_from_line_list(text)
    for i in range(len(word_list)):
        w=word_list[i]
        l=len(w)
        if l>3 and w[l-3:]=='ing':
            word_list[i]=w[:l-3]
        elif l>3 and w[l-3:]=='ies':
            word_list[i]=w[:l-3]+'y'
        elif l>2 and w[l-2:]=='es':
            word_list[i]=w[:l-2]
        elif l>2 and w[l-2:]=='ed':
            word_list[i]=w[:l-2]  
    freq_mapping = count_frequency(word_list)
    return freq_mapping

def inner_product(D1,D2):
    sum = 0.0
    for key in D1:
        if key in D2:
            sum += D1[key] * D2[key]
    return sum

def vector_angle(D1,D2):
    numerator = inner_product(D1,D2)
    denominator = math.sqrt(inner_product(D1,D1)*inner_product(D2,D2))
    return math.acos(numerator/denominator)

def main():
    n = input()
    d = {}
    for i in range(n):
        title = raw_input()
        s, text = ' ', ' '
        while s != '#':
            s = raw_input()
            if s == '#': break
            else: text += ' '+s
        sorted_word_list = word_frequencies_for_file(text)
        d[title] = sorted_word_list
    m = input()
    for i in range(m):
        s = raw_input().split()
        a, b = s[0], s[1]
        distance = vector_angle(d[a], d[b])
        print "Case %d: %0.3f"  %(i+1, distance)

if __name__ == "__main__":
    main()

