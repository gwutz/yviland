// modules: sdl2 engine gee-0.8
// vapidirs: ../../engine
using SDL.Video;

public class TextureSystem : Engine.EntitySystem {
    private weak Renderer renderer;
    private weak TextureManager textureManager;

    public TextureSystem(Renderer renderer, TextureManager textureManager) {
        this.renderer = renderer;
        this.textureManager = textureManager;
    }

    public override Type[] getEntityTypes() {
        return {
            typeof(RenderComponent)
        };
    }

    public override void update(float deltaTime) {
        foreach (Engine.Entity e in entities) {
            var rendcomp = e.get_component<RenderComponent>();
            debug("CHECK TEXTURE: %s", rendcomp.identifier);
            if (!textureManager.texture_loaded(rendcomp.identifier)) {
                textureManager.load(rendcomp.identifier, rendcomp.sprite_filename, renderer);
            }
        }
    }
}
