#include "shadereditor.hpp"
#include "editorstabs.hpp"

EditorsTabs::EditorsTabs() {
  addTab(new ShaderEditor(), tr("Vertex shader"));  
  addTab(new ShaderEditor(), tr("Fragment shader"));
}
