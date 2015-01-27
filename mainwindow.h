#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QtSerialPort/QSerialPortInfo>
#include <QtSerialPort/QSerialPort>

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();

    bool initPortSetting();
    bool shutterPortSetting();

    //シリアルポート用
    QSerialPort *serial;//ステージ用
    QSerialPort *serial2;//シャッター用
    QString portName;
    int baudrate;
    int waitTime;
    QSerialPort::Parity parity;
    QSerialPort::StopBits stopbits;

    //ステージ移動用
    QString movement;
    QString velocity;

    //造形条件設定
    QString start;
    QString end;
    QString interval;

    //造形条件設定
    int format;//データ形式(xy=0,xz=1,yz=2,xyz=3)
    bool data_reverse;//断面データ正負反転(チェックのとき1)
    bool position_return;//開始位置復帰(チェックのとき1)
    bool reverse;//逆造形(チェックのとき1)
    bool method;//造形方式(ガルバノ=0,ステージ=1)

    //層ごとの造形速度設定
    QString velocity1;
    QString velocity2;
    QString velocity3;
    QString layer1s;
    QString layer2s;
    QString layer3s;
    QString layer1e;
    QString layer2e;
    QString layer3e;

private slots:
    //ステージ移動
    void on_x_pushButton_clicked();
    void on_y_pushButton_clicked();
    void on_z_pushButton_clicked();
    void on_p_pushButton_clicked();
    void on_x0_pushButton_clicked();
    void on_y0_pushButton_clicked();
    void on_z0_pushButton_clicked();
    void on_p0_pushButton_clicked();
    //データ参照
    void on_folder_refer_pushButton_clicked();
    void on_layer_refer_pushButton_clicked();
    void on_xyz_refer_pushButton_clicked();
    //造形操作
    void on_renew_pushButton_clicked();
    QString on_start_pushButton_clicked();
    void on_stop_pushButton_clicked();
    //シャッター開閉
    void on_open_pushButton_clicked();
    void on_close_pushButton_clicked();

private:
    Ui::MainWindow *ui;

protected:
    bool couldOpenSerialPort;
    bool update;//データ更新確認
    const QString errorString;
    const QString finish;

};

#endif // MAINWINDOW_H
