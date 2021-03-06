// modules: sdl2 engine gee-0.8
// vapidirs: ../../engine
using SDL.Video;

public class RenderSystem : Engine.EntitySystem {
    private weak Renderer renderer;
    private weak TextureManager textureManager;
    private weak Camera camera;

    public RenderSystem(Camera camera, Renderer renderer, TextureManager textureManager) {
        this.camera = camera;
        this.renderer = renderer;
        this.textureManager = textureManager;
    }

    public override Type[] getEntityTypes() {
        return {
            typeof(RenderComponent),
            typeof(PositionComponent)
        };
    }

    public override void update(float deltaTime) {
        foreach (Engine.Entity e in entities) {
            render(e);
        }
    }

    private void render(Engine.Entity e) {
        var c = e.get_component<RenderComponent>();
        var pos = e.get_component<PositionComponent>();
        var ani = e.get_component<AnimationComponent>();
        var collision = e.get_component<CollisionComponent>();
        if(engine.state != Engine.State.PAUSED)
            pos.update_position();
        var r = Rect() {
            x = pos.x - camera.x, y = pos.y, w = c.w, h = c.h
        };

        /*if(collision != null) {
            renderer.set_draw_color (96, 190, 255, 118);
            var box = SDL.Video.Rect () {
                x = pos.x + collision.box.x, y = pos.y + collision.box.y,
                w = collision.box.w, h = collision.box.h
            };
            renderer.fill_rect (box);
        }*/

        if(ani != null) {
            textureManager.draw_frame(c.identifier, r, 0, ani.get_animation_number(), pos.flip, renderer);
        } else {
            textureManager.draw_frame(c.identifier, r, 0, 0, pos.flip, renderer);
        }
    }

    /*private void render(RenderComponent c) {
        foreach (Engine.Entity e in entities) {
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
    }*/
}
