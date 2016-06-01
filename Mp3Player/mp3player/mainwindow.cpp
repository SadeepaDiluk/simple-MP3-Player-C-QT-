#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    player = new QMediaPlayer(this);

    connect(player,&QMediaPlayer::positionChanged, this, &MainWindow::on_positionChanged);
    connect(player,&QMediaPlayer::durationChanged, this, &MainWindow::on_durationChanged);

    //positionLable = new QLabel(tr("00:00"), this);

}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_horizontalSlider_sliderMoved(int position)
{
    player->setPosition(position);
}

void MainWindow::on_dial_sliderMoved(int position)
{
    player->setVolume(position);
}

void MainWindow::on_actionPlay_triggered()
{
    player->play();

}

void MainWindow::on_actionStop_triggered()
{
    player->stop();

}

void MainWindow::on_positionChanged(quint64 position)
{
    ui-> horizontalSlider->setValue(position);
}

void MainWindow::on_durationChanged(quint64 position)
{
    ui->horizontalSlider->setMaximum(position);
}

void MainWindow::on_actionOpen_triggered()
{
//    Dialog = new dialog(this);
//    Dialog-> show();

    const QStringList files = QFileDialog::getOpenFileNames(this, "Open File", "", "MP3 files (*.mp3)");
    QList<QMediaContent> content;
    foreach(QString const &argument, files)
    {
        QFileInfo fileInfo(argument);
        if (fileInfo.exists()) {
            QUrl url = QUrl::fromLocalFile(fileInfo.absoluteFilePath());
            if (fileInfo.suffix().toLower() == QLatin1String("m3u")) {
                playlist->load(url);
            } else
                playlist->addMedia(url);
        } else {
            QUrl url(argument);
            if (url.isValid()) {
                playlist->addMedia(url);
            }
        }

       }

    QString title = player->metaData(QMediaMetaData::Title).toString();
    ui->test->setText(title);

//    player->setMedia(QUrl::fromLocalFile(files));
//    player->play();

}

//void MainWindow::updateState(QMediaPlayer::State state)
//{
//}

void MainWindow::updatePosition(qint64 position)
{
    positionSlider->setValue(position);
    QTime duration(0, position / 60000, qRound((position % 60000) / 1000.0));
    positionLable->setText(duration.toString(tr("mm:ss")));

}

void MainWindow::on_actionPause_triggered()
{
    player->pause();
}

