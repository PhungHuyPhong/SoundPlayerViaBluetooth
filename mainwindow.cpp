#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QFileInfo>
#include <QTime>
#include <QBluetoothDeviceInfo>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent),
    ui(new Ui::MainWindow),
    player(new QMediaPlayer(this)),
    audioOutput(new QAudioOutput(this)),
    videoWidget(new QVideoWidget(this)),
    discoveryAgent(new QBluetoothDeviceDiscoveryAgent(this)),
    // IS_Pause(true),
    // IS_Muted(false),
    currentSongIndex(0),
    mDuration(0)
{
    ui->setupUi(this);

    // Set up player, audioOutput, and videoWidget
    player->setAudioOutput(audioOutput);
    player->setVideoOutput(videoWidget);

    // Set video widget into the groupBox_Video container
    videoWidget->setGeometry(5, 5, ui->groupBox_Video->width() - 5, ui->groupBox_Video->height() - 5);
    videoWidget->setParent(ui->groupBox_Video);

    // Set icons for buttons
    ui->pushButton_Play_Pause->setIcon(style()->standardIcon(QStyle::SP_MediaPlay));
    ui->pushButton_Play_Pause->setIconSize(QSize(45, 45));
    ui->pushButton_Stop->setIcon(style()->standardIcon(QStyle::SP_MediaStop));
    ui->pushButton_Stop->setIconSize(QSize(45, 45));
    ui->pushButton_Seek_Backward->setIcon(style()->standardIcon(QStyle::SP_MediaSeekBackward));
    ui->pushButton_Seek_Backward->setIconSize(QSize(45, 45));
    ui->pushButton_Seek_Forward->setIcon(style()->standardIcon(QStyle::SP_MediaSeekForward));
    ui->pushButton_Seek_Forward->setIconSize(QSize(45, 45));
    ui->pushButton_Volume->setIcon(style()->standardIcon(QStyle::SP_MediaVolume));
    ui->pushButton_Volume->setIconSize(QSize(100, 100));

    // Set up volume slider
    ui->horizontalSlider_Volume->setMinimum(0);
    ui->horizontalSlider_Volume->setMaximum(100);
    ui->horizontalSlider_Volume->setValue(10);
    audioOutput->setVolume(ui->horizontalSlider_Volume->value() / 100.0);

    // Connect signals and slots
    connect(player, &QMediaPlayer::durationChanged, this, &MainWindow::durationChanged);
    connect(player, &QMediaPlayer::positionChanged, this, &MainWindow::positionChanged);
    connect(ui->pushButton_Next, &QPushButton::clicked, this, &MainWindow::playNextSong);
    connect(ui->pushButton_Previous, &QPushButton::clicked, this, &MainWindow::playPreviousSong);
    connect(ui->horizontalSlider_Duration, &QSlider::valueChanged, this, &MainWindow::checkSliderPosition);

    connect(ui->pushButton_Bluetooth, &QPushButton::clicked, this, &MainWindow::toggleBluetooth);


    // Volume control
    connect(ui->horizontalSlider_Volume, &QSlider::valueChanged, [&](int value) {
        if (!audioOutput->isMuted()) {
            audioOutput->setVolume(value / 100.0);
        }
    });

    // Set up duration slider
    ui->horizontalSlider_Duration->setRange(0, player->duration() / 1000);

    // Connect Bluetooth
    connectBluetooth();
}

MainWindow::~MainWindow() {
    delete ui;
    delete discoveryAgent;
    delete player;
    delete audioOutput;
    delete videoWidget;
}

void MainWindow::on_actionOpen_File_triggered() {
    QStringList fileNames = QFileDialog::getOpenFileNames(
        this, tr("Open Files"), "", tr("Media Files (*.mp4 *.mp3)"));

    if (!fileNames.isEmpty()) {
        loadPlaylist(fileNames); // Load playlist with selected files
    }
}

void MainWindow::durationChanged(qint64 duration) {
    mDuration = duration / 1000;
    ui->horizontalSlider_Duration->setMaximum(mDuration);
}

void MainWindow::positionChanged(qint64 position) {
    if (!ui->horizontalSlider_Duration->isSliderDown()) {
        ui->horizontalSlider_Duration->setValue(position / 1000);
    }
    updateDuration(position / 1000);
}

void MainWindow::updateDuration(qint64 duration) {
    QTime currentTime((duration / 3600) % 60, (duration / 60) % 60, duration % 60);
    QTime totalTime((mDuration / 3600) % 60, (mDuration / 60) % 60, mDuration % 60);
    QString format = (mDuration > 3600) ? "hh:mm:ss" : "mm:ss";

    ui->label_current_Time->setText(currentTime.toString(format));
    ui->label_Total_Time->setText(totalTime.toString(format));
}

void MainWindow::on_pushButton_Play_Pause_clicked() {
    if (IS_Pause) {
        IS_Pause = false;
        player->play();
        ui->pushButton_Play_Pause->setIcon(style()->standardIcon(QStyle::SP_MediaPause));
    } else {
        IS_Pause = true;
        player->pause();
        ui->pushButton_Play_Pause->setIcon(style()->standardIcon(QStyle::SP_MediaPlay));
    }
}

void MainWindow::on_pushButton_Stop_clicked() {
    player->stop();
    IS_Pause = true;
    ui->pushButton_Play_Pause->setIcon(style()->standardIcon(QStyle::SP_MediaPlay));
}

void MainWindow::on_pushButton_Volume_clicked() {
    IS_Muted = !IS_Muted;
    audioOutput->setMuted(IS_Muted);
    ui->pushButton_Volume->setIcon(style()->standardIcon(IS_Muted ? QStyle::SP_MediaVolumeMuted : QStyle::SP_MediaVolume));
}

void MainWindow::on_horizontalSlider_Volume_valueChanged(int value) {
    audioOutput->setVolume(value / 100.0);
}

void MainWindow::on_pushButton_Seek_Backward_clicked() {
    int newPosition = ui->horizontalSlider_Duration->value() - 5;
    ui->horizontalSlider_Duration->setValue(newPosition);
    player->setPosition(newPosition * 1000);
}

void MainWindow::on_pushButton_Seek_Forward_clicked() {
    int newPosition = ui->horizontalSlider_Duration->value() + 5;
    ui->horizontalSlider_Duration->setValue(newPosition);
    player->setPosition(newPosition * 1000);
}

void MainWindow::loadPlaylist(const QStringList &songs) {
    playlist = songs;  // Only store the file paths
    currentSongIndex = 0;
    playSong(currentSongIndex);
}

void MainWindow::playNextSong() {
    if (currentSongIndex + 1 < playlist.size()) {
        currentSongIndex++;
        playSong(currentSongIndex);
    }
}

void MainWindow::playPreviousSong() {
    if (currentSongIndex - 1 >= 0) {
        currentSongIndex--;
        playSong(currentSongIndex);
    }
}

void MainWindow::checkSliderPosition(int value) {
    if (value >= ui->horizontalSlider_Duration->maximum()) {
        playNextSong();
    }
}

void MainWindow::playSong(int index) {
    if (index >= 0 && index < playlist.size()) {
        player->setSource(QUrl::fromLocalFile(playlist[index]));
        player->play();

        // Update Play/Pause button
        IS_Pause = false;
        ui->pushButton_Play_Pause->setIcon(style()->standardIcon(QStyle::SP_MediaPause));

        // Get the file name without extension
        QString songName = QFileInfo(playlist[index]).baseName();
        ui->label_songTitle->setText(songName);
    }
}

void MainWindow::addSong() {
    QString fileName = QFileDialog::getOpenFileName(this, "Add Song", "", "Audio and Video Files (*.mp3 *.wav *.mp4 *.avi)");
    if (!fileName.isEmpty()) {
        ui->playlistWidget->addItem(fileName);  // Add file to playlist
        player->setSource(QUrl::fromLocalFile(fileName));
    }
}

void MainWindow::savePlaylist() {
    QString fileName = QFileDialog::getSaveFileName(this, "Save Playlist", "", "JSON Files (*.json)");
    if (!fileName.isEmpty()) {
        QJsonArray jsonArray;
        for (int i = 0; i < ui->playlistWidget->count(); ++i) {
            jsonArray.append(ui->playlistWidget->item(i)->text());
        }
        QJsonDocument doc(jsonArray);
        QFile file(fileName);
        if (file.open(QIODevice::WriteOnly)) {
            file.write(doc.toJson());
            file.close();
        }
    }
}

void MainWindow::loadPlaylist() {
    QString fileName = QFileDialog::getOpenFileName(this, "Load Playlist", "", "JSON Files (*.json)");
    if (!fileName.isEmpty()) {
        QFile file(fileName);
        if (file.open(QIODevice::ReadOnly)) {
            QJsonDocument doc = QJsonDocument::fromJson(file.readAll());
            QJsonArray jsonArray = doc.array();
            ui->playlistWidget->clear();
            for (const auto &url : jsonArray) {
                ui->playlistWidget->addItem(url.toString());
            }
            file.close();
        }
    }
}

void MainWindow::connectBluetooth() {
    discoveryAgent->start();
    connect(discoveryAgent, &QBluetoothDeviceDiscoveryAgent::deviceDiscovered, this, [this](const QBluetoothDeviceInfo &info) {
        QMessageBox::information(this, "Device Found", info.name() + " - " + info.address().toString());
    });
}

void MainWindow::onBluetoothButtonClicked() {
    // Ví dụ: bắt đầu tìm kiếm thiết bị Bluetooth
    if (discoveryAgent->isActive()) {
        discoveryAgent->stop();
        QMessageBox::information(this, "Bluetooth", "Dừng tìm kiếm thiết bị.");
    } else {
        discoveryAgent->start();
        QMessageBox::information(this, "Bluetooth", "Bắt đầu tìm kiếm thiết bị.");
    }
}

// void MainWindow::toggleBluetooth() {
//     QBluetoothLocalDevice localDevice;

//     if (!localDevice.isValid()) {
//         QMessageBox::critical(this, "Bluetooth", "Bluetooth không khả dụng trên thiết bị này!");
//         return;
//     }

//     // Kiểm tra và bật chế độ discoverable nếu chưa bật
//     if (!localDevice.hostMode().testFlag(QBluetoothLocalDevice::HostDiscoverable)) {
//         localDevice.setHostMode(QBluetoothLocalDevice::HostDiscoverable);
//         QMessageBox::information(this, "Bluetooth", "Bluetooth đã được bật.");
//     } else {
//         QMessageBox::information(this, "Bluetooth", "Bluetooth đã sẵn sàng.");
//     }
// }

void MainWindow::toggleBluetooth() {
    QBluetoothLocalDevice localDevice;

    // Kiểm tra nếu Bluetooth không khả dụng
    if (!localDevice.isValid()) {
        QMessageBox::critical(this, "Bluetooth", "Bluetooth không khả dụng trên thiết bị này!");
        return;
    }

    // Kiểm tra chế độ hiện tại và chuyển sang HostDiscoverable nếu cần
    if (localDevice.hostMode() != QBluetoothLocalDevice::HostDiscoverable) {
        localDevice.setHostMode(QBluetoothLocalDevice::HostDiscoverable);
        QMessageBox::information(this, "Bluetooth", "Bluetooth đã được bật.");
    } else {
        QMessageBox::information(this, "Bluetooth", "Bluetooth đã ở chế độ HostDiscoverable.");
    }
}

// QBluetoothLocalDevice localDevice;
// if (!localDevice.isValid()) {
//     QMessageBox::critical(this, "Bluetooth", "Bluetooth không khả dụng trên thiết bị này!");
//     return;
// }

// if (!localDevice.hostMode().testFlag(QBluetoothLocalDevice::HostDiscoverable)) {
//     localDevice.setHostMode(QBluetoothLocalDevice::HostDiscoverable);
//     QMessageBox::information(this, "Bluetooth", "Bluetooth đã được bật.");
// }


// void MainWindow::positionChanged(qint64 duration) {
//     if (!ui->horizontalSlider_Duration->isSliderDown()) {
//         ui->horizontalSlider_Duration->setValue(duration / 1000);
//     }
//     updateDuration(position / 1000);
// }

// void MainWindow::durationChanged(qint64 duration) {
//     mDuration = duration / 1000;
//     ui->horizontalSlider_Duration->setMaximum(mDuration);
// }
