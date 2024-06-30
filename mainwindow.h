#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QTreeView>
#include <QListView>
#include <QLineEdit>
#include <QPushButton>
#include <QLabel>
#include <QComboBox>
#include <QFileSystemModel>
#include <QSplitter>

QT_BEGIN_NAMESPACE
namespace Ui {
class MainWindow;
}
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private:
    Ui::MainWindow *ui;
    QTreeView *treeView;
    QListView *listView;
    QLineEdit *searchLineEdit;
    QPushButton *backButton;
    QPushButton *forwardButton;
    QLabel *pathLabel;
    QComboBox *filterComboBox;
    QLabel *statusLabel;
    QFileSystemModel *dirModel;
    QFileSystemModel *fileModel;

private slots:
    void on_treeView_clicked(const QModelIndex &index);
    void on_backButton_clicked();
    void on_forwardButton_clicked();
    void on_searchLineEdit_textChanged(const QString &text);
    void on_filterComboBox_currentTextChanged(const QString &text);

};
#endif // MAINWINDOW_H
