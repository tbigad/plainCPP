#ifndef FULLSCREENHELPER
#define FULLSCREENHELPER

#include <QWidget>
#include <QWindow>

class FullScreenHelper
{
public:
    static void MaximizeOnVirtualScreen(QWidget *widget);
};

#endif // FULLSCREENHELPER

