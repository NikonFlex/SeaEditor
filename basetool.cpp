#include "basetool.h"

int BaseTool::tryChangeSelection(const QPoint& pos)
{
  int cur_selected = -1;

  const QVector<ViewModel>& view_models = _main_service->GetProjectService()->GetObjects();
  if (view_models.empty())
    return -1;

  for (size_t i = view_models.size() - 1; i > 0; i--)
  {
    const ViewModel & vm = view_models[i];
    if (vm.GetPicture()->geometry().contains(pos) && cur_selected == -1)
    {
      cur_selected = vm.GetId();
      ViewModel modif = vm;
      modif.SetSelected(true);
      modif.SetHovered(false);
      _main_service->GetProjectService()->ChangeObject(modif);
    }
    else if (vm.IsSelected())
    {
      ViewModel modif = vm;
      modif.SetSelected(false);
      _main_service->GetProjectService()->ChangeObject(modif);
    }
  }

  selection_data selection_d;
  selection_d.route_point = -1;
  selection_d.ship_id = cur_selected;
  _main_service->ChangeSelection(selection_d);
  return cur_selected;

}
