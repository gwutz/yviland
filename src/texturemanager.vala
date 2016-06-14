using SDL;
using SDLImage;

public class Texture : GLib.Object {
    private SDL.Video.Texture texture;
    public Texture (ref SDL.Video.Texture texture) {
        this.texture = (owned) texture;
    }

    public unowned SDL.Video.Texture get_texture() {
        return this.texture;
    }

}

public class TextureManager : GLib.Object {
    private Gee.Map<string, Texture> map;
    public TextureManager () {
        this.map = new Gee.HashMap<string, Texture>();
    }

    public Texture load(string identifier, string filename, SDL.Video.Renderer renderer) {
        SDL.Video.Texture texture = SDLImage.load_texture (renderer, filename);
        Texture t = new Texture (ref texture);
        map.set (identifier, t);
        return t;
    }

    public void draw(string identifier, SDL.Video.Rect dst, SDL.Video.Renderer renderer) {
        var src = SDL.Video.Rect () {
            x = 0, y = 0, w = dst.w, h = dst.h
        };

        renderer.copy (map.get (identifier).get_texture (), src, dst);
    }

    public void draw_frame(string identifier, SDL.Video.Rect dst, int row, int column, Video.RendererFlip flip, SDL.Video.Renderer renderer) {
        var src = SDL.Video.Rect () {
            x = (int) dst.w * column,
            y = (int) dst.h * row,
            w = dst.w,
            h = dst.h
        };
        /*dst.x *= 4;
           dst.y *= 4;
           dst.w *= 4;
           dst.h *= 4;*/
        renderer.copyex (map.get (identifier).get_texture (), src, dst, 0, null, flip);
    }

}
