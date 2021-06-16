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

private slots:
    void on_actionNouveau_triggered();

    void on_actionOuvrir_triggered();

    void on_actionSauvegarder_triggered();

    void on_actionEnregistrer_sous_triggered();

    void on_actionCouper_triggered();

    void on_actionCopier_triggered();

    void on_actionColler_triggered();

    void on_actionR_tablir_triggered();

    void on_actionAnnuler_triggered();

    void on_actionA_propos_de_Notepad_triggered();

private:
    Ui::MainWindow *ui;
    QString file_path_;
};
#endif // MAINWINDOW_H
