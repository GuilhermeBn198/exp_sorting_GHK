lista = list(range(100, -1, -1))
with open('lista_decrescente.csv', 'w') as f:
    f.write(' '.join(map(str, lista)))
