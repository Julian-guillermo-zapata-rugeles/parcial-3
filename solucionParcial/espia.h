#ifndef ESPIA_H
#define ESPIA_H

#include <QObject>
#include <QTimer>
#include <canondefensivo.h>
#include <canonofensivo.h>


class Espia :public QObject
{
    Q_OBJECT
public:
    Espia(CanonOfensivo *canon_ofensivo  ,CanonDefensivo *canon_defensivo);
private:
    QTimer *controladorEventos;
    CanonOfensivo *ptr_canon_ofensivo;
    CanonDefensivo *ptr_canon_defensivo;

private slots:
    void actions();
};

#endif // ESPIA_H
