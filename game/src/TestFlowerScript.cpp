#include <TestFlowerScript.hpp>

#include <Canis/App.hpp>
#include <Canis/ConfigHelper.hpp>
#include <Canis/AssetManager.hpp>


namespace
{
    Canis::ScriptConf scriptConf = {};
}

void RegisterTestFlowerScriptScript(Canis::App& _app)
{
    // REGISTER_PROPERTY(scriptConf, TestFlowerScript, exampleProperty);

    DEFAULT_CONFIG(scriptConf, TestFlowerScript);

    scriptConf.DEFAULT_DRAW_INSPECTOR(TestFlowerScript);

    _app.RegisterScript(scriptConf);
}

DEFAULT_UNREGISTER_SCRIPT(scriptConf, TestFlowerScript)

void TestFlowerScript::Create() {}

void TestFlowerScript::Ready() {

    i32 textureId = AssetManager::LoadTexture("assets/textures/fire_textures/blue_orchid.png");
    entity.GetComponent<Material>().materialFields.SetTexture("albedoFlowerMap", textureId);

    //seeding the randomizer
    static bool seeded = false;
    if (!seeded) 
    {
        srand(time(NULL));
        seeded = true;
    }

    //picks random index from my textures
    int randomIndex = rand() % texturePaths.size();
    std::string chosenPath = texturePaths[randomIndex];

    //loads and applies texture/s
    textureId = Canis::AssetManager::LoadTexture(chosenPath);
    
    //setter for texture and shader
    entity.GetComponent<Canis::Material>().materialFields.SetTexture("albedoFlowerMap", textureId);
}

void TestFlowerScript::Destroy() {}

void TestFlowerScript::Update(float) {}
