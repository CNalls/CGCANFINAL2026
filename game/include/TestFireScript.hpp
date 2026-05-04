#pragma once

#include <Canis/Entity.hpp>

namespace Canis
{
    class App;
}
class TestFireScript : public Canis::ScriptableEntity
{
public:
    static constexpr const char* ScriptName = "TestFireScript";

    Canis::Entity* hideObject = nullptr;
    float timer = 0.0f; // Added this to track time for the flicker

    explicit TestFireScript(Canis::Entity& _entity) : Canis::ScriptableEntity(_entity) {}

    void Create() override;
    void Ready() override;
    void Destroy() override;
    void Update(float _dt) override;
};

void RegisterTestFireScriptScript(Canis::App& _app);
void UnRegisterTestFireScriptScript(Canis::App& _app);
