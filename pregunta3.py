
import threading, time
import math, random
lock = threading.Lock()
import queue

class pi(threading.Thread):
    def __init__(self, n, q):
        threading.Thread.__init__(self)
        self.n = n
        self.x = 0
        self.y = 0
        self.c = 0

    def enCirculo(self, x, y):
        acierta = False
        res = x ** 2 + y ** 2
        if res <= 1:
            acierta = True
        return acierta

    def run(self):
        for i in range(int(self.n)):
            self.x = random.random()
            self.y = random.random()
            self.acierta = self.enCirculo(self.x, self.y)
            if self.acierta:
                self.c = self.c + 1
        pii = (4.0 * self.c)/self.n
        q.put(self.c)


q = queue.Queue()
hilos = 5 #simula 5 procesadores
n = 100000000 #numero de pruebas

for i in range(hilos):
    h = pi(n/5, q)
    h.start()
    h.join()

    print(q.qsize())
i = 0
total = 0
for i in range(q.qsize()):
    num =  q.get(i)
    print (num) #aqui se imprime la suma que obtiene cada hilo individual
    total = num + total

pi = (4.0 * total)/n # formula para obtener el pi tomando el total de aciertos y dividiendo
print ("Pi en colaboracion " + str(pi)) 



