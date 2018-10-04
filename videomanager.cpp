#include "videomanager.h"
#include <QDebug>
#include <QImage>
#include <opencv2/core/core.hpp>
#include <opencv2/highgui/highgui.hpp>
// needed for Shared memory stuff
#include <sys/mman.h>
#include <fcntl.h>
#include <QTime>

using namespace cv;

VideoManager::VideoManager() : QQuickImageProvider (QQuickImageProvider :: Pixmap)
{
    // variable initiation
    shm_pointer = NULL;
    frame = new cv::Mat(cv::Size(WIDTH, HEIGHT), CV_8UC3, memory_data + HEADER_LENGTH);
    int file = shm_open("/shrMem", O_RDWR, 0600);									// file descriptor

    if (file == -1) {
        qDebug() << "Error occured when connecting to shared memory";
    }

    // mapping the file to memory
    shm_pointer = mmap((void *)0, MEM_SIZE, PROT_READ | PROT_WRITE, MAP_SHARED, file, 0);

    if (shm_pointer == MAP_FAILED) {
        qDebug() << "failed mapping";
    }
    outputImage = new QImage((uchar*)(memory_data + HEADER_LENGTH), WIDTH, HEIGHT, QImage::Format_RGB888);
}
VideoManager::~VideoManager()
{
    // unmap the file from memory
    munmap(shm_pointer, MEM_SIZE);
}

void VideoManager::framePainted()
{
    readyfor = true;
}

void VideoManager::run()
{
    isRunning = true;
    while (isRunning) {
        // check whether the data is ready to read
        do {
            memcpy(h.bytes, shm_pointer, 1);
        } while (h.data.frameReady != 1);

        // read the frame from memory
        memcpy(memory_data, shm_pointer, BLOCK_SIZE);

        // clear frameReady flag to confirm that reading has been completed
        h.data.frameReady = 0;

        // update header
        //.................................... PUT HERE FEEDBACK FROM MOUSE

        memcpy(shm_pointer, h.bytes, HEADER_LENGTH);

        // show the image
        emit frameChanged();
    }
}

QPixmap VideoManager::requestPixmap(const QString &id, QSize *size, const QSize &requestedSize)
{
    QPixmap imagePix = QPixmap::fromImage(*outputImage);
    return imagePix;
}
