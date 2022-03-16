#include "DataAccess.h"
#include <QIODevice>
#include <QFile>
#include <iostream>

void traversJson(QJsonObject json_obj) ;

DataAccess::DataAccess(const QString& path)
{
    QFile file(path);
    std::cout << "Opening file..." << "\n";
    if( file.open( QIODevice::ReadOnly ) )
    {
        QByteArray bytes = file.readAll();
        std:: cout << "bytes: " << QString(bytes).toStdString() << "\n";
        file.close();

        QJsonParseError jsonError;
        QJsonDocument document = QJsonDocument::fromJson( bytes, &jsonError );
        if( jsonError.error != QJsonParseError::NoError )
        {
            qDebug() << "fromJson failed: " << jsonError.errorString() << "\n";
            return ;
        }
        if( true || document.isObject() )
        {
            qDebug()  << "entered if document isObject(), keys:\n";
            QJsonObject jsonObj = document.object();
            qDebug() << jsonObj.find(QString("Compositions"))->toString();
            QStringList keys = jsonObj.keys();
            //traversJson(jsonObj);
            IterateThroughJSON(jsonObj);
            //for(auto key : keys)
            //{
            //    qDebug() << key << "\n";
            //}
        }
    }
}

void DataAccess::IterateThroughJSON(QJsonObject& jsonObj)
{
    for (auto it = jsonObj.constBegin(); it != jsonObj.constEnd(); ++it)
    {
        qDebug() << "entered json object loop";
        const QJsonValue &val = *it;

        // We expect that array contains objects like:
        // {"MCC_Dealer":'test',"MCC_User":'test',"CurrentDealer":'test',"CurrentUser":'test'}
        QJsonArray o = val.toArray();

        // Iterate over all sub-objects. They all have string values.
        for (auto oIt = o.constBegin(); oIt != o.constEnd(); ++oIt)
        {
            QJsonObject song = oIt->toObject();
            QString line = song["FilePath"].toString();
            qDebug() << line;
            filePaths.append(line);
        }
    }
}

void traversJson(QJsonObject json_obj) {
    foreach(const QString& key, json_obj.keys()) {
        QJsonValue value = json_obj.value(key);
        if (!value.isObject()) {
          qDebug() << "Key = " << key << ", Value = " << value;
        } else {
             qDebug() << "Nested Key = " << key;
             traversJson(value.toObject());
        }
    }
};
