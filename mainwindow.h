#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QMediaPlayer>
#include <QAudioOutput>
#include <QVideoWidget>
#include <QBluetoothDeviceDiscoveryAgent>
#include <QPushButton>
#include <QSlider>
#include <QLabel>
#include <QFileDialog>
#include <QJsonArray>
#include <QJsonDocument>
#include <QMessageBox>
#include <QBluetoothLocalDevice>


namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private slots:
    void on_actionOpen_File_triggered();
    void on_pushButton_Play_Pause_clicked();
    void on_pushButton_Stop_clicked();
    void on_pushButton_Volume_clicked();
    void on_horizontalSlider_Volume_valueChanged(int value);
    void on_pushButton_Seek_Backward_clicked();
    void on_pushButton_Seek_Forward_clicked();
    void playNextSong();
    void playPreviousSong();
    void checkSliderPosition(int value);
    void addSong();
    void savePlaylist();
    void loadPlaylist();
    void connectBluetooth();

    void positionChanged(qint64 duration);
    void durationChanged(qint64 duration);

    void onBluetoothButtonClicked();
    void toggleBluetooth();

    // Additional slots...
private:
    Ui::MainWindow *ui;

    // Declare media and audio output objects
    QMediaPlayer *player;
    QAudioOutput *audioOutput;
    QVideoWidget *videoWidget;

    // Bluetooth discovery
    QBluetoothDeviceDiscoveryAgent *discoveryAgent;

    // Playlist management
    QStringList playlist;
    int currentSongIndex;

    // State flags
    bool IS_Pause;
    bool IS_Muted;
    qint64 mDuration;

    // Helper functions
    void loadPlaylist(const QStringList &songs);
    void playSong(int index);
    void updateDuration(qint64 Duration);
};

#endif // MAINWINDOW_H
