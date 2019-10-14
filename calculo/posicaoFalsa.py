import math

def funcao(x):
    fx = math.exp(-x**2+1)+math.sin(x**2)-x
    return fx

a =float(input("ponto A:"))
b =float(input("ponto B:"))
p =float(input("precisao p: "))

i = 0

while True:
    i += 1

    fxa = funcao(a)

    fxb = funcao(b)

    x = (a*fxb-b*fxa)/(fxb-fxa)

    fx = funcao(x)

    if abs(fxa) < p:
        x = a
        break
    elif abs(fxb) < p:
        x = b
        break
    elif abs(fx) < p:
        break
    elif fxa*fx < 0:
        b = x
    elif fxa*fx > 0:
        a = x
    elif b-a < p:
        x = (b+a)/2

print(f"Aproximação da raiz ={x}")