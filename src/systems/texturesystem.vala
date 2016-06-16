using SDL.Video;

public class TextureSystem : Engine.EntitySystem {
    private weak Renderer renderer;
    private weak TextureManager textureManager;
    private Gee.List<Engine.Entity> entities;

    public TextureSystem(Renderer renderer, TextureManager textureManager) {
        this.renderer = renderer;
        this.textureManager = textureManager;
    }

    public override void update(float deltaTime) {
        this.entities = this.engine.getEntitiesFor(new Gee.ArrayList<Type>.wrap(
                    { typeof(RenderComponent) }
        ));
        foreach (Engine.Entity e in entities) {
            var rendcomp = e.get_component<RenderComponent>();
            if (!textureManager.texture_loaded(rendcomp.identifier)) {
                
                var texture = textureManager.load(rendcomp.identifier, rendcomp.sprite_filename, renderer);
            }
        }
    }
}
