#include "configuration.h"
#include "ui_configuration.h"
#include <mainwindow.h>
//#include <QSizeF>

Configuration::Configuration(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Configuration)
{
    ui->setupUi(this);
    FUI = (MainWindow*)parent;//((MainWindow*)FUI)->octonetwork.SendGCode(_GCode_Setting);

    QStringList strList;
    strList.append("Wifi");
//    strList.append("GConde");
    strList.append("Terminal");

    foreach(QString item,strList)
    {
        QStandardItem *menulist = new QStandardItem(static_cast<QString>(item));
        menulist->setTextAlignment(Qt::AlignCenter);
        if(item == "Wifi")
        {
            menulist->setIcon(QIcon(":/assets/Wifi.svg"));
        }
        else if(item == "Terminal")
        {
            menulist->setIcon(QIcon(":/assets/terminal.svg"));
        }

        ItemModel->appendRow(menulist);
    }
    ui->Frm_ListView->setModel(ItemModel);
    ui->Frm_ListView->setIconSize(QSize((int)(SizePercent.width()*72),(int)(SizePercent.height()*72)));

    QFont font;
    font.setPointSize((int)(ui->Frm_ListView->font().pointSize()*(SizePercent.width() < SizePercent.height() ? SizePercent.width():SizePercent.height())));
    ui->Frm_ListView->setFont(font);

    this->resize((int)(SizePercent.width()*800),(int)(SizePercent.height()*480));
    this->setMaximumSize((int)(SizePercent.width()*800),(int)(SizePercent.height()*480));
    this->setFixedSize((int)(SizePercent.width()*800),(int)(SizePercent.height()*480));
}

Configuration::~Configuration()
{
    delete ui;
}

void Configuration::on_Btn_Back_clicked()
{
    this->close();
}

void Configuration::showEvent(QShowEvent *event)
{
    Q_UNUSED(event);
}

void Configuration::on_Frm_ListView_doubleClicked(const QModelIndex &index)
{
    //ui->Btn_Help->setText(index.data().toString());
    if(index.data().toString() == "Wifi")
        ((MainWindow*)FUI)->wlanconfig->show();
    if(index.data().toString() == "Terminal")
        ((MainWindow*)FUI)->terminaldialog->show();
}
