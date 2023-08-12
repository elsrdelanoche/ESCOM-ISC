from collections import deque    # Módulo de mesa lineal

# Primero se define una clase para crear un gráfico, usando la matriz de adyacencia
class Graph(object):
    def __init__(self, *args, **kwargs):
        self.order = []  # visited order
        self.neighbor = {}
 
    def add_node(self, node):
        key, val = node
        if not isinstance(val, list):
            print('La entrada del nodo debe ser una tabla lineal')    # Evitar una entrada incorrecta
        self.neighbor[key] = val
 
    # Implementación del algoritmo de ancho primero
    def BFS(self, root):
        # Dterminar si el nodo raíz es un nodo vacío
        if root != None:
            search_queue = deque()
            search_queue.append(root)
            visited = []
        else:
            print('root is None')
            return -1
 
        while search_queue:
            person = search_queue.popleft()
            self.order.append(person)
 
            if (not person in visited) and (person in self.neighbor.keys()):
                search_queue += self.neighbor[person]
                visited.append(person)
 
    # Implementación del algoritmo de profundidad primero
    def DFS(self, root):
        # Primero determinar si el nodo raíz es un nodo vacío
        if root != None:
            search_queue = deque()
            search_queue.append(root)
 
            visited = []
        else:
            print('root is None')
            return -1
 
        while search_queue:
            person = search_queue.popleft()
            self.order.append(person)
 
            if (not person in visited) and (person in self.neighbor.keys()):
                tmp = self.neighbor[person]
                tmp.reverse()
 
                for index in tmp:
                    search_queue.appendleft(index)
 
                visited.append(person)
 
    def clear(self):
        self.order = []
 
    def node_print(self):
        for index in self.order:
            print(index, end='  ')
 
 
if __name__ == '__main__':
    # Crear un gráfico de árbol binario
    g = Graph()
    g.add_node(('A', ['B', 'C']))
    g.add_node(('B', ['D', 'E']))
    g.add_node(('C', ['F']))
 
    # Hacer primera búsqueda en amplitud
    g.BFS('A')
    print('Amplitud primera búsqueda:')
    print('  ', end='  ')
    g.node_print()
    g.clear()
 
    # Hacer primera búsqueda en profundidad
    print('\n \nprimera búsqueda en profundidad:')
    print('  ', end='  ')
    g.DFS('A')
    g.node_print()
    print()