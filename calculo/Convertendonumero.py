numero = int(input("Informe o numero que deseja converter:"))
resto = 0
base = int(input("Informe a base em que deseja converter, utilize:\n 2-> binario\n 8-> octal\n 16->hexadecimal\n ==>_\b"))

dicionario = {10:"A", 11:"B",12:"C",13:"D",14:"E",15:"F"}

lista = []

while (numero//base)>=1:
    resto = numero % base
    numero = numero // base
    
    if(resto > 9):
        lista.append(dicionario[resto])
    else:
        lista.append(resto)

if numero >9:
    lista.append(dicionario[numero]) #adicionando o ultimo elemento da divisao
else:
    lista.append(numero)

j = lista[::-1]

print(f"\n{j}")
