# ==============================================
# ALUNO: RAFAEL SAMPAIO E SILVA
# RA: 844559
# ==============================================

import random
import time

def insertionSort(list):
    n = len(list)
    if n == 1:
        return list
    for i in range(1,n):
        chave = list[i]
        j = i - 1
        while j>=0 and list[j] > chave:
            list[j+1] = list[j]
            j = j - 1
        list[j+1] = chave     
        
def selectionSort(list):
    n = len(list)
    for j in range(n-1):
        menorNumero_index = j
        if n == 1:
            return list
        for i in range(j,n):
            if list[i] < list[menorNumero_index]:
                menorNumero_index = i
        if list[j] > list[menorNumero_index]:
            aux = list[j]
            list[j] = list[menorNumero_index]
            list[menorNumero_index] = aux
            
def mergesort(lista, inicio=0, fim=None):
    if fim is None:
        fim = len(lista)
    if(fim - inicio > 1):
        meio = (fim + inicio)//2
        mergesort(lista, inicio, meio)
        mergesort(lista, meio, fim)
        merge(lista, inicio, meio, fim)
def merge(lista, inicio, meio, fim):
    left = lista[inicio:meio]
    right = lista[meio:fim]
    top_left, top_right = 0, 0
    for k in range(inicio, fim):
        if top_left >= len(left):
            lista[k] = right[top_right]
            top_right = top_right + 1
        elif top_right >= len(right):
            lista[k] = left[top_left]
            top_left = top_left + 1
        elif left[top_left] < right[top_right]:
            lista[k] = left[top_left]
            top_left = top_left + 1
        else:
            lista[k] = right[top_right]
            top_right = top_right + 1

def heapify(arr, n, i):
	largest = i
	l = 2 * i + 1 # esquerda = 2*i + 1
	r = 2 * i + 2 # direita = 2*i + 2
 
	if l < n and arr[i] < arr[l]:
		largest = l
	if r < n and arr[largest] < arr[r]:
		largest = r
	if largest != i:
		(arr[i], arr[largest]) = (arr[largest], arr[i]) # swap
		heapify(arr, n, largest)
def heapSort(arr):
	n = len(arr)
	for i in range(n // 2, -1, -1):
		heapify(arr, n, i)
	for i in range(n - 1, 0, -1):
		(arr[i], arr[0]) = (arr[0], arr[i])
		heapify(arr, i, 0)

def quicksort(lista, inicio=0, fim=None):
    if fim is None:
        fim = len(lista)-1
    if inicio < fim:
        p = partition(lista, inicio, fim)
        quicksort(lista, inicio, p-1)
        quicksort(lista, p+1, fim)

def partition(lista, inicio, fim):
    pivot = lista[fim]
    i = inicio
    for j in range(inicio, fim):
        if lista[j] <= pivot:
            lista[j], lista[i] = lista[i], lista[j]
            i = i + 1
    lista[i], lista[fim] = lista[fim], lista[i]
    return i

# list = [2,7,0,8,0,3,5,4,6,1] # teste padrao
# list = [1,2,3,3,3,2,2,8,6,5] # teste repeticao
# list = [8,7,6,5,4,3,2,1] # teste inversão

# ==========================V===================
# Trocar o TAMANHO da lista desordenada AQUI
# ==========================V===================
numero_de_elementos = 10 ** 1
lista_desordenada = [random.randint(0, 999) for _ in range(numero_de_elementos)]

print("\n\n")
inicio = time.time() # COMEÇA o "Cronômetro"

insertionSort(lista_desordenada)
# selectionSort(lista_desordenada)
# mergesort(lista_desordenada)
# heapSort(lista_desordenada)
# quicksort(lista_desordenada)

fim = time.time() # PARA o Cronômetro
print(fim - inicio)
print("\n\n")
