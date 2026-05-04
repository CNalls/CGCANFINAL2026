#pragma once

#include <Canis/Entity.hpp>

namespace Canis
{
    class App;
}
class TestGrassBladesScript : public Canis::ScriptableEntity
{
public:
    static constexpr const char* ScriptName = "TestGrassBladesScript";

    Canis::Entity* hideObject = nullptr;

    explicit TestGrassBladesScript(Canis::Entity& _entity) : Canis::ScriptableEntity(_entity) {}

    void Create() override;
    void Ready() override;
    void Destroy() override;
    void Update(float _dt) override;
};

void RegisterTestGrassBladesScriptScript(Canis::App& _app);
void UnRegisterTestGrassBladesScriptScript(Canis::App& _app);
