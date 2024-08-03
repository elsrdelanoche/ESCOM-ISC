#include <QApplication>
#include <QMainWindow>
#include <QTextEdit>
#include <QPushButton>
#include <QVBoxLayout>
#include <QLabel>
#include <QProcess>

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr)
        : QMainWindow(parent)
    {
        // Configurar la ventana principal
        setWindowTitle("Ejecutor de código C++");

        // Crear el editor de texto para el código C++
        codeEditor = new QTextEdit(this);

        // Crear la etiqueta para mostrar la imagen generada
        imageLabel = new QLabel(this);
        imageLabel->setAlignment(Qt::AlignCenter);

        // Crear el botón para ejecutar el código
        executeButton = new QPushButton("Ejecutar", this);

        // Conectar el evento click del botón a la función correspondiente
        connect(executeButton, &QPushButton::clicked, this, &MainWindow::executeCode);

        // Crear el diseño de la interfaz
        QVBoxLayout *layout = new QVBoxLayout;
        layout->addWidget(codeEditor);
        layout->addWidget(imageLabel);
        layout->addWidget(executeButton);

        // Crear el widget central y asignarle el diseño
        QWidget *centralWidget = new QWidget(this);
        centralWidget->setLayout(layout);
        setCentralWidget(centralWidget);
    }

private slots:
    void executeCode()
    {
        // Obtener el código ingresado por el usuario
        QString code = codeEditor->toPlainText();

        // Compilar y ejecutar el código utilizando QProcess
        QProcess process;
        process.start("bash", QStringList() << "-c" << "g++ -o code_executable code.cpp && ./code_executable");
        process.waitForFinished(-1);

        // Leer la salida estándar del proceso
        QString output = process.readAllStandardOutput();

        // Actualizar la etiqueta con la salida generada
        imageLabel->setText(output);
    }

private:
    QTextEdit *codeEditor;
    QLabel *imageLabel;
    QPushButton *executeButton;
};

int main(int argc, char *argv[])
{
    QApplication app(argc, argv);

    MainWindow window;
    window.show();

    return app.exec();
}
