using SDL.Video;

public class RenderComponent : Engine.Component {
    public string identifier;
    public string sprite_filename;
    public uint w;
    public uint h;

    public RenderComponent (string identifier, string sprite_filename, uint w, uint h) {
        this.identifier = identifier;
        this.sprite_filename = sprite_filename;
        this.w = w;
        this.h = h;
    }

    public RenderComponent.withTexture (string identifier, string sprite_filename, TextureManager t, Renderer renderer) {
        this.identifier = identifier;
        var texture = t.load (identifier, sprite_filename, renderer);
        texture.get_texture ().query (null, null, out this.w, out this.h);
    }

    public RenderComponent.withTexture2 (string identifier, string sprite_filename) {
        this.identifier = identifier;
        this.sprite_filename = sprite_filename;
        //var texture = t.load (identifier, sprite_filename, renderer);
        //texture.get_texture ().query (null, null, out this.w, out this.h);
    }

    /*public void render(TextureManager texmanager, SDL.Video.Renderer renderer) {
        var pos = entity.get_component<PositionComponent>();
        if( pos == null ){
            stdout.printf ("entity is missing a PositionComponent to get rendered\n");
        } else {
            var ani = entity.get_component<AnimationComponent>();
            if( ani != null ){
                pos.update_position ();

                var r = SDL.Video.Rect () {
                    x = pos.x, y = pos.y, w = ani.sprite_width, h = this.h
                };
#if DEBUG
                renderer.set_draw_color (255, 118, 118, 118);
                renderer.fill_rect (r);

                var collbox = entity.get_component<CollisionComponent>();
                if( collbox != null ){
                    renderer.set_draw_color (96, 190, 255, 118);
                    var box = SDL.Video.Rect () {
                        x = pos.x + collbox.box.x, y = pos.y + collbox.box.y,
                        w = collbox.box.w, h = collbox.box.h
                    };
                    renderer.fill_rect (box);
                }
#endif
                texmanager.draw_frame (this.identifier, r, 0, ani.get_animation_sprite (), pos.flip, renderer);
            } else {
                var r = SDL.Video.Rect () {
                    x = pos.x, y = pos.y, w = 203, h = 17
                };
                texmanager.draw (this.identifier, r, renderer);
            }
        }
    }*/

}
