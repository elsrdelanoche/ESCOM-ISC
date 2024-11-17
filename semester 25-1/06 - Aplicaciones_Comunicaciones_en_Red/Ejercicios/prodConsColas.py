import threading
import random
import time
import queue

class Buffer:
    def __init__(self, max_size):
        self.buffer = queue.Queue(max_size)  # Cola con tamaño máximo

    def produce(self, item, producer_id):
        try:
            self.buffer.put(item, timeout=1)  # Intento de agregar a la cola con tiempo de espera
            print(f"Productor {producer_id} produjo: {item}. Estado del buffer: {list(self.buffer.queue)}")
        except queue.Full:
            print(f"Buffer lleno. Productor {producer_id} esperando...")

    def consume(self, consumer_id):
        try:
            item = self.buffer.get(timeout=1)  # Intento de sacar de la cola con tiempo de espera
            print(f"Consumidor {consumer_id} consumió: {item}. Estado del buffer: {list(self.buffer.queue)}")
            return item
        except queue.Empty:
            print(f"Buffer vacío. Consumidor {consumer_id} esperando...")

class Producer(threading.Thread):
    def __init__(self, buffer, producer_id):
        super().__init__()
        self.buffer = buffer
        self.producer_id = producer_id
        self.running = True

    def run(self):
        while self.running:
            item = random.randint(10, 99)  # Genera un número aleatorio de 2 dígitos
            self.buffer.produce(item, self.producer_id)
            time.sleep(random.uniform(0.5, 1.5))  # Simula tiempo de producción

    def stop(self):
        self.running = False

class Consumer(threading.Thread):
    def __init__(self, buffer, consumer_id):
        super().__init__()
        self.buffer = buffer
        self.consumer_id = consumer_id
        self.running = True

    def run(self):
        while self.running:
            self.buffer.consume(self.consumer_id)
            time.sleep(random.uniform(0.5, 1.5))  # Simula tiempo de consumo

    def stop(self):
        self.running = False

def main():
    # Configuración inicial
    num_producers = int(input("Ingrese la cantidad de hilos productores: "))
    num_consumers = int(input("Ingrese la cantidad de hilos consumidores: "))
    max_buffer_size = int(input("Ingrese el tamaño máximo del buffer: "))

    # Inicialización del buffer
    buffer = Buffer(max_buffer_size)

    # Creación de productores y consumidores
    producers = [Producer(buffer, i + 1) for i in range(num_producers)]
    consumers = [Consumer(buffer, i + 1) for i in range(num_consumers)]

    # Inicio de los hilos
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

        # Espera a que todos los hilos terminen
        for producer in producers:
            producer.join()
        for consumer in consumers:
            consumer.join()

    print("Programa terminado.")

if __name__ == "__main__":
    main()
