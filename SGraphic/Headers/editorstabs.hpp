#ifndef EDITORSTABS_HPP
#define EDITORSTABS_HPP

#include <QTabWidget>
#include <vector>

class MainFrame;
class VertexShaderEditor;
class FragmentShaderEditor;

class EditorsTabs : public QTabWidget {
  Q_OBJECT
public:
  EditorsTabs();

private:
  VertexShaderEditor* _vertexShaderEditor;
  FragmentShaderEditor* _fragmentShaderEditor;

  friend MainFrame;
};

#endif
