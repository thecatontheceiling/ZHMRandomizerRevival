#pragma once

#include <IPluginInterface.h>
#include <Glacier/SGameUpdateEvent.h>
#include <memory>
#include "randomizers/Randomizer.h"

namespace hitman_randomizer {
    class Config;
    class RandomDrawRepository;
    class DefaultItemPoolRepository;
    class Randomizer;
}

class ZHMRandomizer : public IPluginInterface {
public:
    void OnEngineInitialized() override;
    ~ZHMRandomizer() override;
    void OnDrawMenu() override;
    void OnDrawUI(bool p_HasFocus) override;

private:
    std::shared_ptr<hitman_randomizer::RandomDrawRepository> m_repo;
    std::unique_ptr<hitman_randomizer::DefaultItemPoolRepository> m_defaultItemPoolRepo;

    std::unique_ptr<hitman_randomizer::Randomizer> m_worldInventoryRandomizer;
    std::unique_ptr<hitman_randomizer::Randomizer> m_npcItemRandomizer;
    std::unique_ptr<hitman_randomizer::Randomizer> m_heroInventoryRandomizer;
    std::unique_ptr<hitman_randomizer::Randomizer> m_stashItemRandomizer;

    std::shared_ptr<hitman_randomizer::Config> m_config;
    std::shared_ptr<hitman_randomizer::RandomDrawRepository> m_repo;
    std::unique_ptr<hitman_randomizer::DefaultItemPoolRepository> m_defaultItemPoolRepo;

    void createRandomizers();

    bool m_isMenuVisible = false;

    void OnFrameUpdate(const SGameUpdateEvent& p_UpdateEvent);
    DECLARE_PLUGIN_DETOUR(ZHMRandomizer, void, OnLoadScene, ZEntitySceneContext* th, ZSceneData& p_SceneData);

private:
    bool m_ShowMessage = false;
};

DEFINE_ZHM_PLUGIN(ZHMRandomizer)
