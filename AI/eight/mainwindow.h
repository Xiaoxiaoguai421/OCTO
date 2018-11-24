#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include "bfs.h"
#include "dfs.h"
#include "heu.h"
namespace Ui
{
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private slots:
    void on_btn_quit_clicked();

    void on_edit_start_textEdited(const QString &arg1);

    void on_edit_target_textEdited(const QString &arg1);

    void on_btn_begin_clicked();

    void on_comboBox_activated(int index);

    void on_edit_depth_textEdited(const QString &arg1);

private:
    Ui::MainWindow *ui;
    std::string m_start;
    std::string m_target;
    int index_algo;
    int m_depth;
};

#endif // MAINWINDOW_H
