#include <gtk/gtk.h>

// Función para manejar el evento "clicked" del botón
void button_clicked(GtkWidget *widget, gpointer data) {
    g_print("¡Botón presionado!\n");
}

int main(int argc, char *argv[]) {
    // Inicializar GTK+
    gtk_init(&argc, &argv);

    // Crear una ventana
    GtkWidget *window = gtk_window_new(GTK_WINDOW_TOPLEVEL);
    gtk_window_set_title(GTK_WINDOW(window), "Ventana de menú");
    gtk_window_set_default_size(GTK_WINDOW(window), 200, 200);

    // Crear un contenedor
    GtkWidget *box = gtk_box_new(GTK_ORIENTATION_VERTICAL, 5);
    gtk_container_add(GTK_CONTAINER(window), box);

    // Crear un botón
    GtkWidget *button = gtk_button_new_with_label("Ejecutar");
    g_signal_connect(button, "clicked", G_CALLBACK(button_clicked), NULL);
    gtk_box_pack_start(GTK_BOX(box), button, TRUE, TRUE, 0);

    // Mostrar todos los widgets
    gtk_widget_show_all(window);

    // Ejecutar el bucle principal de GTK+
    gtk_main();

    return 0;
}

