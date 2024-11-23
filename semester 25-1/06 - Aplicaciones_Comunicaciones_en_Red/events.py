import threading
import time

def worker(event, file_name):
    while True:
        event.wait()  # Espera a que el evento sea establecido
        with open(file_name, 'a') as f:
            f.write(f"Hilo {threading.current_thread().name} ha escrito\n")
        event.clear()  # Limpia el evento para la próxima iteración

if __name__ == "__main__":
    event = threading.Event()
    file_name = "output.txt"

    # Crear 10 hilos
    threads = []
    for i in range(10):
        t = threading.Thread(target=worker, args=(event, file_name))
        threads.append(t)
        t.start()

    # Simular trabajo y establecer el evento
    while True:
        time.sleep(2)
        print("Señalando a los hilos para escribir...")
        event.set()  # Establece el evento para despertar a los hilos
