import tkinter as tk
import random
import time
import threading
from sorted_list import SortedList
class Laberinto:
    def __init__(self, root, ancho, alto):
        self.root = root
        self.ancho = ancho
        self.alto = alto
        self.canvas = tk.Canvas(root, width=ancho * 20, height=alto * 20)
        self.canvas.pack()
        self.generar_laberinto()
        self.dibujar_laberinto()
        self.visited=[[0]*(self.ancho+1) for _ in range(self.alto+1)]
        self.pesos=[[1]*(self.ancho+1) for _ in range(self.alto+1)]
        self.root.bind("<Key>", self.mover)
        # Posición inicial del jugador
        self.jugador_pos = [1, 1]
        self.dibujar_jugador()
        self.order_Search=[]


    def generar_laberinto(self):
        # Generar un laberinto aleatorio simple
        self.laberinto = [[1] * self.ancho for _ in range(self.alto)]
        for y in range(1, self.alto - 1, 2):
            for x in range(1, self.ancho - 1, 2):
                self.laberinto[y][x] = 0  # Espacio libre
                if random.choice([True, False]):
                    self.laberinto[y][x + 1] = 0  # Pasillo horizontal
                else:
                    self.laberinto[y + 1][x] = 0  # Pasillo vertical

    def dibujar_laberinto(self):
        for y in range(self.alto):
            for x in range(self.ancho):
                color = "black" if self.laberinto[y][x] == 1 else "white"
                self.canvas.create_rectangle(x * 20, y * 20, x * 20 + 20, y * 20 + 20, fill=color)

    def dibujar_jugador(self):
        self.canvas.create_oval(self.jugador_pos[0] * 20 + 5, self.jugador_pos[1] * 20 + 5,
                                self.jugador_pos[0] * 20 + 15, self.jugador_pos[1] * 20 + 15,
                                fill="red", tags="jugador")
    
    def drawMoves(self,axis,color):
        x,y = axis
        self.canvas.create_rectangle(x * 20, y * 20, x * 20 + 20, y * 20 + 20, fill=color)
        self.root.update()  
        time.sleep(0.1) 
        
    def clearMoves(self):
        for x,y in self.order_Search:
            self.canvas.create_rectangle(x * 20, y * 20, x * 20 + 20, y * 20 + 20, fill="white")

    def init_dfs(self):
        original_pos=self.jugador_pos.copy()
        self.order_Search.clear()
        for x in range(self.alto+1):
            for y in range(self.ancho+1):
                 self.visited[x][y] = 0
        self.dfs(original_pos)
        for cord in self.order_Search:
            self.drawMoves(cord,"red")
        for x in self.order_Search:
            self.drawMoves(x,"white")

    def dfs(self, pos):
        if(self.visited[pos[0]][pos[1]] == 0):
            self.order_Search.append(pos)
            self.visited[pos[0]][pos[1]] = 1
            x,y=pos
            moves=[[-1,0],[0,1],[1,0],[0,-1]]
            for move in moves:
                if(self.validar_movimiento([pos[0]+move[0],pos[1]+move[1]])):
                    self.dfs([pos[0]+move[0],pos[1]+move[1]])
    
    def dijstra(self):
        self.order_Search.clear()
        original_pos=self.jugador_pos.copy()
        for x in range(self.alto+1):
            for y in range(self.ancho+1):
                 self.visited[x][y] = 1e9
        moves=[[-1,0],[0,1],[1,0],[0,-1]]
        q=SortedList()
        visited[original_pos[0]][original_pos[1]]=0
        q.append([0,original_pos])
        while(len(q)):
            data=q[0]
            cord=q[1]
            if( data>self.visited[cord[0]][cord[1]]):
                continue
            q.pop(0)
            order_Search.append(cord)
            for move in moves:
                to=[pos[0]+move[0],pos[1]+move[1]]
                if(self.visited[to[0]][to[1]]>self.visited[cord[0]][cord[1]]+self.pesos[to[0]][to[1]]):
                    self.visited[to[0]][to[1]] = self.visited[cord[0]][cord[1]]+self.pesos[to[0]][to[1]]
                    q.append([visited[to[0]][to[1]],to])

        for cord in self.order_Search:
            self.drawMoves(cord,"red")
        for x in self.order_Search:
            self.drawMoves(x,"white")

    def bfs(self):
        self.order_Search.clear()
        original_pos=self.jugador_pos.copy()
        q=[]
        for x in range(self.alto+1):
            for y in range(self.ancho+1):
                 self.visited[x][y] = 0
        moves=[[-1,0],[0,1],[1,0],[0,-1]]
        q.append(original_pos)
        while(len(q)):
            pos=q[0]
            self.visited[pos[0]][pos[1]] = 1
            self.order_Search.append(pos)
            q.pop(0)
            for move in moves:
                to=[pos[0]+move[0],pos[1]+move[1]]
                if(self.validar_movimiento(to) and self.visited[to[0]][to[1]]==0):
                    q.append(to)
                    self.visited[to[0]][to[1]] = 1

        for cord in self.order_Search:
            self.drawMoves(cord,"red")
        for x in self.order_Search:
            self.drawMoves(x,"white")
    
    def mover(self, event):
        nueva_pos = self.jugador_pos.copy()
        if event.keysym == "Up":
            self.clearMoves()
            self.init_dfs()
        elif event.keysym == "Down":
            self.clearMoves()
            self.bfs()
        elif event.keysym == "Left":
            nueva_pos[0] -= 1
        elif event.keysym == "Right":
            nueva_pos[0] += 1

        if self.validar_movimiento(nueva_pos):
            self.canvas.delete("jugador")
            self.jugador_pos = nueva_pos
            self.dibujar_jugador()

    def validar_movimiento(self, nueva_pos):
        x, y = nueva_pos
        if 0 <= x < self.ancho and 0 <= y < self.alto:
            return self.laberinto[y][x] == 0
        return False

if __name__ == "__main__":
    root = tk.Tk()
    laberinto = Laberinto(root, 30, 30)  # Tamaño del laberinto (ancho, alto)
    root.title("Laberinto")
    root.mainloop()
