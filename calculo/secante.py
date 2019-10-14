import math

def Fx(x):
    fx = math.exp(-x ** 2 + 1) + math.sin(x ** 2) - x
    return fx

a = float(input("Ponto a:"))
b = float(input("Ponto b:"))
p = float(input("Precisao p:"))

Y = a
X = b

i = 1
list = []

list.append(Fx(a))
list.append(Fx(b))

K = 0
#X = Xk, Y = Xk-1, K = Xk+1

while True:
    K = X - (((list[i]) * (X - Y)) / (list[i] - list[i-1]))
    Y = X
    X = K

    list.append(Fx(K))

    if list[i] < p:
        print(f"O valor aproximado é de:{K}, o numero de iterações é{i}")
        break
    i += 1