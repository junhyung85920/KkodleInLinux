import pandas as pd
import re
from jamo import h2j, j2hcj


def is_pure_hangul(s):
    if (re.search(r'[A-Za-z0-9]', s)):
        print(s +  ": contains alphanum")
        return False
    return True


def is_single_jamo(word):
    jamo = j2hcj(h2j(word))
    dic = {'ㅐ':'ㅏㅣ','ㅒ':'ㅑㅣ','ㅔ':'ㅓㅣ','ㅖ':'ㅕㅣ',
       'ㅘ':'ㅗㅏ','ㅙ':'ㅗㅏㅣ','ㅚ':'ㅗㅣ','ㅝ':'ㅜㅓ',
       'ㅞ':'ㅜㅓㅣ','ㅟ':'ㅜㅣ','ㅢ':'ㅡㅣ',
       'ㄳ' : 'ㄱㅅ', 'ㄵ' : 'ㄴㅈ', 'ㄶ' : 'ㄴㅎ','ㄺ' : 'ㄹㄱ',
       'ㄻ' : 'ㄹㅁ', 'ㄼ' : 'ㄹㅂ', 'ㄽ' : 'ㄹㅅ', 'ㄾ' : 'ㄹㅌ', 
       'ㄿ' : 'ㄹㅍ', 'ㅀ' : 'ㄹㅎ', 'ㅄ' : 'ㅂㅅ', 'ㄲ' : 'ㄱㄱ','ㅆ'  : 'ㅅㅅ',
       'ㄸ':'ㄷㄷ','ㅃ':'ㅂㅂ','ㅉ':'ㅈㅈ'}
    for i in jamo:
        if i in dic.keys():
            jamo = jamo.replace(i,dic[i])


def jamo_split(word):
    jamo = j2hcj(h2j(word))
    dic = {'ㅐ':'ㅏㅣ','ㅒ':'ㅑㅣ','ㅔ':'ㅓㅣ','ㅖ':'ㅕㅣ',
       'ㅘ':'ㅗㅏ','ㅙ':'ㅗㅏㅣ','ㅚ':'ㅗㅣ','ㅝ':'ㅜㅓ',
       'ㅞ':'ㅜㅓㅣ','ㅟ':'ㅜㅣ','ㅢ':'ㅡㅣ',
       'ㄳ' : 'ㄱㅅ', 'ㄵ' : 'ㄴㅈ', 'ㄶ' : 'ㄴㅎ','ㄺ' : 'ㄹㄱ',
       'ㄻ' : 'ㄹㅁ', 'ㄼ' : 'ㄹㅂ', 'ㄽ' : 'ㄹㅅ', 'ㄾ' : 'ㄹㅌ', 
       'ㄿ' : 'ㄹㅍ', 'ㅀ' : 'ㄹㅎ', 'ㅄ' : 'ㅂㅅ', 'ㄲ' : 'ㄱㄱ','ㅆ'  : 'ㅅㅅ',
       'ㄸ':'ㄷㄷ','ㅃ':'ㅂㅂ','ㅉ':'ㅈㅈ'}
    for i in jamo:
        if i in dic.keys():
            jamo = jamo.replace(i,dic[i])
    if(len(jamo) == 6):
        print(word + " : " + jamo + "   길이: ", len(jamo))
    # print(word + " : " + jamo + "   길이: ", len(jamo))  
    return jamo


translation_map = {
    'ㄱ': 'R', 'ㄴ': 'S', 'ㄷ': 'E', 'ㄹ': 'F',
    'ㅁ': 'A', 'ㅂ': 'Q', 'ㅅ': 'T', 'ㅇ': 'D',
    'ㅈ': 'W', 'ㅊ': 'C', 'ㅋ': 'Z', 'ㅌ': 'X', 'ㅍ': 'V',
    'ㅎ': 'G', 'ㅏ': 'K', 'ㅑ': 'I', 'ㅓ': 'J',
    'ㅕ': 'U', 'ㅗ': 'H',
    'ㅛ': 'Y', 'ㅜ': 'N',
    'ㅠ': 'B', 'ㅡ': 'M', 'ㅣ': 'L'
}


def translate_string(input_str):
    # Translate each character using the map, default to the original character if not found
    return ''.join(translation_map.get(char, char) for char in input_str)


file_path = '/Users/junhyung85920/Cworkspace/data_org.xlsx'
data = pd.read_excel(file_path)

first_column = data.columns[0]
data[first_column] = data[first_column].astype(str)
data[first_column].apply(lambda x: jamo_split(x))
data['Jamo'] = data[first_column].apply(jamo_split)
data = data.drop_duplicates(subset=['Jamo'], keep='first')
data['alphabet'] = data['Jamo'].apply(translate_string)

filtered_data = data[(data['Jamo'].apply(len) == 6) & 
                     (data[first_column].apply(is_pure_hangul)) &
                     (data[first_column].apply(lambda x: len(x.encode('utf-8')) in [6, 9]))]
output_path = '/Users/junhyung85920/Cworkspace/filtered_data.xlsx'
filtered_data.to_excel(output_path, index=False)

print("Written to:", output_path)