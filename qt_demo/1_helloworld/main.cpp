#include <QtCore/QCoreApplication>
#include <QtCore/QDebug>

int main(int argc, char* argv[]) {
    QCoreApplication app(argc, argv);
    qDebug() << "Hello World";
    app.exec();
}