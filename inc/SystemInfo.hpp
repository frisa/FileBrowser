/*
    This is the class providing the simple system informations
*/
#include <QObject>
#include <string>

class SystemInfo: public QObject{
    Q_OBJECT
    // public properties to be read by the UI
    Q_PROPERTY(QString hostName READ getHostNameItf WRITE setHostName NOTIFY changeHostNameNotify);
    Q_PROPERTY(QString currentDate READ getCurrentDateItf WRITE setHostName NOTIFY changeCurrentDateNotify);

public:
    Q_INVOKABLE QString getHostNameItf();
    Q_INVOKABLE QString getCurrentDateItf();
    Q_INVOKABLE void setHostName(const QString& value);
signals:
    void changeHostNameNotify();
    void changeCurrentDateNotify();
    // get various computer informations
private:
    std::string getComputerName();
    std::string getCurrentDate();
    // print the computer informations
    void printComputerName();
    void printCurrentDate();
};