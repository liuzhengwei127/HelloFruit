#include "rankwindow.h"
#include "inputwindow.h"

Rankwindow::Rankwindow(bool ifp, int tot)
{
    ifpass = ifp;
    total = tot;
    resize(540,350);

    QPushButton *closebutton = new QPushButton("关闭",this);
    connect(closebutton,SIGNAL(clicked(bool)),this,SLOT(hide()));
    closebutton->setGeometry(0,300,180,50);

    QPushButton *uploadbutton = new QPushButton("上传成绩",this);
    connect(uploadbutton,SIGNAL(clicked(bool)),this,SLOT(getusername()));
    connect(uploadbutton,SIGNAL(clicked(bool)),uploadbutton,SLOT(close()));
    uploadbutton->setGeometry(360,300,180,50);
    if (!ifpass)
        uploadbutton->close();

    ranktxt.setParent(this);
    ranktxt.setStyleSheet("font:25px 微软雅黑");
    ranktxt.setGeometry(0,0,540,300);

    if(QSqlDatabase::contains("qt_sql_default_connection"))
        db = QSqlDatabase::database("qt_sql_default_connection");
    else
        db = QSqlDatabase::addDatabase("QMYSQL");

    db.setHostName("118.25.141.95");
    db.setDatabaseName("hellofruit");
    db.setUserName("root");
    db.setPassword("root");
    if(!db.open()){
        qDebug() << "数据库连接失败";
    }

    showrank();
}

void Rankwindow::showrank()   //显示排名
{
    QSqlQuery query;

    query.exec("select * from grades");

    for (int i=0;i<5;i++)
    {
        query.seek(i);

        QSqlRecord rec = query.record();

        int r = rec.value("rank").toInt();

        grade[r-1] = rec.value("grade").toInt();
        name[r-1] = rec.value("name").toString();
    }

    ranktxt.setText("\n\n"
                    "\t排名\t分数\t用户名\n"
                    "\t1\t"+QString::number(grade[0])+"\t"+name[0]+"\n"
                    "\t2\t"+QString::number(grade[1])+"\t"+name[1]+"\n"
                    "\t3\t"+QString::number(grade[2])+"\t"+name[2]+"\n"
                    "\t4\t"+QString::number(grade[3])+"\t"+name[3]+"\n"
                    "\t5\t"+QString::number(grade[4])+"\t"+name[4]+"\n");
}

void Rankwindow::upload(QString username) //上传排名
{    
    int k = 5;
    for (int i=0;i<5;i++)
        if (total > grade[i])
        {
            k = i;
            break;
        }

    if (k != 5)
    {
        QSqlQuery query;

        query.exec("update hellofruit.grades set name='"+username+"' where rank="+QString::number(k+1));
        query.exec("update hellofruit.grades set grade='"+QString::number(total)+"' where rank="+QString::number(k+1));
        for (int i=k+1;i<5;i++)
        {
            query.exec("update hellofruit.grades set name='"+name[i-1]+"' where rank="+QString::number(i+1));
            query.exec("update hellofruit.grades set grade='"+QString::number(grade[i-1])+"' where rank="+QString::number(i+1));
        }
    }

    showrank();
}

void Rankwindow::getusername()
{
    Inputwindow *in = new Inputwindow();
    connect(in,SIGNAL(name(QString)),this,SLOT(upload(QString)));
    in->show();
}
