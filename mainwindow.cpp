#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    QFile file("D:/Projects/ELIFILEEXPLORER/style.qss");
    if (file.open(QFile::ReadOnly)) {
        QString styleSheet = QLatin1String(file.readAll());
        qApp->setStyleSheet(styleSheet);
    }

    ui->setupUi(this);

    backButton = new QPushButton("<", this);
    forwardButton = new QPushButton(">", this);
    pathLabel = new QLabel("Home/", this);
    searchLineEdit = new QLineEdit(this);
    filterComboBox = new QComboBox(this);
    filterComboBox->addItem(".pdf");
    filterComboBox->addItem(".png");
    filterComboBox->addItem("All Files");
    statusLabel = new QLabel("12 items, 26.2 GB", this);

    treeView = new QTreeView(this);
    listView = new QListView(this);

    dirModel = new QFileSystemModel(this);
    dirModel->setRootPath(QDir::rootPath());
    dirModel->setFilter(QDir::NoDotAndDotDot | QDir::AllDirs);

    fileModel = new QFileSystemModel(this);
    fileModel->setRootPath(QDir::rootPath());
    fileModel->setFilter(QDir::NoDotAndDotDot | QDir::Files);

    treeView->setModel(dirModel);
    listView->setModel(fileModel);

    // layouts
    QVBoxLayout *mainLayout = new QVBoxLayout;
    QHBoxLayout *topBarLayout = new QHBoxLayout;
    QSplitter *splitter = new QSplitter(Qt::Horizontal, this);

    topBarLayout->addWidget(backButton);
    topBarLayout->addWidget(forwardButton);
    topBarLayout->addWidget(pathLabel);
    topBarLayout->addWidget(searchLineEdit);
    topBarLayout->addWidget(filterComboBox);

    splitter->addWidget(treeView);
    splitter->addWidget(listView);

    mainLayout->addLayout(topBarLayout);
    mainLayout->addWidget(splitter);
    mainLayout->addWidget(statusLabel);

    QWidget *centralWidget = new QWidget(this);
    centralWidget->setLayout(mainLayout);
    setCentralWidget(centralWidget);

    // Set initial paths
    treeView->setRootIndex(dirModel->index(QDir::rootPath()));
    listView->setRootIndex(fileModel->index(QDir::rootPath()));

    connect(treeView, &QTreeView::clicked, this, &MainWindow::on_treeView_clicked);
    connect(backButton, &QPushButton::clicked, this, &MainWindow::on_backButton_clicked);
    connect(forwardButton, &QPushButton::clicked, this, &MainWindow::on_forwardButton_clicked);
    connect(searchLineEdit, &QLineEdit::textChanged, this, &MainWindow::on_searchLineEdit_textChanged);
    connect(filterComboBox, &QComboBox::currentTextChanged, this, &MainWindow::on_filterComboBox_currentTextChanged);
}

void MainWindow::on_treeView_clicked(const QModelIndex &index)
{
    QString path = dirModel->fileInfo(index).absoluteFilePath();
    pathLabel->setText(path);
    listView->setRootIndex(fileModel->setRootPath(path));
}

void MainWindow::on_backButton_clicked()
{
}

void MainWindow::on_forwardButton_clicked()
{
}

void MainWindow::on_searchLineEdit_textChanged(const QString &text)
{
}

void MainWindow::on_filterComboBox_currentTextChanged(const QString &text)
{
}


MainWindow::~MainWindow()
{
    delete ui;
}
