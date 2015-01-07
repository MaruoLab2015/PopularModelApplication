#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QDebug>
#include <QFileDialog>
#include <QMessageBox>


MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
}

MainWindow::~MainWindow()
{
    delete ui;
}

//シャッター開閉
void MainWindow::on_pushButton_18_clicked()
{

}

void MainWindow::on_pushButton_19_clicked()
{

}

//ステージ移動
void MainWindow::on_pushButton_clicked()
{
    movement = ui->lineEdit_2->text();
    velocity = ui->lineEdit_14->text();
    float m = movement.toFloat();
    float v = velocity.toFloat();

}

void MainWindow::on_pushButton_2_clicked()
{
    movement = ui->lineEdit_3->text();
    velocity = ui->lineEdit_15->text();
    float m = movement.toFloat();
    float v = velocity.toFloat();

}

void MainWindow::on_pushButton_3_clicked()
{
    movement = ui->lineEdit_4->text();
    velocity = ui->lineEdit_22->text();
    float m = movement.toFloat();
    float v = velocity.toFloat();
}

void MainWindow::on_pushButton_4_clicked()
{
    movement = ui->lineEdit_5->text();
    velocity = ui->lineEdit_23->text();
    float m = movement.toFloat();
    float v = velocity.toFloat();

}

//ステージ原点移動
void MainWindow::on_pushButton_5_clicked()
{

}

void MainWindow::on_pushButton_6_clicked()
{

}

void MainWindow::on_pushButton_7_clicked()
{

}

void MainWindow::on_pushButton_8_clicked()
{

}

//データ参照
void MainWindow::on_pushButton_9_clicked()
{
    //積層造形フォルダ参照
    QFileDialog::Options options = QFileDialog::DontResolveSymlinks | QFileDialog::ShowDirsOnly;

    QString strDir = QFileDialog::getExistingDirectory(
                this,
                tr("造形フォルダを選択してください"),
                tr("初期ディレクトリ"), options);

    if ( !strDir.isEmpty() )
    {
        // ファイル名を表示
        ui->folder_lineEdit->setText(strDir);
    }
}

void MainWindow::on_pushButton_10_clicked()
{
    //層データ参照
    QFileDialog::Options options = QFileDialog::DontResolveSymlinks | QFileDialog::ShowDirsOnly;

    QString strDir2 = QFileDialog::getExistingDirectory(
                this,
                tr("層データを選択してください"),
                tr("初期ディレクトリ"), options);

    if ( !strDir2.isEmpty() )
    {
        // ファイル名を表示
        ui->layer_lineEdit->setText(strDir2);
    }
}

void MainWindow::on_pushButton_11_clicked()
{
    //XYZ造形フォルダ参照
    QFileDialog::Options options = QFileDialog::DontResolveSymlinks | QFileDialog::ShowDirsOnly;

    QString strDir3 = QFileDialog::getExistingDirectory(
                this,
                tr("造形フォルダを選択してください"),
                tr("初期ディレクトリ"), options);

    if ( !strDir3.isEmpty() )
    {
        // ファイル名を表示
        ui->xyz_folder_lineEdit->setText(strDir3);
    }
}

//造形操作
void MainWindow::on_pushButton_15_clicked()
{
    //データ形式の反映
    if(ui->radioButton_xy->isChecked())
    {

    }
   else if(ui->radioButton_xz->isChecked())
    {

    }
    else if(ui->radioButton_yz->isChecked())
    {

    }
    else if(ui->radioButton_xyz->isChecked())
    {

    }
    else{
        qDebug("No data type");
        QMessageBox msgbox;
        msgbox.setText("データ形式を決めてください");
        msgbox.exec();

        return;
    }

    //断面データ正負反転，開始位置復帰の反映


    //逆造形の反映
    if(ui->data_reverse_radioButton->isChecked())
    {

    }
    if(ui->return_radioButton->isChecked())
    {

    }

    //造形方式の反映
    if(ui->galvano_radioButton->isChecked())
    {

    }
    else if(ui->stage_radioButton->isChecked())
    {

    }
    else{
        qDebug("No fablication type");
        QMessageBox msgbox;
        msgbox.setText("造形形式を決めてください");
        msgbox.exec();

        return;
    }

    //造形条件の設定
    start = ui->start_spinBox->text();
    end = ui->end_spinBox->text();
    interval = ui->interval_lineEdit->text();
    int start2 = start.toInt();
    int end2 = end.toInt();
    float interval2 = interval.toFloat();

    //層ごとの造形速度設定
    velocity1 = ui->v1_lineEdit->text();
    velocity2 = ui->v2_lineEdit->text();
    velocity3 = ui->v3_lineEdit->text();
    float v1 = velocity1.toFloat();
    float v2 = velocity2.toFloat();
    float v3 = velocity3.toFloat();

    layer1 = ui->l1_lineEdit->text();
    layer2 = ui->l2_lineEdit->text();
    layer3 = ui->l3_lineEdit->text();
    float l1 = layer1.toFloat();
    float l2 = layer2.toFloat();
    float l3 = layer3.toFloat();

    //造形時間計算


    //造形データ大きさ計算


}

void MainWindow::on_pushButton_16_clicked()
{

}

void MainWindow::on_pushButton_17_clicked()
{

}

