#ifndef INTERFACESCENEVIEW_H
#define INTERFACESCENEVIEW_H

#include "scenario_data.h"
#include "interfacetool.h"
#include "editormath.h"
#include "viewmodel.h"

struct selection_data
{
  int ship_id = -1;
  int route_point = -1;
};

struct iEditorProject
{
  virtual const QVector<ViewModel>& GetObjects() const = 0;
  virtual int AddObject() = 0;
  virtual void DeleteObject(int id) = 0;
  virtual void ChangeObject(const ViewModel& view_model) = 0;
};

struct iScreenViewService
{
  virtual const Transformation GetScreenTransform() const = 0;
  virtual void SetScreenTransform(const Transformation& transformator) = 0;
  virtual void SetCursor(Qt::CursorShape) = 0;
  virtual QSize GetScreenSize() const = 0;
};

struct iMainService
{
  virtual void ChangeScenario(const QString& sender_name) = 0;
  virtual void ChangeSelection(selection_data& selection_d) = 0;
  virtual void ChangeWindow() = 0;
  virtual Scenario::scenario_data* GetScenario() = 0;
  virtual iScreenViewService* GetScreenViewService() const = 0;
  virtual iEditorProject* GetProjectService() const = 0;
  virtual iTool* GetActiveTool() const = 0;
  virtual void SetDefaultTool() = 0;
};


struct iSceneViewComponent
{
  virtual void SetMainService(iMainService *i_main_service) = 0;
  virtual void SetScenario(Scenario::scenario_data *scenario) = 0;
  virtual void ScenarioChanged() = 0;
  virtual void SelectionChanged(selection_data& selection_d) = 0;
  virtual void WindowChanged() = 0;
  virtual QString GetName() const = 0;
};

#endif // INTERFACESCENEVIEW_H
