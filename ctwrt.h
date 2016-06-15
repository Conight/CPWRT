#ifndef CTWRT_H
#define CTWRT_H

#include <QMainWindow>

namespace Ui {
class CTWRT;
}

class CTWRT : public QMainWindow
{
    Q_OBJECT

public:
    explicit CTWRT(QWidget *parent = 0);
    ~CTWRT();
    bool newFile();
    bool saveFile(const QString &fileName);
    void startTimer();
    QClipboard *board;

private:
    Ui::CTWRT *ui;
    QString filePath;
    QString tmpClib, curClib;
    QTimer *timer;

private slots:
    void listenCli();
    void on_action_New_triggered();
    void on_action_Save_triggered();
    void on_action_About_triggered();
    void on_action_Exit_triggered();
};

#endif // CTWRT_H
