#include "editor.h"
#include <QApplication>

int main(int argc, char *argv[])
{
  QApplication a(argc, argv);

  Scenario::scenario_data s = load_object_from_json<Scenario::scenario_data>(
        read_json_from_file("../EditorApp/res/Scenarios/scenario_3.json"));
  if (s.targets.empty())
      s = load_object_from_json<Scenario::scenario_data>(read_json_from_file("scenario_3.json"));

  Editor editor;
  editor.setWindowModality(Qt::ApplicationModal);
  editor.showMaximized();
  editor.LoadScenario(s);


  return a.exec();
}
