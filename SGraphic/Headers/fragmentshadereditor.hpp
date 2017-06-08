#ifndef FRAGMENTSHADEREDITOR_HPP 
#define FRAGMENTSHADEREDITOR_HPP 

#include "shadereditor.hpp" 


class MainFrame;

class FragmentShaderEditor: public ShaderEditor {
public:
  static FragmentShaderEditor* get();
  
  FragmentShaderEditor(const FragmentShaderEditor&) = delete;
  void operator=(const FragmentShaderEditor&) = delete;

private slots:
  void load();

private:
  FragmentShaderEditor();

  static FragmentShaderEditor* _instance;

  friend MainFrame;
};

#endif
