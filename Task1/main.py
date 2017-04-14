import random

n = int(input("Podaj n: "))
k = int(input("Podaj k: "))


def przedzial():
    """Funkcja ustalania poczatku i konca przedzialu"""
    while True:
        while True:
            s = int(input("Podaj poczatek przedzialu: "))
            if s >= 0:
                break
        while True:
            e = int(input("Podaj koniec przedzialu: "))
            if e >= 0:
                break
        if s < e:
            break
        else:
            print("Blad, podales poczatek wiekszy niz koniec! Zrob to poprawnie raz jeszcze: ")
    return s, e


def przedzial4():
    """Funkcja ustalania poczatku i konca przedzialu"""
    while True:
        while True:
            s = int(input("Podaj poczatek przedzialu dla punktu 4: "))
            if s > 0:
                break
        while True:
            e = int(input("Podaj koniec przedzialu dla punktu 4: "))
            if e > 0:
                break
        if s < e:
            break
        else:
            print("Blad, podales poczatek wiekszy niz koniec! Zrob to poprawnie raz jeszcze: ")
    return s, e

plik = open('Task.txt', 'w')

try:
    while True:
        plik.write('%d ' % n + '%d ' % k + '\n')
        choice = int(input("Wybierz 1 dla liczba calkowitych, wybierz 2 dla liczb zmiennoprzecinkowych: "))
        if choice == 1 or choice == 2:
            break
    if choice == 1:
        t, g = przedzial()
        for i in range(k):
            for j in range(n):
                plik.write(('%d ' % random.randint(t, g)))
            plik.write('\n')
        for i in range(k):
            plik.write(('%d ' % random.randint(t, g)))
        plik.write('\n')
        t, g = przedzial4()
        for i in range(n):
            plik.write(('%d ' % random.randint(t, g)))
        plik.write('\n')
    if choice == 2:
        t, g = przedzial()
        for i in range(k):
            for j in range(n):
                plik.write(('%f ' % random.uniform(t, g)))
            plik.write('\n')
        for i in range(k):
            plik.write(('%f ' % random.uniform(t, g)))
        plik.write('\n')
        t, g = przedzial4()
        for i in range(n):
            plik.write(('%f ' % random.uniform(t, g)))
        plik.write('\n')
    print(plik)
finally:
    plik.close()
