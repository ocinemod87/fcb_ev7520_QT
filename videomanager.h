#ifndef VIDEOMANAGER_H
#define VIDEOMANAGER_H
#include <QThread>
#include <opencv2/opencv.hpp>
#include <QQuickImageProvider>
#include <QImage>

#define MEM_SIZE        6300000
#define HEIGHT          1080
#define WIDTH           1920
#define BLOCK_SIZE      (HEIGHT * WIDTH * 3) + 1
#define HEADER_LENGTH   9

union header_t {
    uint8_t bytes[HEADER_LENGTH];
    struct {
        uint8_t frameReady;		// bit 0 of the memory
        uint8_t mouseTrigger;
        uint8_t mouseEvent;
        uint16_t xPosition;
        uint16_t yPosition;
        uint8_t keyTrigger;
        uint8_t keyValue;
    } data;
};

class VideoManager : public QThread, public QQuickImageProvider
{
    Q_OBJECT
private:
    void *shm_pointer;                  // pointer to the shared memory stack
    uint8_t memory_data[BLOCK_SIZE];	// buffer for raw memory data
    cv::Mat *frame;                     // opencv Mat frame referring to raw memory data and interpreting it to image
    header_t h;                         // union declaration
    bool isRunning;
    int framerate;
    bool readyfor;
    void run ()override;
public:
    QPixmap requestPixmap(const QString &id, QSize *size, const QSize& requestedSize);
    VideoManager ();
    ~VideoManager();
    QImage *outputImage; // check if can be private
signals:
    void frameChanged();

public slots:
    void framePainted();
};

#endif // VIDEOMANAGER_H
