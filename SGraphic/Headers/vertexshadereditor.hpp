#ifndef VERTEXSHADEREDITOR_HPP
#define VERTEXSHADEREDITOR_HPP

#include "shadereditor.hpp" 

class MainFrame;

class VertexShaderEditor : public ShaderEditor {
  Q_OBJECT
public:
  static VertexShaderEditor* get();
  
  VertexShaderEditor(const VertexShaderEditor&) = delete;
  void operator=(const VertexShaderEditor&) = delete;

protected:
  void load() override;
  void save() override;

private:
  VertexShaderEditor();

  static VertexShaderEditor* _instance;

  friend MainFrame;
};

#endif
