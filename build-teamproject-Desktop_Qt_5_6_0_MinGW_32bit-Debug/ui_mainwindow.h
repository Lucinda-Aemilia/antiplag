/********************************************************************************
** Form generated from reading UI file 'mainwindow.ui'
**
** Created by: Qt User Interface Compiler version 5.6.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWINDOW_H
#define UI_MAINWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QComboBox>
#include <QtWidgets/QFrame>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QTextBrowser>
#include <QtWidgets/QTextEdit>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QVBoxLayout *verticalLayout_4;
    QLabel *nameLabel;
    QVBoxLayout *verticalLayout_2;
    QHBoxLayout *horizontalLayout_2;
    QLabel *configLabel;
    QSpacerItem *horizontalSpacer;
    QFrame *line;
    QGridLayout *gridLayout;
    QLabel *dirLabel;
    QComboBox *comboBox;
    QLineEdit *lineEdit;
    QLabel *label;
    QLabel *label_2;
    QTextEdit *textEdit;
    QVBoxLayout *verticalLayout_3;
    QHBoxLayout *horizontalLayout_3;
    QLabel *configLabel_2;
    QSpacerItem *horizontalSpacer_2;
    QFrame *line_2;
    QHBoxLayout *horizontalLayout;
    QVBoxLayout *verticalLayout;
    QPushButton *configButton;
    QPushButton *processButton;
    QPushButton *resultButton;
    QPushButton *printButton;
    QPushButton *quitButton;
    QTextBrowser *textBrowser;

    void setupUi(QWidget *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName(QStringLiteral("MainWindow"));
        MainWindow->resize(527, 593);
        verticalLayout_4 = new QVBoxLayout(MainWindow);
        verticalLayout_4->setObjectName(QStringLiteral("verticalLayout_4"));
        nameLabel = new QLabel(MainWindow);
        nameLabel->setObjectName(QStringLiteral("nameLabel"));
        nameLabel->setMinimumSize(QSize(500, 50));
        nameLabel->setStyleSheet(QLatin1String("font: 87 9pt \"Arial Black\";\n"
"background-color: qlineargradient(spread:pad, x1:0, y1:0, x2:1, y2:0, stop:0 rgba(0, 0, 0, 255), stop:1 rgba(255, 255, 255, 255));\n"
"color: rgb(255, 255, 255);"));

        verticalLayout_4->addWidget(nameLabel);

        verticalLayout_2 = new QVBoxLayout();
        verticalLayout_2->setObjectName(QStringLiteral("verticalLayout_2"));
        horizontalLayout_2 = new QHBoxLayout();
        horizontalLayout_2->setObjectName(QStringLiteral("horizontalLayout_2"));
        configLabel = new QLabel(MainWindow);
        configLabel->setObjectName(QStringLiteral("configLabel"));

        horizontalLayout_2->addWidget(configLabel);

        horizontalSpacer = new QSpacerItem(408, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_2->addItem(horizontalSpacer);


        verticalLayout_2->addLayout(horizontalLayout_2);

        line = new QFrame(MainWindow);
        line->setObjectName(QStringLiteral("line"));
        line->setFrameShape(QFrame::HLine);
        line->setFrameShadow(QFrame::Sunken);

        verticalLayout_2->addWidget(line);


        verticalLayout_4->addLayout(verticalLayout_2);

        gridLayout = new QGridLayout();
        gridLayout->setObjectName(QStringLiteral("gridLayout"));
        dirLabel = new QLabel(MainWindow);
        dirLabel->setObjectName(QStringLiteral("dirLabel"));
        dirLabel->setMinimumSize(QSize(80, 0));
        dirLabel->setMaximumSize(QSize(80, 16777215));

        gridLayout->addWidget(dirLabel, 0, 0, 1, 1);

        comboBox = new QComboBox(MainWindow);
        comboBox->setObjectName(QStringLiteral("comboBox"));
        comboBox->setMinimumSize(QSize(0, 30));
        comboBox->setMaximumSize(QSize(16777215, 30));

        gridLayout->addWidget(comboBox, 2, 1, 1, 1);

        lineEdit = new QLineEdit(MainWindow);
        lineEdit->setObjectName(QStringLiteral("lineEdit"));
        lineEdit->setMinimumSize(QSize(0, 30));
        lineEdit->setMaximumSize(QSize(16777215, 30));

        gridLayout->addWidget(lineEdit, 0, 1, 1, 1);

        label = new QLabel(MainWindow);
        label->setObjectName(QStringLiteral("label"));
        label->setMinimumSize(QSize(80, 0));
        label->setMaximumSize(QSize(80, 16777215));
        label->setLayoutDirection(Qt::LeftToRight);

        gridLayout->addWidget(label, 1, 0, 1, 1);

        label_2 = new QLabel(MainWindow);
        label_2->setObjectName(QStringLiteral("label_2"));

        gridLayout->addWidget(label_2, 2, 0, 1, 1);

        textEdit = new QTextEdit(MainWindow);
        textEdit->setObjectName(QStringLiteral("textEdit"));

        gridLayout->addWidget(textEdit, 1, 1, 1, 1);


        verticalLayout_4->addLayout(gridLayout);

        verticalLayout_3 = new QVBoxLayout();
        verticalLayout_3->setObjectName(QStringLiteral("verticalLayout_3"));
        horizontalLayout_3 = new QHBoxLayout();
        horizontalLayout_3->setObjectName(QStringLiteral("horizontalLayout_3"));
        configLabel_2 = new QLabel(MainWindow);
        configLabel_2->setObjectName(QStringLiteral("configLabel_2"));

        horizontalLayout_3->addWidget(configLabel_2);

        horizontalSpacer_2 = new QSpacerItem(408, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_3->addItem(horizontalSpacer_2);


        verticalLayout_3->addLayout(horizontalLayout_3);

        line_2 = new QFrame(MainWindow);
        line_2->setObjectName(QStringLiteral("line_2"));
        line_2->setFrameShape(QFrame::HLine);
        line_2->setFrameShadow(QFrame::Sunken);

        verticalLayout_3->addWidget(line_2);


        verticalLayout_4->addLayout(verticalLayout_3);

        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setObjectName(QStringLiteral("horizontalLayout"));
        verticalLayout = new QVBoxLayout();
        verticalLayout->setObjectName(QStringLiteral("verticalLayout"));
        configButton = new QPushButton(MainWindow);
        configButton->setObjectName(QStringLiteral("configButton"));
        configButton->setMinimumSize(QSize(80, 30));
        configButton->setMaximumSize(QSize(80, 30));
        configButton->setStyleSheet(QStringLiteral("font: 10pt \"Arial\";"));

        verticalLayout->addWidget(configButton);

        processButton = new QPushButton(MainWindow);
        processButton->setObjectName(QStringLiteral("processButton"));
        processButton->setMinimumSize(QSize(80, 30));
        processButton->setMaximumSize(QSize(80, 30));
        processButton->setStyleSheet(QStringLiteral("font: 10pt \"Arial\";"));

        verticalLayout->addWidget(processButton);

        resultButton = new QPushButton(MainWindow);
        resultButton->setObjectName(QStringLiteral("resultButton"));
        resultButton->setMinimumSize(QSize(80, 30));
        resultButton->setMaximumSize(QSize(80, 30));
        resultButton->setStyleSheet(QStringLiteral("font: 10pt \"Arial\";"));

        verticalLayout->addWidget(resultButton);

        printButton = new QPushButton(MainWindow);
        printButton->setObjectName(QStringLiteral("printButton"));
        printButton->setMinimumSize(QSize(80, 30));
        printButton->setMaximumSize(QSize(80, 30));
        printButton->setStyleSheet(QStringLiteral("font: 10pt \"Arial\";"));

        verticalLayout->addWidget(printButton);

        quitButton = new QPushButton(MainWindow);
        quitButton->setObjectName(QStringLiteral("quitButton"));
        quitButton->setMinimumSize(QSize(80, 30));
        quitButton->setMaximumSize(QSize(80, 30));
        quitButton->setStyleSheet(QStringLiteral("font: 10pt \"Arial\";"));

        verticalLayout->addWidget(quitButton);


        horizontalLayout->addLayout(verticalLayout);

        textBrowser = new QTextBrowser(MainWindow);
        textBrowser->setObjectName(QStringLiteral("textBrowser"));
        textBrowser->setMinimumSize(QSize(0, 300));

        horizontalLayout->addWidget(textBrowser);


        verticalLayout_4->addLayout(horizontalLayout);


        retranslateUi(MainWindow);

        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QWidget *MainWindow)
    {
        MainWindow->setWindowTitle(QApplication::translate("MainWindow", "antiPlag", 0));
        nameLabel->setText(QApplication::translate("MainWindow", "<html><head/><body><h1 align=\"center\">antiPlag</h1></body></html>", 0));
        configLabel->setText(QApplication::translate("MainWindow", "Configuration", 0));
        dirLabel->setText(QApplication::translate("MainWindow", "Work Dir", 0));
        comboBox->clear();
        comboBox->insertItems(0, QStringList()
         << QApplication::translate("MainWindow", "Single Mode", 0)
         << QApplication::translate("MainWindow", "Multiple(Folder) Mode", 0)
        );
        label->setText(QApplication::translate("MainWindow", "<html><head/><body><p>Excluded<br/>Contents</p></body></html>", 0));
        label_2->setText(QApplication::translate("MainWindow", "File Mode", 0));
        configLabel_2->setText(QApplication::translate("MainWindow", "Execution", 0));
        configButton->setText(QApplication::translate("MainWindow", "Config", 0));
        processButton->setText(QApplication::translate("MainWindow", "Process", 0));
        resultButton->setText(QApplication::translate("MainWindow", "Result", 0));
        printButton->setText(QApplication::translate("MainWindow", "Print", 0));
        quitButton->setText(QApplication::translate("MainWindow", "Quit", 0));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
