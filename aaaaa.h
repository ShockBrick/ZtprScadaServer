ifndef AAAAA_H
#define AAAAA_H

#include <QDeclarativeItem>
#include <QMainWindow>
#include <QObject>
#include <QQuickItem>
#include <QSharedDataPointer>
#include <QWidget>

class aaaaaData;

class aaaaa
{
    Q_OBJECT
public:
    aaaaa();
    aaaaa(const aaaaa &);
    aaaaa &operator=(const aaaaa &);
    ~aaaaa();

private:
    QSharedDataPointer<aaaaaData> data;
};

#endif // AAAAA_H
