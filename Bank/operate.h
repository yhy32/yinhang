#ifndef OPERATE_H
#define OPERATE_H

#include <QWidget>

namespace Ui {
class operate;
}

class operate : public QWidget
{
    Q_OBJECT

public:
    explicit operate(QWidget *parent = nullptr);
    ~operate();

private:
    Ui::operate *ui;
};

#endif // OPERATE_H
