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
   double frequency;

   QSettings ini("F:/QtProjects/untitled1/test.ini", QSettings::IniFormat);
   ini.beginGroup("STATION_1");
   callSign = ini.value("call_sign").toString();
   color = ini.value("color").toString();
   frequency = ini.value("frequency").toDouble();

   qDebug() << callSign << color << frequency;
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

   double pDelta, pK;
   double mFrequency = frequency;
   string mCall = callSign;
   string mColor = color;

   cout << "Input delta: " << endl; cin >> pDelta;
   cout << "Input k: " << endl; cin >> pK;

   Station myStation(pDelta, pK, mCall, mColor, mFrequency);
   myStation.error();
   myStation.output();
    
    return 0;
}
