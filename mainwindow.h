#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();
    bool checkMasterPass();

private slots:
    void on_generateButton_clicked();
    void on_showButton_clicked();
    void on_findButton_clicked();
    void on_deleteButton_clicked();
    void on_addButton_clicked();
    void chooseDiff(int &begin, int &min, int &max, bool &ok);

    void on_clearButton_clicked();

private:
    Ui::MainWindow *ui;
    QMap<QString, QString> savedPasswords;

    void loadPasswords();
    void savePassword(const QString &name, const QString &password);
    void initDatabase();
    void masterPassword();
    bool verifyMasterPass(const QString &inputPass);
    QString passGeneration(int passwordSize);
    QByteArray getMasterPasswordHash();
    QByteArray generateIV(int size);
};

#endif // MAINWINDOW_H
