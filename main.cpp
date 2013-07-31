#include <QCoreApplication>
#include <QtCore/QCoreApplication>
#include <QTextCodec>
#include <QSettings>
#include <QDebug>
#include <QFile>
#include <QIODevice>
#include "station.h"



int main(int argc, char *argv[])
{
   QCoreApplication a(argc, argv);

   QString callSign;
   QString color;
   int frequency;

   QSettings ini("F:/QtProjects/untitled1/test.ini", QSettings::IniFormat);
   ini.beginGroup("STATION_1");
   callSign = ini.value("call_sign").toString();
   frequency = ini.value("frequency").toInt();

   qDebug() << callSign << frequency;
   ini.endGroup();

/*

   QFile file("F:/QtProjects/untitled1/test.txt");
   if(file.open(QIODevice::ReadOnly))
   {
        QTextStream stream(&file);
        QString str;
         while (!stream.atEnd())
         {
                str = stream.readAll();
                qDebug() << str;
         }

         if (stream.status() != QTextStream::Ok)
         {
                qDebug() << "Ошибка чтения файла";
         }
   file.close();
   }

*/

   int pDelta, pK, mFrequency;
   cout << "Input delta: " << endl; cin >> pDelta;
   cout << "Input k: " << endl; cin >> pK;
   mFrequency = frequency;
   Station myStation(pDelta, pK, mFrequency);
   myStation.error();
   myStation.output();
    
    return 0;
}
