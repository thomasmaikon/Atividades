import math

def Fx(x):
    fx = math.exp(-x ** 2 + 1) + math.sin(x ** 2) - x
    return fx

def Wx(x):
    Wx = ((math.exp(-x ** 2 + 1) + math.sin(x ** 2) - x) + 2 * x) / 2
    return Wx

x0 = float(input("Entre com o numero real x0: "))
p = float(input("Entre com o numero para a precisao P: "))

i = 0

while True:
    i+=1
    x1=Wx(x0)
    if abs(Fx(x1)) < p or abs(x1-x0) < p:
        print(f"x = {x1}")
        print(f"Número de vezes ={i}")
        break
    x0=x1