#ifndef SETTINGS_H
#define SETTINGS_H

#include <QSettings>

class Settings : public QSettings
{
    Q_OBJECT
    Q_PROPERTY(int currentPage READ getCurrentPage WRITE setCurrentPage NOTIFY currentPageChanged)
public:
    explicit Settings(QObject *parent = 0);

    void restoreSettings();
    void saveSettings();

    int getCurrentPage() const;

public slots:
    void setCurrentPage(int value);

signals:
    void currentPageChanged();

private:
    int currentPage;
    QString translation;
    QString fontFamily;
    QString fontSize;
    QString theme;
};

#endif // SETTINGS_H