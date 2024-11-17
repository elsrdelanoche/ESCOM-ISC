import threading
import random
import time

class Buffer:
    def __init__(self, max_size):
        self.buffer = []
        self.max_size = max_size
        self.lock = threading.Lock()
        self.not_full = threading.Condition(self.lock)
        self.not_empty = threading.Condition(self.lock)

    def produce(self, item, producer_id):
        self.lock.acquire()
        try:
            while len(self.buffer) >= self.max_size:
                print(f"Buffer lleno. Productor {producer_id} en espera...")
                self.not_full.wait()  # Espera hasta que haya espacio disponible

            self.buffer.append(item)  # Agrega el ítem al buffer
            print(f"Productor {producer_id} produjo: {item}. Estado del buffer: {self.buffer}")
            self.not_empty.notify_all()  # Notifica a los consumidores que hay un nuevo ítem
        finally:
            self.lock.release()  # Libera el lock del buffer

    def consume(self, consumer_id):
        self.lock.acquire()
        try:
            while not self.buffer:
                print(f"Buffer vacío. Consumidor {consumer_id} en espera...")
                self.not_empty.wait()  # Espera hasta que haya algo en el buffer

            item = self.buffer.pop(0)  # Extrae el primer ítem del buffer
            print(f"Consumidor {consumer_id} consumió: {item}. Estado del buffer: {self.buffer}")
            self.not_full.notify_all()  # Notifica a los productores que hay espacio disponible
            return item
        finally:
            self.lock.release()  # Libera el lock del buffer


class Producer(threading.Thread):
    def __init__(self, buffer, producer_id):
        super().__init__()
        self.buffer = buffer
        self.producer_id = producer_id
        self.running = True

    def run(self):
        while self.running:
            item = random.randint(10, 99)  # Genera un número aleatorio entre 10 y 99
            self.buffer.produce(item, self.producer_id)
            time.sleep(random.uniform(0.5, 1.5))  # Simula el tiempo de producción

    def stop(self):
        self.running = False  # Indica que debe detenerse


class Consumer(threading.Thread):
    def __init__(self, buffer, consumer_id):
        super().__init__()
        self.buffer = buffer
        self.consumer_id = consumer_id
        self.running = True

    def run(self):
        while self.running:
            self.buffer.consume(self.consumer_id)
            time.sleep(random.uniform(0.5, 1.5))  # Simula el tiempo de consumo

    def stop(self):
        self.running = False  # Indica que debe detenerse


def main():
    # Configuración inicial de número de hilos y tamaño del buffer
    num_producers = int(input("Ingrese la cantidad de hilos productores: "))
    num_consumers = int(input("Ingrese la cantidad de hilos consumidores: "))
    max_buffer_size = 10

    # Crea el buffer y los hilos productores y consumidores
    buffer = Buffer(max_buffer_size)
    producers = [Producer(buffer, i + 1) for i in range(num_producers)]
    consumers = [Consumer(buffer, i + 1) for i in range(num_consumers)]

    # Inicia los hilos de productores y consumidores
    for producer in producers:
        producer.start()
    for consumer in consumers:
        consumer.start()

    try:
        while True:
            time.sleep(5)
    except KeyboardInterrupt:
        print("Deteniendo productores y consumidores...")
        for producer in producers:
            producer.stop()
        for consumer in consumers:
            consumer.stop()

        # Espera a que todos los hilos finalicen
        for producer in producers:
            producer.join()
        for consumer in consumers:
            consumer.join()

    print("Programa terminado.")

if __name__ == "__main__":
    main()
