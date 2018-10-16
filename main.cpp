#include <QtCore>
#include <QtXml>
#include <QDebug>

int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);

    QDomDocument document;

    QDomElement root = document.createElement("Masini");

    document.appendChild(root);

    for(int a = 0; a < 10; a++)
    {
        QDomElement masina = document.createElement("Masina");
        masina.setAttribute("ID", QString::number(a));
        masina.setAttribute("Nume", " Masina " + QString::number(a));
        root.appendChild(masina);

        for(int b = 0; b < 4; b++)
        {
            QDomElement model = document.createElement("Model");
            model.setAttribute("ID", QString::number(b));
            model.setAttribute("Nume", " Model " + QString::number(b));
            masina.appendChild(model);
        }
    }

    QFile file("C:/Users/Administrator/Documents/Qt Projects/XML.xml");
    if(!file.open(QIODevice::WriteOnly | QIODevice::Text))
    {
        qDebug() << "Nu se poate deschide";
        return -1;
    }
    else
    {
        QTextStream stream(&file);
        stream << document.toString();
        file.close();
        qDebug() << "Terminat";
    }

    return a.exec();
}
