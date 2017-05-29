#ifndef MAINFRAME_HPP
#define MAINFRAME_HPP

#include <QMainWindow>
#include <QKeyEvent>
#include <EventBus.hpp>

class QShowEvent;

// extends Object to send events
class MainFrame : public QMainWindow , public Object {
  Q_OBJECT

public:
  MainFrame();

  void showEvent(QShowEvent*);

 /* 
protected:
  void keyPressEvent(QKeyEvent*) override;
  */

private slots:
  void onAddNew();
};

class GuiReadyEvent : public Event {
public:
  GuiReadyEvent(Object& sender) : Event(sender) { }

  virtual ~GuiReadyEvent() { }
};

#endif
