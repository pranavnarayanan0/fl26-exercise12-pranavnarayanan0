
#include <QtTest/QtTest>
#include <QtWidgets>
#include <QDebug>

#include "toggle_widget.h"

class TestToggleWidget : public QObject {
  Q_OBJECT

private slots:
  void testToggle();
};

void TestToggleWidget::testToggle() {
  ToggleWidget widget;

  QPushButton *button = widget.findChild<QPushButton *>();
  QVERIFY(button != nullptr);

  // Initially OFF
  QVERIFY(!widget.isOn());

  // Click once -> ON
  QTest::mouseClick(button, Qt::LeftButton);
  QVERIFY(widget.isOn());

  // Click twice -> OFF
  QTest::mouseClick(button, Qt::LeftButton);
  QVERIFY(!widget.isOn());
}

QTEST_MAIN(TestToggleWidget)
#include "test_toggle_widget.moc"
