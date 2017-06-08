#include "fragmentshadereditor.hpp"
#include "vertexshadereditor.hpp"
#include "editorstabs.hpp"

EditorsTabs::EditorsTabs() {
  _vertexShaderEditor = VertexShaderEditor::get();
  _fragmentShaderEditor = FragmentShaderEditor::get();
  addTab(_vertexShaderEditor, tr("Vertex shader"));  
  addTab(_fragmentShaderEditor, tr("Fragment shader"));
}
