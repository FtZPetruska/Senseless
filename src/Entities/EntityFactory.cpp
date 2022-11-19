#include "EntityFactory.hpp"

#include <memory>

#include "Entity.hpp"
#include "EntitySetting.hpp"
#include "EntityType.hpp"

#include "Doorman.hpp"
#include "Luis.hpp"
#include "Magnetick.hpp"
#include "Stalker.hpp"
#include "Vagrant.hpp"

using namespace GameLib;

std::unique_ptr<Entity> makeEntity(const EntitySetting &entity_setting) {
  switch (entity_setting.first) {
  case (EntityType::STALKER):
    break;
  case (EntityType::DOORMAN):
    break;
  case (EntityType::LUIS):
    break;
  case (EntityType::MAGNETICK):
    break;
  case (EntityType::VAGRANT):
    break;
  case (EntityType::PLAYER):
    break;
  }

  return {nullptr};
}
