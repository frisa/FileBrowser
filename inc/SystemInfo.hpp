/*
    This is the class providing the simple system informations
*/
#include <QObject>
#include <string>

class SystemInfo: public QObject{
    Q_OBJECT
    // public properties to be read by the UI
    Q_PROPERTY(QString hostName READ getHostName WRITE setHostName NOTIFY changeHostNameNotify);
public:
    Q_INVOKABLE QString getHostName();
    Q_INVOKABLE void setHostName(const QString& value);
signals:
    void changeHostNameNotify();
    // get various computer informations
private:
    std::string getComputerName();
    std::string getCurrentDate();
    // print the computer informations
    void printComputerName();
    void printCurrentDate();
};