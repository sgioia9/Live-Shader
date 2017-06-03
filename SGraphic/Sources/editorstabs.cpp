#include "fragmentshadereditor.hpp"
#include "vertexshadereditor.hpp"
#include "editorstabs.hpp"

EditorsTabs::EditorsTabs() {
  addTab(new VertexShaderEditor(), tr("Vertex shader"));  
  addTab(new FragmentShaderEditor(), tr("Fragment shader"));
}
