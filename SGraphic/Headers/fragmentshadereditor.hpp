#ifndef FRAGMENTSHADEREDITOR_HPP 
#define FRAGMENTSHADEREDITOR_HPP 

#include "shadereditor.hpp" 


class MainFrame;

class FragmentShaderEditor: public ShaderEditor {
  Q_OBJECT
public:
  static FragmentShaderEditor* get();
  
  FragmentShaderEditor(const FragmentShaderEditor&) = delete;
  void operator=(const FragmentShaderEditor&) = delete;

protected:
  void load() override;
  void save() override;

private:
  FragmentShaderEditor();

  static FragmentShaderEditor* _instance;

  friend MainFrame;
};

#endif
