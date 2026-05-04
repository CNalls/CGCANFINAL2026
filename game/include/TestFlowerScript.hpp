#pragma once

#include <Canis/Entity.hpp>

namespace Canis
{
    class App;
}
class TestFlowerScript : public Canis::ScriptableEntity
{
public:
    static constexpr const char* ScriptName = "TestFlowerScript";
    Canis::Entity* hideObject = nullptr;

    // alis of textures
    std::vector<std::string> texturePaths = {
        "assets/textures/block_game/grass.png",
        "assets/textures/block_game/blue_orchid.png"
        
    };

    explicit TestFlowerScript(Canis::Entity& _entity) : Canis::ScriptableEntity(_entity) {}

    void Create() override;
    void Ready() override;
    void Destroy() override;
    void Update(float _dt) override;
};

void RegisterTestFlowerScriptScript(Canis::App& _app);
void UnRegisterTestFlowerScriptScript(Canis::App& _app);
