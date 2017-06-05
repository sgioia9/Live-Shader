#ifndef FRAGMENTSHADEREDITOR_HPP 
#define FRAGMENTSHADEREDITOR_HPP 

#include "shadereditor.hpp" 
class FragmentShaderEditor: public ShaderEditor {
public:
  static FragmentShaderEditor* get();
  
  FragmentShaderEditor(const FragmentShaderEditor&) = delete;
  void operator=(const FragmentShaderEditor&) = delete;

private:
  FragmentShaderEditor();

  static FragmentShaderEditor* _instance;

};

#endif
