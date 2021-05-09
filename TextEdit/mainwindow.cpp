#include "mainwindow.h"
#include <QTextEdit>
#include <QFont>
#include<QLabel>
#include<QPushButton>
MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
{
    //Font Declarations
    QFont plaintext("Times New Roman",12,QFont::DemiBold);
    QFont label("Corbel",12);
    // Text Edit
    QTextEdit *editor=new QTextEdit(this);
    editor->setFont(plaintext);
    editor->setStyleSheet(" border: 1px solid blue;color:red;orange;letter-spacing:3px;");
    editor->move(30,50);
    editor->setMinimumSize(491,291);
    editor->setMaximumSize(491,291);
    // Label
      QLabel *textlabel=new QLabel(this);
      textlabel->setGeometry(30,25,121,21);
      textlabel->setStyleSheet(" color:navy;background-color:yellow;letter-spacing:3px;");
      textlabel->setText(" Text Editor");
      textlabel->setFont(label);

      //QPush Button
      QPushButton *cut,*copy,*paste,*undo,*redo,*html;
      cut=new QPushButton(this);copy=new QPushButton(this);paste=new QPushButton(this);
      undo=new QPushButton(this);redo=new QPushButton(this);html=new QPushButton(this);
      cut->setText("Cut");
      cut->setGeometry(30,350,93,28);
      copy->setText("Copy");
      copy->setGeometry(130,350,93,28);
      paste->setText("Paste");
      paste->setGeometry(30,400,93,28);
      undo->setText("Undo");
      undo->setGeometry(130,400,93,28);
      redo->setText("Redo");
      redo->move(230,400);
      html->setText("HTML");
      html->setGeometry(430,400,93,28);

      //actions
      connect(cut,&QPushButton::clicked,[=](){editor->cut();});
      connect(editor,&QTextEdit::textChanged,[=](){qDebug()<<"Text Changed";});
      connect(paste,&QPushButton::clicked,[=](){editor->paste();});
      connect(copy,&QPushButton::clicked,[=](){editor->copy();});
      connect(undo,&QPushButton::clicked,[=](){editor->undo();});
      connect(redo,&QPushButton::clicked,[=](){editor->redo();});
      //
      QString l="<br>THIS IS GEETHIKA<br><br><ul>NUMBERS<li>ONE</li><li>TWO</li><li>THREE</li>";
      connect(html,&QPushButton::clicked,[=]{editor->setText(l);});
}

MainWindow::~MainWindow()
{
}

