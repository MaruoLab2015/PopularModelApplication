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
    initportSetting();
    update = 0;
}

MainWindow::~MainWindow()
{
    delete ui;
}

//シリアル通信
bool MainWindow::initportSetting()
{
    //ポートの取得
    foreach(const QSerialPortInfo &info, QSerialPortInfo::availablePorts())
    {
        qDebug() << info.portName();
        portName = info.portName();
    }

    //ポートの設定
    baudrate = 38400;
    //    waitTime = ui->lineEdit_3->text().toInt();
    parity = QSerialPort::NoParity;
    stopbits = QSerialPort::OneStop;

    qDebug() << portName;
    qDebug() << baudrate;
    //    qDebug() << waitTime;
    qDebug() << parity;
    qDebug() << stopbits;

    //ポートのオープン
    serial = new QSerialPort();

    serial->setPortName(portName);
    serial->setBaudRate(baudrate);
    serial->setParity(parity);
    serial->setStopBits(stopbits);
    serial->setDataBits(QSerialPort::Data8);

    couldOpenSerialPort = serial->open(QIODevice::ReadWrite);
    if (couldOpenSerialPort)
        qDebug() << QString("Open %1").arg(portName);
    else{
        qDebug() << QString("Couldn't open %1").arg(portName);
        QMessageBox msgbox;
        msgbox.setText("通信できません");
        msgbox.exec();
    }

    return couldOpenSerialPort;

}

//シャッター開閉
void MainWindow::on_open_pushButton_clicked()
{

}

void MainWindow::on_close_pushButton_clicked()
{

}

//ステージ移動
void MainWindow::on_x_pushButton_clicked()
{
    movement = ui->x_lineEdit->text();
    velocity = ui->x_ms_lineEdit->text();
    float m = movement.toFloat();
    float v = velocity.toFloat();

}

void MainWindow::on_y_pushButton_clicked()
{
    movement = ui->y_lineEdit->text();
    velocity = ui->y_ms_lineEdit->text();
    float m = movement.toFloat();
    float v = velocity.toFloat();

}

void MainWindow::on_z_pushButton_clicked()
{
    movement = ui->z_lineEdit->text();
    velocity = ui->z_ms_lineEdit->text();
    float m = movement.toFloat();
    float v = velocity.toFloat();

}

void MainWindow::on_p_pushButton_clicked()
{
    movement = ui->p_lineEdit->text();
    velocity = ui->p_ms_lineEdit->text();
    float m = movement.toFloat();
    float v = velocity.toFloat();

}

//ステージ原点移動
void MainWindow::on_x0_pushButton_clicked()
{

}

void MainWindow::on_y0_pushButton_clicked()
{

}

void MainWindow::on_z0_pushButton_clicked()
{

}

void MainWindow::on_p0_pushButton_clicked()
{

}

//データ参照
void MainWindow::on_folder_refer_pushButton_clicked()
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

void MainWindow::on_layer_refer_pushButton_clicked()
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

void MainWindow::on_xyz_refer_pushButton_clicked()
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

//データ更新
void MainWindow::on_renew_pushButton_clicked()
{
    if(ui->v1_lineEdit->text().isEmpty() ||
            ui->start_spinBox->text().isEmpty()||
            ui->end_spinBox->text().isEmpty() ||
            ui->interval_lineEdit->text().isEmpty())
    {
        qDebug("No data");
        QMessageBox msgbox;
        msgbox.setText("造形条件を設定してください");
        msgbox.exec();
        return;//造形速度がないときは終了
    }


    //データ形式の反映
    if(ui->radioButton_xy->isChecked())
    {
        format = 0;
    }
   else if(ui->radioButton_xz->isChecked())
    {
        format = 1;
    }
    else if(ui->radioButton_yz->isChecked())
    {
        format = 2;
    }
    else if(ui->radioButton_xyz->isChecked())
    {
        format = 3;
    }
    else{
        qDebug("No data type");
        QMessageBox msgbox;
        msgbox.setText("データ形式を決めてください");
        msgbox.exec();

        return;
    }

    //断面データ正負反転，開始位置復帰の反映
    if(ui->data_reverse_checkBox->isChecked())
    {
        data_reverse = 1;
    }
    else{
        data_reverse = 0;
    }
    if(ui->position_return_checkBox->isChecked())
    {
        position_return = 1;
    }
    else{
        position_return = 0;
    }

    //逆造形の反映
    if(ui->reverse_checkBox->isChecked())
    {
        reverse = 1;
    }
    else{
        reverse = 0;
    }

    //造形方式の反映
    if(ui->galvano_radioButton->isChecked())
    {
        method = 0;
    }
    else if(ui->stage_radioButton->isChecked())
    {
        method = 1;
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

    layer1s = ui->l1_start_lineEdit->text();
    layer2s = ui->l2_start_lineEdit->text();
    layer3s = ui->l3_start_lineEdit->text();
    float l1s = layer1s.toFloat();
    float l2s = layer2s.toFloat();
    float l3s = layer3s.toFloat();

    layer1e = ui->l1_end_lineEdit->text();
    layer2e = ui->l2_end_lineEdit->text();
    layer3e = ui->l3_end_lineEdit->text();
    float l1e = layer1e.toFloat();
    float l2e = layer2e.toFloat();
    float l3e = layer3e.toFloat();

    if (ui->folder_lineEdit->text().isEmpty()) // パスがないときは終了
    {
        qDebug("No fablication type");
        QMessageBox msgbox;
        msgbox.setText("造形形式を決めてください");
        msgbox.exec();
        return;
    }

    //データ方式の造形データへの反映
    //XY造形の場合
    if(format == 0)
    {

    }

    //XZ造形の場合
    if(format == 1)
    {

    }

    //YZ造形の場合
    if(format == 2)
    {

    }

    //XYZ造形の場合
    if(format == 3)
    {

    }

    //造形時間計算
    float tmptime = 0;
    float fulltime = 0;
    float totaltime = 0;

    float oldX, oldY;
    float newX, newY;

    for(int i=start2;i<=end2;i++){
        QString str = ui->folder_lineEdit->text();
        QString str2 = QString("/model.%1%2%3.csv").arg(0).arg(0).arg(i);
        str.append(str2);
        qDebug() << str;

        QFile file(str);

        if (file.open(QIODevice::ReadOnly))//読込のみでオープンできたかチェック
        {
            qDebug("open!");
        }else
        {
            qDebug("Couldn't open!");
            QMessageBox msgbox;
            msgbox.setText("フォルダを読み込めません");
            msgbox.exec();

            ui->Time_label->setText("error");

            return;
        }

        QTextStream in(&file);

        oldX = 0; oldY = 0;

        while(!in.atEnd()){
            QString line = in.readLine();
            QStringList list = line.split(",");

            newX = list.at(0).toFloat();
            newY = list.at(1).toFloat();

            qDebug() << "old x : " << oldX << ", old y : " << oldY;
            qDebug() << "new x : " << newX << ", new y : " << newY;

            //計算
            qDebug()<< "compute";
            tmptime = sqrt((newX-oldX)*(newX-oldX)+(newY-oldY)*(newY-oldY))/1000/v1;
            fulltime = fulltime + tmptime;

            // 更新
            oldX = newX;
            oldY = newY;
        }
        totaltime = totaltime + fulltime;
        fulltime = 0;
    }

    totaltime += interval2 * (end2 - start2)/1000/v1;

    QString total = QString(QString::number(totaltime));//計算結果表示
    ui->Time_label->setText(total);

    //造形データ大きさ計算


    update = 1;//データ更新確認
    return;

}

//造形操作
QString MainWindow::on_start_pushButton_clicked()
{
    if(!couldOpenSerialPort) return errorString;//ポートがオープンでないときは終了
    if(!update) return errorString;//データが更新されていないときは終了

    //XY,XZ,YZ造形の場合
    if(format == 0 || format == 1 || format == 2)
    {
        //読み込みデータ送信
        if (ui->folder_lineEdit->text().isEmpty()) return errorString; // パスがないときは終了
        if (ui->layer_lineEdit->text().isEmpty()) return errorString; // パスがないときは終了

        QString sendRequest;
        QString stx, etx; // stx = Start of TeXt, etx = End of TeXt
        stx = ">";
        etx = "\r";

        QString str = ui->folder_lineEdit->text();
    //    QString str2 = QString("/stage.%1%2%3.csv").arg(0).arg(0).arg(1);
        QString str2 = QString("/stage.001.csv");
        str.append(str2);
        qDebug() << str;

        QFile file(str);

        if (file.open(QIODevice::ReadOnly))//読込のみでオープンできたかチェック
        {
            qDebug("open!");
        }else
        {
            qDebug("Couldn't open!");
            QMessageBox msgbox;
            msgbox.setText("error");
            msgbox.exec();
        }

        QTextStream in(&file);

        while(!in.atEnd()){
            QString line = in.readLine();
            QStringList list = line.split(",");

            QString command = list.at(0);

            qDebug() << command;

            sendRequest.append(stx);
            sendRequest.append(command);
            sendRequest.append(etx);

            QByteArray requestData = sendRequest.toLocal8Bit();

            qDebug("serial start");

            serial->write(requestData);
            QByteArray responseData = serial->readAll();

            while (serial->waitForReadyRead(50))
            {
                responseData += serial->readAll();
            }
            QString response(responseData);
            qDebug() << response;

            qDebug("one loop finish");

        }

    }

    //XYZ造形の場合
    if(format == 3)
    {
        //読み込みデータ送信
        if (ui->xyz_folder_lineEdit->text().isEmpty()) return errorString; // パスがないときは終了



    }

    return finish;
}

void MainWindow::on_stop_pushButton_clicked()
{
    //造形停止
}

