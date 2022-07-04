'''
Created on Dec 10, 2020

@author: Miruna
'''

def shake_sort(lista, key = lambda x: x, reversed = False):
    """
    Functie pentru sortarea de tip Shake sort
    """
    left = 0
    right = len(lista) - 1
    lastSwap = 0
    if reversed == False:
        while left < right: 
            
            for i in range(right, left, -1):
                if key(lista[i - 1]) > key(lista[i]):
                    aux = lista[i]
                    lista[i] = lista[i - 1]
                    lista[i - 1] = aux
                    lastSwap = i; 
            left = lastSwap
            
            for i in range(left, right):
                if key(lista[i]) > key(lista[i + 1]): 
                    aux = lista[i]
                    lista[i] = lista[i + 1]
                    lista[i + 1] = aux
                    lastSwap = i 
            right = lastSwap
    else:
        while left < right: 
            
            for i in range(right, left, -1):
                if key(lista[i - 1]) < key(lista[i]):
                    aux = lista[i]
                    lista[i] = lista[i - 1]
                    lista[i - 1] = aux
                    lastSwap = i; 
            left = lastSwap
            
            for i in range(left, right):
                if key(lista[i]) < key(lista[i + 1]): 
                    aux = lista[i]
                    lista[i] = lista[i + 1]
                    lista[i + 1] = aux
                    lastSwap = i 
            right = lastSwap
    return lista


def selection_sort(lista, key = lambda x: x, reversed = False):
    """
    Functie pentru sortarea de tip Selection sort
    """
    if reversed == False:
        for i in range(0, len(lista) - 1):
            index = i
            for j in range(i + 1, len(lista)):
                if (key(lista[j]) < key(lista[index])):
                    index = j
            if (i < index):
                aux = lista[i]
                lista[i] = lista[index]
                lista[index] = aux
    else:
        for i in range(0, len(lista) - 1):
            index = i
            for j in range(i + 1, len(lista)):
                if (key(lista[j]) > key(lista[index])):
                    index = j
            if (i < index):
                aux = lista[i]
                lista[i] = lista[index]
                lista[index] = aux
    return lista


def selection_sort_doua_criterii(lista, key1 = lambda x: x, key2 = lambda x: x, reversed = False):
    """
    Functie pentru sortarea de tip Selection sort
    """
    if reversed == False:
        for i in range(0, len(lista) - 1):
            index = i
            for j in range(i + 1, len(lista)):
                if key1(lista[j]) < key1(lista[index]):
                    index = j
                elif key1(lista[j]) == key1(lista[index]):
                    if key2(lista[j]) < key2(lista[index]):
                        index = j
            if (i < index):
                aux = lista[i]
                lista[i] = lista[index]
                lista[index] = aux
    else:
        for i in range(0, len(lista) - 1):
            index = i
            for j in range(i + 1, len(lista)):
                if key1(lista[j]) > key1(lista[index]):
                    index = j
                elif key1(lista[j]) == key1(lista[index]):
                    if key2(lista[j]) > key2(lista[index]):
                        index = j
            if (i < index):
                aux = lista[i]
                lista[i] = lista[index]
                lista[index] = aux
    return lista


def key(eveniment):
            zi = eveniment[0]
            luna = eveniment[1]
            an = eveniment[2]
            data = str(an) + "."
            if int(luna) < 10:
                data += "0"
            data += str(luna) + "."
            if int(zi) < 10:
                data += "0" 
            data += str(zi)
        
            return data

def test_sortari():
    """Functie de test"""
    
    assert selection_sort_doua_criterii([[1, 5], [3, 0], [1, 8], [5, 7], [1, 1], [5, 9]], key1 = lambda x: x[0], key2 = lambda x: x[1]) == [[1, 1], [1, 5], [1, 8], [3, 0], [5, 7], [5, 9]]
    
    assert selection_sort([1, 5, 29, -3928, 376, 109, -33, 176]) == [-3928, -33, 1, 5, 29, 109, 176, 376]
    assert selection_sort([1, 5, 29, -3928, 376, 109, -33, 176], reversed = True) == [376, 176, 109, 29, 5, 1, -33, -3928]
    assert selection_sort([[1, 5], [4, 8], [1, 1], [5, 9]], key = lambda x: x[1]) == [[1, 1], [1, 5], [4, 8], [5, 9]]
    assert shake_sort([[1, 5], [4, 8], [10, 1], [5, 9]], key = lambda x: x[1], reversed = True) == [[5, 9],  [4, 8], [1, 5], [10, 1]]
    
    assert shake_sort([1, 5, 29, -3928, 376, 109, -33, 176]) == [-3928, -33, 1, 5, 29, 109, 176, 376]
    assert shake_sort([1, 5, 29, -3928, 376, 109, -33, 176], reversed = True) == [376, 176, 109, 29, 5, 1, -33, -3928]
    assert shake_sort([[1, 5], [4, 8], [10, 1], [5, 9]], key = lambda x: x[1]) == [[10, 1], [1, 5], [4, 8], [5, 9]]
    assert shake_sort([[1, 5], [4, 8], [10, 1], [5, 9]], key = lambda x: x[1], reversed = True) == [[5, 9],  [4, 8], [1, 5], [10, 1]]
    
    date = [[11, 12, 2019], [20, 11, 2020], [11, 11, 2009], [30, 1, 2020], [1, 5, 2018], [15, 10, 2021], [12, 12, 2019], [30, 2, 2020], [1, 10, 2021]]

    assert selection_sort(date, key) == [[11, 11, 2009], [1, 5, 2018], [11, 12, 2019], [12, 12, 2019], [30, 1, 2020], [30, 2, 2020], [20, 11, 2020], [1, 10, 2021], [15, 10, 2021]]
    assert shake_sort(date, key) == [[11, 11, 2009], [1, 5, 2018], [11, 12, 2019], [12, 12, 2019], [30, 1, 2020], [30, 2, 2020], [20, 11, 2020], [1, 10, 2021], [15, 10, 2021]]




test_sortari()






