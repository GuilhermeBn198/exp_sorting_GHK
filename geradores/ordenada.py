lista = list(range(101))
with open('lista_crescente.csv', 'w') as f:
    f.write(' '.join(map(str, lista)))
