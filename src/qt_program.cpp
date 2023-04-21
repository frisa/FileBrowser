#include <QGuiApplication>
#include <QQuickView>

int main(int argc, char **argv)
{
    QGuiApplication app(argc, argv);
    QQuickView view;
    view.setSource(QUrl::fromLocalFile("./src/main.qml"));
    view.show();
    return app.exec();
}

// some notes
//https://lightrun.com/solutions/3fon3fonov-exostriker-qtqpaplugin-could-not-load-the-qt-platform-plugin-xcb-in-even-though-it-was-found-ubuntu-r/
// sudo apt-get install '^libxcb.*-dev' libx11-xcb-dev libglu1-mesa-dev libxrender-dev libxi-dev libxkbcommon-dev libxkbcommon-x11-dev