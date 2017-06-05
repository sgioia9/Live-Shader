#include "fragmentshadereditor.hpp"
#include "vertexshadereditor.hpp"
#include "editorstabs.hpp"

EditorsTabs::EditorsTabs() {
  addTab(VertexShaderEditor::get(), tr("Vertex shader"));  
  addTab(FragmentShaderEditor::get(), tr("Fragment shader"));
}
