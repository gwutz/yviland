using SDL.Video;

public class TextRenderSystem : Engine.IteratingEntitySystem {
    private weak FontManager fontManager;
    private weak Renderer renderer;

    public TextRenderSystem(FontManager fontManager, Renderer renderer) {
        this.fontManager = fontManager;
        this.renderer = renderer;
    }


    public override Type[] getEntityTypes() {
        return {
            typeof(TextComponent)
        };
    }

    public override void processEntity(float deltaTime, Engine.Entity e) {
        var textc = e.get_component<TextComponent>();
        if(textc.visible) {
            debug("RENDER STRING %s", textc.text);
            unowned SDLTTF.Font font = fontManager.getFont(textc.font);
            if(font == null) {
                debug("Font is null");
                return;
            }
            var surface = font.render_blended_utf8(textc.text, textc.color);
            if(surface == null) {
                debug("Surface is null");
            }
            var texture = SDL.Video.Texture.create_from_surface(renderer, surface);

            var dst = SDL.Video.Rect() {
                x = 0, y = 0, w = surface.w, h = surface.h
            };

            renderer.copy(texture, null, dst);
        }
    }
}
