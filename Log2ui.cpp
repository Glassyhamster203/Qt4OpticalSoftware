#include "Log2ui.h"
QMutex mutex;

void MainWindow::softwave_log_callback(QtMsgType type, const QMessageLogContext &context, const QString &msg)
{
    // 加锁
    mutex.lock();

    QByteArray localMsg = msg.toLocal8Bit();

    //信息分类
    QString strMsg("");
//    switch(type)
//    {
//    case QtDebugMsg:
//        strMsg = QString("Debug:");
//        break;
//    case QtInfoMsg:
//        strMsg = QString("Info:");
//        break;
//    case QtWarningMsg:
//        strMsg = QString("Warning:");
//        break;
//    case QtCriticalMsg:
//        strMsg = QString("Critical:");
//        break;
//    case QtFatalMsg:
//        strMsg = QString("Fatal:");
//        break;

//        default:
//            break;
//    }
    // 设置输出信息格式
    QString strDateTime = QDateTime::currentDateTime().toString("hh:mm:ss");
    QString strMessage = QString("%1 %2:%3").arg(strDateTime).arg(strMsg).arg(localMsg.constData());
    // 输出信息到UI
//    mainUI->ui->LogTextBrowser->appendPlainText(strMessage);
        mainUI->LogContextUpdate(localMsg);
    // 解锁
    mutex.unlock();

}



