#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QFile>
#include <QFileDialog>
#include <QTextStream>
#include <QMessageBox>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    this->setCentralWidget(ui->textEdit);
}

MainWindow::~MainWindow()
{
    delete ui;
}


void MainWindow::on_actionNouveau_triggered()
{
    file_path_ = "";
    ui->textEdit->setText("");

}

void MainWindow::on_actionOuvrir_triggered()
{
    QString file_name = QFileDialog::getOpenFileName(this,"Ouvrir le fichier");
    QFile file(file_name);
    file_path_ = file_name;
    if(!file.open(QFile::ReadOnly | QFile::Text)){
        QMessageBox::warning(this, "..", "Le fichier n'est pas ouvert");
        return;

    }
    QTextStream in (&file);
    QString text = in.readAll();
    ui->textEdit->setText(text);
    file.close();

}

void MainWindow::on_actionSauvegarder_triggered()
{

    QFile file(file_path_);
    if(!file.open(QFile::WriteOnly | QFile::Text)){
        QMessageBox::warning(this, "..", "Le fichier n'est pas ouvert");
        return;

    }
    QTextStream out (&file);
    QString text = ui->textEdit->toPlainText();
    out << text;
    file.flush();
    file.close();

}

void MainWindow::on_actionEnregistrer_sous_triggered()
{
    QString file_name = QFileDialog::getSaveFileName(this,"Ouvrir le fichier");
    QFile file(file_name);
    file_path_ = file_name ;
    if(!file.open(QFile::WriteOnly | QFile::Text)){
        QMessageBox::warning(this, "..", "Le fichier n'est pas ouvert");
        return;

    }
    QTextStream out (&file);
    QString text = ui->textEdit->toPlainText();
    out << text;
    file.flush();
    file.close();

}

void MainWindow::on_actionCouper_triggered()
{
    ui->textEdit->cut();

}

void MainWindow::on_actionCopier_triggered()
{
    ui->textEdit->copy();


}

void MainWindow::on_actionColler_triggered()
{
    ui->textEdit->paste();

}

void MainWindow::on_actionR_tablir_triggered()
{
    ui->textEdit->redo();

}

void MainWindow::on_actionAnnuler_triggered()
{
    ui->textEdit->undo();

}

void MainWindow::on_actionA_propos_de_Notepad_triggered()
{
    QString about_text;
    about_text = "Auteur : Dufour-Lamartinie Clément\n";
    about_text += "Date  : 26/04/2021\n";
    about_text += "(C)   Notepad  (R) \n";
    QMessageBox::about(this,"A propos de Notepad", about_text);
}
