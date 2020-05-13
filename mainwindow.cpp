 #include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    init_steps();
    ui->description_label->setStyleSheet("QLabel { color: rgb(176, 58, 176); }");
    ui->step_label->setStyleSheet("QLabel { color: rgb(84, 29, 84); }");
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::init_steps()
{
    this->steps = {
        "",
        "Creating multiset1 and \nfilling it with elements \nof type double.", // 1
        "Displaying multiset1.",    // 2
        "Changing multiset1.",      // 3
        "Displaying multiset1 \nusing iterators.",  // 4
        "Creating multiset2 & \nfilling it with numbers \nof type double.", // 5
        "Deleting 5 elements \nfrom multiset1 and \nadding \
all elements from \nmultiset2 to multiset1.",   //6
        "Showing multiset1 \nand multiset2.",   // 7
        "Sorting both multisets\n in descending order \nand displaying them.",  //8
        "Finding a greater \nthan 5 element.",  // 9
        "Moving bigger than 5 \nelements to vector.",   //10
        "Displaying vector.",   // 11
        "Creating queue from \nmultiset1 and vector.",  // 12
        "Displaying queue.",    // 13
        "Counting hom many bigger \nthan 5 elements has queue.", //14
        "End.",
    };
    this->operations = this->steps.size() - 2;
}

void MainWindow::display_multiset(std::multiset<double, std::less<double> > &multset, QTextEdit *tEd)
{
    QString out = "";
    for (auto& it : multset) {
        out += QString::number(it, 'g', 6) + "\n";
    }
    tEd->setText(out);
}

void MainWindow::display_vector(std::vector<double> &vec, QTextEdit *tEd)
{
    QString out = "";
    for (auto& it : vec) {
        out += QString::number(it, 'g', 6) + "\n";
    }
    tEd->setText(out);
}

void MainWindow::display_queue(std::queue<double> &queue, QTextEdit *tEd)
{
    QString out = "";
    std::queue<double> tempQueue = queue;
    while (!tempQueue.empty()){
        out += QString::number(tempQueue.front(), 'g', 6) + "\n";
        tempQueue.pop();
    }
    tEd->setText(out);
}

void MainWindow::on_next_pushButton_clicked()
{
    QDebug cout = qDebug();
    if (completed_operations <= operations){
        completed_operations++;
    }
    ui->step_label->setText("Step " + QString::number(completed_operations));
    ui->description_label->setText(QString::fromStdString(steps.at(completed_operations)));

    QString str = "";
    double num = 0.0;
    int cnt = 0;

    switch (this->completed_operations) {
    case 0:
        break;
    case 1:
        // step 1
        for (int i = 0; i < size; i++){
            if (myMultiset1.empty()){
                ms_it = myMultiset1.insert((std::rand() % 100) / 13);
            }
            else{
                ms_it = myMultiset1.insert(ms_it, 1.0 * (std::rand() % 100) / 13);
            }
        }
        break;
    case 2:
        // step 2
        display_multiset(myMultiset1, ui->multiset_textEdit_1);
        for (auto it : myMultiset1) {
            cout << it;
        }
        break;
    case 3:
        // step 3
        for (int i = 0; i < 7; i++) {
            myMultiset1.erase(std::next(myMultiset1.begin(), 5));
        }
        break;
    case 4:
        // step 4
        for (ms_it = myMultiset1.begin(); ms_it != myMultiset1.end(); ms_it++) {
            str += QString::number(*ms_it) + "\n";
        }
        ui->multiset_textEdit_1->setText(str);
        break;
    case 5:
        // step 5
        myMultiset2 = myMultiset1;
        break;
    case 6:
        // step 6
        for (int i = 0; i < 5; i++){
            myMultiset1.erase(std::next(myMultiset1.begin(), 1));
        }
        for (auto it = myMultiset2.begin(); it != myMultiset2.end(); it++){
            myMultiset1.insert(*it);
        }
        break;
    case 7:
        // step 7
        display_multiset(myMultiset1, ui->multiset_textEdit_1);
        display_multiset(myMultiset2, ui->multiset_textEdit_2);
        break;
    case 8:
        // step 8
        break;
    case 9:
        // step 9
        for (auto it : myMultiset1) {
            if (it > 5) {
                num = it;
                break;
            }
        }
        cout << num;
        QMessageBox::information(this, "Info", "First greater than 5 element is: " + QString::number(num));
        break;
    case 10:
        // step 10
        for (auto it : myMultiset1) {
            if (it > 5) {
                myVector.push_back(it);
            }
        }
        break;
    case 11:
        // step 11
        display_vector(myVector, ui->vector_textEdit);
        break;
    case 12:
        // step 12
        for (auto it : myMultiset1){
            myQueue.push(it);
        }
        for (auto it : myVector) {
            myQueue.push(it);
        }
        break;
    case 13:
        // step 13
        display_queue(myQueue, ui->queue_textEdit);
        break;
    case 14:
        // step 14
        copyQueue = myQueue;
        while (!copyQueue.empty()) {
            if (copyQueue.front() > 5) {
                cnt++;
            }
            copyQueue.pop();
        }
        QMessageBox::information(this, "Info", "Number of elements, greater than 5: " + QString::number(cnt));
        break;
    case 15:
        cout << "finished.";
        break;
    }
}
