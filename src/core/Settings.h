#ifndef SETTINGS_H
#define SETTINGS_H

#include <QSettings>

class Settings : public QSettings
{
    Q_OBJECT
    Q_PROPERTY(int fontSize READ getFontSize WRITE setFontSize NOTIFY fontSizeChanged)
    Q_PROPERTY(int translationFontSize READ getTranslationFontSize WRITE setTranslationFontSize NOTIFY translationFontSizeChanged)
    Q_PROPERTY(int currentPage READ getCurrentPage WRITE setCurrentPage NOTIFY currentPageChanged)
    Q_PROPERTY(QString textType READ getTextType WRITE setTextType NOTIFY settingsChanged)
    Q_PROPERTY(QString translation READ getTranslation WRITE setTranslation NOTIFY settingsChanged)
public:
    explicit Settings(QObject *parent = 0);

    void restoreSettings();
    Q_INVOKABLE void resetSettings();

    int getCurrentPage() const;
    int getFontSize() const;
    int getTranslationFontSize() const;
    QString getFontName() const;
    QString getTranslation() const;
    QString getTextType() const;

public slots:
    void setCurrentPage(const int &value);
    void setFontSize(const int &value);
    void setTranslationFontSize(const int &value);
    void setFontName(const QString &value);
    void setTranslation(const QString &value);
    void setTextType(const QString &value);

    void saveSettings();

signals:
    void fontSizeChanged();
    void translationFontSizeChanged();
    void currentPageChanged();
    void settingsChanged();

private:
    int currentPage;
    QString translation;
    QString fontName;
    QString dbName;
    int fontSize;
    int translationFontSize;
    QString textType;
    QString theme;
};

#endif // SETTINGS_H
