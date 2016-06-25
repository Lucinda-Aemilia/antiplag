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
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QTextBrowser>
#include <QtWidgets/QTextEdit>
#include <QtWidgets/QToolButton>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QVBoxLayout *verticalLayout_2;
    QLabel *nameLabel;
    QHBoxLayout *horizontalLayout_2;
    QTextEdit *textEdit;
    QToolButton *toolButton;
    QHBoxLayout *horizontalLayout;
    QTextBrowser *textBrowser;
    QVBoxLayout *verticalLayout;
    QPushButton *processButton;
    QPushButton *resultButton;
    QPushButton *quitButton;

    void setupUi(QWidget *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName(QStringLiteral("MainWindow"));
        MainWindow->resize(500, 365);
        verticalLayout_2 = new QVBoxLayout(MainWindow);
        verticalLayout_2->setObjectName(QStringLiteral("verticalLayout_2"));
        nameLabel = new QLabel(MainWindow);
        nameLabel->setObjectName(QStringLiteral("nameLabel"));
        nameLabel->setMinimumSize(QSize(500, 50));
        nameLabel->setStyleSheet(QLatin1String("font: 87 9pt \"Arial Black\";\n"
"background-color: qlineargradient(spread:pad, x1:0, y1:0, x2:1, y2:0, stop:0 rgba(0, 0, 0, 255), stop:1 rgba(255, 255, 255, 255));\n"
"color: rgb(255, 255, 255);"));

        verticalLayout_2->addWidget(nameLabel);

        horizontalLayout_2 = new QHBoxLayout();
        horizontalLayout_2->setObjectName(QStringLiteral("horizontalLayout_2"));
        textEdit = new QTextEdit(MainWindow);
        textEdit->setObjectName(QStringLiteral("textEdit"));
        textEdit->setMaximumSize(QSize(16777215, 30));

        horizontalLayout_2->addWidget(textEdit);

        toolButton = new QToolButton(MainWindow);
        toolButton->setObjectName(QStringLiteral("toolButton"));

        horizontalLayout_2->addWidget(toolButton);


        verticalLayout_2->addLayout(horizontalLayout_2);

        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setObjectName(QStringLiteral("horizontalLayout"));
        textBrowser = new QTextBrowser(MainWindow);
        textBrowser->setObjectName(QStringLiteral("textBrowser"));
        textBrowser->setMinimumSize(QSize(0, 300));

        horizontalLayout->addWidget(textBrowser);

        verticalLayout = new QVBoxLayout();
        verticalLayout->setObjectName(QStringLiteral("verticalLayout"));
        processButton = new QPushButton(MainWindow);
        processButton->setObjectName(QStringLiteral("processButton"));
        processButton->setStyleSheet(QStringLiteral("font: 10pt \"Arial\";"));

        verticalLayout->addWidget(processButton);

        resultButton = new QPushButton(MainWindow);
        resultButton->setObjectName(QStringLiteral("resultButton"));
        resultButton->setStyleSheet(QStringLiteral("font: 10pt \"Arial\";"));

        verticalLayout->addWidget(resultButton);

        quitButton = new QPushButton(MainWindow);
        quitButton->setObjectName(QStringLiteral("quitButton"));
        quitButton->setStyleSheet(QStringLiteral("font: 10pt \"Arial\";"));

        verticalLayout->addWidget(quitButton);


        horizontalLayout->addLayout(verticalLayout);


        verticalLayout_2->addLayout(horizontalLayout);


        retranslateUi(MainWindow);

        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QWidget *MainWindow)
    {
        MainWindow->setWindowTitle(QApplication::translate("MainWindow", "antiPlag", 0));
        nameLabel->setText(QApplication::translate("MainWindow", "<html><head/><body><h1 align=\"center\">antiPlag</h1></body></html>", 0));
        toolButton->setText(QApplication::translate("MainWindow", "...", 0));
        processButton->setText(QApplication::translate("MainWindow", "Process", 0));
        resultButton->setText(QApplication::translate("MainWindow", "Result", 0));
        quitButton->setText(QApplication::translate("MainWindow", "Quit", 0));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
