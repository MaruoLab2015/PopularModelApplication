//#include "stagesetting.h"
//#include "ui_mainwindow.h"
//#include <QDebug>
//#include <QFileDialog>
//#include <QMessageBox>


////ステージ移動
//void StageSetting::on_x_pushButton_clicked()
//{
//    if (ui->x_lineEdit->text().isEmpty() || ui->x_ms_lineEdit->text().isEmpty())//条件がないときは終了
//    {
//        qDebug("No data");
//        QMessageBox msgbox;
//        msgbox.setText("条件を設定してください");
//        msgbox.exec();
//        return;
//    }

//    movement = ui->x_lineEdit->text();
//    velocity = ui->x_ms_lineEdit->text();
////    float m = movement.toFloat();
////    float v = velocity.toFloat();

//    QString movementRequest;
//    QString driveRequest;
//    QString velocityRequest;
//    QString stx; // stx = Start of TeXt
//    QString dtx; //drive
//    QString vtx1,vtx2,vtx3; //velocity
//    stx = "M:1+P";
//    dtx = "G:";
//    vtx1 = "D:1S";
//    vtx2 = "F";
//    vtx3 = "R0";

//    movementRequest.append(stx);
//    movementRequest.append(movement);

//    driveRequest.append(dtx);

//    velocityRequest.append(vtx1);
//    velocityRequest.append(velocity);
//    velocityRequest.append(vtx2);
//    velocityRequest.append(velocity);
//    velocityRequest.append(vtx3);

//    QByteArray movementData = movementRequest.toLocal8Bit();
//    QByteArray driveData = driveRequest.toLocal8Bit();
//    QByteArray velocityData = velocityRequest.toLocal8Bit();

//    //移動速度送信
//    serial->write(velocityData);
//    QByteArray responseData = serial->readAll();

//    while (serial->waitForReadyRead(50))
//    {
//        responseData += serial->readAll();
//    }
//    QString response(responseData);
//    qDebug() << response;

//    //移動距離送信
//    serial->write(movementData);
//    serial->write(driveData);
//    responseData = serial->readAll();

//    while (serial->waitForReadyRead(50))
//    {
//        responseData += serial->readAll();
//    }
//    QString response2(responseData);
//    qDebug() << response2;

//}

//void StageSetting::on_y_pushButton_clicked()
//{
//    if (ui->y_lineEdit->text().isEmpty() || ui->y_ms_lineEdit->text().isEmpty())//条件がないときは終了
//    {
//        qDebug("No data");
//        QMessageBox msgbox;
//        msgbox.setText("条件を設定してください");
//        msgbox.exec();
//        return;
//    }

//    movement = ui->y_lineEdit->text();
//    velocity = ui->y_ms_lineEdit->text();
////    float m = movement.toFloat();
////    float v = velocity.toFloat();

////    QString str2 = QString("/model.%1%2%3.csv").arg(0).arg(0).arg(i);



//}

//void StageSetting::on_z_pushButton_clicked()
//{
//    if (ui->z_lineEdit->text().isEmpty() || ui->z_ms_lineEdit->text().isEmpty())//条件がないときは終了
//    {
//        qDebug("No data");
//        QMessageBox msgbox;
//        msgbox.setText("条件を設定してください");
//        msgbox.exec();
//        return;
//    }

//    movement = ui->z_lineEdit->text();
//    velocity = ui->z_ms_lineEdit->text();
////    float m = movement.toFloat();
////    float v = velocity.toFloat();

//}

//void StageSetting::on_p_pushButton_clicked()
//{
//    movement = ui->p_lineEdit->text();
//    velocity = ui->p_ms_lineEdit->text();
////    float m = movement.toFloat();
////    float v = velocity.toFloat();



//}

////ステージ原点移動
//void StageSetting::on_x0_pushButton_clicked()
//{
//    QString sendRequest;
//    QString stx; // stx = Start of TeXt
//    stx = "H:1";

//    sendRequest.append(stx);

//    QByteArray requestData = sendRequest.toLocal8Bit();

//    qDebug("serial start");

//    serial->write(requestData);
//    QByteArray responseData = serial->readAll();

//    while (serial->waitForReadyRead(50))
//    {
//        responseData += serial->readAll();
//    }
//    QString response(responseData);
//    qDebug() << response;

//}

//void StageSetting::on_y0_pushButton_clicked()
//{

//}

//void StageSetting::on_z0_pushButton_clicked()
//{

//}

//void StageSetting::on_p0_pushButton_clicked()
//{

//}








