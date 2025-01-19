#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::~MainWindow() {
    delete ui;  // Giải phóng bộ nhớ giao diện nếu `ui` được cấp phát động
}

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent), ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    // Khởi tạo Player, AudioOutput, và Video chỉ một lần
    Player = new QMediaPlayer(this);
    AudioOutput = new QAudioOutput(this);
    Video = new QVideoWidget(this);
    DiscoveryAgent = new QBluetoothDeviceDiscoveryAgent(this);
    //ListDevice = new QListWidget(this);
   // setCentralWidget(ListDevice);
    Player->setAudioOutput(AudioOutput);  // Liên kết với QMediaPlayer
    Player->setVideoOutput(Video);  // Liên kết với Video

    // Đặt video widget vào groupBox_Video
    Video->setGeometry(5, 5, ui->groupBox_Video->width() - 5, ui->groupBox_Video->height() - 5);
    Video->setParent(ui->groupBox_Video);

    // Thiết lập icon cho các nút một lần trong constructor
    ui->pushButton_Play_Pause->setIcon(style()->standardIcon(QStyle::SP_MediaPlay));
    ui->pushButton_Play_Pause->setIconSize(QSize(60, 60));
   // ui->pushButton_Play_Pause->setIcon(QIcon(":/bluetooth-icon-vector-art-image-600nw-2488448915.webp"));
   // ui->pushButton_Play_Pause->setCheckable(true);
    //ui->pushButton_Stop->setIcon(style()->standardIcon(QStyle::SP_MediaStop));
    //ui->pushButton_Stop->setIconSize(QSize(45, 45));
    ui->pushButton_Seek_Backward->setIcon(style()->standardIcon(QStyle::SP_MediaSeekBackward));
    ui->pushButton_Seek_Backward->setIconSize(QSize(45,45));
    ui->pushButton_Seek_Forward->setIcon(style()->standardIcon(QStyle::SP_MediaSeekForward));
    ui->pushButton_Seek_Forward->setIconSize(QSize(45,45));
    ui->pushButton_Volume->setIcon(style()->standardIcon(QStyle::SP_MediaVolume));
    ui->pushButton_Volume->setIconSize(QSize(200,200));
    ui->pushButton_Next->setIcon(style()->standardIcon(QStyle::SP_MediaSkipForward));
    ui->pushButton_Next->setIconSize(QSize(45,45));
    ui->pushButton_Previous->setIcon(style()->standardIcon(QStyle::SP_MediaSkipBackward));
    ui->pushButton_Previous->setIconSize(QSize(45,45));
    ui->videoLabel->setPixmap(style()->standardPixmap(QStyle::SP_MediaStop));
    // Cài đặt thanh trượt âm lượng
    ui->horizontalSlider_Volume->setMinimum(0);
    ui->horizontalSlider_Volume->setMaximum(100);
    ui->horizontalSlider_Volume->setValue(30);
    AudioOutput->setVolume(ui->horizontalSlider_Volume->value() / 100.0);

    connect(Player, &QMediaPlayer::durationChanged, this, &MainWindow::durationChanged);
    connect(Player, &QMediaPlayer::positionChanged, this, &MainWindow::positionChanged);
    connect(ui->pushButton_Next, &QPushButton::clicked, this, &MainWindow::playNextSong);
    connect(ui->pushButton_Previous, &QPushButton::clicked, this, &MainWindow::playPreviousSong);
    connect(ui->horizontalSlider_Duration, &QSlider::valueChanged, this, &MainWindow::checkSliderPosition);

    // Thiết lập phạm vi cho thanh trượt thời gian
    ui->horizontalSlider_Duration->setRange(0, Player->duration() / 1000);

    // Kết nối sự kiện thay đổi âm lượng
    connect(ui->horizontalSlider_Volume, &QSlider::valueChanged, [&](int value) {
        if (!AudioOutput->isMuted()) {
            AudioOutput->setVolume(value / 100.0);
        }
    });
   // adjustSize();
}

void MainWindow::on_actionOpen_File_triggered() {
    QStringList fileNames = QFileDialog::getOpenFileNames(
        this, tr("Open Files"), "", tr("Media Files (*.mp4 *.mp3)"));

    if (!fileNames.isEmpty()) {
        loadPlaylist(fileNames); // Nạp playlist với các tệp đã chọn
    }
}

void MainWindow::durationChanged(qint64 duration) {
    mDuration = duration / 1000;
    ui->horizontalSlider_Duration->setMaximum(mDuration);
}

void MainWindow::positionChanged(qint64 duration) {
    if (!ui->horizontalSlider_Duration->isSliderDown()) {
        ui->horizontalSlider_Duration->setValue(duration / 1000);
    }
    updateDuration(duration / 1000);
}

void MainWindow::updateDuration(qint64 Duration) {
    QTime CurrentTime((Duration / 3600) % 60, (Duration / 60) % 60, Duration % 60);
    QTime TotalTime((mDuration / 3600) % 60, (mDuration / 60) % 60, mDuration % 60);
    QString Format = (mDuration > 3600) ? "hh:mm:ss" : "mm:ss";

    ui->label_current_Time->setText(CurrentTime.toString(Format));
    ui->label_Total_Time->setText(TotalTime.toString(Format));
}

void MainWindow::on_horizontalSlider_Duration_valueChanged(int value) {
    Player->setPosition(value * 1000);
}

void MainWindow::on_pushButton_Play_Pause_clicked() {
    if (IS_Pause) {
        IS_Pause = false;
        Player->play();
        ui->pushButton_Play_Pause->setIcon(style()->standardIcon(QStyle::SP_MediaPause));
    } else {
        IS_Pause = true;
        Player->pause();
        ui->pushButton_Play_Pause->setIcon(style()->standardIcon(QStyle::SP_MediaPlay));
    }
}

//void MainWindow::on_pushButton_Stop_clicked() {
  //  Player->stop();
  //  IS_Pause = true;
  //  ui->pushButton_Play_Pause->setIcon(style()->standardIcon(QStyle::SP_MediaPlay));
//}

void MainWindow::on_pushButton_Volume_clicked() {
    IS_Muted = !IS_Muted;
    AudioOutput->setMuted(IS_Muted);
    ui->pushButton_Volume->setIcon(style()->standardIcon(IS_Muted ? QStyle::SP_MediaVolumeMuted : QStyle::SP_MediaVolume));
}

void MainWindow::on_horizontalSlider_Volume_valueChanged(int value) {
    AudioOutput->setVolume(value / 100.0);
}

void MainWindow::on_pushButton_Seek_Backward_clicked() {
    int newPosition = ui->horizontalSlider_Duration->value() - 5;
    ui->horizontalSlider_Duration->setValue(newPosition);
    Player->setPosition(newPosition * 1000);
}

void MainWindow::on_pushButton_Seek_Forward_clicked() {
    int newPosition = ui->horizontalSlider_Duration->value() + 5;
    ui->horizontalSlider_Duration->setValue(newPosition);
    Player->setPosition(newPosition * 1000);
}

void MainWindow::loadPlaylist(const QStringList &songs) {
    playlist = songs;  // Chỉ lưu danh sách đường dẫn tệp
    currentSongIndex = 0;
    playSong(currentSongIndex);
}

void MainWindow::playNextSong() {
    if (currentSongIndex + 1 < playlist.size()) {
        currentSongIndex++;
        playSong(currentSongIndex);
    }
    else{
        playSong(0);
        currentSongIndex = 0;
    }
}

void MainWindow::playPreviousSong() {
    if (currentSongIndex - 1 >= 0) {
        currentSongIndex--;
        playSong(currentSongIndex);
    }
    else{
        playSong(playlist.size()-1);
        currentSongIndex = playlist.size()-1;
    }
}

void MainWindow::checkSliderPosition(int value) {
    if (value >= ui->horizontalSlider_Duration->maximum()) {
        playNextSong();
    }
}

void MainWindow::playSong(int index) {
    if (index >= 0 && index < playlist.size()) {
        Player->setSource(QUrl::fromLocalFile(playlist[index]));
        Player->play();

        // Cập nhật nút Play/Pause
        IS_Pause = false;  // Đặt IS_Pause là false khi bài hát được phát
        ui->pushButton_Play_Pause->setIcon(style()->standardIcon(QStyle::SP_MediaPause));

        // Lấy tên file mà không có phần mở rộng
        QString songName = QFileInfo(playlist[index]).baseName();  // Lấy tên tệp không có đuôi
        ui->label_songTitle->setText(songName);  // Hiển thị tên bài hát trên nhãn
    }
}

void MainWindow::on_actionAdd_Device_triggered() //Scan devices and display name and address of each scanned device
{
    QDialog *deviceDialog = new QDialog(this);
    deviceDialog->setWindowTitle(tr("Add New Device"));
    QListWidget *ListDevice = new QListWidget(deviceDialog);
    DiscoveryAgent->start();
    connect(DiscoveryAgent, &QBluetoothDeviceDiscoveryAgent::deviceDiscovered, this, [ListDevice](const QBluetoothDeviceInfo &info) {
        ListDevice->addItem(info.name());
    });
    connect(ListDevice, &QListWidget::itemClicked, this, [this](QListWidgetItem *item) {
        ConnectToDevice(item->text()); // Kết nối với thiết bị đã chọn
    });
    deviceDialog->exec();
}
void MainWindow::ConnectToDevice(const QString &DeviceName){
    // Tìm thiết bị Bluetooth từ danh sách các thiết bị đã phát hiện
    foreach (const QBluetoothDeviceInfo &device, DiscoveryAgent->discoveredDevices()) {
        if (device.name() == DeviceName) {
            // Tạo một QBluetoothSocket để kết nối
            QBluetoothSocket *socket = new QBluetoothSocket(QBluetoothServiceInfo::RfcommProtocol, this);

            // Kết nối tín hiệu lỗi và thành công của kết nối
            connect(socket, &QBluetoothSocket::connected, this, &MainWindow::onDeviceConnected);
            connect(socket, &QBluetoothSocket::errorOccurred, this, &MainWindow::onDeviceError);

            // Kết nối đến thiết bị qua địa chỉ và cổng của nó
            static const QString serviceUuid(QStringLiteral("0000110b-0000-1000-8000-00805f9b34fb"));
            socket->connectToService(device.address(), QBluetoothUuid(serviceUuid));
            qDebug() << "Connecting to device: " << DeviceName;
            return;
        }
    }
    qDebug() << "Device not found: " << DeviceName;
}
void MainWindow::onDeviceConnected()
{
    qDebug() << "Connected to device!";
    // Bạn có thể thực hiện các thao tác thêm sau khi kết nối thành công, ví dụ: gửi/nhận dữ liệu
}

void MainWindow::onDeviceError(QBluetoothSocket::SocketError error)
{
    qDebug() << "Error occurred: " << error;
    // Xử lý lỗi kết nối tại đây
}
