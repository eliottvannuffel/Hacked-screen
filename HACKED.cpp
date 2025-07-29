#include <QApplication>
#include <QMainWindow>
#include <QVBoxLayout>
#include <QHBoxLayout>
#include <QLabel>
#include <QTextEdit>
#include <QLineEdit>
#include <QTimer>
#include <QFont>
#include <QPalette>
#include <QColor>
#include <QKeyEvent>
#include <QPushButton>
#include <QWidget>
#include <QScreen>
#include <QDesktopWidget>
#include <QThread>
#include <QTime>
#include <QDate>
#include <QDebug>
#include <QScrollBar>
#include <QScreen>
#include <QPixmap>
#include <QDateTime>
#include <QDir>
#include <cstdlib>
#include <ctime>

class HackedWindow : public QMainWindow
{
    Q_OBJECT

public:
    HackedWindow(QWidget *parent = nullptr) : QMainWindow(parent)
    {
        setWindowTitle("⚠️ SYSTEM HACKED ⚠️");
        
        // Set window to fullscreen
        setWindowState(Qt::WindowFullScreen);
        
        // Set black background
        setStyleSheet("background-color: black;");
        
        // Create central widget
        QWidget *centralWidget = new QWidget(this);
        setCentralWidget(centralWidget);
        
        // Create main layout
        QVBoxLayout *mainLayout = new QVBoxLayout(centralWidget);
        mainLayout->setSpacing(20);
        mainLayout->setContentsMargins(40, 40, 40, 40);
        
        // Title
        QLabel *titleLabel = new QLabel("💥 SYSTEM HACKED 💥", this);
        titleLabel->setAlignment(Qt::AlignCenter);
        titleLabel->setStyleSheet("color: red; font-size: 72px; font-weight: bold; background-color: black;");
        mainLayout->addWidget(titleLabel);
        
        // Subtitle
        QLabel *subtitleLabel = new QLabel("🇧🇪 BELGIUM CLAIMS YOUR DEVICE 🇧🇪", this);
        subtitleLabel->setAlignment(Qt::AlignCenter);
        subtitleLabel->setStyleSheet("color: yellow; font-size: 36px; background-color: black;");
        mainLayout->addWidget(subtitleLabel);
        
        // ASCII Art
        QLabel *asciiLabel = new QLabel(this);
        asciiLabel->setText(
            "      [====]\n"
            "     | 🧇🧇 |\n"
            "     | 🧇🧇 |\n"
            "      [====]\n\n"
            "     [ 🍟🍟🍟 ]\n"
            "     [  🍟🍟  ]\n"
            "     [_______]"
        );
        asciiLabel->setAlignment(Qt::AlignCenter);
        asciiLabel->setStyleSheet("color: white; font-size: 28px; background-color: black; font-family: monospace;");
        mainLayout->addWidget(asciiLabel);
        
        // Log area
        QLabel *logTitle = new QLabel("HACKING LOG:", this);
        logTitle->setStyleSheet("color: green; font-size: 24px; font-weight: bold; background-color: black;");
        mainLayout->addWidget(logTitle);
        
        logArea = new QTextEdit(this);
        logArea->setStyleSheet(
            "QTextEdit {"
            "   background-color: black;"
            "   color: green;"
            "   font-size: 18px;"
            "   font-family: monospace;"
            "   border: 2px solid green;"
            "   padding: 15px;"
            "}"
        );
        logArea->setReadOnly(true);
        logArea->setMaximumHeight(400);
        mainLayout->addWidget(logArea);
        
        // Exit section
        QLabel *exitLabel = new QLabel("Type 'chicon' and press Enter to exit:", this);
        exitLabel->setAlignment(Qt::AlignCenter);
        exitLabel->setStyleSheet("color: white; font-size: 20px; background-color: black;");
        mainLayout->addWidget(exitLabel);
        
        exitInput = new QLineEdit(this);
        exitInput->setEchoMode(QLineEdit::Password);
        exitInput->setStyleSheet(
            "QLineEdit {"
            "   background-color: black;"
            "   color: green;"
            "   font-size: 20px;"
            "   font-family: monospace;"
            "   border: 2px solid green;"
            "   padding: 10px;"
            "}"
        );
        exitInput->setMaximumWidth(300);
        exitInput->setAlignment(Qt::AlignCenter);
        
        QHBoxLayout *inputLayout = new QHBoxLayout();
        inputLayout->addStretch();
        inputLayout->addWidget(exitInput);
        inputLayout->addStretch();
        mainLayout->addLayout(inputLayout);
        
        // Connect signals
        connect(exitInput, &QLineEdit::returnPressed, this, &HackedWindow::checkExit);
        
        // Set focus to input
        exitInput->setFocus();
        
        // Initialize random seed
        std::srand(std::time(nullptr));
        
        // Start message timer
        messageTimer = new QTimer(this);
        connect(messageTimer, &QTimer::timeout, this, &HackedWindow::addRandomMessage);
        
        // Screenshot timer - take screenshot after 30 seconds
        screenshotTimer = new QTimer(this);
        connect(screenshotTimer, &QTimer::timeout, this, &HackedWindow::takeScreenshot);
        screenshotTimer->setSingleShot(true);
        screenshotTimer->start(30000); // 30 seconds
        
        // Add initial messages
        addInitialMessages();
        
        // Start random messages after initial messages
        QTimer::singleShot(5000, this, [this]() {
            messageTimer->start(1000 + (std::rand() % 1500));
        });
    }
    
    void keyPressEvent(QKeyEvent *event) override
    {
        // Block F11 and other function keys
        if (event->key() == Qt::Key_F11 || 
            event->key() == Qt::Key_Escape ||
            event->key() == Qt::Key_F4) {
            event->ignore();
            return;
        }
        QMainWindow::keyPressEvent(event);
    }
    
    void closeEvent(QCloseEvent *event) override
    {
        // Prevent normal closing
        event->ignore();
    }

private slots:
    void addInitialMessages()
    {
        QStringList messages = {
            "[!] Establishing Brussels backdoor...",
            "[!] Injecting mayonnaise into firewall...",
            "[!] Replacing DNS with .be domains...",
            "[!] Loading King Philippe admin panel..."
        };
        
        for (int i = 0; i < messages.size(); ++i) {
            QTimer::singleShot(i * 1000, this, [this, messages, i]() {
                logArea->append(messages[i]);
                logArea->moveCursor(QTextCursor::End);
            });
        }
    }
    
    void addRandomMessage()
    {
        int randomNum = 1000 + (std::rand() % 9000);
        QString message = QString("[#] Brussels Override @ %1.be").arg(randomNum);
        logArea->append(message);
        logArea->moveCursor(QTextCursor::End);
    }
    
    void takeScreenshot()
    {
        try {
            // Get the primary screen
            QScreen *screen = QGuiApplication::primaryScreen();
            if (screen) {
                // Take screenshot of the entire screen
                QPixmap screenshot = screen->grabWindow(0);
                
                // Create filename with timestamp
                QString timestamp = QDateTime::currentDateTime().toString("yyyyMMdd_hhmmss");
                QString filename = QString("hacked_screenshot_%1.png").arg(timestamp);
                
                // Ensure Pictures directory exists
                QString picturesDir = QDir::homePath() + "/Pictures";
                QDir().mkpath(picturesDir);
                
                // Save screenshot
                QString fullPath = picturesDir + "/" + filename;
                if (screenshot.save(fullPath)) {
                    // Add message to log that screenshot was taken
                    logArea->append(QString("[!] Screenshot saved: %1").arg(filename));
                    logArea->moveCursor(QTextCursor::End);
                } else {
                    logArea->append("[!] Failed to save screenshot");
                    logArea->moveCursor(QTextCursor::End);
                }
            }
        } catch (...) {
            // Silently handle any errors
        }
    }
    
    void checkExit()
    {
        if (exitInput->text() == "chicon") {
            messageTimer->stop();
            screenshotTimer->stop();
            close();
            QApplication::quit();
        }
        exitInput->clear();
    }

private:
    QTextEdit *logArea;
    QLineEdit *exitInput;
    QTimer *messageTimer;
    QTimer *screenshotTimer;
};

int main(int argc, char *argv[])
{
    QApplication app(argc, argv);
    
    HackedWindow window;
    window.show();
    
    return app.exec();
}

#include "HACKED.moc" 