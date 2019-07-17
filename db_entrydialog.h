#ifndef DB_ENTRYDIALOG_H
#define DB_ENTRYDIALOG_H

#include <QDialog>
#include <dbhandler.h>
/**
 *Shows all data for chosen entry
 */
namespace Ui {
class DbEntryDialog;
}

class DbEntryDialog : public QDialog
{
    Q_OBJECT

public:
    explicit DbEntryDialog(QWidget *parent = 0);
    ~DbEntryDialog();
    void setCaption(QString caption);
    void setTableData(QSharedPointer<QList<QString>> data);

private:
    Ui::DbEntryDialog *ui;
};

#endif // DB_ENTRYDIALOG_H
