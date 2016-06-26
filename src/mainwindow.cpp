#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <fstream>
#include <QMessageBox>
#include <QDir>

int ans = 1;

void Initialize()
{
    // Initialize RK_BASE_POW
    for (int i = 1; i < PATTERN_LENGTH; i++)
    {
        ans *= RK_BASE;
        ans %= RK_MOD;
    }
}

extern const int RK_BASE_POW = ans;

void cleanUp()
{
    PatternTree::instance()->destroy();
    std::cout << "Finishing up this program" << std::endl;
}


MainWindow::MainWindow(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::MainWindow), m_curHomework(NULL), m_hwType(Homework::Single)
{
    ui->setupUi(this);
    Initialize();
    ui->textBrowser->setText(tr("Welcome!"));
}

MainWindow::~MainWindow()
{
    cleanUp();
    delete ui;
}

void MainWindow::on_processButton_clicked()
{
    if (m_curHomework != NULL)
    {
        delete m_curHomework;
        m_curHomework = NULL;
    }

    if (m_workdir == "")
    {
        QMessageBox::information(this, tr("Error"), tr("Not configured yet."));
        return;
    }

    ui->textBrowser->setText(tr("Running..."));
    m_curHomework = new Homework(m_workdir, m_hwType, m_toIgnore);

    ui->textBrowser->setText(tr("Done."));
}

void MainWindow::on_resultButton_clicked()
{
    if (m_curHomework == NULL)
    {
        QMessageBox::information(this, tr("Error"), tr("No Project is at work."));
    }
    else
    {
        QString str;
        std::vector<std::vector<int>> result(m_curHomework->getResult());
        for (int i = 0; i < result.size(); i++)
        {
            QString temp = QObject::tr("Project %1\n");
            str += temp.arg(i);

            for (int j = 0; j < result[i].size(); j++)
            {
                temp = QObject::tr("Clashes with Project %1 : %2\n");
                str += temp.arg(j).arg(result[i][j]);
            }
        }
        ui->textBrowser->setText(str);
    }
}

void MainWindow::on_quitButton_clicked()
{
    this->close();
}

void MainWindow::on_configButton_clicked()
{
    m_workdir = ui->lineEdit->text().toStdString();
    m_toIgnore = ui->textEdit->toPlainText().toStdString();

    QDir dir(QString::fromStdString(m_workdir));
    if (m_workdir == "" || !dir.exists())
    {
        QMessageBox::information(this, tr("Error"), tr("File folder does not exist."));
        m_workdir = "";
    }

    ui->textBrowser->setText(tr("Configured."));
}

void MainWindow::on_comboBox_currentIndexChanged(int index)
{
    if (index == 0)
        m_hwType = Homework::Single;
    else
        m_hwType = Homework::Multiple;
}

void MainWindow::on_printButton_clicked()
{
    if (m_curHomework == NULL)
        QMessageBox::information(this, tr("Error"), tr("No Project is at work."));
    else
    {
        if (m_curHomework->printToFile())
            QMessageBox::information(this, tr("Succeeded"), tr("Succeeded printed information to result.txt."));
        else
            QMessageBox::information(this, tr("Failed"), tr("Failed to print information to result.txt."));
    }
}
