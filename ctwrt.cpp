#include "ctwrt.h"
#include "ui_ctwrt.h"

#include <QMessageBox>
#include <QClipboard>
#include <QFileDialog>
#include <QTextStream>
#include <QTimer>
#include <QDebug>

CTWRT::CTWRT(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::CTWRT)
{
    ui->setupUi(this);
    ui->textEdit->hide();
    board = QApplication::clipboard();
    board->clear();
    tmpClib = "";
}

CTWRT::~CTWRT()
{
    delete ui;
}

void CTWRT::on_action_New_triggered()
{
    newFile();
    startTimer();
    listenCli();
}

void CTWRT::on_action_Save_triggered()
{
    saveFile(filePath);
}


void CTWRT::on_action_Exit_triggered()
{
    qApp->exit();
}

void CTWRT::on_action_About_triggered()
{
    if (!ui->textEdit->isVisible()) {
        ui->textEdit->show();
    }
    ui->textEdit->append(tr("Open Source \n"
                            "LICENSE & more\n"
                            "https://github.com/Conight/CPWRT"));
}

bool CTWRT::newFile() {
    QString fileName = QFileDialog::getSaveFileName(this,
                                                    tr("New"),
                                                    filePath);
    if (fileName.isEmpty()) return false;
    filePath = tr("Untitled Doc");
    setWindowTitle(filePath);
    ui->textEdit->clear();
    ui->textEdit->setVisible(true);
    return saveFile(fileName);
}

bool CTWRT::saveFile(const QString &fileName)
{
   QFile file(fileName);
   if (!file.open(QFile::WriteOnly | QFile::Text)) {
       QMessageBox::warning(this, tr("CPWRT"),
                            tr("Cannot save %1:\n%2")
                            .arg(fileName)
                            .arg(file.errorString()));
       return false;
   }
   QTextStream out(&file);
   QApplication::setOverrideCursor(Qt::WaitCursor);
   out << ui->textEdit->toPlainText();
   QApplication::restoreOverrideCursor();
   filePath = QFileInfo(fileName).canonicalFilePath();
   setWindowTitle(filePath);
   return true;
}

void CTWRT::startTimer() {
    timer = new QTimer(this);
    connect(timer, SIGNAL(timeout()),
            this, SLOT(listenCli()));
    timer->start(500);
}

void CTWRT::listenCli() {
    curClib = board->text();
    if (curClib != tmpClib) {
        tmpClib = curClib;
        ui->textEdit->append(tmpClib);
        saveFile(filePath);
    }
}
