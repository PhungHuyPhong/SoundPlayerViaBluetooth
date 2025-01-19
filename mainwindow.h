#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QtMultimedia>
#include <QtMultimediaWidgets>
#include <QtCore>
#include <QtWidgets>
#include <QtGui>
#include <QMessageBox>
#include <QPointer>
#include <QFileInfo>
#include <QTime>
#include <QBluetoothDeviceDiscoveryAgent>
#include <QBluetoothSocket>
#include <QDebug>
QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

    void ConnectToDevice(const QString &DeviceName);
public slots:
    void onDeviceConnected();
    void onDeviceError(QBluetoothSocket::SocketError error);
private slots:
    void durationChanged(qint64 duration);
    void positionChanged(qint64 duration);

    void on_horizontalSlider_Duration_valueChanged(int value);
    void on_pushButton_Play_Pause_clicked();
    //void on_pushButton_Stop_clicked();
    void on_pushButton_Volume_clicked();
    void on_horizontalSlider_Volume_valueChanged(int value);
    void on_pushButton_Seek_Backward_clicked();
    void on_pushButton_Seek_Forward_clicked();

    void playNextSong();
    void playPreviousSong();
    void playSong(int index);
    void checkSliderPosition(int value);
    void loadPlaylist(const QStringList &songs);
    void on_actionOpen_File_triggered();




    void on_actionAdd_Device_triggered();

private:
    Ui::MainWindow *ui;

    QMediaPlayer *Player;
    QVideoWidget *Video;
    QAudioOutput *AudioOutput;
    qint64 mDuration;
    bool IS_Pause = true;
    bool IS_Muted = false;
    QStringList playlist; // Danh sách bài hát
    int currentSongIndex; // Vị trí hiện tại trong danh sách phá
    QBluetoothDeviceDiscoveryAgent *DiscoveryAgent;
    void updateDuration(qint64 Duration);
};
#endif // MAINWINDOW_H
