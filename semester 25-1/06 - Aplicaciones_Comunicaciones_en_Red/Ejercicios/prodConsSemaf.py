import threading
import random
import time

class Buffer:
    def __init__(self, max_size):
        self.buffer = []
        self.max_size = max_size
        self.semaphore_empty = threading.Semaphore(max_size)  # Semáforo para espacios vacíos
        self.semaphore_full = threading.Semaphore(0)  # Semáforo para ítems disponibles
        self.mutex = threading.Lock()  # Lock para acceso exclusivo al buffer

    def produce(self, item, producer_id):
        self.semaphore_empty.acquire()  # Espera hasta que haya espacio disponible
        with self.mutex:  # Acceso exclusivo al buffer
            self.buffer.append(item)
            print(f"Productor {producer_id} produjo: {item}. Estado del buffer: {self.buffer}")
        self.semaphore_full.release()  # Indica que hay un nuevo ítem disponible

    def consume(self, consumer_id):
        self.semaphore_full.acquire()  # Espera hasta que haya ítems disponibles
        with self.mutex:  # Acceso exclusivo al buffer
            item = self.buffer.pop(0)
            print(f"Consumidor {consumer_id} consumió: {item}. Estado del buffer: {self.buffer}")
        self.semaphore_empty.release()  # Indica que hay espacio disponible
        return item


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
