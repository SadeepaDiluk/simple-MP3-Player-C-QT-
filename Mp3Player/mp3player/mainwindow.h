#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QMediaPlayer>
#include <QMediaPlaylist>
#include <QDebug>
#include <QLabel>
#include <QFileDialog>
#include <QStandardPaths>
#include <QSlider>
#include <QTime>
#include <QMediaMetaData>
#include <QDialog>
#include "dialog.h"
#include <QFileInfo>

namespace Ui {
class MainWindow;
}



class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();

private slots:
    void on_horizontalSlider_sliderMoved(int position);

    void on_dial_sliderMoved(int position);

    void on_actionPlay_triggered();

    void on_actionStop_triggered();

    void on_positionChanged(quint64 position);

    void on_durationChanged(quint64 position);

    void on_actionOpen_triggered();

    void updateState(QMediaPlayer::State state);

    void updatePosition(qint64 position);

    void on_actionPause_triggered();

private:
    Ui::MainWindow *ui;
    QMediaPlayer *player;
    QMediaPlaylist *playlist;
    QLabel *labelDuration;
    QSlider* positionSlider;
    QLabel* positionLable;
    QDialog *Dialog;
    QFileInfo *fileInfo;
};

#endif // MAINWINDOW_H
