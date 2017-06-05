#ifndef VERTEXSHADEREDITOR_HPP
#define VERTEXSHADEREDITOR_HPP

#include "shadereditor.hpp" 

class VertexShaderEditor : public ShaderEditor {
public:
  static VertexShaderEditor* get();
  
  VertexShaderEditor(const VertexShaderEditor&) = delete;
  void operator=(const VertexShaderEditor&) = delete;

private:
  VertexShaderEditor();

  static VertexShaderEditor* _instance;

};

#endif
