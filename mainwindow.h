#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();

    //ステージ移動用
    QString movement;
    QString velocity;

    //造形条件設定
    QString start;
    QString end;
    QString interval;

    //層ごとの造形速度設定
    QString velocity1;
    QString velocity2;
    QString velocity3;
    QString layer1;
    QString layer2;
    QString layer3;

private slots:
    //ステージ移動
    void on_pushButton_clicked();
    void on_pushButton_2_clicked();
    void on_pushButton_3_clicked();
    void on_pushButton_4_clicked();
    void on_pushButton_5_clicked();
    void on_pushButton_6_clicked();
    void on_pushButton_7_clicked();
    void on_pushButton_8_clicked();
    //データ参照
    void on_pushButton_9_clicked();
    void on_pushButton_10_clicked();
    void on_pushButton_11_clicked();
    //造形操作
    void on_pushButton_15_clicked();
    void on_pushButton_16_clicked();
    void on_pushButton_17_clicked();
    //シャッター開閉
    void on_pushButton_18_clicked();
    void on_pushButton_19_clicked();


private:
    Ui::MainWindow *ui;


};

#endif // MAINWINDOW_H
