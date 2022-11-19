#ifndef SCREENVIEW_H
#define SCREENVIEW_H

#include "interfacesceneview.h"
#include "editormath.h"
#include <QWidget>
#include <QPointer>
#include <QSvgRenderer>
#include <QMap>
#include <QLabel>

class ScreenView : public QWidget, public iSceneViewComponent, public iScreenViewService, public iEditorProject
{
public:
  explicit ScreenView(QWidget *parent = 0);
  void ZoomAll();

protected:
  void paintEvent(QPaintEvent *event);
  void mouseMoveEvent(QMouseEvent *event);
  void mousePressEvent(QMouseEvent *event);
  void wheelEvent(QWheelEvent *event);

private:
  // iSceneViewComponent implementaion
  void SetMainService(iMainService* i_main_service) override final;
  void SetScenario(Scenario::scenario_data *scenario) override final;
  void ScenarioChanged() override final;
  void SelectionChanged(selection_data& selection_d) override final;
  void WindowChanged() override final;
  QString GetName() const override final;

  // iScreenViewService implementation
  const Transformation GetScreenTransform() const override final;
  void SetScreenTransform(const Transformation& transformator) override final;
  void SetCursor(Qt::CursorShape) override final;
  QSize GetScreenSize() const override final;

  // iEditorProject implementaion
  const QVector<ViewModel> &GetObjects() const override final;
  int AddObject() override final;
  void DeleteObject(int id) override final;
  void ChangeObject(const ViewModel& view_model) override final;

  void draw();
  void replaceView();
  QLabel* bringLabelToCommonForm(QLabel* label);
  ViewModel createNewViewModel(int pos_in_scenario);
  void setNewShipPicture(ViewModel &view_model);

private:
  Transformation _transformator;
  QVector<ViewModel> _view_models;
  iMainService* _main_service;
  Scenario::scenario_data* _scenario = nullptr;
  QPoint _last_mouse_pos;
};

#endif // SCREENVIEW_H
