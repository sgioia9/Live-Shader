#include "scene.hpp"

class CamController;

class NanosuitScene : public Scene {
  public:
    NanosuitScene();
    void attachController(CamController& conntroller);
    virtual void draw() override;
};
