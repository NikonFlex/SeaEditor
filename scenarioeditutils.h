#ifndef SCENARIOEDITUTILS
#define SCENARIOEDITUTILS

#include "scenario_data.h"

inline Scenario::target find_target(const Scenario::TargetVector& targets, int id)
{
  for (const auto& t : targets)
    if (t.id == id)
      return t;
  return Scenario::target();
}

inline int make_new_id(const Scenario::TargetVector& targets)
{
  int max_id = 0;
  for (const auto& t : targets)
    max_id = t.id >= max_id ? t.id : max_id;
  return max_id + 1;
}

inline void delete_target(Scenario::TargetVector& targets, int id)
{
  for (int i = 0; i < targets.size(); i++)
    if (targets[i].id == id)
    {
      targets.remove(i);
      return;
    }
}

#endif // SCENARIOEDITUTILS

