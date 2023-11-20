a = [0] * 10
for i in range(len(a)):
    a[i] = int(input("ciao: "))
print("ValoreMaximo: ", max(a))
print("ValoreMinimo: ", min(a))
print("OrdineCrescente: ", sorted(a))
print("OrdineDecrescente: ", sorted(a, reverse=True))
x = list(reversed(a))
print("AlContrario: ", x)
print("Somma: ", sum(a))