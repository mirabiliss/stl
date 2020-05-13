#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <set>
#include <vector>
#include <queue>
#include <algorithm>
#include <QTextEdit>
#include <QDebug>
#include <QMessageBox>

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();
    void init_steps();
    void display_multiset(std::multiset<double, std::less<double> >& multset, QTextEdit* tEd);
    void display_vector(std::vector<double>& vec, QTextEdit* tEd);
    void display_queue(std::queue<double>& queue, QTextEdit* tEd);


private slots:
    void on_next_pushButton_clicked();

private:
    Ui::MainWindow *ui;
    std::multiset<double, std::less<double> > myMultiset1;
    std::multiset<double, std::less<double> > myMultiset2;
    std::vector <double> myVector;
    std::vector<float> mergedVector;
    std::queue<double> myQueue;
    std::queue<double> copyQueue;
    int size = 15;
    std::vector<std::string> steps;
    int operations;
    int completed_operations = 0;
    std::multiset<double>::iterator ms_it;

};
#endif // MAINWINDOW_H
