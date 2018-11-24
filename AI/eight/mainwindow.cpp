#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    m_start="";
    m_target="";
    index_algo=0;
    m_depth=4;  //默认值

    ui->setupUi(this);
    ui->lab_depth->setVisible(false);
    ui->edit_depth->setEnabled(false);
    ui->edit_depth->setVisible(false);
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_btn_quit_clicked()
{
    close();
}

void MainWindow::on_edit_start_textEdited(const QString &arg1)
{
    m_start = arg1.toStdString();
}

void MainWindow::on_edit_target_textEdited(const QString &arg1)
{
    m_target = arg1.toStdString();
}

void MainWindow::on_btn_begin_clicked()
{
    if((""==m_start)||(""==m_target) )
        return;
    ui->tab_Info->clearContents();
    switch (index_algo)
    {
    case 0:
        break;
    case 1:
    {
        ui->tab_Info->setItem(0,0,new QTableWidgetItem("BFS"));
        bfs *temp = new bfs(m_start,m_target);
        temp->BfsSearch();
        if(temp->getREACH())
        {
            ui->tab_Info->setItem(0,1,new QTableWidgetItem("能"));
            ui->tab_Info->setItem(0,2,new QTableWidgetItem(QString::number(temp->getOPEN())));
            ui->tab_Info->setItem(0,3,new QTableWidgetItem(QString::number(temp->getCLOSED())));
        }
        else
        {
            ui->tab_Info->setItem(0,1,new QTableWidgetItem("否"));
            ui->tab_Info->setItem(0,2,new QTableWidgetItem(""));
            ui->tab_Info->setItem(0,3,new QTableWidgetItem(""));
        }
        break;
    }
    case 2:
    {
        ui->tab_Info->setItem(0,0,new QTableWidgetItem("DFS"));
        dfs *temp = new dfs(m_start,m_target,m_depth);
        temp->DfsSearch();
        if(temp->getREACH())
        {
            ui->tab_Info->setItem(0,1,new QTableWidgetItem("能"));
            ui->tab_Info->setItem(0,2,new QTableWidgetItem(QString::number(temp->getOPEN())));
            ui->tab_Info->setItem(0,3,new QTableWidgetItem(QString::number(temp->getCLOSED())));
        }
        else
        {
            ui->tab_Info->setItem(0,1,new QTableWidgetItem("否"));
            ui->tab_Info->setItem(0,2,new QTableWidgetItem(""));
            ui->tab_Info->setItem(0,3,new QTableWidgetItem(""));
        }
        break;
    }
    case 3:
    {
        ui->tab_Info->setItem(0,0,new QTableWidgetItem("有序搜索"));
        heu *temp = new heu(m_start,m_target);
        temp->HeuSearch();
        if(temp->getREACH())
        {
            ui->tab_Info->setItem(0,1,new QTableWidgetItem("能"));
            ui->tab_Info->setItem(0,2,new QTableWidgetItem(QString::number(temp->getOPEN())));
            ui->tab_Info->setItem(0,3,new QTableWidgetItem(QString::number(temp->getCLOSED())));
        }
        else
        {
            ui->tab_Info->setItem(0,1,new QTableWidgetItem("否"));
            ui->tab_Info->setItem(0,2,new QTableWidgetItem(""));
            ui->tab_Info->setItem(0,3,new QTableWidgetItem(""));
        }
        break;
    }
    default:
        break;
    }
}

void MainWindow::on_comboBox_activated(int index)
{
    index_algo=index;
    if(2==index_algo)
    {
        ui->lab_depth->setVisible(true);
        ui->edit_depth->setEnabled(true);
        ui->edit_depth->setVisible(true);
        ui->edit_depth->setText(QString("4"));
    }
    else
    {
        ui->lab_depth->setVisible(false);
        ui->edit_depth->setEnabled(false);
        ui->edit_depth->setVisible(false);
    }
}

void MainWindow::on_edit_depth_textEdited(const QString &arg1)
{
    m_depth=arg1.toInt();
}
