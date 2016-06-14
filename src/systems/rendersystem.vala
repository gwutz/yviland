using SDL.Video;

public class RenderSystem : EntitySystem {

    private weak Renderer renderer;
    private weak TextureManager textureManager;
    private Gee.List<Entity> entities;
    private weak Camera camera;

    public RenderSystem(Camera camera, Renderer renderer, TextureManager textureManager) {
        this.camera = camera;
        this.renderer = renderer;
        this.textureManager = textureManager;
    }

    public override void update(float deltaTime) {
        this.entities = this.engine.getEntitiesFor(new Gee.ArrayList<Type>.wrap(
                    { typeof(RenderComponent), typeof(PositionComponent) }
        ));

        foreach (Entity e in entities) {
            // draw entities
            var v = e.get_component<RenderComponent>();
            render(v);
        }
    }

    private void render(RenderComponent c) {
        foreach (Entity e in entities) {
            var rendercomp = e.get_component<RenderComponent>();
            var pos = e.get_component<PositionComponent>();
            if( pos == null ){
                stdout.printf ("entity is missing a PositionComponent to get rendered\n");
            } else {
                var ani = e.get_component<AnimationComponent>();
                if( ani != null ){
                    pos.update_position ();

                    var r = SDL.Video.Rect () {
                        x = pos.x, y = pos.y, w = ani.sprite_width, h = rendercomp.h
                    };
    #if DEBUG
                    renderer.set_draw_color (255, 118, 118, 118);
                    renderer.fill_rect (r);

                    var collbox = e.get_component<CollisionComponent>();
                    if( collbox != null ){
                        renderer.set_draw_color (96, 190, 255, 118);
                        var box = SDL.Video.Rect () {
                            x = pos.x + collbox.box.x, y = pos.y + collbox.box.y,
                            w = collbox.box.w, h = collbox.box.h
                        };
                        renderer.fill_rect (box);
                    }
    #endif
                    textureManager.draw_frame (rendercomp.identifier, r, 0, ani.get_animation_sprite (), pos.flip, renderer);
                } else {
                    var r = SDL.Video.Rect () {
                        x = pos.x, y = pos.y, w = 203, h = 17
                    };
                    textureManager.draw (rendercomp.identifier, r, renderer);
                }
            }
        }
    }
}
